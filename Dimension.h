#ifndef Dimension_H
#define Dimension_H
#include "DataNode.h"
#include <vector>
/*
Author: Daniel Ortyn
Last Update: 2018/22/01
Purpose: CS 481 Project
*/


using namespace std;

// a class to hold and manage data with a common index for several sets
class Dimension {
public:
	// create a dimension of size 0 at index 0
	Dimension();
	// create a dimension for the pass index(index) and passed size(size)
	Dimension(int index, int size);
	// delete the object
	~Dimension();

	// get the index of the current position of the dimension
	const int getIndex();
	// get the index of the the dimension was created with
	const int getOriginalIndex();
	// set the index of the current position of the dimension and returns the previous index
	const int changeIndex(int newIndex);
	// calibrate the data to the [0,1] space
	void calibrateData();
	// gets the data for the set of the passed index(dataIndex)
	const double getData(unsigned int dataIndex);
	// gets the original data for the set of the passed index(dataIndex)
	const double getOriginalData(unsigned int dataIndex);
	// sets the data of the set at the passed index(dataIndex) to the passed value(newData), alters the original data
	void setData(unsigned int dataIndex, double newData);
	// multiplies all the data in the dimension by the passed double, does not alter original data
	void multiplyData(double multiplier);
	// divides all the data in the dimension by the passed double, does not alter original data
	void divideData(double divisor);
	// adds the passed double to all the data in the dimension, does not alter original data
	void addToData(double addend);
	// gets the number of sets in the dimensions
	int getDimensionSize();

private:
	// the vector holding all the data
	vector<DataNode*> data;
	// gets the index the dimension was originally at
	int originalIndex;
	// gets the index the dimension is at
	int currentIndex;
	// gets the maximum data value in the dimension
	const double getMaximum();
	// gets the minimum data value in the dimension
	const double getMinimum();

};

#endif
