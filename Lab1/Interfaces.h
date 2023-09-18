#pragma once
#include <iostream>
#include <string>

using namespace std;

class Customer {
public:
	string name;
    virtual void makeOrder(string order) = 0;
    virtual void getOrder() = 0;
};

class Personel {
public:
	string name;
    string cname;
    virtual void Work() = 0;
};

class Order {
public:
    virtual void getCall(Customer& c1, string order) = 0;
};

