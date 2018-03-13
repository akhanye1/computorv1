#include "../computorv.h"

int polynomial::counter = 0;

bool    polynomial::addTerm(term *termVal) {
    this->terms.push_back(*termVal);
    polynomial::counter++;
    if (termVal) {
        
    }
    return (true);
}

void        polynomial::toString(void) {
    int x = 0;
    term oneTerm;

    for (x = 0; x < polynomial::counter; x++) {
        oneTerm = this->terms.at(x);
        oneTerm.toString();
    }
}

polynomial::polynomial(void) {
    polynomial::counter = 0;
}