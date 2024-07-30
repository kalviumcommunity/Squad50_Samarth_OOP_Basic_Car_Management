#include <bits/stdc++.h>
using namespace std;


class Car {
public:
    // Constructor
    Car(string make, string model, int year, string color)
        : make(make), model(model), year(year), color(color), is_running(false) {}

    // Member function to start the car
    void start() {
        this->is_running = true;
    }

    // Member function to stop the car
    void stop() {
        this->is_running = false;
    }

    // Member function to drive the car
    void drive() const {
        if (this->is_running) {
            cout << this->make << " " << this->model << " is driving." << endl;
        } else {
            cout << "Start the " << this->make << " " << this->model << " first." << endl;
        }
    }

    // Getters
    string getMake() const { return this->make; }
    string getModel() const { return this->model; }
    int getYear() const { return this->year; }
    string getColor() const { return this->color; }

private:
    string make;
    string model;
    int year;
    string color;
    bool is_running;
};
