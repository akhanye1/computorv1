#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <vector>
#include "term.h"

using namespace std;

class polynomial {
    private:
        vector<term>    terms;
        void            solveByOrder(int start, char check);
        void            moveRight(int index);

    public:
        polynomial(void);
        bool            addTerm(term *Term);
        void            toString(void);
        term            getTerm(int index);
        void            moveLeft(term tempTerm, int changeIndex, int removeIndex);
        void            changeSide(term tempTerm, int index);
        static int      counter;
        void            showReduced();
        void            simplifyRight();
        void            showAll();
        void            bodmasRule(int start);
        void            solveExponents(int start);
        void            solveExpression();
        void            showExpression();
        void            addRemaining(int index);
};

#endif