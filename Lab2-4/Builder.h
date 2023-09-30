#pragma once
#include "Interfaces.h"
#include "PayStrategy.h"
using namespace std;

class OrderBuilder {
private:
    string order;

public:
    OrderBuilder() {
        order = "";
    }

    OrderBuilder& addItem(const string& item) {
        if (!order.empty()) {
            order += ", ";
        }
        order += item;
        return *this;
    }

    string build() {
        return order;
    }
};
