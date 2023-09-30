#pragma once
#include "Interfaces.h"

using namespace std;

class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
};

class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " $ using a credit card." << endl;
    }
};

class CashPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " $ in cash." << endl;
    }
};

class PaymentContext {
private:
    PaymentStrategy* strategy;
    int amount;

public:
    PaymentContext(PaymentStrategy* strategy, int amount) : strategy(strategy), amount(amount) {}

    void performPayment() {
        strategy->pay(amount);
    }
};
