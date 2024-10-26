#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract class: Vehicle (Base class for Car)
class Vehicle {
protected:
    string make;
    string model;
    int year;

public:
    // Constructor
    Vehicle(string mk = "Unknown", string mdl = "Unknown", int yr = 0)
        : make(mk), model(mdl), year(yr) {}

    // Pure virtual function to make this class abstract
    virtual void displayInfo() const = 0;

    // Virtual destructor to ensure proper cleanup
    virtual ~Vehicle() {
        cout << "Vehicle destructor called for: " << model << endl;
    }
};

// Car class (Derived from Vehicle - Single Inheritance)
class Car : public Vehicle {
private:
    string color;
    int fuelLevel;

public:
    static int totalCarsCreated;

    // Constructor Overloading (Compile-time Polymorphism)
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
    ~Car() override {
        cout << "Destructor called for Car: " << model << endl;
        totalCarsCreated--;
    }

    // Accessor methods (Encapsulation)
    string getColor() const { return color; }
    int getFuelLevel() const { return fuelLevel; }

    // Mutator methods (Encapsulation)
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

    // Override the pure virtual function from Vehicle (Run-time Polymorphism)
    void displayInfo() const override {
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year
             << ", Color: " << color << ", Fuel Level: " << fuelLevel << endl;
    }

    // Static function to get the total number of cars created
    static int getTotalCarsCreated() { return totalCarsCreated; }
};

// Initialize static variable
int Car::totalCarsCreated = 0;

// ElectricCar class (Derived from Car - Multilevel Inheritance)
class ElectricCar : public Car {
private:
    int batteryLevel;

public:
    // Constructor
    ElectricCar(string mk, string mdl, int yr, string clr, int fuel, int battery)
        : Car(mk, mdl, yr, clr, fuel), batteryLevel(battery) {
        cout << "ElectricCar constructor called." << endl;
    }

    // Accessor and Mutator methods for battery level
    int getBatteryLevel() const { return batteryLevel; }
    void setBatteryLevel(int battery) { batteryLevel = battery; }

    // Overriding displayInfo function (Run-time Polymorphism)
    void displayInfo() const override {
        Car::displayInfo();  // Call base class version
        cout << "Battery Level: " << batteryLevel << "%" << endl;
    }
};

// Garage class definition
class Garage {
private:
    int capacity;
    vector<Vehicle*> vehicles;  // Store pointers to Vehicle objects

public:
    static int totalGaragesCreated;

    // Constructor
    Garage(int cap = 1) : capacity(cap) {
        totalGaragesCreated++;
        cout << "Garage constructor called." << endl;
    }

    // Destructor
    ~Garage() {
        cout << "Destructor called for Garage." << endl;
        totalGaragesCreated--;
    }

    // Add vehicle to the garage
    void addVehicle(Vehicle* vehicle) {
        if (vehicles.size() < capacity) {
            vehicles.push_back(vehicle);
            cout << "Vehicle added to the garage." << endl;
        } else {
            cout << "Garage is full." << endl;
        }
    }

    // List all vehicles in the garage
    void listVehicles() const {
        cout << "Listing vehicles in the garage:" << endl;
        for (const auto& vehicle : vehicles) {
            vehicle->displayInfo();  // Runtime polymorphism in action
        }
    }

    // Static function to get the total number of garages created
    static int getTotalGaragesCreated() { return totalGaragesCreated; }
};

// Initialize static variable
int Garage::totalGaragesCreated = 0;

int main() {
    // Create a Garage
    Garage garage(2);

    // Create Car and ElectricCar objects
    Car* car1 = new Car("Toyota", "Corolla", 2020, "Blue", 10);
    ElectricCar* car2 = new ElectricCar("Tesla", "Model 3", 2021, "White", 0, 85);

    // Add vehicles to the garage
    garage.addVehicle(car1);
    garage.addVehicle(car2);

    // Start the vehicles
    car1->start();
    car2->start();

    // List vehicles in the garage
    garage.listVehicles();

    // Display total counts
    cout << "Total cars created: " << Car::getTotalCarsCreated() << endl;
    cout << "Total garages created: " << Garage::getTotalGaragesCreated() << endl;

    // Clean up dynamically allocated memory
    delete car1;
    delete car2;

    return 0;
}
