// Here are all the libraries that I will be using.

#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <cstdlib>

using namespace std;

// This is the function where the random walk will be calculated.
void randomwalk(double stepsize, int max, double run)
{
	// Creating the file were the data is being stored.
	ofstream RandomWalk;
	RandomWalk.open("RandomWalk.txt");

	// Here are the constant values.
	const int interval = 1000;
	int t = 0;
	double x = 0, x2 = 0, y = 0, y2 = 0, r2 = 0, random = 0;
	
	// The header for the table.
	RandomWalk << "Step	R^2" << endl;
	RandomWalk << t << "	"<< r2 << endl;

	// Create an Array and initialize everything in the array to 0. Make sure that the array is big enough to hold all the numbers.
	double RunAverage[interval + 1];
	for (int p = 0; p <= interval; p++)
	{
		RunAverage[p] = 0;
	}

	// Now the time interval will start with time 1.
	t = 1;

	// This will add a time dependency of the random numbers making them closer to true random.
	srand(time(0));

	// This loop will run the random number generator loop for as many times as needed, depending on what the user inputs.
	for (int s = 1; s <= run; s++)
	{

		// This is the loop that will increase the coordinates.
		while (t <= interval)
		{

			// Call for a random number.
			random = (rand() % (max));

			// X - Coordinates.
			if (random < (max / 2))
			{
				x = x + stepsize;
			}
			else
			{
				x = x - stepsize;
			}

			// Get a new random number.
			random = (rand() % (max));

			// Y - Coordinates.
			if (random < (max / 2))
			{
				y = y + stepsize;
			}
			else
			{
				y = y - stepsize;
			}

			// Make 0 equal to 0.
			if (x <= 2.77556e-017 && x >= -2.77556e-017)
			{
				x = 0;
			}

			if (y <= 2.77556e-017 && y >= -2.77556e-017)
			{
				y = 0;
			}

			// Solve for x^2 and y^2.
			x2 = pow(x, 2);
			y2 = pow(y, 2);

			// Add the value of the runs for each step to the array.
			r2 = x2 + y2;
			RunAverage[t] = (RunAverage[t] + r2);

			// Increase the counter
			t++;
		}

		// Reset the counter and the values for x and y for the 
		t = 1;
		x = 0;
		y = 0;

	}
	
	// Output the step number and the average value of all the runs for a given step.
	for (int u = 1; u <= interval; u++)
	{
		RandomWalk << u << "	" << (RunAverage[u]) / run << endl;
	}
}

int main()
{
	// Tell the user what the program does.
	cout << "This program will calculate the R^2 values for a random walk of runs 1, 10, 100, and 1000." << endl << endl;

	// For an Step Size of 1, a random pool of 10000 numbers, and for 1 runs.
	randomwalk(1, 10000, 1);
	rename("RandomWalk.txt", "1, 10000, 1.txt");

	// For an Step Size of 1, a random pool of 10000 numbers, and for 10 runs.
	randomwalk(1, 10000, 10);
	rename("RandomWalk.txt", "1, 10000, 10.txt");

	// For an Step Size of 1, a random pool of 10000 numbers, and for 100 runs.
	randomwalk(1, 10000, 100);
	rename("RandomWalk.txt", "1, 10000, 100.txt");

	// For an Step Size of 1, a random pool of 10000 numbers, and for 1000 runs.
	randomwalk(1, 10000, 1000);
	rename("RandomWalk.txt", "1, 10000, 1000.txt");

	// Let the user know that the program completed the task.
	cout << "The program has completed." << endl << endl;

	// End Program.
	return 0;
}