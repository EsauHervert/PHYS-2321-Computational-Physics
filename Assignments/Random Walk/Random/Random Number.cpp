#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <stdio.h>

using namespace std;

	// Since this program will write to only one file, there was no usage of functions rather the algorithm is contained all in the main body of the program.

int main()
{
	// THis is the file that will contain all the random sequences that this program will find.
	ofstream RandomNumber;
	
	RandomNumber.open("Random.txt");
	// These integers were all used as counters for all the loops that were used in this program.
	int n = 1, k = 1, l = 0, T = 0, o = 1, p = 0, q = 0, s = 0, u = 0, v = 0;

	// All the values that will be used in this program will come from increasing these values.
	int Seed = 1, A = 1, C = 1;

	// This program will only find the random sequences for variables of lenght of 20.
	const int MM = 20;

	// This is the array that will contain all the number sequences which will be tested for uniqueness of values.
	int Random[MM + 1];
	
	// The first value in the array will be the seeder value.
	Random[1] = Seed;

	// This is the giant loop that will give all the permutations of the values of the seed, a, and r from 1 to 20.

	// This loop will go through all the seed values from 0 to 20.
	while (Seed < 20)
	{

	// This loop will go through all the a values from 0 to 20.
		while (A < 20)
		{

	// This loop will go through all the a values from 0 to 20.
			while (C < 20)
			{
	// This is the loop that will create all the arrays for all the variables that were given by the previous loops.
				while (n < MM)
				{
					Random[n + 1] = ((Random[n] * A) + C) % MM;
					n++;
				}
	// After the loop is completed, the value of n must be returned to 1 for the next iteration.
				n = 1;

	// Test 1. Testing the first number and seeing if it is different from the rest.
				while (o < (MM - 1))
				{
					if (Random[o + 1] != Random[1])
					{
						T++;
					}
					o++;
				}
				o = 1;

	// Test 2. Testing the second number against all the other numbers indexed greater than 2.
				while (o < (MM - 2))
				{
					if (Random[o + 2] != Random[2])
					{
						s++;
					}
					o++;
				}
				o = 1;
				
	// Test 3. Testing the third number against all the other numbers indexed greater than 3.
				while (o < (MM - 3))
				{
					if (Random[o + 3] != Random[3])
					{
						u++;
					}
					o++;
				}
				o = 1;

	// Test 4. Testing the 4th number against all the other numbers indexed greater than 4.
				while (o < (MM - 4))
				{
					if (Random[o + 4] != Random[4])
					{
						v++;
					}
					o++;
				}
				o = 1;
	// Check the test to see if the values pass.
				if (T >= (MM - 2) && s >= (MM - 3) && u >= (MM - 4) && v >= (MM - 5))
				{
					RandomNumber << "The values are as follows: seed = " << Seed
						<< ", a = " << A << ", c = " << C << ", M = " << MM << "." << endl;
					while (l < MM)
					{
						RandomNumber << Random[l + 1] << " | ";
						l++;
					}
					RandomNumber << endl << endl;
					l = 0;
				}

	// Reset the counters.
				T = 0;
				s = 0;
				u = 0;
				v = 0;

	// Increase the c counter.
				C++;
			}
	// Increase the a counter and reset the c counter.
			A++;
			C = 1;
		}

	// increase the seed counter and reset the a counters a and c.
		Seed++;
		A = 1;
		C = 1;
	}

	RandomNumber << endl;

	// Close the file.
	RandomNumber.close();

	return 0;
}