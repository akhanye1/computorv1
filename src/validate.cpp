
#include "../computorv.h"

bool	isOperand(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void	skipToNext(char *equation) {
	while (*equation != ' ' && *equation && !isOperand(*equation)) {
			equation++;
	}
}

bool	Validate::isTermValid(char *termVal, polynomial *equation) {
	term *termClass = new term();

	termClass->setOperand(*termVal);
	termVal++;
	while (*termVal == ' ' && *termVal) {
		termVal++;
	}
	while (*termVal != ' ' && *termVal) {
		if (isdigit(*termVal)) {
			termClass->setContant(atof(termVal));
			skipToNext(termVal);			
		} else if (isalpha(*termVal)) {
			termClass->setVariable(*termVal);
			skipToNext(termVal);
		} else if (*termVal == '^') {
			if (termVal[1] == '-') {
				return (false);
			}
			termVal++;
			termClass->setExponent((char)*termVal);
			skipToNext(termVal);
			termClass->toString();			
		}
		termVal++;
	}
	equation->addTerm(termClass);
	return (true);
}

bool	Validate::isPolynomialValid(char *poly, polynomial *equation) {
	term *termValue = new term();
	if (isdigit(*poly)) {
		termValue->setContant(atof(poly));
		skipToNext(poly);
	} else if (isalpha((int)*poly)) {
		termValue->setVariable(*poly);
		skipToNext(poly);
	}
	else {
		return (false);
	}
	equation->addTerm(termValue);
	while (*poly) {
		if (isOperand(*poly)) {
			if (!Validate::isTermValid(poly, equation)) {
				return (false);
			}
		}
		poly++;
	}
	return (true);
}

Validate::Validate(void) {
}
