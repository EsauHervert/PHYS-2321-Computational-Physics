#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

// Problem 2.2
double BikeVelocity()
{
	// Opening the file where the data points will be inputted for Problem 2.2.
	ofstream Problem22;
	Problem22.open("2.2.txt");
	cout << "Problem 2.2" << endl;
	Problem22 << "Problem 2.2" << endl << endl;

	// These are all the constants that I will be using for the program.
	// The dt will be in 1e^(-2) seconds and the entire interval will be 100 seconds.
	// Area 2 is .7 of Area 1 because the problem asked what a decrease of the frontal area by 30 percent would do.
	long double Power = 445, Power2 = 500, Time = 10000, Mass = 80, dt = .01, TimeCurrent = 0, T = 1, Area = .33, Area2 = (.33 * .7), C = 1, rho = 1.225, 
		V_DragForce = 0, V_DragForceChangePower = 0, V_DragForceChangeArea = 0,
		V_DrivingForce = 0, V_DrivingForceChangePower = 0, V_DrivingForceChangeArea = 0, 
		Velocity = 10, VelocityChangePower = 10, VelocityChangeArea = 10;

	// This is the header for the display and file.
	cout << "Time (sec)	Bike Velocity	Changing Power	Changing Area" << endl;
	Problem22 << "Time (sec)	Bike Velocity	Changing Power	Changing Area" << endl;

	// Showing the valuse at time zero.
	cout << TimeCurrent << "		" << Velocity << "		" << VelocityChangePower << "		" << VelocityChangeArea << endl;
	Problem22 << TimeCurrent << "		" << Velocity << "		" << VelocityChangePower << "		" << VelocityChangeArea << endl;

	// These are the three cases.
	// Loop to do Euler Method
	while (T <= Time)
	{
		// This is case 1 where the Area and the Power are just some numbers that will be as a control.
		V_DragForce = (C * rho * Area * pow(Velocity, 2)) / (2 * Mass) * dt;
		V_DrivingForce = (Power / (Mass * Velocity)) * (dt);
		Velocity = Velocity + V_DrivingForce - V_DragForce;

		// This is the case where the Power was increased by 55 watts.
		V_DragForceChangePower = (C * rho * Area * pow(VelocityChangePower, 2)) / (2 * Mass)*dt;
		V_DrivingForceChangePower = (Power2 / (Mass * VelocityChangePower)) * dt;
		VelocityChangePower = VelocityChangePower + V_DrivingForceChangePower - V_DragForceChangePower;

		// This is the case where Area was decreased by 30 percent.
		V_DragForceChangeArea = (C * rho * Area2 * pow(VelocityChangeArea, 2)) / (2 * Mass) * dt;
		V_DrivingForceChangeArea = VelocityChangeArea + (Power / (Mass * VelocityChangeArea)) * (dt);
		VelocityChangeArea = V_DrivingForceChangeArea - V_DragForceChangeArea;

		// Display the results at each time interval.
		Problem22 << T/100 << "		" << Velocity << "		" << VelocityChangePower << "		" << VelocityChangeArea << endl;

		// Increase counter by one second so that the loop goes again.

		// Displayin the final results.
		if (T == 10000)
		{
			cout << "\nThe final results for Time " << T / 100 << "s are: \nBike Velocity: " << Velocity << "\nChanging Power: " << VelocityChangePower << "\nChanging Area: " << VelocityChangeArea << endl << endl;
		}
		T++;
	}


	// Now close the program.
	Problem22.close();

	return 0;
};

// Problem 2.3
double BikeVelocityWithDrag()
{
	// Opening the files for the programs.
	ofstream Problem23;
	Problem23.open("2.3.txt");
	Problem23 << "Problem 2.3" << endl << endl;

	ofstream Problem232;
	Problem232.open("2.3-2.txt");
	Problem232 << "Problem 2.3" << endl << endl;

	// Header for the file.
	cout << "Problem 2.3" << endl;

	// Declaring the Constants. dt for Water had to be smaller in order to give good results.
	long double Power = 445, Time = 10000, Mass = 80, dt = .01, dt2 = .0001, TimeCurrent = 0, T = 1,
		DragCoefficientAir = 2e-5, DragCoefficientWater = 1e-3,
		V_DragForceAir = 0, V_DragForceWater = 0,
		V_DrivingForceAir = 0, V_DrivingForceWater = 0,
		V_LinearDragForceAir = 0, V_LinearDragForceWater = 0,
		VelocityAir = 10, VelocityWater = 10,
		Height = 1, Area = .33, C = 1, rhoAir = 1.225, rhoWater = 9999.97;

	// Creating the labels.
	Problem23 << "Time (s)	Velocity With Air Drag" << endl;
	Problem232 << "Time (s)	Velocity with Water Drag" << endl;
	cout << "Time (s)	Velocity with Air Drag	Velocity With Water Drag" << endl;

	// Displaying the initial values.
	Problem23 << TimeCurrent << "		" << VelocityAir << endl;
	Problem232 << TimeCurrent << "		" << VelocityWater << endl;
	cout << TimeCurrent << "		" << VelocityAir <<  "			" << VelocityWater << endl;

	while (T <= Time)
	{
		// This includes the linear drag term for air
		V_LinearDragForceAir = ((DragCoefficientAir * Area) * (VelocityAir / Height)) / (Mass) * dt;
		V_DragForceAir = (C * rhoAir * Area * pow(VelocityAir, 2)) / (2 * Mass) * dt;
		V_DrivingForceAir = (Power / (Mass * VelocityAir)) * (dt);
		VelocityAir = VelocityAir + V_DrivingForceAir - V_LinearDragForceAir - V_DragForceAir;

		// This is what would happen if the bike is in water
		V_LinearDragForceWater = ((DragCoefficientWater * Area) * (VelocityWater / Height)) / (Mass)* dt2;
		V_DragForceWater = (C * rhoWater * Area * pow(VelocityWater, 2)) / (2 * Mass) * dt2;
		V_DrivingForceWater = ((Power) / (Mass * VelocityWater)) * (dt2);
		VelocityWater = VelocityWater + V_DrivingForceWater - V_LinearDragForceWater - V_DragForceWater;

		// Displaying the results in terms of 
		Problem23 << T/100 << "		" << VelocityAir << endl;
		Problem232 << T/1000 << "		" << VelocityWater << endl;
		
		if (T == 10000)
		{

			// Displaying the final results.
			cout << "\nThe final result for Time " << T / 100 << "s is: Velocity in Air - " << VelocityAir << endl;
			cout << "\nThe final result for Time " << T / 1000 << "s is: Velocity in Water - " << VelocityWater << endl;
		}

		T++;

	}

	// Closing the files.
	Problem23.close();
	Problem232.close();

	return 0;
};
int main()
{
	// Making something clear.
	cout << "All velocity terms are in meters per second." <<endl << endl;

	// Calling the subroutines
	BikeVelocity();

	// Adding some space.
	cout << endl;

	BikeVelocityWithDrag();

	return 0;
}