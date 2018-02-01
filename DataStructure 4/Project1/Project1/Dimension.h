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

	// get the index of the the dimension was created with
	int getOriginalIndex() const;
	// calibrate the data to the [0,1] space
	void calibrateData();
	// gets the data for the set of the passed index(dataIndex)
	double getData(int dataIndex) const;
	// gets the data calibrated, but not inverted or shifted data for the set of the passed index(dataIndex)
	double getCalibratedData(int dataIndex) const;
	// gets the original data for the set of the passed index(dataIndex)
	double getOriginalData(int dataIndex) const;
	// gets the name
	string* getName();
	// sets the name and returns the old name
	void setName(string* newName);
	// sets the data of the set at the passed index(dataIndex) to the passed value(newData), alters the original data
	void setData(int dataIndex, double newData);


	// multiplies all the data in the dimension by the passed double, does not alter original data
	void multiplyData(double multiplier);
	// divides all the data in the dimension by the passed double, does not alter original data
	void divideData(double divisor);
	// adds the passed double to all the data in the dimension, does not alter original data
	void addToData(double addend);
	// adds the amount passed(shiftAmount) to the data shift amount
	void shiftDataBy(double shiftAmount);
	// toggles whether the data is inverted
	void invertData();


	// gets the number of sets in the dimensions
	int size() const;
	// sets the calibration to use the data's(not the artificial) maximum and minimum
	void clearArtificialCalibration();
	// sets the bounds to be used for artificial calibration
	void setCalibrationBounds(double newMaximum, double newMinimum);
	// gets the artificial maximum
	double getArtificialMaximum() const;
	// gets the artificial minimum
	double getArtificialMinimum() const;
	// gets the maximum data value in the dimension
	double getMaximum() const;
	// gets the minimum data value in the dimension
	double getMinimum() const;

private:
	// the vector holding all the data
	vector<DataNode*> data;
	// the amount to add to data when it is retrieved
	double shiftAmount;
	// holds whether the data is inverted or not
	bool isInverted;
	// gets the index the dimension was originally at
	int originalIndex;
	// the boolean checking whether to use artificial calibration
	bool useArtificialCalibration;
	// the maximum to calibrate the set with
	double artificialMaximum;
	// the minimum to calibrate the set with
	double artificialMinimum;
	// the name of the dimension
	std::string name;
};

#endif