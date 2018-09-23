#include "../computorv.h"

int polynomial::counter = 0;

bool    polynomial::addTerm(term *termVal) {
    this->terms.push_back(*termVal);
    polynomial::counter++;
    return (true);
}

term        polynomial::getTerm(int index) {
    return (this->terms.at(index));
}

void        polynomial::changeSide(term tempTerm, int index) {
    char    tempOperand;

    cout << "Temp Term at side 1 >> " << tempTerm.getSide() << endl;
    if (tempTerm.getOperand() == '+' || tempTerm.getOperand() == '-') {
        tempOperand = (tempTerm.getOperand() == '+') ? '-' : '+';
    }
    else {
        tempOperand = (tempTerm.getOperand() == '*') ? '/' : '*';
    }
    tempTerm.setOperand(tempOperand);
    tempTerm.setSide(0);
    this->terms.at(index).replaceTerm(tempTerm);
    cout << "Temp Term at side 2 >> " << this->terms.at(index).getSide() << " Index " << index << endl;
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
            if ((this->terms.at(x).getConstant() == 1 && this->terms.at(x).isVar()) ||
                (this->terms.at(x).getConstant() == 0 && this->terms.at(x).isVar())) {

            }
            else {
                cout << this->terms.at(x).getConstant();
            }
        }
        if (this->terms.at(x).isVar() && this->terms.at(x).getConstant() != 0) {
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

void    polynomial::simplifyRight() {
    int     index = -1;

    while (++index < counter && this->terms.at(index).getSide() == 0);
    if (index == counter) {
        return;
    }
    bodmasRule(index);
}

float   power(float number, int exponent) {
    float sum;

    sum = number;
    while (--exponent > 0) {
        sum = sum * number;
    }
    return (sum);
}

void    polynomial::solveExponents(int start) {
    int     tempNumber;
    float   number;
    int     exponent;

    while (start < counter) {
        if (this->terms.at(start).getConstant() == 0 && this->terms.at(start).isVar()) {
            this->terms.erase(this->terms.begin() + start);
            counter--;
            return (solveExponents(start));
        }
        if (this->terms.at(start).isExp()) {
            if (this->terms.at(start).isVar() && this->terms.at(start).getExponent() == 0) {
                this->terms.at(start).removeVariable();
                tempNumber = this->terms.at(start).getConstant() * 1;
                this->terms.at(start).setConstant(tempNumber);
            }
            else if (!this->terms.at(start).isVar()) {
                number = this->terms.at(start).getConstant();
                exponent = this->terms.at(start).getExponent();
                tempNumber = power(number, exponent);
                this->terms.at(start).removeVariable();
                this->terms.at(start).setConstant(tempNumber);
            }
        }
        start++;
    }
}

// NB NB NB NBget the last instance of a variable
void    polynomial::solveByOrder(int start, char check) {
    if (start >= counter) {
        return ;
    }
    while (start < counter) {
        if (this->terms.at(start).getOperand() == check) {
            if (this->terms.at(start - 1).addTerm(this->terms.at(start))) {
                moveLeft(this->terms.at(start - 1), start - 1, start);
                return (solveByOrder(start, check));
            }
        }
        start++;
    }
}

void    polynomial::bodmasRule(int start) {
    solveExponents(start);
    solveByOrder(start + 1, '/');
    solveByOrder(start + 1, '*');
    solveByOrder(start + 1, '+');
    solveByOrder(start + 1, '-');
}

void    polynomial::showAll() {
    int index = -1;

    cout << "START START START" << endl;
    while (++index < counter) {
        this->getTerm(index).toString();
    }
    cout << "END END END" << endl;
}

void    polynomial::moveRight(int index) {
    char    operand;

    operand = this->terms.at(index).getOperand() == '+' ? '-' : '+';
    this->terms.at(index).setOperand(operand);
    this->terms.at(index).setSide(1);
    this->terms.at(index).toString();
}

void    polynomial::solveExpression() {
    if (this->terms.at(0).isVar()) {
        moveRight(1);
        this->terms.at(1).toString();
    }
    else {
        moveRight(0);
        this->terms.at(0).toString();
    }
}

void    polynomial::showExpression() {
    // int     index = -1;
    // bool    changeSide = false;

    cout << "Showing expression : " << endl;
    showAll();
    // while (++index < counter) {
    //     if (this->terms.at(index).getSide() == 1 && !changeSide) {
    //         cout << " = ";
    //         changeSide = true;
    //     }
    //     cout << this->terms.at(index).getOperand() << " ";
    //     cout << this->terms.at(index).getConstant();
    //     if (this->terms.at(index).isVar()) {
    //         cout << this->terms.at(index).getVariable();
    //     }
    //     if (this->terms.at(index).isExp()) {
    //         cout << "^" << this->terms.at(index).getExponent();
    //     }
    //     cout << " ";
    // }
    cout << endl;
}

