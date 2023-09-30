#pragma once
#include <bits/stdc++.h>

using namespace std;

class Customer {
public:
    virtual string getName() = 0;
    virtual void makeOrder(string order) = 0;
    virtual void getOrder() = 0;
};

class Personel {
public:
	string name;
    string cname;
    virtual void Work() = 0;
};

class OrderObserver {
public:
    virtual void update(const string& message) = 0;
};

class Command {
public:
    virtual void execute() = 0;
};


