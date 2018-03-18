#ifndef TERM_H
#define TERM_H

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
        //static int  count;
        char        termSide;

    public:
        bool    setContant(float constant);
        void    addConstant(term leftConstant, term rightConstant);
        bool    setVariable(char variable);
        bool    setExponent(int exponent);
        void    addExponent(int leftExponent, int rightExponent);
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
        term(int termSide);
        term(void);
};

#endif