#pragma once
#include "Interfaces.h"
#include "Builder.h"
#include "PayStrategy.h"
#include "Personel.h"
using namespace std;

class OrderCommand : public Command {
private:
    Assistant& assistant;
    Customer& customer;
    OrderBuilder& builder;
    PaymentContext& paymentContext;

public:
    OrderCommand(Assistant& assistant, Customer& customer, OrderBuilder& builder, PaymentContext& paymentContext)
            : assistant(assistant), customer(customer), builder(builder), paymentContext(paymentContext) {}

    void execute() override {
        assistant.getCall(customer, builder.build());
        assistant.makeOrder(customer.getName(), builder, paymentContext);
    }
};