#include "Vehicle.hpp"

void    Vehicle::inputData() {
    cout << "Enter Company name" << endl;
    cin >> make;
    cout << "Enter Model" << endl;
    cin >> model;
    cout << "Enter Year" << endl;
    cin >> year;
    cout << "Enter VIN (Vehicle Identification Number)" << endl;
    cin >> VIN;
    cout << "Enter status" << endl;
    cin >> status;
}

void    Vehicle::displayData() {
    cout << "Company name" << make << endl;
    cout << "Model" << model << endl;
    cout << "Year" << year << endl;
}