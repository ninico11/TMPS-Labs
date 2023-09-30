#pragma once
#include "Interfaces.h"

using namespace std;

class OrderSubject {
private:
    vector<OrderObserver*> observers;

public:
    void addObserver(OrderObserver* observer) {
        observers.push_back(observer);
    }

    void notifyObservers(const string& message) {
        for (OrderObserver* observer : observers) {
            observer->update(message);
        }
    }
};

class Order : public OrderSubject {
public:
    void placeOrder(Customer& c1, const string& order) {
        cout << "Order placed: " << order << endl;
        notifyObservers(order);
    }
};
