
#include "../computorv.h"

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
	if (ac != 2) {
		cout << "Usage: ./computor <polynimial>" << endl;
		return (1);
	}
	if (!Validate::isPolynomialValid(av[1], equation)) {
		cout << "Polynomial expression is incorrect" << endl;
		return (1);
	}
	cout << "Polynomial degree is " << polynomialDegree(equation) << endl;
	if (polynomialDegree(equation) > 2) {
		cout << "The Polynomial degree is stricly greater than 2, I can't solve." << endl;
		return (1);
	}
	equation->toString();
	return (0);
}
