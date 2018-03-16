#ifndef VALIDATE_H
#define VALIDATE_H

#include "../computorv.h"

class	Validate {
	public:
		static bool	isPolynomialValid(char *poly, polynomial *equation);
        static bool isTermValid(char *term, polynomial *equation, int *termValid);
        Validate(void);
};

#endif