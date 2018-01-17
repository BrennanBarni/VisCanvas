#include "DataInterface.h"
#include "DataNode.h"
#include "Dimension.h"
#include <vector>
#include <string> 
#include <iostream>
#include <fstream>


using namespace std;

// create the data interface
// full implementation after file parsing
DataInterface::DataInterface(string* filePath) {
	dataDimensions = vector<Dimension*>();

	classSizes = vector<unsigned int>();
	classNames = vector<string*>();
	setNames = vector<string*>();
	classColors = vector<Color>();
	selectedSetColor = Color();
	selectedSetColor = Color();
	selectedSetIndex = 0;
	yMaxName = "1.0";
	yMinName = "0.0";
	xAxisName = "X-Axis";
	yAxisName = "Y-Axis";

	// set up default set names
	for (int i = 0; i < (*dataDimensions[0]).getDimensionSize(); i++) {
		string tempString = std::to_string(i);
		setNames.push_back(&tempString);
	}
}

void DataInterface::readFile(char * filePath)
{
	std::fstream inStream; // calls function to read from file
	inStream.open(filePath); // open the file

	if (inStream.fail())
		return; // if there is no file, end function
	// get lines
	vector<string> lines = vector<string>();
	string currentLine = "";
	while (inStream.good()) {
		inStream >> currentLine;
		lines.push_back(currentLine);
	}
	inStream.close(); // closes the text file
	// create the dimensions
	int numberOfLines = lines.size() - 1;
	vector<char>* seperators = new vector<char>();
	seperators->push_back(',');
	seperators->push_back(';');
	int numberOfDimensions = countCharacters(seperators, &lines[1]);
	for (int i = 0; i < numberOfDimensions; i++) {
		dataDimensions.push_back(new Dimension(i, numberOfLines));
	}

	// parse lines
	for (int i = 0; i < numberOfLines; i++) {
		for (int j = 0; j < numberOfDimensions; j++) {
		}
	}
}



// gets the number of classes in the data
const int DataInterface::getClassAmount() {
	return classSizes.size();
}

/*
Returns the amount of sets within the class at the passed index
Returns -1 for indexes of classes that are out of bounds
*/
const int DataInterface::getSetAmount(unsigned int indexOfClass) {
	if (indexOfClass >= classSizes.size()) {
		return -1;
	}
	return classSizes[indexOfClass];
}

/*
 Gets the total number of sets in the data
 full implementation after file parsing
*/
const int DataInterface::getSetAmount() {
	return setNames.size();
}

// gets the number of dimensions in the data
const int DataInterface::getDimensionAmount() {
	return dataDimensions.size();
}

// gets the data in the passed set at the passed index
double DataInterface::getData(unsigned int indexOfSet, unsigned int indexOfData) {
	// check if indexes are in bounds
	if (dataDimensions.size() >= indexOfData) {
		return 0.0;
	}
	if (indexOfSet >= getDimensionAmount()) {
		return 0.0;
	}

	// get data
	return (*dataDimensions[indexOfData]).getData(indexOfSet);
}

/*
returns the index of the class containing the set at the passed index
returns -1 if the passed set index is out of bounds
*/
const int DataInterface::getClassofSet(unsigned int indexOfSet) {
	// count the number of sets in classes before the class being checked
	unsigned int setsInClassesAbove = 0;
	for (unsigned int i = 0; i < getClassAmount(); i++) {
		setsInClassesAbove += getSetAmount(i);
		// check if the passed set index is in class before/at this point
		if (setsInClassesAbove > indexOfSet) {
			return i;
		}
	}
	return -1;
}

/*
moves the position of a dimensions from the passed index(indexOfDimension) to after the other passed index(indexBeforeInsertion)
Note: the new position is calculated before the dimension being moved is removed from its place so if the data had dimensions 0,1,2,3
and the call moveData(1, 2) was made the dimensions would become 0,2,1,3 not 0,2,3,1
*/
void DataInterface::moveData(unsigned int indexOfDimension, unsigned int indexBeforeInsertion) {
	// place the dimension in the new position
	dataDimensions.insert(dataDimensions.begin(), indexBeforeInsertion, dataDimensions[indexOfDimension]);
	// remove the dimension from the old position
	if (indexOfDimension <= indexBeforeInsertion) {
		dataDimensions.erase(dataDimensions.begin() + indexOfDimension);
	}
	else {
		dataDimensions.erase(dataDimensions.begin() + indexOfDimension + 1);
	}
}

// gets the name of the class at the passed index
// full implementation after file parsing
const string* DataInterface::getClassName(unsigned int classIndex) {
	if (classNames.size() >= classIndex) {
		return nullptr;
	}
	return &(string());
}

// sets the name of the class at the passed index to the passed string and returns the old name
// full implementation after file parsing
string* DataInterface::setClassName(unsigned int classIndex, string* newName) {
	if (classNames.size() >= classIndex) {
		return nullptr;
	}

	return &(string());
}

// gets the name of the set at the pased index
// full implementation after file parsing
const string* DataInterface::getSetName(unsigned int classIndex, unsigned int setIndex) {
	// count the number of sets in classes before the class being checked
	int absoluteSetIndex = getSetIndex(classIndex, setIndex);

	// check for invalid indexes
	if (absoluteSetIndex < 0) {
		return nullptr;
	}
	// get the set name
	return setNames[absoluteSetIndex];
}

// sets the name of the set at the passed index to the passed string and returns the old name
// full implementation after file parsing
string* DataInterface::setSetName(unsigned int classIndex, unsigned int setIndex, string* newName) {
	// count the number of sets in classes before the class being checked
	int absoluteSetIndex = getSetIndex(classIndex, setIndex);

	// check for invalid indexes
	if (absoluteSetIndex < 0) {
		return nullptr;
	}
	// get the set name
	return setNames[absoluteSetIndex] = newName;
}

// gets the name of the x-axis
// full implementation after file parsing
const string* DataInterface::getXAxisName() {
	return &(string());
}

// gets the name of the y-axis
// full implementation after file parsing
const string* DataInterface::getYAxisName() {
	return &(string());
}

// gets the name of the maximum of the y axis
// full implementation after file parsing
const string* DataInterface::getYMaxName() {
	return &(string());
}

// gets the name of the minimum of the y axis
// full implementation after file parsing
const string* DataInterface::getYMinName() {
	return &(string());
}

// sorts the dimensions in ascending order by the data corresponding to the passed set index
void DataInterface::sortAscending(unsigned int setIndex) {
	sortAscending(setIndex, 0, getDimensionAmount());
}

// sorts the dimensions in descending order by the data corresponding to the passed set index(setIndex)
void DataInterface::sortDescending(unsigned int setIndex) {
	sortDescending(setIndex, 0, getDimensionAmount());
}

// adjusts data of the set at the passed index to the all be the same value and adjusts the data of all other sets accordingly
void DataInterface::level(unsigned int setIndex) {
	// don't accept out of bounds data set indexes
	if (setIndex >= getSetAmount()) {
		return;
	}
	double newValue = 0.5;
	// adjust each data point to the new 0 amount for its dimension
	for (unsigned int i = 0; i < getDimensionAmount(); i++) {
		double currentData = getData(setIndex, i);
		double change = newValue - currentData;
		// change data
		for (unsigned int j = 0; j < getSetAmount(); j++) {
			(*dataDimensions[i]).addToData(change);
		}
	}
	// calibrate all data to the [0, 1] space
	calibrateData();
}

// calibrate each dimension to the [0,1] space
void DataInterface::calibrateData() {
	for (unsigned int i = 0; i < getDimensionAmount(); i++) {
		(*dataDimensions[i]).calibrateData();
	}
}

// creates a string representation of the data and settings in this class
// full implementation after file parsing
const string* DataInterface::saveData(string* filePath) {

	return nullptr;
}





// gets the index of the set at the passed class and set index
const int DataInterface::getSetIndex(unsigned int classIndex, unsigned int setIndex) {
	if (classIndex > getClassAmount()) {
		return -1;
	}
	if (classIndex > getSetAmount(setIndex)) {
		return -1;
	}

	// count the number of sets in classes before the passed class index
	unsigned int setsInClassesAbove = 0;
	for (unsigned int i = 0; i < classIndex; i++) {
		setsInClassesAbove += getSetAmount(i);
	}
	return setsInClassesAbove + setIndex;
}

const float * DataInterface::getColor(int classIndex) {
	if (classIndex < 0) {
		classIndex = 0;
	}
	else if (classIndex >= classColors.size()) {
		classIndex = classColors.size() - 1;
	}
	return classColors[classIndex].getColorComponents();
}

void DataInterface::setColor(int classIndex, float * newColor) {
	if (classIndex < 0) {
		classIndex = 0;
	}
	else if (classIndex >= classColors.size()) {
		classIndex = classColors.size() - 1;
	}
	return classColors[classIndex].setColorComponents(newColor);
}

void DataInterface::setSelectedSetIndex(int newSelectedSetIndex) {
	if (newSelectedSetIndex < 0) {
		newSelectedSetIndex = 0;
	}
	else if (newSelectedSetIndex >= getSetAmount()) {
		newSelectedSetIndex = getSetAmount() - 1;
	}
	selectedSetIndex = newSelectedSetIndex;
}

const int DataInterface::getSelectedSetIndex() {
	return selectedSetIndex;
}

void DataInterface::setSelectedSetColor(float * newSelectedSetColor) {
	selectedSetColor.setColorComponents(newSelectedSetColor);
}

const float* DataInterface::getSelectedSetColor() {
	return selectedSetColor.getColorComponents();
}


// private:
// a merge sort implementation to sort the dimensions in ascending order by the data corresponding to the passed set index(setIndex)
// only the data at and between the passed indexes(start, end) will be sorted
void DataInterface::sortAscending(unsigned int setIndex, unsigned int start, unsigned int end) {
	// don't accept out of bounds data set indexes
	if (setIndex >= dataDimensions.size()) {
		return;
	}
	if (start < 0) {
		return;
	}
	if (end > dataDimensions.size()) {
		return;
	}
	int sectionSize = (end - start + 1);
	int middleIndex = (end - start) / 2 + start;
	// split data for merge sort
	if (sectionSize >= 6) {
		sortAscending(setIndex, start, middleIndex);
		sortAscending(setIndex, middleIndex + 1, end);
		// sort the combined parts
		// make copy to hold the data while its sorted
		std::vector<Dimension*> copy = std::vector<Dimension*>();
		int firstCounter = start;
		int secondCounter = middleIndex + 1;
		// push data into copy in a sorted manner
		while (firstCounter <= middleIndex && secondCounter <= end) {
			if ((*(dataDimensions[firstCounter])).getData[setIndex] < (*(dataDimensions[secondCounter])).getData[setIndex]) {
				copy.push_back(dataDimensions[firstCounter]);
				firstCounter++;
			}
			else {
				copy.push_back(dataDimensions[secondCounter]);
				secondCounter++;
			}
		}
		// push remainder
		while (firstCounter <= middleIndex) {
			copy.push_back(dataDimensions[firstCounter]);
			firstCounter++;
		}
		while (secondCounter <= end) {
			copy.push_back(dataDimensions[secondCounter]);
			secondCounter++;
		}
		// place sorted list back into data vector
		for (int i = 0; i < copy.size(); i++) {
			dataDimensions[i + start] = copy[i];
		}
	}
	else {
		bubbleSortDataAscending(setIndex, start, end);
	}

}

// a bubble sort implementation to sort the dimensions in ascending order by the data corresponding to the passed set index(setIndex)
void DataInterface::bubbleSortDataAscending(unsigned int setIndex, unsigned int start, unsigned int end) {
	for (int i = start; i <= end; i++) {
		for (int j = i + 1; j <= end; j++) {
			if ((*(dataDimensions[i])).getData[setIndex] > (*(dataDimensions[j])).getData[setIndex]) {
				std::swap((*(dataDimensions[i])).getData[setIndex], (*(dataDimensions[j])).getData[setIndex]);
			}
		}
	}
}

// a merge sort implementation to sort the dimensions in descending order by the data corresponding to the passed set index(setIndex)
// only the data at and between the passed indexes(start, end) will be sorted
void DataInterface::sortDescending(unsigned int setIndex, unsigned int start, unsigned int end) {
	// don't accept out of bounds data set indexes
	if (setIndex >= dataDimensions.size()) {
		return;
	}
	if (start < 0) {
		return;
	}
	if (end > dataDimensions.size()) {
		return;
	}
	int sectionSize = (end - start + 1);
	int middleIndex = (end - start) / 2 + start;
	// split data for merge sort
	if (sectionSize >= 6) {
		sortDescending(setIndex, start, middleIndex);
		sortDescending(setIndex, middleIndex + 1, end);
		// sort the combined parts
		// make copy to hold the data while its sorted
		std::vector<Dimension*> copy = std::vector<Dimension*>();
		int firstCounter = start;
		int secondCounter = middleIndex + 1;
		// push data into copy in a sorted manner
		while (firstCounter <= middleIndex && secondCounter <= end) {
			if ((*(dataDimensions[firstCounter])).getData[setIndex] > (*(dataDimensions[secondCounter])).getData[setIndex]) {
				copy.push_back(dataDimensions[firstCounter]);
				firstCounter++;
			}
			else {
				copy.push_back(dataDimensions[secondCounter]);
				secondCounter++;
			}
		}
		// push remainder
		while (firstCounter <= middleIndex) {
			copy.push_back(dataDimensions[firstCounter]);
			firstCounter++;
		}
		while (secondCounter <= end) {
			copy.push_back(dataDimensions[secondCounter]);
			secondCounter++;
		}
		// place sorted list back into data vector
		for (int i = 0; i < copy.size(); i++) {
			dataDimensions[i + start] = copy[i];
		}
	}
	else {
		bubbleSortDataDescending(setIndex, start, end);
	}
}

// a bubble sort implementation to sort the dimensions in descending order by the data corresponding to the passed set index(setIndex)
void DataInterface::bubbleSortDataDescending(unsigned int setIndex, unsigned int start, unsigned int end) {
	for (int i = start; i <= end; i++) {
		for (int j = i + 1; j <= end; j++) {
			if ((*(dataDimensions[i])).getData[setIndex] < (*(dataDimensions[j])).getData[setIndex]) {
				std::swap((*(dataDimensions[i])).getData[setIndex], (*(dataDimensions[j])).getData[setIndex]);
			}
		}
	}
}

// count number of characters
int DataInterface::countCharacters(vector<char>* characters, string* line)
{
	int count = 0;
	// iterate through all characters in passed line
	for (int i = 0; i < line->size(); i++) {
		// check the character against each character in the passed vector
		for (int j = 0; j < characters->size(); j++) {
			if (line->at(i) == (*characters)[j]) {
				count++;
				j = (*characters).size();
			}
		}
	}
	return count;
}

