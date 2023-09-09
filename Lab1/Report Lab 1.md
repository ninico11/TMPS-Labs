# Topic: *SOLID Principles*
## Author: *Spatari Stanislav*
------
## Objectives:
&ensp; &ensp; __1. Study and understand the SOLID Principles.__

&ensp; &ensp; __2. Choose a domain, define its main classes/models/entities and choose the appropriate instantiation mechanisms.__

&ensp; &ensp;__3. Create a sample project that respects SOLID Principles.__

## Theory:
&ensp; &ensp; SOLID is a set of five object-oriented design principles intended to make software designs more maintainable, flexible, and easy to understand. The acronym stands for Single Responsibility Principle, Open-Closed Principle, Liskov Substitution Principle, Interface Segregation Principle, and Dependency Inversion Principle. Each principle addresses a specific aspect of software design, such as the organization of responsibilities, the handling of dependencies, and the design of interfaces. By following these principles, software developers can create more modular, testable, and reusable code that is easier to modify and extend over time. These principles are widely accepted and adopted in the software development community and can be applied to any object-oriented programming language.
   
## Main tasks:
&ensp; &ensp; __1. Choose an OO programming language and a suitable IDE or Editor (No frameworks/libs/engines allowed).__

&ensp; &ensp; __2. Select a domain area for the sample project.__

&ensp; &ensp; __3. Define the main involved classes and think about what instantiation mechanisms are needed.__

&ensp; &ensp; __4. Respect SOLID Principles in your project.__

## Code examples of SOLID Principles:
* Single Responsibility Principle (SRP):
Class Driver and Class Assistant are responsible only for their own work. For example Assistant get calls and orders from customers, Driver transport order to the customer. 
```cpp
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
```
* Open/Closed Principle (OCP) and Liskov Substitution Principle (LSP):
Class Customer is open for extension because you can to add for example another type of customer, if you change something in Customer class you need to change his child classes. And LSP is presented in fact that Customer class can be easely substituted with OrdinaryCustomer class.
```cpp
class Customer {
public:
    virtual void makeOrder(string order) = 0;
    virtual void getOrder() = 0;
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
```
* Interface Segregation Principle (ISP):
OrdinaryCustomer, Driver, and Assistant are concrete classes that implement the interfaces. None of these classes are forced to implement methods they do not need. For example, OrdinaryCustomer only implements methods related to customers, and Driver and Assistant implement methods related to personnel and orders, respectively.
```cpp
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
```

* Dependency Inversion Principle (DIP):
OrdinaryCustomer class and Assistant class does not depend on each over their both depend on abstract class Order.

```cpp
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
```
