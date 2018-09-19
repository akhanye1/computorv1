#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <vector>
#include "term.h"

using namespace std;

class polynomial {
    private:
        vector<term>    terms;

    public:
        bool            addTerm(term *Term);
        void            toString(void);
        term            getTerm(int index);
        void            moveLeft(term tempTerm, int changeIndex, int removeIndex);
        void            changeSide(term tempTerm, int index);
        static int      counter;
        void            showReduced();
        polynomial(void);
};

#endif