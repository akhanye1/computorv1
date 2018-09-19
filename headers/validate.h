#ifndef VALIDATE_H
#define VALIDATE_H

#include "../computorv.h"

class	Validate {
    private:
        void            splitString(char *poly);
        vector<string>  tempStrings;

	public:
		bool	isPolynomialValid(char *poly, polynomial *equation);
        bool isTermValid(char *term, polynomial *equation, int *termValid);
        Validate(void);
};

#endif