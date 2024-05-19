#pragma once

#include "Vehicle.hpp"

class Customer {
    private:
        string name, contact, rentalHistory, currentRentals;

    public:
        Customer(const Customer& obj);
};