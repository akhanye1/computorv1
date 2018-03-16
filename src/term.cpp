#include "../computorv.h"

term::term(int termSide) {
    this->isConstant = false;
    this->isVariable = false;
    this->isExponent = false;
    this->termSide = termSide;
}

term::term(void) {
    this->isConstant = false;
    this->isVariable = false;
    this->isExponent = false;
    this->termSide = 0;
}

bool    term::setContant(float constant) {
    this->constant = constant;
    this->isConstant = true;
    return (true);
}

bool    term::setVariable(char variable) {
    this->variable = variable;
    this->isVariable = true;
    return (true);
}

bool    term::setExponent(int exponent) {
    this->exponent = exponent;
    this->isExponent = true;
    return (true);
}

void    term::setSide(int side) {
    this->termSide = side;
}

bool    term::setOperand(char operand) {
    this->operand = operand;
    return (true);
}

bool    term::isVar() {
    return (this->isVariable);
}

bool    term::isConst() {
    return (this->isConstant);
}

bool    term::isExp() {
    return (this->isExponent);
}

int     term::getExponent() {
    return (this->exponent);
}

int     term::getSide() {
    return (this->termSide);
}

void    term::toString() {
    cout << "Signage " << this->operand << " ";
    if (this->isConst()) {
        cout << "Term has const with value " << this->constant << " ";
    }
    if (this->isVar()) {
        cout << "Term has variable with variable " << this->variable << " ";
    }
    if (this->isExp()) { 
        cout << "Term has exponent " << this->exponent << " ";
    }
    if (this->termSide == 0) {
        cout << "Left hand side";
    } else {
        cout << "Right hand side";
    }
    cout << endl;
}