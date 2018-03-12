#include "../computorv.h"

int polynomial::counter = 0;

bool    polynomial::addTerm(term *termVal) {
    //this->terms.insert(*termVal, 1);
    this->terms.insert(*termVal, counter);
    polynomial::counter++;
    if (termVal) {
        
    }
    return (true);
}

void        polynomial::toString(void) {

}

polynomial::polynomial(void) {
    polynomial::counter = 0;
}