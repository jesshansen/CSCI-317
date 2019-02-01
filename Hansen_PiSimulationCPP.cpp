#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <math.h>
/**
 * @author jhansen001
 *
 */
using namespace std;

	int main() {
		float games = 0.0;
		cout << "Please enter the number of games.";
		cin >> games;
		float darts = 0.0;
		cout << "Please enter the amount of darts.";
		cin >> darts;
		// lower bound of random coordinate
		double lower = -0.5;
		// upper bound of random coordinate
		double upper = 0.5;
		// added up total of pi values from all games
		double totalPi = 0;
		// values to help calculate standard deviation
		float standardDev = 0;
		double standardDevTotal = 0;
		float averageStandardDev = 0;
		// average pi value from all games
		float averagePi = 0;
		float pi = 0;
		srand (static_cast <unsigned> (time(0)));
		// loop through all the requested games
		for (int j = 1; j <= games; j++) {
			// count of darts inside the circle each game
			float countInside = 0;
			// loop through requested darts per game
			for (int i = 0; i < darts; i++) {
				// x and y coordinates for each dart
				float x = lower + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(upper-lower)));
				float y = lower + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(upper-lower)));
				// calculates distance for each dart on the board
				float distance = (float) sqrt((x * x) + (y * y));
				// checks if it made it inside the circle
				if (distance < 0.5) {
					countInside++;
				}
			}
			// calculating pi and standard deviation after each game
			pi = (countInside / darts) * 4;
			totalPi += pi;
			averagePi = (float) (totalPi / j);
			standardDev = (float) pow(pi - averagePi,2);
			// keep a running total of the standard deviations to average out at the end
			standardDevTotal += standardDev;
		}
		averagePi = totalPi/games;
		float variance = (float) standardDevTotal/games;
		averageStandardDev = (float) sqrt(variance); 
		cout << "Estimation for pi: " << averagePi;
		cout << "\nStandard Deviation: " << averageStandardDev;
		return 0;
	}


