#ifndef TERM_H
#define TERM_H

class term {
    private:
        float       constant;
        char        variable;
        char        exponent;
        bool        isConstant;
        bool        isVariable;
        bool        isExponent;
        char        order;
        char        operand;
        //static int  count;
        char        termSide;

    public:
        bool    setContant(float constant);
        bool    setVariable(char variable);
        bool    setExponent(char exponent);
        bool    setOperand(char operand);
        void    setSide(int side);
        bool    isVar();
        bool    isConst();
        bool    isExp();
        void    toString();
        term(void);
};

#endif