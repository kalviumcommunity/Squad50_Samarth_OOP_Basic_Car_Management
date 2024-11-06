#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract class: Vehicle (Base class for Car)
class Vehicle
{
protected:
    string make;
    string model;
    int year;

public:
    // Member initializer list is used for initialization
    Vehicle(string mk = "Unknown", string mdl = "Unknown", int yr = 0)
        : make(mk), model(mdl), year(yr) {}

    // Pure virtual function (making Vehicle abstract)
    virtual void displayInfo() const = 0;

    virtual ~Vehicle()
    {
        cout << "Vehicle destructor called for: " << model << endl;
    }

    // Accessor methods
    string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }
};

// Car class (Derived from Vehicle)
class Car : public Vehicle
{
private:
    string color;
    int fuelLevel;

public:
    static int totalCarsCreated;

    Car() : Vehicle(), color("Unknown"), fuelLevel(0)
    {
        totalCarsCreated++;
        cout << "Default constructor called for Car" << endl;
    }

    Car(string mk, string mdl, int yr, string clr, int fuel)
        : Vehicle(mk, mdl, yr), color(clr), fuelLevel(fuel)
    {
        totalCarsCreated++;
        cout << "Parameterized constructor called for Car" << endl;
    }

    ~Car() override
    {
        cout << "Destructor called for Car: " << model << endl;
        totalCarsCreated--;
    }

    // Overriding the displayInfo method
    void displayInfo() const override
    {
        cout << "Car Make: " << make << ", Model: " << model
             << ", Year: " << year << ", Color: " << color
             << ", Fuel Level: " << fuelLevel << "%" << endl;
    }
};

int Car::totalCarsCreated = 0;

// ElectricCar class (Derived from Car)
class ElectricCar : public Car
{
private:
    int batteryLevel;

public:
    ElectricCar(string mk, string mdl, int yr, string clr, int fuel, int battery)
        : Car(mk, mdl, yr, clr, fuel), batteryLevel(battery)
    {
        cout << "ElectricCar constructor called." << endl;
    }

    void displayInfo() const override
    {
        Car::displayInfo();
        cout << "Battery Level: " << batteryLevel << "%" << endl;
    }
};

// Truck class (Derived from Vehicle)
class Truck : public Vehicle
{
private:
    int cargoCapacity;

public:
    Truck(string mk, string mdl, int yr, int capacity)
        : Vehicle(mk, mdl, yr), cargoCapacity(capacity)
    {
        cout << "Truck constructor called." << endl;
    }

    ~Truck() override
    {
        cout << "Destructor called for Truck: " << model << endl;
    }

    void displayInfo() const override
    {
        cout << "Truck Make: " << make << ", Model: " << model
             << ", Year: " << year << ", Cargo Capacity: " << cargoCapacity << " kg" << endl;
    }
};

// Garage class definition
class Garage
{
private:
    int capacity;
    vector<Vehicle *> vehicles;

public:
    static int totalGaragesCreated;

    Garage(int cap = 1) : capacity(cap)
    {
        totalGaragesCreated++;
        cout << "Garage constructor called." << endl;
    }

    ~Garage()
    {
        cout << "Destructor called for Garage." << endl;
        totalGaragesCreated--;

        // Free all dynamically allocated vehicles safely using an iterator
        for (auto it = vehicles.begin(); it != vehicles.end(); ++it)
        {
            delete *it; // Free the memory allocated for each vehicle
        }

        // Clear the vector (this ensures the vector is empty after deletion)
        vehicles.clear();
    }

    void addVehicle(Vehicle *vehicle)
    {
        if (vehicles.size() < capacity)
        {
            vehicles.push_back(vehicle);
            cout << "Vehicle added to the garage." << endl;
        }
        else
        {
            cout << "Garage is full." << endl;
        }
    }

    static int getTotalGaragesCreated() { return totalGaragesCreated; }
};

int Garage::totalGaragesCreated = 0;

// New Class for Displaying Vehicle Information
class VehicleInfoDisplay
{
public:
    static void displayVehicleInfo(const Vehicle &vehicle)
    {
        vehicle.displayInfo();
    }
};

int main()
{
    Garage garage(3);

    Car *car1 = new Car("Toyota", "Corolla", 2020, "Blue", 10);
    ElectricCar *car2 = new ElectricCar("Tesla", "Model 3", 2021, "White", 0, 85);
    Truck *truck1 = new Truck("Ford", "F-150", 2022, 1000); // New Truck object

    garage.addVehicle(car1);
    garage.addVehicle(car2);
    garage.addVehicle(truck1); // Add truck to garage

    VehicleInfoDisplay::displayVehicleInfo(*car1);
    VehicleInfoDisplay::displayVehicleInfo(*car2);
    VehicleInfoDisplay::displayVehicleInfo(*truck1); // Display truck info

    cout << "Total cars created: " << Car::totalCarsCreated << endl; // Use static variable directly
    cout << "Total garages created: " << Garage::getTotalGaragesCreated() << endl;

    // No need to delete vehicles manually, the garage destructor handles it

    return 0;
}
