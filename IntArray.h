#pragma once
#include<iostream>
#include<vector>
using namespace std;
class IntArray
{
private:
	vector<int> array;

public:
	class IndexOutOfRange {};
	IntArray();

	void display() const;
	void displayIndex(int index);

};

