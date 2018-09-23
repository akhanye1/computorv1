#ifndef TERM_H
#define TERM_H

#include "../computorv.h"

using namespace std;

class term {
    private:
        float       constant;
        char        variable;
        int         exponent;
        bool        isConstant;
        bool        isVariable;
        bool        isExponent;
        char        order;
        char        operand;
        int         termSide;
        void        fillTerm(string str);

    public:
        term(int termSide);
        term(string str, char operand, int termSide);
        term(void);
        bool    setConstant(float constant);
        void    addConstant(term leftConstant, term rightConstant);
        bool    setVariable(char variable);
        bool    setExponent(int exponent);
        void    addExponent(int leftExponent, int rightExponent);
        void    addVariable(term rightVariable, term leftVariable);
        bool    setOperand(char operand);
        void    setSide(int side);
        void    replaceTerm(term tempTerm);
        bool    isVar();
        bool    isConst();
        bool    isExp();
        void    toString();
        int     getExponent();
        int     getSide();
        float   getConstant();
        char    getVariable();
        char    getOperand();
        bool    sameAs(term compareTerm);
        bool    addTerm(term addTerm);
        void    removeVariable();
        void    swapTerm(term rightTerm);
        void    matchTerm(term rhs);
};

#endif