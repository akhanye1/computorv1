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

void    term::replaceTerm(term tempTerm) {
    this->constant = tempTerm.getConstant();
    this->variable = tempTerm.getVariable();
    this->exponent = tempTerm.getExponent();
    this->operand = tempTerm.getOperand();
    this->termSide = tempTerm.getSide();
    this->isConstant = tempTerm.isConst();
    this->isVariable = tempTerm.isVar();
    this->isExponent = tempTerm.isExp();
}

bool    term::setContant(float constant) {    
    this->constant = constant;
    this->isConstant = true;
    return (true);
}

float   getRealValue(term tempTerm) {
    return (tempTerm.getOperand() == '-') ? (-1 * tempTerm.getConstant()) : tempTerm.getConstant();
}

void    term::addConstant(term rightConstant, term leftConstant) {
    if (rightConstant.getOperand() == '+' || rightConstant.getOperand() == '-') {
        this->constant = (-1 * getRealValue(rightConstant)) + getRealValue(leftConstant);
        this->operand = (this->constant > 0) ? '+' : '-';
        this->constant = (this->constant > 0) ? this->constant : (-1 * this->constant);
    }
}

void    term::addVariable(term rightVariable, term leftVariable) {
    if (!rightVariable.isConst()) {
        rightVariable.setContant(0);
    }
    if (!leftVariable.isConst()) {
        leftVariable.setContant(0);
    }
    this->addConstant(rightVariable, leftVariable);
    //rightVal = (rightVariable.isConst()) ? rightVariable.getConstant() : 0;
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

void    term::addExponent(int rightExponent, int leftExponent) {
    this->exponent = rightExponent - leftExponent;
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

float   term::getConstant() {
    return (this->constant);
}

char    term::getVariable() {
    return (this->variable);
}

char    term::getOperand() {
    return (this->operand);
}