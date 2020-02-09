// Nuclear Decay Program.

// Here are all the libraries that will be used for the project.
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

// Here is the fucntion where the Euler Method will be performed.
void Decay(double TimeConstant, double InitialAmount, double dt)
{
	// Here the file which will contain all the data points will be created.
	ofstream NuclearDecay;
	NuclearDecay.open("Nuclear.txt");

	// Here is iwhat is going to be outputted.
	double amount, time = 0;

	// Let the starting amount be set.
	amount = InitialAmount;

	// Header for the data points.
	NuclearDecay << "Time	Amount" << endl;

	// Amount at time 0.
	NuclearDecay << time << "	" << amount << endl;

	// Loop where the Euler method will be done.
	// The total amount of time this will be done is 5 seconds, so dividing it by the time interval will give how many itarations need to be complete.
	for (int t = 0; t < 5/ dt ; t++)
	{
		// Euler Method.
		amount = amount - (amount / TimeConstant) * dt; 
		
		// increase the time display counter.
		time = time + dt;

		// Display the time and amount at the time.
		NuclearDecay << time << "	" << amount << endl;

	}
	// Display the starting and ending amounts to the user.
	cout << "The amount of Uranium that we started with was " << InitialAmount << " nuclei.\nAfter " << time << " seconds, " << amount << " nuclei was left." << endl;

	// Close the program.
	NuclearDecay.close();
}

int main()
{
	// For a decay constant of 1, starting amount of 100, and .01 for the time step.
	Decay(1, 100, .01);

	// End program.
	return 0;
}
