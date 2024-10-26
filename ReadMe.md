# Basic Car Management Simulation
## Introduction
The "Basic Car Management Simulation" project aims to create a simple yet effective simulation of a car management system. This project will help beginners understand and apply fundamental Object-Oriented Programming (OOP) principles by modeling basic car behaviors and interactions.

## Objectives
### Simulate basic operations of a car management system.
- Implement key OOP concepts such as classes, objects, inheritance, and methods.
- Provide a straightforward project that demonstrates the use of OOP in a practical scenario.

## Key Features
### Car Simulation
#### Classes
- Car: This is the base class for all car objects.
- ElectricCar: This class inherits from the Car class and includes an additional attribute for battery level.
- GasCar: This class inherits from the Car class and includes an additional attribute for fuel level.

#### Attributes
Attribute: A variable within a class that holds data specific to an object.
- Make: The manufacturer of the car.
- Model: The specific model of the car.
- Year: The year the car was manufactured.
- Color: The color of the car.
- Fuel Level: The current fuel level of the car (specific to GasCar).
- Battery Level: The current battery level of the car (specific to ElectricCar).

#### Behaviors
- Start: Method to start the car.
- Stop: Method to stop the car.
- Drive: Method to simulate driving the car, which will decrease the fuel or battery level.
- Refuel/Recharge: Method to increase the fuel or battery level.

### Garage Management
#### Classes
- Garage: This class manages a collection of cars.

#### Attributes
- Capacity: The maximum number of cars the garage can hold.
- List of Cars: A list that stores car objects.

#### Behaviors
- Add Car: Method to add a new car to the garage.
- Remove Car: Method to remove a car from the garage.
- List Cars: Method to display all cars currently in the garage.
- Find Car: Method to search for a car in the garage by make or model.

## Key OOP Concepts
### Classes and Objects
Meaning:- Class: A blueprint for creating objects, defining a set of attributes and methods.
          Object: An instance of a class, representing a specific entity with attributes and behaviors.
Usage: The core of the project revolves around creating classes (Car, ElectricCar, GasCar, Garage) and creating objects from these classes to simulate real-world entities.

### Inheritance
Usage: Inheritance allows ElectricCar and GasCar to inherit attributes and methods from the Car class, promoting code reuse and organization.

### Methods
Meaning:- Member Function: A function defined within a class that operates on objects of that class.
Usage: Methods are used to define behaviors for the car objects, such as starting, stopping, driving, and refueling/recharging.

### The "this" Pointer
Meaning:- The this pointer helps clarify that the member variables and functions being accessed belong to the current instance of the class, ensuring that there is no ambiguity in the code.
Usage: The this pointer is used to reference the current object within a method or constructor, enhancing code clarity and reducing ambiguity.

### Encapsulation
Usage: Encapsulation is achieved by keeping the attributes private and providing public getter and setter methods to access and modify them.

Polymorphism is an essential concept in Object-Oriented Programming (OOP). The term "polymorphism" means "many forms." It allows objects to be treated as instances of their parent class, even though they might be of a derived type. This capability provides flexibility and reusability by enabling one interface to be used for multiple implementations.

Types of Polymorphism:

Compile-time Polymorphism (Static Binding):
Achieved through function overloading and operator overloading.
The decision about which function to call is made at compile time.

Run-time Polymorphism (Dynamic Binding):
Achieved through function overriding.
The decision about which function to call is made at runtime based on the type of object.


What is a Static Variable?
A static variable in a class is shared among all objects of that class. Unlike regular member variables that are unique to each object, a static variable has a single copy that is shared by all instances of the class. Static variables are often used to store data or counters that need to be common across all instances of a class.

How Static Variables Are Used in This Project
Tracking Total Cars Created:

The Car class has a static variable totalCarsCreated that tracks the total number of cars instantiated. Every time a new Car object is created, this variable is incremented.
The static member function getTotalCarsCreated() is used to access the value of totalCarsCreated.
Tracking Total Garages Created:

The Garage class has a static variable totalGaragesCreated that tracks the total number of garages instantiated. Every time a new Garage object is created, this variable is incremented.
The static member function getTotalGaragesCreated() is used to access the value of totalGaragesCreated.
