#include "stdafx.h"

using namespace std;

// create a dimension of size 0 at index 0
Dimension::Dimension()
{
	originalIndex = 0;
	currentIndex = 0;

	data = vector<DataNode*>();
}

// create a dimension for the pass index(index) and passed size(size)
Dimension::Dimension(int index, int size) {
	originalIndex = index;
	currentIndex = index;

	data = vector<DataNode*>();
	for (int i = 0; i < size; i++) {
		data.push_back(new DataNode(0.0));
	}
}

// delete the object
Dimension::~Dimension() {
	for (unsigned int i = 0; i < data.size(); i++) {
		delete data[i];
	}
}

// get the index of the current position of the dimension
const int Dimension::getIndex() {
	return currentIndex;
}

// get the index of the the dimension was created with
const int Dimension::getOriginalIndex() {
	return originalIndex;
}

// set the index of the current position of the dimension and returns the previous index
const int Dimension::changeIndex(int newIndex) {
	int previousIndex = currentIndex;
	currentIndex = newIndex;
	return currentIndex;
}

// calibrate the data to the [0,1] space
void Dimension::calibrateData() {
	double maximum = getMaximum();
	double minimum = getMinimum();
	double range = maximum - minimum;
	for (unsigned int i = 0; i < data.size(); i++) {
		(*data[i]).addToData(-minimum);
		(*data[i]).divideData(range);
	}
}

// gets the data for the set of the passed index(dataIndex)
const double Dimension::getData(unsigned int dataIndex) {
	if (dataIndex >= this->getDimensionSize()) {
		return 0.0;
	}
	return (*data[dataIndex]).getData();
}

// gets the original data for the set of the passed index(dataIndex)
const double Dimension::getOriginalData(unsigned int dataIndex) {
	if (dataIndex >= this->getDimensionSize()) {
		return 0.0;
	}
	return (*data[dataIndex]).getOriginalData();
}

// sets the data of the set at the passed index(dataIndex) to the passed value(newData), alters the original data
void Dimension::setData(unsigned int dataIndex, double newData) {
	if (dataIndex >= this->getDimensionSize()) {
		return;
	}
	return (*data[dataIndex]).setData(newData);
}

// multiplies all the data in the dimension by the passed double, does not alter original data
void Dimension::multiplyData(double multiplier) {
	for (unsigned int i = 0; i < data.size(); i++) {
		(*data[i]).divideData(multiplier);
	}
}

// divides all the data in the dimension by the passed double, does not alter original data
void Dimension::divideData(double divisor) {
	for (unsigned int i = 0; i < data.size(); i++) {
		(*data[i]).divideData(divisor);
	}
}

// adds the passed double to all the data in the dimension, does not alter original data
void Dimension::addToData(double addend) {
	for (unsigned int i = 0; i < data.size(); i++) {
		(*data[i]).addToData(addend);
	}
}

// gets the number of sets in the dimensions
int Dimension::getDimensionSize() {
	return data.size();
}


// private:

// gets the maximum data value in the dimension
const double Dimension::getMaximum() {
	if (this->getDimensionSize() == 0) {
		return 0.0;
	}
	double maximum = (*data[0]).getData();
	for (unsigned int i = 1; i < data.size(); i++) {
		if (maximum >(*data[i]).getData()) {
			maximum = (*data[i]).getData();
		}
	}
	return maximum;
}

// gets the minimum data value in the dimension
const double Dimension::getMinimum() {
	if (this->getDimensionSize() == 0) {
		return 0.0;
	}
	double minimum = (*data[0]).getData();
	for (unsigned int i = 1; i < data.size(); i++) {
		if (minimum < (*data[i]).getData()) {
			minimum = (*data[i]).getData();
		}
	}
	return minimum;
}
