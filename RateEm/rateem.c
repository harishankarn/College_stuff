#include <stdio.h>
#include <stdbool.h> 
#include <math.h>
#include "rateem.h"


// Function to calculate the Probability
float Probability(int rating1, int rating2)
{
    return 1/(1+1*pow(10,1.0 * (rating1 - rating2) / 400));
}

// Function to calculate Elo rating
// K is a constant.
// d determines whether Player A wins or Player B.
void EloRating(float Ra, float Rb, int K, bool d)
{

	// To calculate the Winning
	// Probability of Player B
	float Pb = Probability(Ra, Rb);

	// To calculate the Winning
	// Probability of Player A
	float Pa = Probability(Rb, Ra);

	// Case -1 When Player A wins
	// Updating the Elo Ratings
	if (d == 1) {
		Ra = Ra + K * (1 - Pa);
		Rb = Rb + K * (0 - Pb);
	}

	// Case -2 When Player B wins
	// Updating the Elo Ratings
	else {
		Ra = Ra + K * (0 - Pa);
		Rb = Rb + K * (1 - Pb);
	}

	printf("Updated Ratings:-\n");
	printf("Ra = %.2f : Rb = %.2f\n",Ra,Rb);
}

// Driver code

