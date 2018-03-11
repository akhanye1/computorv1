
#include "../computorv.h"


bool	isOperand(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

bool	Validate::isTermValid(char *termVal, polynomial *equation) {
	term *termClass = new term();

	termClass->setOperand(*termVal);
	termVal++;
	while (*termVal == ' ') {
		termVal++;
	}
	while (*termVal != ' ' || *termVal) {
		if (isdigit(*termVal)) {
			termClass->setContant(atof(termVal));			
		} else if (isalpha(*termVal)) {
			termClass->setVariable(*termVal);
		} else if (*termVal == '^') {
			if (termVal[1] == '-') {
				return (false);
			}
			termVal++;
			termClass->setExponent((char)*termVal);
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
		cout << "Iterating throught the equation ";
		while (*poly != ' ' && *poly && !isOperand(*poly)) {
			cout << *poly << " ";
			poly++;
		}
		cout << endl;
		cout << "Char @ " << *poly << endl;
	} else if (isalpha((int)*poly)) {
		termValue->setVariable(*poly);
	}
	else {
		return (false);
	}
	termValue->toString();
	equation->addTerm(termValue);
	cout << "Check debug : " << poly << endl;
	while (*poly) {
		cout << " " << *poly << " " << endl;
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
