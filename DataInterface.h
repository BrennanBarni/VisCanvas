#ifndef DataInterface_H
#define DataInterface_H
#include "DataNode.h"
#include "Dimension.h"
#include "ColorCustom.h"
#include "DataClass.h"
#include "DataSet.h"
#include <vector>
/*
Author: Daniel Ortyn
Last Update: 2018/22/01
Purpose: CS 481 Project
*/


using namespace std;

// a class to hold several sets of data and manage interactions with the data
class DataInterface {
public:
	// create a blank class without any data
	DataInterface();
	// create a class with data taken from the file at the passed path(filePath)
	DataInterface(string* filePath);
	// delete the object
	~DataInterface();

	// read data from the file at the passed path(filePath) and 
	void readFile(string* filePath);
	// get the amounts of class for the data
	const int getClassAmount();
	// gets the total amount of data sets
	const int getSetAmount();
	/*
	Gets the number of sets in the class at the passed index(classIndex)
	*/
	const int getSetAmount(int classIndex);
	// gets the number of dimensions in the data
	const int getDimensionAmount();
	// gets the data in the set of the passed index(setIndex), for the passed dimension(indexOfData)
	double getData(int setIndex, int indexOfData);
	// get the class index for the set at the passed index
	const int getClassofSet(int setIndex);
	// moves the dimension at the passed index(indexOfDimension) to the spot after the other index(indexBeforeInsertion)
	void moveData(int indexOfDimension, int indexBeforeInsertion);
	// gets the name of the class at the passed index(classIndex)
	const string* getClassName(unsigned int classIndex);
	// sets the name of the class at the passed index(classIndex) to the passed string(newName)
	string* setClassName(unsigned int classIndex, string* newName);
	// gets the name of the set in the class at the passed index(classIndex) at the passed class relative index(setIndex)
	const string* getSetName(unsigned int setIndex);
	// sets the name of the set at the passed index(setIndex)
	string* setSetName(unsigned int setIndex, string* newName);
	// gets the index of the data class of the set at the passed index
	const int getSetClass(unsigned int setIndex);
	// sets the index data class of the set at the passed index(setIndex)
	int setSetClass(unsigned int setIndex, unsigned int newClassIndex);
	// gets a copy of the color the set should be painted
	const float* getSetColor(unsigned int setIndex);
	// gets the name of the x-axis
	const string* getXAxisName();
	// gets the name of the y-axis
	const string* getYAxisName();
	// gets the name of maximum y value
	const string* getYMaxName();
	// gets the name of minimum y value
	const string* getYMinName();
	// sorts the data by the set at the passed index, in ascending order(left to right)
	void sortAscending(unsigned int setIndex);
	// sorts the data by the set at the passed index, in descending order(left to right)
	void sortDescending(unsigned int setIndex);
	/* adjusts the data of each dimension by shifting the data of each dimension by the
	amount necessary to put the dat of the set at the passed index(setIndex) to the passed value(levelValue)*/
	void level(unsigned int setIndex, double levelValue);
	// gets the mean data value of the passed set
	const double getMean(unsigned int setIndex);
	// gets the median data value of the passed set
	const double getMedian(unsigned int setIndex);
	// calibrates each dimension's data to the [0,1] space, dimensions calibrated individually
	void calibrateData();
	// saves the data to the file att the passed index
	// warning not implemented
	const string* saveData(string* filePath);

	// gets the color for the class at the passed class index
	const float* getColor(unsigned int classIndex);
	// sets the color for the class at the passed class index(classIndex) to the passed color(newColor)
	void setColor(unsigned int classIndex, float* newColor);
	// sets the index of the selected set to the passed index(newSelectedSetIndex)
	void setSelectedSetIndex(unsigned int newSelectedSetIndex);
	// gets the index of the selected set
	const int getSelectedSetIndex();
	// sets the selected set's color to the colors in the passed float array(newSelectedSetColor)
	void setSelectedSetColor(float* newSelectedSetColor);
	// gets the color of the selected set
	const float* getSelectedSetColor();

private:
	// a vector to hold the dimensions containing the data for the sets
	vector<Dimension*> dataDimensions;

	// a vector to hold the data class
	vector<DataClass> dataClasses;
	// a vector to hold the data sets
	vector<DataSet> dataSets;
	// a field to hold the color of the selected set
	ColorCustom selectedSetColor;
	// a field to hold the index of the selected set
	int selectedSetIndex;

	// a field to hold the name of the maximum y value
	string yMaxName;
	// a field to hold the name of the minimum y value
	string yMinName;
	// a field to hold the name of the x axis
	string xAxisName;
	// a field to hold the name of the y axis
	string yAxisName;

	// a method to hold the basic intialization of the object fields
	void init();

	// an ascending(left to right), merge sort method that sorts the data between the passed indexes(start, end) by the data of the set at the passed index(setIndex)
	void sortAscending(unsigned int setIndex, unsigned int start, unsigned int end);
	// an ascending(left to right), bubble sort method that sorts the data between the passed indexes(start, end) by the data of the set at the passed index(setIndex)
	void bubbleSortDataAscending(unsigned int setIndex, unsigned int start, unsigned int end);

	// an descending(left to right), merge sort method that sorts the data between the passed indexes(start, end) by the data of the set at the passed index(setIndex)
	void sortDescending(unsigned int setIndex, unsigned int start, unsigned int end);
	// an descending(left to right), merge sort method that sorts the data between the passed indexes(start, end) by the data of the set at the passed index(setIndex)
	void bubbleSortDataDescending(unsigned int setIndex, unsigned int start, unsigned int end);

	// counts the number of characters in the passed string(line) that are one of the characters in the passed vector(characters)
	int countCharacters(vector<char>* characters, string* line);
};

#endif
