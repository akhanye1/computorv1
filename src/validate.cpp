
#include "../computorv.h"

bool	isOperand(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

char	*skipToNext(char *equation) {
	if (isOperand(*equation)) {
		equation++;
	}
	while (*equation != ' ' && *equation && !isOperand(*equation) &&
		*equation != '^' && *equation != '=' && !isdigit(*equation)) {
			equation++;
	}
	return (equation);
}

char	*skipSpace(char *equation) {
	while (*equation == ' ' && *equation) {
			equation++;
	}
	return (equation);
}

// bool	Validate::isTermValid(char *termVal, polynomial *equation, int *termSide) {
// 	term *termClass = new term(*termSide);
// 	if (isOperand(*termVal)) {
// 		termClass->setOperand(*termVal);
// 		termVal++;
// 	} else  {
// 		termClass->setOperand('+');
// 	}
// 	if (!*termVal) {
// 		return (true);
// 	}
// 	while (*termVal == ' ') {
// 		termVal++;
// 	}
// 	while (*termVal != ' ' && *termVal && !isOperand(*termVal) && *termVal != '=') {
// 		if (isdigit(*termVal)) {
// 			termClass->setContant(atof(termVal));
// 			termVal = skipToNext(termVal);

// 		} else if (isalpha(*termVal)) {
// 			termClass->setVariable(*termVal);
// 			termVal = skipToNext(termVal);
// 		}
// 		if (*termVal == '^' && termClass->isVar()) {
// 			if (termVal[1] == '-') {
// 				return (false);
// 			}
// 			termVal++;
// 			termClass->setExponent(atoi(termVal));
// 			termVal = skipToNext(termVal);	
// 		}
// 		if (!isOperand(*termVal) && *termVal != '=') {
// 			termVal++;
// 		}
// 		if (*termVal == '=') {
// 			(*termSide)++;
// 			if (*termSide > 1 || !*termVal) {
// 				return (false);
// 			}
// 		}
// 	}
// 	equation->addTerm(termClass);
// 	return (true);
// }

void	Validate::splitString(char *polyTemp) {
	string temp;
	size_t pos;
	int		cnt;
	string	poly(polyTemp);

	cnt = 0;
	while ((pos = poly.find(" ")) != string::npos) {
		temp = poly.substr(0, pos);
		poly = poly.substr(pos + 1);
		tempStrings.push_back(temp);
	}
}

bool	Validate::isPolynomialValid(char *poly, polynomial *equation) {
	splitString(poly);
	if (equation) {
		cout << "Equation valid" << endl;
	}
	// string[] all_terms = string::split(poly, " ");
	// cout << "Length of split :: " << all_terms.Length() << endl;
	// int	termSide;
	// termSide = 0;
	// if (!Validate::isTermValid(poly, equation, &termSide)) {
	// 	return (false);
	// }
	// poly = skipToNext(poly);
	// while (*poly) {
	// 	if (isOperand(*poly) || *poly == '=') {
	// 		if (*poly == '=') {
	// 			poly++;
	// 			if (*poly == ' ') {
	// 				poly = skipSpace(poly);
	// 				if (!isdigit(*poly) && *poly != '-') {
	// 					return (false);
	// 				}
	// 			}
	// 		}
	// 		if (!Validate::isTermValid(poly, equation, &termSide)) {
	// 			return (false);
	// 		}
	// 		poly = skipToNext(poly);
	// 	}
	// 	if (!isOperand(*poly) || *poly != '=') {
	// 		poly++;
	// 	}
	// }
	return (true);
}

Validate::Validate(void) {
}
