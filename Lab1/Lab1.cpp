#include "Interfaces.h"
#include "Personel.h"
#include "Customer.h"

using namespace std;

int main() {
	Customer* cs1;
	OrdinaryCustomer cus1("Caracaci Danu");
    Assistant a1("Irina Plahotniuc", "Panasonic");
    Driver d1("Vitalik Afanasii", "Panasonic");
	
	cs1 = &cus1;
	
	a1.getCall(cus1, "5 HDTV");
    a1.Work();
    d1.Work();
    cs1 -> getOrder();

    return 0;
}
