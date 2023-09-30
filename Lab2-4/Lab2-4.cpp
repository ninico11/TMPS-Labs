#include "Interfaces.h"
#include "Builder.h"
#include "Customer.h"
#include "Observer.h"
#include "PayStrategy.h"
#include "Personel.h"
#include "Facade.h"

using namespace std;

int main() {
    Order orderSubject; // Create the order subject
    Assistant assistant("Irina Plahotniuc", "Panasonic", &orderSubject); // Pass the order subject to the Assistant

    Assistant* clonedAssistant = assistant.clone();

    Driver& driver = Driver::getInstance("Vitalik Afanasii", "Panasonic");

    OrdinaryCustomer customer1("Caracaci Danu");

    VIPCustomer vipCustomer(customer1);

    Team team;
    team.addPersonel(&assistant);
    team.addPersonel(&driver);

    OrderBuilder builder;
    builder.addItem("5 HDTV");

    PaymentStrategy* creditCardPayment = new CreditCardPayment();
    PaymentContext paymentContext(creditCardPayment, 1000);

    OrderCommand orderCmd(assistant, vipCustomer, builder, paymentContext);
    orderCmd.execute();

    team.Work();
    orderSubject.placeOrder(vipCustomer, builder.build());
    vipCustomer.getOrder();

    return 0;
}
