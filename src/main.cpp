
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
		if (tempTerm.sameAs(oneTerm)) {
			tempTerm.swapTerm(oneTerm);
			equation->moveLeft(tempTerm, i, index);
			break ;
		}
	}
	return (true);
}

bool	reducedOk(polynomial *equation) {
	int		index;
	term	oneTerm;
	int		maxRight;

	index = -1;
	equation->simplifyRight();
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
	equation->solveExponents(0);
	return (true);
}

int		polynomialDegree(polynomial *equation) {
	int		len;
	term	oneTerm;
	int		polDegree;

	len = -1;
	polDegree = 1;
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
	if (!reducedOk(equation)) {
		cout << "Error reducing polynomial";
		return (1);
	}
	if (polynomialDegree(equation) > 2) {
		cout << "The Polynomial degree is stricly greater than 2, I can't solve." << endl;
		return (1);
	}
	equation->bodmasRule(0);
	equation->addRemaining(0);
	if (polynomialDegree(equation) == 1) {
		if (equation->counter != 2) {
			cout << "Cannot solve expression" << endl;
			return (1);
		}
		equation->solveExpression();
	}
	else if (polynomialDegree(equation) == 2) {
		
	}
	return (0);
}
