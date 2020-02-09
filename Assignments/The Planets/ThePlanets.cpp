// Here are all the libraries that will be used.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <stdio.h>

using namespace std;

// Here is the function that will run the planetary 
void KeplersLaw(long double e, long double a, long double vx, long double vy)
{
	ofstream Kepler;
	Kepler.open("OrbitFile.txt");

	// Here are all the constants that will be used.
	long double r, rx, ry = 0, ax, ay, tt = 0, T = 0, r_0 = 0, mu,
		dt = .0001, Period = 0, Pi = 3.1415926535898;
	mu = 4 * pow(Pi, 2);

	// Here is the title for all the values that will be outputted.
	Kepler << "Radius (AU)	X position (AU)	Y position (AU)	Time (Yr)" << endl;
	
	// Setting the precision for stylistic reasons.
	Kepler << showpoint << setprecision(8);

	// Setting the radius depending on the particular values of each planet.
	r = (a * (1 - pow(e, 2))) / (1 - (e * cos(2 * Pi * T)));
	rx = r;
	r_0 = r;

	// Output the first value.
	Kepler << r <<  "	" << rx << "	" << ry << "	" << T << endl;

	// Loop which will use the Euler Method to calculate the positions at each time period.
	while (Period == 0)
	{
		// Start the time index at 1.
		T = tt * dt + dt;

		// recalculate the radius.
		r = (a * (1 - pow(e, 2))) / (1 - (e * cos(2 * Pi * T)));
		
		// Find the x components of the acceleration and velocity to find it's position.
		ax = - (mu * rx) / pow(r, 3);
		vx = vx + ax * dt;
		rx = rx + vx * dt;
	
		// Find the y components of the acceleration and velocity to find it's position.
		ay = -(mu * ry) / pow(r, 3);
		vy = vy + ay * dt;
		ry = ry + vy * dt;

	//Have a condition which ends the orbit close to where it started, with some error.
		if (tt > 100)
		{
			if (rx >= r_0 - 0.01 && rx <= r_0 + .01)
			{
				if (ry >= -0.01 && ry <= .01)
				{
					Period = 1;
				}
			}
		}
		
		// increase the counter, different from the index, but related.
		tt++;
		
		// Display the values.
		Kepler << r << "	" << rx << "	" << ry << "	" << T << endl;

	}

	// Calculate T^2/A^3.
	long double KeplerValue = pow(T, 2) / pow(a, 3);

	// Display to the user the final T^2/A^3 value.
	Kepler << "\n							The Value for T^2/A^3 is: " << KeplerValue << endl;
	cout << KeplerValue;

	// Close the file.
	Kepler.close();
};

int main()
{
	// Redefine Pi since it needs to be redefined.
	long double Pi = 3.1415926535898;

	// For Venus.
	cout << "The Value T^2/A^3 for Venus is: ";
	KeplersLaw(0.0067, 0.7233, 0, 1.188 * 2 * Pi);

	rename("Orbitfile.txt", "Venus.txt");
	cout << endl;

	//For Earth
	cout << "The Value T^2/A^3 for Earth is: ";
	KeplersLaw(.0167, 1, 0, 2 * Pi);

	rename("Orbitfile.txt", "Earth.txt");
	cout << endl; 
	
	// For Mars, although it does not work.
	/*
	cout << "The Value T^2/A^3 for Mars is: ";
	KeplersLaw(0.09341233, 1.52366231, 0, 0.875 * 2 * Pi);
	
	rename("Orbitfile.txt", "Mars.txt");
	cout << endl; 
	*/

	// For Jupiter.
	cout << "The Value T^2/A^3 for Jupiter is: ";
	KeplersLaw(0.0484, 5.2034, 0, 0.453 * 2 * Pi);

	rename("Orbitfile.txt", "Jupiter.txt");
	cout << endl;
	
	// For Saturn.
	cout << "The Value T^2/A^3 for Saturn is: ";
	KeplersLaw(0.05415, 9.5371, 0, 0.336 * 2 * Pi);

	rename("Orbitfile.txt", "Saturn.txt");
	cout << endl;
	
	// End the program.
	return 0;
}