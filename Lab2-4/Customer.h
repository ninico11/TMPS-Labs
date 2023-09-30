#pragma once
#include "Interfaces.h"

using namespace std;

class OrdinaryCustomer : public Customer {
private:
	string name;
	
    void setName(string iname) {
        name = iname;
    }

public:
    explicit OrdinaryCustomer(string iname) {
        setName(iname);
    }

    void makeOrder(string order) override {
        cout << "Hello, my name is " << name << ", I want to order " << order << ".\n";
    }

    void getOrder() override {
        cout << "Sign...\n";
        cout << "Thank You!";
    }
    
    string getName() override{
        return name;
    }
};

class VIPCustomer : public Customer {
private:
    Customer& decoratedCustomer;

public:
    explicit VIPCustomer(Customer& customer) : decoratedCustomer(customer) {}

    string getName() override {
        return decoratedCustomer.getName();
    }

    void makeOrder(string order) override {
        decoratedCustomer.makeOrder(order);
        cout << "This is a VIP order!\n";
    }

    void getOrder() override {
        decoratedCustomer.getOrder();
        cout << "Thank You for being a VIP customer!\n";
    }
};

