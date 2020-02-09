#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <stdio.h>

using namespace std;

// This function will allow different values for time increments and for exponents of r.
double Orbit(long double dt, long double B)
{
	// Creating the file which will contain all the information.
	ofstream Orbit;

	Orbit.open("Planetary Orbit.txt");

	// Declare the constants.
	long double r = 1, Pi = 3.1415926535898, x = 1.0, y = 0, v_x = 0, v_y = 2 * Pi, T = 1;

	// Create the heading.
	Orbit << "This is the orbit for the dt value of " << dt << " and power " << B << endl << endl;

	// Make sure that the values are outputted correctly.
	Orbit << fixed << setprecision(6);

	// Create a heading that shows all that is being calculated.
	Orbit << "Radius		X Velocity	Y Velocity	X Position	Y Position" << endl;
	Orbit << r << "	" << v_x << "	" << v_y << "	" << x << "	" << y << endl;

	// The 1/dt wiill make sure that the total amount of times the program will be run will be enough for a complete orbit to be created.
	while (T <= 1 / dt)
	{
		// Here is the radius.
		r = pow((pow(x, 2) + pow(y, 2)), .5);
		Orbit << r << "	";

		// Here are the velocities.
		v_x = v_x - (4 * pow(Pi, 2) * x) / pow(r, B + 1) * dt;
		v_y = v_y - (4 * pow(Pi, 2) * y) / pow(r, B + 1) * dt;
		Orbit << v_x << "	" << v_y << "	";

		// Here are the positions.
		x = x + v_x * dt;
		y = y + v_y * dt;
		Orbit << x << "	" << y << endl;

		// Increase the counter for the next run.
		T++;
	}

	// Close the file and end the function.
	Orbit.close();
	return 0;
}

int main()
{
	/* These calls to the subroutines will use the following dt and B values.
	The files will be renamed so that they can be easily searched for.*/
	Orbit(.1, 2);
	rename("Planetary Orbit.txt", "dt = .1, B = 2.txt");

	Orbit(.01, 2);
	rename("Planetary Orbit.txt", "dt = .01, B = 2.txt");

	Orbit(.001, 2);
	rename("Planetary Orbit.txt", "dt = .001, B = 2.txt");

	Orbit(.01, 1.5);
	rename("Planetary Orbit.txt", "dt = .01, B = 1.5.txt");

	Orbit(.01, 2.5);
	rename("Planetary Orbit.txt", "dt = .01, B = 2.5.txt");

	Orbit(.01, 3);
	rename("Planetary Orbit.txt", "dt = .01, B = 3.txt");

	//Display information to user.
	cout << "The following Files for the values given have been created:\n\ndt = .1,	B = 2\ndt = .01,	B = 2\ndt = .001,	B = 2\ndt = .01,	B = 1.5\ndt = .01,	B = 2.5\ndt = .01,	B = 3." << endl;

	return 0;
	
}