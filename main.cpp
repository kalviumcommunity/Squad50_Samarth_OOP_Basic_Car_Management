#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract class: Vehicle (Base class for all vehicles)
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

    // Virtual destructor to allow proper cleanup for derived classes
    virtual ~Vehicle() {}

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
    }

    Car(string mk, string mdl, int yr, string clr, int fuel)
        : Vehicle(mk, mdl, yr), color(clr), fuelLevel(fuel)
    {
        totalCarsCreated++;
    }

    ~Car() override
    {
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
    }

    ~Truck() override {}

    void displayInfo() const override
    {
        cout << "Truck Make: " << make << ", Model: " << model
             << ", Year: " << year << ", Cargo Capacity: " << cargoCapacity << " kg" << endl;
    }
};

// Abstract Garage Interface (for Dependency Inversion)
class IGarage
{
public:
    virtual void addVehicle(Vehicle *vehicle) = 0;
    virtual void displayAllVehicles() const = 0;
    virtual ~IGarage() {}
};

// Concrete Garage class (Derived from IGarage)
class Garage : public IGarage
{
private:
    int capacity;
    vector<Vehicle *> vehicles;

public:
    static int totalGaragesCreated;

    Garage(int cap = 1) : capacity(cap)
    {
        totalGaragesCreated++;
    }

    ~Garage()
    {
        totalGaragesCreated--;

        // Free all dynamically allocated vehicles safely using a traditional for loop
        for (int i = 0; i < vehicles.size(); ++i)
        {
            delete vehicles[i]; // Free the memory allocated for each vehicle
        }

        // Clear the vector (this ensures the vector is empty after deletion)
        vehicles.clear();
    }

    void addVehicle(Vehicle *vehicle) override
    {
        if (vehicles.size() < capacity)
        {
            vehicles.push_back(vehicle);
        }
        else
        {
            cout << "Garage is full." << endl;
        }
    }

    void displayAllVehicles() const override
    {
        // Traditional for loop for displaying all vehicles
        for (int i = 0; i < vehicles.size(); ++i)
        {
            vehicles[i]->displayInfo();
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
    // Create a garage with capacity for 3 vehicles
    Garage garage(3);

    // Create vehicle objects (can be any derived class of Vehicle)
    Car *car1 = new Car("Toyota", "Corolla", 2020, "Blue", 10);
    ElectricCar *car2 = new ElectricCar("Tesla", "Model 3", 2021, "White", 0, 85);
    Truck *truck1 = new Truck("Ford", "F-150", 2022, 1000);

    // Add vehicles to the garage
    garage.addVehicle(car1);
    garage.addVehicle(car2);
    garage.addVehicle(truck1);

    // Display information about all vehicles in the garage
    garage.displayAllVehicles();

    // Show the total number of cars and garages created
    // cout << "Total cars created: " << Car::totalCarsCreated << endl;
    cout << "Total garages created: " << Garage::getTotalGaragesCreated() << endl;

    // No need to delete vehicles manually, the garage destructor handles it

    return 0;
}
