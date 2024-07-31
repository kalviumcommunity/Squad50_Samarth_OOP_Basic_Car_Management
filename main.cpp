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
        cout << "The car " << this->model << " is starting." << endl;
    }

    void drive() {
        if (this->fuelLevel > 0) {
            this->fuelLevel--;
            cout << "The car is driving. Fuel level is now: " << this->fuelLevel << endl;
        } else {
            cout << "Cannot drive, fuel level is too low." << endl;
        }
    }

    void refuel(int amount) {
        this->fuelLevel += amount;
        cout << "The car is refueled. Fuel level is now: " << this->fuelLevel << endl;
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
        if (this->cars.size() < this->capacity) {
            this->cars.push_back(car);
            cout << "Car added to the garage." << endl;
        } else {
            cout << "Garage is full, cannot add more cars." << endl;
        }
    }

    void listCars() {
        cout << "Listing cars in the garage:" << endl;
        for (Car car : this->cars) {
            cout << "Car Make: " << car.make << ", Model: " << car.model << endl;
        }
    }

    void findCarByMakeModel(string make, string model) {
        for (Car car : this->cars) {
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
    // Create an array of Car objects
    Car carArray[2] = {
        Car("Toyota", "Corolla", 2020, "Blue", 10),
        Car("Honda", "Civic", 2019, "Red", 12)
    };

    // Create a Garage object
    Garage garage(2);

    // Add and start cars using loop
    for (int i = 0; i < 2; i++) {
        garage.addCar(carArray[i]);
    }

    for (int i = 0; i < 2; i++) {
        carArray[i].start();
    }

    garage.listCars();

    // Find a specific car by make and model
    garage.findCarByMakeModel("Toyota", "Corolla");

    return 0;
}
