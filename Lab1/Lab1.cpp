#include <iostream>
#include <string>

using namespace std;

class Customer {
public:
    virtual void makeOrder(string order) = 0;
    virtual void getOrder() = 0;
};

class Personel {
public:
    virtual void Work() = 0;
};

class Order {
public:
    virtual void getCall(Customer& c1, string order) = 0;
};

class OrdinaryCustomer : public Customer {
private:
    string Name;

    void setName(string IName) {
        Name = IName;
    }

public:
    OrdinaryCustomer(string IName) {
        setName(IName);
    }

    void makeOrder(string order) override {
        cout << "Hello, my name is " << Name << ", I want to order " << order << ".\n";
    }

    void getOrder() override {
        cout << "Sign...\n";
        cout << "Thank You!";
    }
};


class Driver : public Personel {
    string Name;
    string CName;

    void setName(string IName) {
        Name = IName;
    }

    void setCName(string ICName) {
        CName = ICName;
    }

    void takeOrder() {
        cout << "My name is, " << Name << ", write the order on me.\n";
    }

    void deliverOrder() {
        cout << "Hello, dear customer, I am " << Name << ", I am from " << CName << ", your order is delivered, you need to sign all documents.\n";
    }

public:
    Driver(string IName, string ICName) {
        setName(IName);
        setCName(ICName);
    }

    void Work() override {
        takeOrder();
        deliverOrder();
    }
};

class Assistant : public Personel, public Order {
private:
    string Name;
    string CName;

    void setName(string IName) {
        Name = IName;
    }

    void setCName(string ICName) {
        CName = ICName;
    }

    void makeDocument() {
        cout << Name << " registered the order, prepared and signed all the necessary documents.\n";
    }

    void sendDriver() {
        cout << Name << " sent the address and order to a free driver.\n";
    }

public:

    Assistant(string IName, string ICName) {
        setName(IName);
        setCName(ICName);
    }

    void Work() override {
        makeDocument();
        sendDriver();
    }

    void getCall(Customer& c1, string order) override {
    cout << "Hello my name is, " << Name << ", from " << CName << ", how can I help you?\n";
    c1.makeOrder(order);
}
};





int main() {
    Assistant a1("Irina Plahotniuc", "Panasonic");
    Driver d1("Vitalik Afanasii", "Panasonic");
    OrdinaryCustomer cus1("Caracaci Danu");

    a1.getCall(cus1, "5 HDTV");
    a1.Work();
    d1.Work();
    cus1.getOrder();

    return 0;
}
