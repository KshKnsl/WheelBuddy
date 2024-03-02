#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Car
{
public:
    string company;
    string model;
    int year;
    string licensePlate;
    bool isAvailable;
    int passengerCapacity;
};

void displayAvailableCars(vector<Car> &cars)
{
    cout << "Available Cars: " << endl;
    for (const Car &car : cars)
    {
        if (car.isAvailable)
        {
            cout << car.company << " " << car.model << " (" << car.year << ")\n";
            cout << "License Plate: " << car.licensePlate << "\n";
            cout << "Passenger Capacity: " << car.passengerCapacity << "\n";
            cout << "---------------------\n";
        }
    }
}

main()
{
    vector<Car> cars = {
        {"Toyota", "Camry", 2021, "ABC123", 50.0, true, 4},
        {"Honda", "Civic", 2022, "XYZ789", 45.0, true, 5},
        {"Ford", "Fusion", 2022, "DEF456", 55.0, true, 5},
        {"Hyundai", "Elantra", 2021, "GHI789", 48.0, true, 4},
        {"Chevrolet", "Malibu", 2020, "JKL012", 52.0, true, 5}};
}