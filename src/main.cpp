
#include "../computorv.h"

int		main(int ac, char **av) {
	if (ac != 2) {
		cout << "Usage: ./computor <polynimial>" << endl;
		return (1);
	}
	//cout << av[1] << endl;
	if (av) {
	}
	if (Validate::polynomialValid(av[1]))
		cout << "Is Valid\n";
	else
		cout << "Is not Valid\n";
	return (0);
}
