#include "../computorv.h"

term::term(void) {
    this->isConstant = false;
    this->isVariable = false;
    this->isExponent = false;
    //term::count = 0;
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

bool    term::setExponent(char exponent) {
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

void    term::toString() {
    if (this->isConst()) {
        cout << "Term has const with value " << this->constant << " ";
    }
    if (this->isVar()) {
        cout << "Term has variable with variable " << this->variable << " ";
    }
    if (this->isExp()) { 
        cout << "Term has exponent " << this->exponent;
    }
    cout << endl;
}