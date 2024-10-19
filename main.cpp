#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Vehicle class (Base class for Car)
class Vehicle {
protected:
    string make;
    string model;
    int year;

public:
    Vehicle(string mk = "Unknown", string mdl = "Unknown", int yr = 0) 
        : make(mk), model(mdl), year(yr) {}

    virtual void displayInfo() const {
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year << endl;
    }
};

// Car class (Derived from Vehicle - Single Inheritance)
class Car : public Vehicle {
private:
    string color;
    int fuelLevel;

public:
    static int totalCarsCreated;

    // Constructors
    Car() : Vehicle(), color("Unknown"), fuelLevel(0) {
        totalCarsCreated++;
        cout << "Default constructor called for Car" << endl;
    }

    Car(string mk, string mdl, int yr, string clr, int fuel) 
        : Vehicle(mk, mdl, yr), color(clr), fuelLevel(fuel) {
        totalCarsCreated++;
        cout << "Parameterized constructor called for Car" << endl;
    }

    // Destructor
    ~Car() {
        cout << "Destructor called for Car: " << model << endl;
        totalCarsCreated--;
    }

    // Accessor methods
    string getColor() const { return color; }
    int getFuelLevel() const { return fuelLevel; }

    // Mutator methods
    void setColor(string clr) { color = clr; }
    void setFuelLevel(int fuel) { fuelLevel = fuel; }

    // Public methods
    void start() const {
        cout << "The car " << model << " is starting." << endl;
    }

    void drive() {
        if (fuelLevel > 0) {
            fuelLevel--;
            cout << "The car is driving. Fuel level: " << fuelLevel << endl;
        } else {
            cout << "Cannot drive, fuel level is too low." << endl;
        }
    }

    void refuel(int amount) {
        fuelLevel += amount;
        cout << "Refueled. Fuel level: " << fuelLevel << endl;
    }

    static int getTotalCarsCreated() { return totalCarsCreated; }
};

// Initialize static variable
int Car::totalCarsCreated = 0;

// ElectricCar class (Derived from Car - Multilevel Inheritance)
class ElectricCar : public Car {
private:
    int batteryLevel;

public:
    ElectricCar(string mk, string mdl, int yr, string clr, int fuel, int battery)
        : Car(mk, mdl, yr, clr, fuel), batteryLevel(battery) {
        cout << "ElectricCar constructor called." << endl;
    }

    // Accessor and Mutator for battery level
    int getBatteryLevel() const { return batteryLevel; }
    void setBatteryLevel(int battery) { batteryLevel = battery; }

    // Overriding displayInfo function to include battery info
    void displayInfo() const override {
        Car::displayInfo();
        cout << "Battery Level: " << batteryLevel << "%" << endl;
    }
};

// Garage class definition
class Garage {
private:
    int capacity;
    vector<Car> cars;

public:
    static int totalGaragesCreated;

    Garage(int cap = 1) : capacity(cap) {
        totalGaragesCreated++;
        cout << "Garage constructor called." << endl;
    }

    ~Garage() {
        cout << "Destructor called for Garage." << endl;
        totalGaragesCreated--;
    }

    void addCar(Car car) {
        if (cars.size() < capacity) {
            cars.push_back(car);
            cout << "Car added to the garage." << endl;
        } else {
            cout << "Garage is full." << endl;
        }
    }

    void listCars() const {
        cout << "Listing cars in the garage:" << endl;
        for (const auto& car : cars) {
            car.displayInfo();
        }
    }

    static int getTotalGaragesCreated() { return totalGaragesCreated; }
};

// Initialize static variable
int Garage::totalGaragesCreated = 0;

int main() {
    // Create a Garage
    Garage garage(2);

    // Create Car and ElectricCar objects
    Car car1("Toyota", "Corolla", 2020, "Blue", 10);
    ElectricCar car2("Tesla", "Model 3", 2021, "White", 0, 85);

    // Add cars to the garage
    garage.addCar(car1);
    garage.addCar(car2);

    // Start the cars
    car1.start();
    car2.start();

    // List cars in the garage
    garage.listCars();

    // Display total counts
    cout << "Total cars created: " << Car::getTotalCarsCreated() << endl;
    cout << "Total garages created: " << Garage::getTotalGaragesCreated() << endl;

    return 0;
}
