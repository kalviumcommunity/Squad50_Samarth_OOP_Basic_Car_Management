#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Car class definition
class Car
{
private:
    string make;
    string model;
    int year;
    string color;
    int fuelLevel;

public:
    // Static variable to track the total number of cars created
    static int totalCarsCreated;

    // Constructor
    Car(string mk, string mdl, int yr, string clr, int fuel)
        : make(mk), model(mdl), year(yr), color(clr), fuelLevel(fuel)
    {
        totalCarsCreated++; // Increment the static variable when a new car is created
    }

    // Mutator (setter) methods
    void setMake(string mk){
        make = mk;
    }
    void setModel(string mdl){
        model = mdl;
    }
    void setYear(int yr){
        year = yr;
    }
    void setColor(string clr){
        color = clr;
    }
    void setFuelLevel(int fuel){
        fuelLevel = fuel;
    }

    // Accessor (getter) methods
    string getMake() const
    {
        return make;
    }
    string getModel() const
    {
        return model;
    }
    int getYear() const
    {
        return year;
    }
    string getColor() const
    {
        return color;
    }
    int getFuelLevel() const
    {
        return fuelLevel;
    }

    // Member functions
    void start()
    {
        cout << "The car " << model << " is starting." << endl;
    }

    void drive()
    {
        if (fuelLevel > 0)
        {
            fuelLevel--;
            cout << "The car is driving. Fuel level is now: " << fuelLevel << endl;
        }
        else
        {
            cout << "Cannot drive, fuel level is too low." << endl;
        }
    }

    void refuel(int amount)
    {
        fuelLevel += amount;
        cout << "The car is refueled. Fuel level is now: " << fuelLevel << endl;
    }

    // Static function to get the total number of cars created
    static int getTotalCarsCreated()
    {
        return totalCarsCreated;
    }
};

// Initialize the static variable
int Car::totalCarsCreated = 0;

// Garage class definition
class Garage
{
private:
    int capacity;
    vector<Car> cars;

public:
    // Static variable to track the total number of garages created
    static int totalGaragesCreated;

    // Constructor
    Garage(int cap) : capacity(cap)
    {
        totalGaragesCreated++; // Increment the static variable when a new garage is created
    }

    // Accessor (getter) methods
    int getCapacity() const { return capacity; }
    vector<Car> getCars() const { return cars; }

    // Mutator (setter) methods
    void setCapacity(int cap) { capacity = cap; }

    // Member functions
    void addCar(Car car)
    {
        if (cars.size() < capacity)
        {
            cars.push_back(car);
            cout << "Car added to the garage." << endl;
        }
        else
        {
            cout << "Garage is full, cannot add more cars." << endl;
        }
    }

    void listCars()
    {
        cout << "Listing cars in the garage:" << endl;
        for (Car car : cars)
        {
            cout << "Car Make: " << car.getMake() << ", Model: " << car.getModel() << endl;
        }
    }

    void findCarByMakeModel(string make, string model)
    {
        for (Car car : cars)
        {
            if (car.getMake() == make && car.getModel() == model)
            {
                cout << "Car found: Make: " << make << ", Model: " << model << endl;
                return;
            }
        }
        cout << "Car not found." << endl;
    }

    // Static function to get the total number of garages created
    static int getTotalGaragesCreated()
    {
        return totalGaragesCreated;
    }
};

// Initialize the static variable
int Garage::totalGaragesCreated = 0;

// Main function
int main()
{
    // Dynamically create a Garage object
    Garage *garage = new Garage(2);

    // Dynamically create Car objects
    Car *car1 = new Car("Toyota", "Corolla", 2020, "Blue", 10);
    Car *car2 = new Car("Honda", "Civic", 2019, "Red", 12);

    // Add cars to the garage
    garage->addCar(*car1);
    garage->addCar(*car2);

    // Start the cars
    car1->start();
    car2->start();

    // List cars in the garage
    garage->listCars();

    // Find a specific car by make and model
    garage->findCarByMakeModel("Toyota", "Corolla");

    // Display the total number of cars and garages created
    cout << "Total cars created: " << Car::getTotalCarsCreated() << endl;
    cout << "Total garages created: " << Garage::getTotalGaragesCreated() << endl;

    // Clean up dynamically allocated memory
    delete car1;
    delete car2;
    delete garage;

    return 0;
}
