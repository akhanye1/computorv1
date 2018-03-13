
#include "../computorv.h"

bool	isOperand(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

char	*skipToNext(char *equation) {
	if (isOperand(*equation)) {
		equation++;
	}
	while (*equation != ' ' && *equation && !isOperand(*equation) &&
		*equation != '^') {
			equation++;
	}
	cout << "Skipped to char @ " << *equation << endl;
	return (equation);
}

bool	Validate::isTermValid(char *termVal, polynomial *equation) {
	term *termClass = new term();

	termClass->setOperand(*termVal);
	termVal++;
	if (!*termVal) {
		return (true);
	}
	while (*termVal == ' ' && *termVal) {
		termVal++;
	}
	while (*termVal != ' ' && *termVal && !isOperand(*termVal)) {
		if (isdigit(*termVal)) {
			termClass->setContant(atof(termVal));
			termVal = skipToNext(termVal);
		} else if (isalpha(*termVal)) {
			termClass->setVariable(*termVal);
			termVal = skipToNext(termVal);
		} else if (*termVal == '^') {
			if (termVal[1] == '-') {
				return (false);
			}
			termVal++;
			termClass->setExponent((char)*termVal);
			termVal = skipToNext(termVal);		
		}
		if (*termVal != '^') {
			termVal++;
		}
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
			poly = skipToNext(poly);
		}
		if (!isOperand(*poly)) {
			poly++;
		}
	}
	return (true);
}

Validate::Validate(void) {
}
