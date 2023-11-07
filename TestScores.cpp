#include "TestScores.h"

//Constructors:
TestScores::TestScores()
{
	scores = nullptr;
	length = 0;
}

TestScores::TestScores(int* tests, int length)
{
	scores = tests;
	this->length = length;
}


//Destructor to free up used memory
TestScores::~TestScores()
{
	delete[] scores;
}

//Methods:
double TestScores::averageTestScores()
{
	double average = 0.0;

	for (int i = 0; i < length; i++)
	{
		if (*(scores + i) < 0)
			throw NegativeTestScore();
		else if (*(scores + i) > 100)
			throw ScoreToBig();
		else
			average += *(scores + i);
	}

	average = average / length;

	return average;
}