#include<string>
using namespace std;

class TestScores
{
private:
	int* scores;
	int length;

public:
	//Constructors:
	TestScores();
	TestScores(int *tests, int length);

	//Exception Classs
	class NegativeTestScore 
	{};

	//Destructor:
	~TestScores();

	class ScoreToBig {};

	double averageTestScores();
};
