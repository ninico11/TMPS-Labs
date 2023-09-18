#pragma once
#include "Interfaces.h"

using namespace std;

class OrdinaryCustomer : public Customer {
    void setName(string iname) {
        name = iname;
    }

public:
    OrdinaryCustomer(string iname) {
        setName(iname);
    }

    void makeOrder(string order) override {
        cout << "Hello, my name is " << name << ", I want to order " << order << ".\n";
    }

    void getOrder() override {
        cout << "Sign...\n";
        cout << "Thank You!";
    }
};

