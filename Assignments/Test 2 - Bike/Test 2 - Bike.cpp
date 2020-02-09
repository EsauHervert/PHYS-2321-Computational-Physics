#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <stdio.h>

using namespace std;

	// This is the function that will be used to calculate the terminal velocity.
	// The values that can be changed are the initial velocity, the time interval, and the density.
void TestBicycle(long double Velocity, long double dt, long double rho)
{
	// Using the constants given.
	long double T = 400, Force = 50, C = .5, A = .33, M = 70, Tint = 1, V = 0;

	// Opening the file that will contain all the data that will be used.
	ofstream Test;
	Test.open("Bicycle.txt");

	// Fixing the outbut numbers.
	Test << fixed << setprecision(6);

	// Creating the header.
	Test << "Time (sec)	Velocity (m/s)" << endl;
	Test << 0.000000 << "	" << Velocity << endl;
	
	// The velocity initial will be stored for reasons.
	V = Velocity;

	// Creating the loop to calculate the program via Euler Method.
	while (Tint <= (T / dt))
	{
		// This will take the velocity initial and update it each time the loop runs according to the Euler Method.
		Velocity = Velocity + (Force / M) * dt- (C * rho * A * pow(Velocity, 2)) / (2 * M)*dt;
	
		// Displaying the time in seconds and the velocity in meters per second
		Test << Tint * dt << "	" << Velocity << endl;
		
		// This will display the final velocity of the bike given the initial changing paramaters.
		if (Tint == T / dt)
		{
			cout << "The final velocity for the following quantities:" << endl;
			cout << "Initial velocity:	" << V << " meters per second" << endl;
			cout << "Time interval:		" << dt << " seconds" << endl;
			cout << "Density of medium:	" << rho << " Kilograms per meter cubed" << endl;
			cout << "Is: " << Velocity << " meters per second." << endl;
			cout << "A file containing the data for the above values has been created."<< endl << endl;
		}

		// Increasing the counter.
		Tint++;
	}
	
	// Closing the file.
	Test.close();
};

int main()
{
	// This is part a. of the test.
	TestBicycle(0, .1, 1.225);
	rename("Bicycle.txt", "Initial Velocity = 0, Time Interval = .1, Density = 1.225.txt");

	// This is part b.

		// This is for time interval of .5 seconds.
		TestBicycle(0, .5, 1.225);
		rename("Bicycle.txt", "Initial Velocity = 0, Time Interval = .5, Density = 1.225.txt");

		// This is for time interval of .01 seconds.
		TestBicycle(0, .01, 1.225);
		rename("Bicycle.txt", "Initial Velocity = 0, Time Interval = .01, Density = 1.225.txt");
	
		// This is for time interval of .001 seconds.
		TestBicycle(0, .001, 1.225);
		rename("Bicycle.txt", "Initial Velocity = 0, Time Interval = .001, Density = 1.225.txt");

	// This is part c., the terminal velocity was 22.242827 meters per second, then the velocity of 25 meters per second is greater than the terminal velocity.
	TestBicycle(25, .1, 1.225);
	rename("Bicycle.txt", "Initial Velocity = 25, Time Interval = .1, Density = 1.225.txt");


	// Assuming that the density is slightly higher than the density of dry air, I get that the density would be 1.425.
	TestBicycle(0, .1, 1.425);
	rename("Bicycle.txt", "Initial Velocity = 0, Time Interval = .1, Density = 1.425.txt");


	// End the program.
	return 0;
}