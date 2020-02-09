// These are all the libraries that will be used in this program.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <stdio.h>

using namespace std;

// Here is the function that will be used to calculate all the population problems.
// The general form of the equation is dN/dt = a*N-b*N^p.
// The function will work with different a, N, b, p, dt, and total time of the program.
void PopulationGrowth(double a, double N, double b, double p, double dt, int Time)
{
	// A file will be created where all the data will be stored.
	ofstream Population;
	Population.open("File.txt");

	// This is where the values will be initialized.
	double N_t, T = 0, dndt, TrueTime;

	//since the total time will be dependent on the dt, the "True time" must be considered.
	// In this case it is the total time divided by dt.
	TrueTime = Time / dt;

	// The initial value is the value that is inputted.
	N_t = N;
	
	// Here is where the header and the starting value will be displayed.
	Population << "Time	Population" << endl;
	Population << T << "	" << N_t << endl;
	
	// This is where the Euler method will be performed.
	// The iterations will be done via a for loop.
	for (int tt = 1; tt <= TrueTime; tt++)
	{
		// Using the dN/dt and the time interval, the differential equations will be solved.
		dndt = a * N_t - b * pow(N_t, p);
		N_t = N_t + (dndt) * dt;

		// The time counter will be updated.
		T = T + dt;

		//Displaying the values.
		Population << T << "	" << N_t << endl;

	}
	
	// Closing the file.
	Population.close();
}

int main()
{
	// The time interval that will be used will be .01, since it is sufficiently small but not excessive.
	// All the functions will rename the file in accordance to their paticular values.

	// Part A
	// Letting a = 10, b = 0, and N_0 = 30.
	PopulationGrowth(10, 30, 0, 2, .01, 10);
	rename("File.txt", "Part A.txt");

	// Part B
	// Letting a = 10, b = 0.1, and N_0 = 30.
	PopulationGrowth(10, 30, .1, 2, .01, 10);
	rename("File.txt", "Part B.txt");

	// Part C
	// Letting a = 10, b = 10, and N_0 = 30.
	PopulationGrowth(10, 30, 10, 1.5, .01, 10);
	rename("File.txt", "Part C.txt");

	// Part D 1/2
	// Assume that the power p in the N^p component is greater than 2.
	PopulationGrowth(10, 30, .1, 2.5, .01, 10);
	rename("File.txt", "Part D, 1 of 2.txt");

	// Part D 2/2
	// Assume that the power p in the N^p component is lesser than 2.
	PopulationGrowth(10, 30, .1, 1.5, .01, 10);
	rename("File.txt", "Part D, 2 of 2.txt");

	// This is the cases for bacteria.
	// Part E 1/2
	// a = 2, b = 0, N_0 = 1, and the power of N^p will be 2.
	PopulationGrowth(2, 1, 0, 2, .01, 10);
	rename("File.txt", "Part E, 1 of 2.txt");

	// Part E 2/2
	// a = 2, b = .1, N_0 = 1, and the power of N^p will be 2.
	PopulationGrowth(2, 1, .1, 2, .01, 10);
	rename("File.txt", "Part E, 2 of 2.txt");

	// Let the user know that the program was successful.
	cout << "The program has completed and all the data points have been calculated." << endl << endl;
	// End the program.
	return 0;
}