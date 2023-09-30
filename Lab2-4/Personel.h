#pragma once
#include "Interfaces.h"
#include "PayStrategy.h"
#include "Observer.h"
#include "Builder.h"

using namespace std;

class Driver : public Personel {
private:

    Driver(string iname, string icname) {
        setName(iname);
        setCName(icname);
    }

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
	
    static Driver& getInstance(string iname, string icname) {
        static Driver instance(iname, icname);
        return instance;
    }

    void Work() override {
        takeOrder();
        deliverOrder();
    }
};

class Assistant : public Personel, public OrderObserver {
private:
    OrderSubject* orderSubject; // Reference to the order subject
    string name;
    string cname;
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
    Assistant(string iname, string icname, OrderSubject* orderSubject)
            : name(iname), cname(icname), orderSubject(orderSubject) {
        orderSubject->addObserver(this); // Register this assistant as an observer
    }

    void Work() override {
        makeDocument();
        sendDriver();
    }

    Assistant* clone() {
        return new Assistant(*this);
    }

    void update(const string& message) override {
        cout << "Assistant " << name << " received notification: " << message << " order is plased." << endl;
    }

    void getCall(Customer& c1, const string& order) {
        cout << "Hello my name is, " << name << ", from " << cname << ", how can I help you?\n";
        c1.makeOrder(order);
    }

    void makeOrder(const string& customerName, OrderBuilder& builder, PaymentContext& paymentContext) {
        string order = builder.build();
        cout << name << " received an order for " << order << " from " << customerName << ".\n";
        paymentContext.performPayment();
    }
};

class Team : public Personel {
private:
    vector<Personel*> teamMembers;

public:
    void addPersonel(Personel* person) {
        teamMembers.push_back(person);
    }

    void Work() override {
        for (Personel* person : teamMembers) {
            person->Work();
        }
    }
};
