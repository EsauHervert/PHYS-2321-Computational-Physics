/*
This Program will calculate the final position of a equaition at a certain time t.

The equation is: x = x_0 + v_0*t +.5*a*t^2.
*/

// These are the libraries that I am needing to call for my program:

// THis one allows me to output results.
#include <iostream>

// This one allows me to use the pow(x,y) feature.
#include <cmath>

// This program allows me to use the setprecision tool so that I can make my output pretty.
#include <iomanip>

using namespace std;

// I wrote this as a function just because that is what made me comfortable. 
double DisplacementCalculator()
{
	// Set my starting point.
	double x = 2, x_0 = 2, v_0 = 0, a = 2, dt = 0.05, t_0 = 0, t = 5, T = 0, v;
	
	// Created a loop so that I can increase the time in increments.
	while (t_0 < t)
	{
		// The equation needed to be done.
		x = x_0 + v_0*t + .5*a*pow(t_0, 2);
		//Display what time we are in.
		cout << "Time:	" << setprecision(2) << fixed << t_0;
		// Display the displacement.
		cout << "	Displacement:	" << setprecision(4) << fixed << x << endl;
		
		// Increment the time interval.
		t_0 = t_0 + dt;
			
	};
	return 0;
}

int main()
{
	// Here it is.
	cout << "Here is the program." << endl;

	DisplacementCalculator();

	return 0;
}