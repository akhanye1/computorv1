#include "../computorv.h"

int polynomial::counter = 0;

bool    polynomial::addTerm(term *termVal) {
    this->terms.push_back(*termVal);
    polynomial::counter++;
    if (termVal) {
        
    }
    return (true);
}

term        polynomial::getTerm(int index) {
    return (this->terms.at(index));
}

void        polynomial::moveLeft(term tempTerm, int changeIndex, int removeIndex) {
    this->terms.at(changeIndex).replaceTerm(tempTerm);
    this->terms.erase(this->terms.begin() +  removeIndex);
    polynomial::counter--;
}

void        polynomial::toString(void) {
    term oneTerm;

    for (int x = 0; x < polynomial::counter; x++) {
        oneTerm = this->terms.at(x);
        oneTerm.toString();
    }
}

void        polynomial::showReduced(void) {
    cout << "Reduced from : ";
    for (int x = 0; x < polynomial::counter; x++) {
        if (x > 0 || (x == 0 && this->terms.at(x).getOperand() == '-')) {
            cout << this->terms.at(x).getOperand() << " ";
        }
        if (this->terms.at(x).isConst()) {
            cout << this->terms.at(x).getConstant();
        } else {
            cout << this->terms.at(x).getVariable();
        }
        if (this->terms.at(x).isExp()) {
            cout << "^" << this->terms.at(x).getExponent();
        }
        cout << " ";
    }
    cout << "= 0" << endl;
}

polynomial::polynomial(void) {
    polynomial::counter = 0;
}