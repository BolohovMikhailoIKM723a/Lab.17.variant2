#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Room {
private:
double area;

public:
Room(double a = 0.0) : area(a) {}
double getArea() const {
return area;
}
void setArea(double a) {
area = a;
}
};
class OneRoomApartment {
private:
Room room;
double kitchenArea;
int floor;
public:
    OneRoomApartment(double roomArea, double kitchenArea, int floor)
        : room(roomArea), kitchenArea(kitchenArea), floor(floor) {}

    Room getRoom() const {
        return room;
    }

    double getKitchenArea() const {
        return kitchenArea;
    }

    int getFloor() const {
        return floor;
    }

    void setRoomArea(double area) {
        room.setArea(area);
    }

    void setKitchenArea(double area) {
        kitchenArea = area;
    }

    void setFloor(int f) {
        floor = f;
    }
};

class CityOneRoomApartment : public OneRoomApartment {
private:
string cityName;

public:
CityOneRoomApartment(double roomArea, double kitchenArea, int floor, const string& city)
        : OneRoomApartment(roomArea, kitchenArea, floor), cityName(city) {}

    ~CityOneRoomApartment() {
        cout << "деструктор викликаний для квартири " << cityName << endl;
    }

    string getCityName() const {
        return cityName;
    }

    void setCityName(const string& city) {
        cityName = city;
    }

    void print() const {
        cout << "місто: " << cityName << endl;
        cout << "площа кімнати: " << getRoom().getArea() << " кв.м" << endl;
        cout << "площа кухні: " << getKitchenArea() << " кв.м" << endl;
        cout << "поверх: " << getFloor() << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    CityOneRoomApartment apartment(20.0, 10.0, 5, "харків");
    apartment.print();

    apartment.setCityName("київ");
    apartment.setRoomArea(25.0);
    apartment.setKitchenArea(12.0);
    apartment.setFloor(3);
    apartment.print();

    return 0;
}
