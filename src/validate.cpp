
#include "../computorv.h"

bool	isOperand(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

char	*skipToNext(char *equation) {
	if (isOperand(*equation)) {
		equation++;
	}
	while (*equation != ' ' && *equation && !isOperand(*equation) &&
		*equation != '^' && *equation != '=') {
			equation++;
	}
	return (equation);
}

bool	Validate::isTermValid(char *termVal, polynomial *equation, int *termSide) {
	term *termClass = new term(*termSide);
	if (isOperand(*termVal)) {
		termClass->setOperand(*termVal);
		termVal++;
	} else  {
		termClass->setOperand('+');
	}
	if (!*termVal) {
		return (true);
	}
	while (*termVal == ' ') {
		termVal++;
	}
	while (*termVal != ' ' && *termVal && !isOperand(*termVal) && *termVal != '=') {
		if (isdigit(*termVal)) {
			termClass->setContant(atof(termVal));
			termVal = skipToNext(termVal);
		} else if (isalpha(*termVal)) {
			termClass->setVariable(*termVal);
			termVal = skipToNext(termVal);
		}
		if (*termVal == '^' && termClass->isVar()) {
			if (termVal[1] == '-') {
				return (false);
			}
			termVal++;
			termClass->setExponent(atoi(termVal));
			termVal = skipToNext(termVal);	
		} else if (*termVal == '^' && !termClass->isVar()) {
			return (false);
		}
		if (!isOperand(*termVal) && *termVal != '=') {
			termVal++;
		}
		if (*termVal == '=') {
			(*termSide)++;
			if (*termSide > 1 || !*termVal) {
				return (false);
			}
			equation->addTerm(termClass);
			termVal++;
			return (Validate::isTermValid(termVal, equation, termSide));
		}
	}
	equation->addTerm(termClass);
	return (true);
}

bool	Validate::isPolynomialValid(char *poly, polynomial *equation) {
	int	termSide;
	termSide = 0;
	if (!Validate::isTermValid(poly, equation, &termSide)) {
		return (false);
	}
	poly = skipToNext(poly);
	while (*poly) {
		if (isOperand(*poly)) {
			if (!Validate::isTermValid(poly, equation, &termSide)) {
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
