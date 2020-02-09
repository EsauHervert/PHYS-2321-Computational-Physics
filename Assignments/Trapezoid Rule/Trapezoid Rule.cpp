#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	long double i = -1, f = 1, f_x = 0, dx = .005, Sum = 0, Integral = 0;

	long double f_i = 4 * pow(-1, 3) + 3 * (-1) + 1;

	while (i < (f - dx))
	{
		i = i + dx;
		f_x = 4 * pow(i, 3) + 3 * i + 1;
		Sum = Sum + f_x;
	};

	long double f_f = 4 * pow(1, 3) + 3 * (1) + 1;

	Integral = (.5*f_i + Sum + .5*f_f)*dx;
	cout << Integral << endl;

	return 0;
}

