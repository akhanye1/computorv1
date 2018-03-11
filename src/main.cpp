
#include "../computorv.h"

int		main(int ac, char **av) {
	polynomial	*equation = new polynomial();
	if (ac != 2) {
		cout << "Usage: ./computor <polynimial>" << endl;
		return (1);
	}
	if (Validate::isPolynomialValid(av[1], equation))
		cout << "Is Valid\n";
	else
		cout << "Is not Valid\n";
	return (0);
}
