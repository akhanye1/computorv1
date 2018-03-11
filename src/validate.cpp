
#include "../computorv.h"

bool	isOperand(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void	skipToNext(char *equation) {
	while (*equation != ' ' && *equation && !isOperand(*equation)) {
			//cout << *equation << " ";
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
			termClass->toString();
		} else if (isalpha(*termVal)) {
			termClass->setVariable(*termVal);
			skipToNext(termVal);
			termClass->toString();
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

	cout << "Attempting to validate polynomial" << endl;
	if (isdigit(*poly)) {
		termValue->setContant(atof(poly));
		skipToNext(poly);
		termValue->toString();
	} else if (isalpha((int)*poly)) {
		termValue->setVariable(*poly);
		skipToNext(poly);
		termValue->toString();
	}
	else {
		return (false);
	}
	termValue->toString();
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
