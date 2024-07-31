#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Car class definition
class Car {
public:
    string make;
    string model;
    int year;
    string color;
    int fuelLevel;

    // Constructor
    Car(string mk, string mdl, int yr, string clr, int fuel) 
        : make(mk), model(mdl), year(yr), color(clr), fuelLevel(fuel) {}

    // Member functions
    void start() {
        cout << "The car " << model <<" is starting." << endl;
    }

    void drive() {
        if (fuelLevel > 0) {
            fuelLevel--;
            cout << "The car is driving. Fuel level is now: " << fuelLevel << endl;
        } else {
            cout << "Cannot drive, fuel level is too low." << endl;
        }
    }

    void refuel(int amount) {
        fuelLevel += amount;
        cout << "The car is refueled. Fuel level is now: " << fuelLevel << endl;
    }
};

// Garage class definition
class Garage {
private:
    int capacity;
    vector<Car> cars;

public:
    // Constructor
    Garage(int cap) : capacity(cap) {}

    // Member functions
    void addCar(Car car) {
        if (cars.size() < capacity) {
            cars.push_back(car);
            cout << "Car added to the garage." << endl;
        } else {
            cout << "Garage is full, cannot add more cars." << endl;
        }
    }

    void listCars() {
        cout << "Listing cars in the garage:" << endl;
        for (Car car : cars) {
            cout << "Car Make: " << car.make << ", Model: " << car.model << endl;
        }
    }

    void findCarByMakeModel(string make, string model) {
        for (Car car : cars) {
            if (car.make == make && car.model == model) {
                cout << "Car found: Make: " << make << ", Model: " << model << endl;
                return;
            }
        }
        cout << "Car not found." << endl;
    }
};

// Main function
int main() {
    // Create a Garage object
    Garage garage(2);

    // Create Car objects
    Car car1("Toyota", "Corolla", 2020, "Blue", 10);
    Car car2("Honda", "Civic", 2019, "Red", 12);

    // Add cars to the garage
    garage.addCar(car1);
    garage.addCar(car2);

    car1.start();
    car2.start();

    // List cars in the garage
    garage.listCars();

    garage.findCarByMakeModel("Toyota", "Corolla");

    return 0;
}
