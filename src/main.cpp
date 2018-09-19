
#include "../computorv.h"

bool	setValue(polynomial *equation, term oneTerm, int index) {
	int		i;
	term	tempTerm;

	i = -1;
	while (++i < equation->counter) {
		tempTerm = equation->getTerm(i);
		if (tempTerm.getSide() > 0) {
			equation->changeSide(oneTerm, index);
			break;
		}
		if (oneTerm.isConst() && tempTerm.isConst() &&
		!oneTerm.isVar() && !tempTerm.isVar() &&
		(oneTerm.getOperand() == '+' || oneTerm.getOperand() == '-') &&
		(tempTerm.getOperand() == '+' || tempTerm.getOperand() == '-')) {
			cout << "Term found " << oneTerm.getConstant() << endl;
			tempTerm.addConstant(oneTerm, tempTerm);
			equation->moveLeft(tempTerm, i, index);
			break ;
		} /*else if (oneTerm.isVar() && tempTerm.isVar()) {
			if ((oneTerm.getVariable() == tempTerm.getVariable()) &&
			(oneTerm.getExponent() == tempTerm.getExponent()) &&
			(oneTerm.getOperand() == '+' || oneTerm.getOperand() == '-') &&
			(tempTerm.getOperand() == '+' || tempTerm.getOperand() == '-')) {
				tempTerm.addVariable(oneTerm, tempTerm);
				equation->moveLeft(tempTerm, i, index);
				//equation->move:
				break ;
			}
		}*/
	}
	return (true);
}

bool	reducedOk(polynomial *equation) {
	int		index;
	term	oneTerm;
	int		maxRight;

	index = -1;
	while (++index < equation->counter) {
		oneTerm = equation->getTerm(index);
		if (oneTerm.getSide() > 0) {
			setValue(equation, oneTerm, index);
			index = -1;
		}
	}
	maxRight = 0;
	index = -1;
	while (++index < equation->counter) {
		if (equation->getTerm(index).getSide() > 0) {
			maxRight++;
		}
	}
	if (maxRight > 0) {
		cout << "Max Right is more that 0 >> " << maxRight << endl;
		return (false);
	}
	equation->showReduced();
	return (true);
}

int		polynomialDegree(polynomial *equation) {
	int		len;
	term	oneTerm;
	int		polDegree;

	len = -1;
	polDegree = 0;
	while (++len < equation->counter) {
		oneTerm = equation->getTerm(len);
		if (oneTerm.getSide() > 0) {
			return (polDegree);
		}
		if (oneTerm.isExp() &&  oneTerm.getExponent() > polDegree) {
			polDegree = oneTerm.getExponent();
		}
	}
	return (polDegree);
}

int		main(int ac, char **av) {
	polynomial	*equation = new polynomial();
	Validate validation;
	if (ac != 2) {
		cout << "Usage: ./computor <polynimial>" << endl;
		return (1);
	}
	if (!validation.isPolynomialValid(av[1], equation)) {
		cout << "Polynomial expression is incorrect" << endl;
		return (1);
	}
	else {
		cout << "Polynomial expression is correct" << endl;
	}
	// if (!reducedOk(equation)) {
	// 	cout << "Error reducing polynomial";
	// 	return (1);
	// }
	// cout << "Polynomial degree is " << polynomialDegree(equation) << endl;
	// if (polynomialDegree(equation) > 2) {
	// 	cout << "The Polynomial degree is stricly greater than 2, I can't solve." << endl;
	// 	return (1);1
	// }
	return (0);
}
