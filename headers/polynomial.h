#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <vector>
#include "term.h"

using namespace std;

class polynomial {
    private:
        vector<term>    terms;
        static int      counter;

    public:
        bool addTerm(term *Term);
};

#endif