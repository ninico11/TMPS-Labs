#pragma once
#include "Interfaces.h"

using namespace std;

class Driver : public Personel {
    void setName(string iname) {
        name = iname;
    }

    void setCName(string icname) {
        cname = icname;
    }

    void takeOrder() {
        cout << "My name is, " << name << ", write the order on me.\n";
    }

    void deliverOrder() {
        cout << "Hello, dear customer, I am " << name << ", I am from " << cname << ", your order is delivered, you need to sign all documents.\n";
    }

public:
    Driver(string iname, string icname) {
        setName(iname);
        setCName(icname);
    }

    void Work() override {
        takeOrder();
        deliverOrder();
    }
};

class Assistant : public Personel, public Order {
private:

    void setName(string iname) {
        name = iname;
    }

    void setCName(string icname) {
        cname = icname;
    }

    void makeDocument() {
        cout << name << " registered the order, prepared and signed all the necessary documents.\n";
    }

    void sendDriver() {
        cout << name << " sent the address and order to a free driver.\n";
    }

public:

    Assistant(string iname, string icname) {
        setName(iname);
        setCName(icname);
    }

    void Work() override {
        makeDocument();
        sendDriver();
    }

    void getCall(Customer& c1, string order) override {
    cout << "Hello my name is, " << name << ", from " << cname << ", how can I help you?\n";
    c1.makeOrder(order);
}
};
