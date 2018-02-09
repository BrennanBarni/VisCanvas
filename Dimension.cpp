#include "stdafx.h"
#include "Dimension.h"
#include "DataNode.h"
#include <vector>
#include <string>

using namespace std;

// create a dimension of size 0 at index 0
Dimension::Dimension() {
	originalIndex = 0;
	name = std::to_string(originalIndex);
	data = vector<DataNode*>();
	shiftAmount = 0.0;
	isInverted = false;

	useArtificialCalibration = false;
	artificialMaximum = 1.0;
	artificialMinimum = 0.0;
}

// create a dimension for the pass index(index) and passed size(size)
Dimension::Dimension(int index, int size) {
	originalIndex = index;

	name = std::to_string(index);

	data = vector<DataNode*>();
	for (int i = 0; i < size; i++) {
		data.push_back(new DataNode(0.0));
	}
	shiftAmount = 0.0;
	isInverted = false;

	useArtificialCalibration = false;
	artificialMaximum = 1.0;
	artificialMinimum = 0.0;
}

// delete the object
Dimension::~Dimension() {
	for (unsigned int i = 0; i < data.size(); i++) {
		delete data[i];
	}
	data.clear();
}

// get the index of the the dimension was created with
int Dimension::getOriginalIndex() const {
	return originalIndex;
}

// calibrate the data to the [0,1] space
void Dimension::calibrateData() {
	double maximum = getMaximum();
	double minimum = getMinimum();
	if (false) {
		maximum = artificialMaximum;
		minimum = artificialMinimum;
	}
	double range = maximum - minimum;
	for (unsigned int i = 0; i < data.size(); i++) {
		(*data[i]).addToData(-minimum);
		(*data[i]).divideData(range);
	}
}

// gets the data for the set of the passed index(dataIndex)
double Dimension::getData(int dataIndex) const {
	if (dataIndex >= size() || dataIndex < 0) {
		return 0.0;
	}
	double dataReturn = (*data[dataIndex]).getData();
	if (isInverted==false) {
		dataReturn = 1 - dataReturn;
	}
	dataReturn += shiftAmount;
	return dataReturn;
}

// gets the data calibrated, but not inverted or shifted data for the set of the passed index(dataIndex)
double Dimension::getCalibratedData(int dataIndex) const {
	if (dataIndex >= size() || dataIndex < 0) {
		return 0.0;
	}
	double dataReturn = (*data[dataIndex]).getData();
	if (isInverted==false) {
		dataReturn = 1 - dataReturn;
	}
	return dataReturn;
}

// gets the original data for the set of the passed index(dataIndex)
double Dimension::getOriginalData(int dataIndex) const {
	if (dataIndex >= size() || dataIndex < 0) {
		return 0.0;
	}
	return (*data[dataIndex]).getOriginalData();
}

// gets the name
string * Dimension::getName() {
	return &name;
}


// sets the name and returns the old name
void Dimension::setName(string * newName) {
	name = *newName;
}

// sets the data of the set at the passed index(dataIndex) to the passed value(newData), alters the original data
void Dimension::setData(int dataIndex, double newData) {
	if (dataIndex >= size() || dataIndex < 0) {
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

// adds the amount passed(shiftAmount) to the data shift amount
void Dimension::shiftDataBy(double modToShiftAmount) {
	shiftAmount += modToShiftAmount;
}

// gets the amount data shift amount
double Dimension::getShift() {
	return shiftAmount;
}

// toggles whether the data is inverted
void Dimension::invertData() {
	isInverted = !isInverted;
}




// gets the number of sets in the dimensions
int Dimension::size() const {
	return data.size();
}

// sets the calibration to use the data's(not the artificial) maximum and minimum
void Dimension::clearArtificialCalibration() {
	useArtificialCalibration = false;
}

// sets the bounds to be used for artificial calibration
void Dimension::setCalibrationBounds(double newMaximum, double newMinimum) {
	useArtificialCalibration = true;
	artificialMaximum = newMaximum;
	artificialMinimum = newMinimum;
}

// gets the artficial calibration maximum for the dimension
double Dimension::getArtificialMaximum() const {
	return artificialMaximum;
}

// gets the artficial calibration maximum for the dimension
double Dimension::getArtificialMinimum() const {
	return artificialMinimum;
}

// gets the maximum data value in the dimension
double Dimension::getMaximum() const {
	if (size() == 0) {
		return 0.0;
	}
	double maximum = (*data[0]).getData();
	for (unsigned int i = 1; i < data.size(); i++) {
		if (maximum > (*data[i]).getData()) {
			maximum = (*data[i]).getData();
		}
	}
	return maximum;
}

// gets the minimum data value in the dimension
double Dimension::getMinimum() const {
	if (this->size() == 0) {
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

// private:

