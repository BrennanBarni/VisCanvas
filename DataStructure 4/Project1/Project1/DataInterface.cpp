#include "DataInterface.h"
#include "DataNode.h"
#include "Dimension.h"
#include "ColorCustom.h"
#include "DataClass.h"
#include "DataSet.h"

#include <vector>
#include <list>
#include <string> 
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	std::string fileName = "C:\\Users\\danie\\OneDrive\\Desktop\\Book2.csv";
	DataInterface* test = new DataInterface();
	test->readFile(&fileName);
	// print sizes
	std::cout << "Class Amount: " << test->getClassAmount();
	std::cout << "\nSet Amount: " << test->getSetAmount();
	for (unsigned int i = 0; i < test->getSetAmount(); i++) {
		std::cout << "\n" << *(test->getSetName(i));
		for (unsigned int j = 0; j < test->getDimensionAmount(); j++) {
			std::cout << "\t" << test->getData(i, j);
		}
	}
	std::vector<double>* color = test->getSetColor(0);
	std::cout << "\n\n" << (*color)[0] << ", " << (*color)[1];
	std::cout << ", " << (*color)[2] << ", " << (*color)[3];
	system("Pause");
}





// create a blank class without any data
DataInterface::DataInterface() {
	init();
}

// create a class with data taken from the file at the passed path(filePath)
DataInterface::DataInterface(string* filePath) {
	// create and set the fields
	init();

	// read data from file
	readFile(filePath);

}

// delete the object
DataInterface::~DataInterface() {
	/*
	for (unsigned int i = 0; i < dataDimensions.size(); i++) {
		delete dataDimensions[i];
	}
	*/
	dataDimensions.clear();
}

// parse the data in the file at the passed path into the object
void DataInterface::readFile(string * filePath) {
	std::vector<std::vector<std::string>*>* fileLines = readFileIntoVector(filePath);
	if (fileLines == nullptr) {
		return;
	}
	// find if a custom file or a basic file
	// find first none blank line
	bool isCustomFileFormat = false;
	for (int i = 0; i < fileLines->size(); i++) {
		if ((*fileLines)[i]->size() > 0) {
			isCustomFileFormat = ((*(*fileLines)[i])[0] == "VisCanvas File Format");
			i = fileLines->size();
		}
	}

	for (unsigned int i = 0; i < dataDimensions.size(); i++) {
		delete dataDimensions[i];
	}
	dataDimensions.clear();
	init();


	if (isCustomFileFormat) {
		readCustomFile(fileLines);
	}
	else {
		readBasicFile(fileLines);
	}
}

// creates a string representation of the data and settings in this class
// full implementation after file parsing
void DataInterface::saveData(string* filePath) const {

	return;
}





// gets the number of classes in the data
int DataInterface::getClassAmount() const {
	return dataClasses.size();
}

/*
 Gets the total number of sets in the data
 full implementation after file parsing
*/
int DataInterface::getSetAmount() const {
	if (dataDimensions.size() == 0) {
		return 0;
	}
	return (*dataDimensions[0]).size();
}

// gets the number of dimensions in the data
int  DataInterface::getDimensionAmount() const {
	return dataDimensions.size();
}

// gets the data in the passed set at the passed index
double DataInterface::getData(int indexOfSet, int indexOfData) const {
	// check if indexes are in bounds
	if (indexOfSet >= getSetAmount() || indexOfSet < 0) {
		return 0.0;
	}
	if (indexOfData >= getDimensionAmount() || indexOfData < 0) {
		return 0.0;
	}

	// get data
	return (*dataDimensions[indexOfData]).getData(indexOfSet);
}

/*
moves the position of a dimensions from the passed index(indexOfDimension) to at the other passed index(indexOfInsertion)
Note: the new position is calculated before the dimension being moved is removed from its place so if the data had dimensions 0,1,2,3
and the call moveData(1, 3) was made the dimensions would become 0,2,1,3 not 0,2,3,1
*/
void DataInterface::moveData(int indexOfDimension, int indexOfInsertion) {
	if (indexOfDimension >= getDimensionAmount() || indexOfDimension < 0) {
		return;
	}
	if (indexOfInsertion > getDimensionAmount()) {
		indexOfInsertion = getDimensionAmount();
	}
	if (indexOfInsertion < 0) {
		indexOfInsertion = 0;
	}
	// check if the insertion at the end
	if (indexOfInsertion == getDimensionAmount()) {
		dataDimensions.push_back(dataDimensions[indexOfDimension]);
		dataDimensions.erase(dataDimensions.begin() + indexOfDimension);
		return;
	}
	// place the dimension in the new position
	dataDimensions.insert(dataDimensions.begin() + indexOfInsertion, dataDimensions[indexOfDimension]);
	// remove the dimension from the old position
	if (indexOfDimension <= indexOfInsertion) {
		dataDimensions.erase(dataDimensions.begin() + indexOfDimension);
	}
	else {
		dataDimensions.erase(dataDimensions.begin() + indexOfDimension + 1);
	}
}




// sets the name of the class at the passed index(classIndex) to the passed string(newName)
std::string * DataInterface::getDimensionName(int dimensionIndex) {
	if (dimensionIndex >= dataDimensions.size() || dimensionIndex < 0) {
		return nullptr;
	}
	return dataDimensions[dimensionIndex]->getName();
}

// gets the name of the class at the passed index(classIndex)
void DataInterface::setDimensionName(int dimensionIndex, string * newName) {
	if (dimensionIndex >= dataDimensions.size() || dimensionIndex < 0) {
		return;
	}
	dataDimensions[dimensionIndex]->setName(newName);
}

/*
// sets the calibration to use the data's(not the artificial) maximum and minimum in dimension at the passed index(dimensionIndex), of the dimension at the passed index(dimensionIndex)
void DataInterface::clearArtificialCalibration(int dimensionIndex) {
	if (dimensionIndex >= dataDimensions.size() || dimensionIndex < 0) {
		return;
	}
	return dataDimensions[dimensionIndex]->clearArtificialCalibration();
}

// sets the bounds to be used for artificial calibration at the passed index(dimensionIndex)
void DataInterface::setCalibrationBounds(int dimensionIndex, double newMaximum, double newMinimum) {
	if (dimensionIndex >= dataDimensions.size() || dimensionIndex < 0) {
		return;
	}
	return dataDimensions[dimensionIndex]->setCalibrationBounds(newMaximum, newMinimum);
}

// gets the artificial maximum for the dimension at the passed index(dimensionIndex)
double DataInterface::getArtificialMaximum(int dimensionIndex) const {
	if (dimensionIndex >= dataDimensions.size() || dimensionIndex < 0) {
		return 1.0;
	}
	return dataDimensions[dimensionIndex]->getArtificialMaximum();
}

// gets the artificial minimum for the dimension at the passed index(dimensionIndex)
double DataInterface::getArtificialMinimum(int dimensionIndex) const {
	if (dimensionIndex >= dataDimensions.size() || dimensionIndex < 0) {
		return 0.0;
	}
	return dataDimensions[dimensionIndex]->getArtificialMinimum();
}
*/
// add the passed double(amountToAdd) to all the data in the dimension at the index(dimensionIndex)
void DataInterface::addToDimension(int dimensionIndex, double amountToAdd) {
	// don't accept out of bounds data set indexes
	if (dimensionIndex >= getDimensionAmount() || dimensionIndex < 0) {
		return;
	}
	dataDimensions[dimensionIndex]->addToData(amountToAdd);
}





// gets the name of the class at the passed index
// full implementation after file parsing
string* DataInterface::getClassName(int classIndex) {
	if (dataClasses.size() >= classIndex || classIndex < 0) {
		return nullptr;
	}
	return dataClasses[classIndex].getName();
}

// sets the name of the class at the passed index to the passed string and returns the old name
// full implementation after file parsing
void DataInterface::setClassName(int classIndex, string* newName) {
	if (dataClasses.size() >= classIndex || classIndex < 0) {
		return;
	}
	dataClasses[classIndex].setName(newName);
}

/*
Gets the number of sets in the class at the passed index(classIndex)
*/
int DataInterface::getSetAmount(int classIndex) const {
	if (classIndex < 0 || classIndex >= getClassAmount()) {
		return -1;
	}
	return dataClasses[classIndex].getSetNumber();
}

// sets the name of the class at the passed index(classIndex) to the passed string(newName)
std::vector<double>* DataInterface::getColor(int classIndex) {
	if (classIndex < 0 || classIndex >= dataClasses.size()) {
		return dataClasses[0].getColor();
	}
	return dataClasses[classIndex].getColor();
}
/*
Gets the number of sets in the class at the passed index(classIndex)
*/
void DataInterface::setColor(int classIndex, std::vector<double>* newColor) {
	if (classIndex < 0 || classIndex >= dataClasses.size()) {
		return;
	}

	dataClasses[classIndex].setColor(newColor);
}





// gets the name of the set at the pased index
// full implementation after file parsing
string* DataInterface::getSetName(int setIndex) {
	// check for invalid indexes
	if (setIndex >= this->getSetAmount() || setIndex < 0) {
		return nullptr;
	}
	// get the set name
	return dataSets[setIndex].getName();
}

// sets the name of the set at the passed index to the passed string and returns the old name
// full implementation after file parsing
void DataInterface::setSetName(int setIndex, string  &newName) {
	// check for invalid indexes
	if (setIndex >= this->getSetAmount() || setIndex < 0) {
		return;
	}
	// get the set name
	dataSets[setIndex].setName(newName);
}
/*
returns the index of the class containing the set at the passed index
returns -1 if the passed set index is out of bounds
*/
int DataInterface::getClassOfSet(int indexOfSet) const {
	// check if indexes are in bounds
	if (indexOfSet >= dataDimensions.size() || indexOfSet < 0) {
		return -1;
	}
	return this->dataSets[indexOfSet].getClass();
}
// sets the index data class of the set at the passed index(setIndex)
int DataInterface::setSetClass(int setIndex, int newClassIndex) {
	if (setIndex >= this->getSetAmount() || setIndex < 0) {
		return -1;
	}
	if (newClassIndex >= this->getClassAmount() || newClassIndex < 0) {
		return -1;
	}
	dataClasses[dataSets[setIndex].getClass()].decrementSetNumber();
	dataClasses[newClassIndex].incrementSetNumber();
	return dataSets[setIndex].setDataClass(newClassIndex);
}

// gets the color the set should be painted
std::vector<double>* DataInterface::getSetColor(int setIndex) {
	if (setIndex >= this->getSetAmount() || setIndex < 0) {
		return dataClasses[0].getColor();
	}
	if (setIndex == selectedSetIndex) {
		return getSelectedSetColor();
	}
	return dataClasses[dataSets[setIndex].getClass()].getColor();
}

// gets the name of the x-axis
// full implementation after file parsing
std::string * DataInterface::getXAxisName() {
	return nullptr;
}

// gets the name of the y-axis
// full implementation after file parsing
string* DataInterface::getYAxisName() {
	return nullptr;
}

// gets the name of the maximum of the y axis
// full implementation after file parsing
string* DataInterface::getYMaxName() {
	return nullptr;
}

// gets the name of the minimum of the y axis
// full implementation after file parsing
string* DataInterface::getYMinName() {
	return nullptr;
}





// sorts the dimensions in ascending order by the data corresponding to the passed set index
void DataInterface::sortAscending(int setIndex) {
	if (setIndex >= this->getSetAmount() || setIndex < 0) {
		return;
	}
	// construct list to sort
	std::list<Dimension*> totalList = std::list<Dimension*>();
	std::list<Dimension*>* ptrTotalList = &totalList;
	for (int i = 0; i < dataDimensions.size(); i++) {
		totalList.push_back(dataDimensions[i]);
	}
	ptrTotalList = mergeSortAscending(ptrTotalList, setIndex);

	// read sorted dimensions back into vector
	for (int i = 0; i < dataDimensions.size(); i++) {
		dataDimensions[i] = ptrTotalList->front();
		ptrTotalList->pop_front();
	}
}

// sorts the dimensions in descending order by the data corresponding to the passed set index(setIndex)
void DataInterface::sortDescending(int setIndex) {
	if (setIndex >= this->getSetAmount() || setIndex < 0) {
		return;
	}
	// construct list to sort
	std::list<Dimension*> totalList = std::list<Dimension*>();
	std::list<Dimension*>* ptrTotalList = &totalList;
	for (int i = 0; i < dataDimensions.size(); i++) {
		totalList.push_back(dataDimensions[i]);
	}
	ptrTotalList = mergeSortDescending(ptrTotalList, setIndex);

	// read sorted dimensions back into vector
	for (int i = 0; i < dataDimensions.size(); i++) {
		dataDimensions[i] = ptrTotalList->front();
		ptrTotalList->pop_front();
	}
}

// places the dimensions back in the original order
void DataInterface::sortOriginal() {
	// construct list to sort
	std::list<Dimension*> totalList = std::list<Dimension*>();
	std::list<Dimension*>* ptrTotalList = &totalList;
	for (int i = 0; i < dataDimensions.size(); i++) {
		totalList.push_back(dataDimensions[i]);
	}
	ptrTotalList = mergeSortOriginal(ptrTotalList);

	// read sorted dimensions back into vector
	for (int i = 0; i < dataDimensions.size(); i++) {
		dataDimensions[i] = ptrTotalList->front();
		ptrTotalList->pop_front();
	}
}





// shifts all the data of the passed set to the passed value
void DataInterface::level(int setIndex, double levelValue) {
	// don't accept out of bounds data set indexes
	if (setIndex >= getSetAmount() || setIndex < 0) {
		return;
	}
	// adjust each data point to the new 0 amount for its dimension
	for (unsigned int i = 0; i < getDimensionAmount(); i++) {
		double currentData = getData(setIndex, i);
		double change = levelValue - currentData;
		// change data
		(*dataDimensions[i]).shiftDataBy(change);
	}
}

// gets the mean data value of the set at the passed index
double DataInterface::getMean(int setIndex) const {
	// don't accept out of bounds data set indexes
	if (setIndex >= getSetAmount() || setIndex < 0) {
		return 0.0;
	}
	double sum = 0.0;
	// adjust each data point to the new 0 amount for its dimension
	for (unsigned int i = 0; i < getDimensionAmount(); i++) {
		double currentData = getData(setIndex, i);
		sum += currentData;
	}
	return sum /= ((double)getDimensionAmount());
}

// gets the median data value of the set at the passed index
double DataInterface::getMedian(int setIndex) const {
	// don't accept out of bounds data set indexes
	if (setIndex >= getSetAmount() || setIndex < 0) {
		return 0.0;
	}
	if (getDimensionAmount() == 0) {
		return 0.0;
	}
	// make a vector to hold the set data
	vector<double> setData = vector<double>();
	// adjust each data point to the new 0 amount for its dimension
	for (unsigned int i = 0; i < getDimensionAmount(); i++) {
		double currentData = getData(setIndex, i);
		setData.push_back(currentData);
	}
	stable_sort(setData.begin(), setData.end());
	// acount for an even number of dimensions
	if (setData.size() % 2 == 1) {
		double first = setData[setData.size() / 2];
		double second = setData[setData.size() / 2 - 1];
		return (first + second) / 2.0;
	}
	return setData[setData.size() / 2 - 1];

}

// calibrate each dimension to the [0,1] space
void DataInterface::calibrateData() {
	for (unsigned int i = 0; i < getDimensionAmount(); i++) {
		(*dataDimensions[i]).calibrateData();
	}
}





// compares the data of a each set to the set at the passed index and checks if the data is within the radius of the data of the passed set
void DataInterface::hypercube(int setIndex, double radius) {
	// don't accept out of bounds data set indexes
	if (setIndex >= getSetAmount() || setIndex < 0) {
		return;
	}
	if (radius < 0) {
		return;
	}
	for (int i = 0; i < getSetAmount(); i++) {
		bool setIsWithinMargin = true;
		// check if the set is the set being compared to
		if (i == setIndex) {
			// do nothing just don't bother checking if the set is within the radius because it is
		}
		else {
			// find if set is within the radius of the hypercube
			for (int j = 0; j < getDimensionAmount(); j++) {
				double compareToSetData = getData(setIndex, j);
				double checkSetData = getData(i, j);
				if (abs(compareToSetData - checkSetData) > radius) {
					setIsWithinMargin = false;
					j = getDimensionAmount();
				}
			}
		}
		// add set to the list of selected sets if it should be
		/*
		if (setIsWithinMargin) {
			this->selectedSets.push_back(i);
		}
		*/
	}
}





// sets the index of the selected set to the passed index(newSelectedSetIndex)
void DataInterface::setSelectedSetIndex(int newSelectedSetIndex) {
	if (newSelectedSetIndex < 0 || newSelectedSetIndex >= getSetAmount()) {
		newSelectedSetIndex = getSetAmount() - 1;
	}
	selectedSetIndex = newSelectedSetIndex;
}

// gets the index of the selected set
int DataInterface::getSelectedSetIndex() const {
	return selectedSetIndex;
}

// sets the selected set's color to the colors in the passed double array(newSelectedSetColor)
void DataInterface::setSelectedSetColor(std::vector<double> &newSelectedSetColor) {
	selectedSetColor.setRed(newSelectedSetColor[0]);
	selectedSetColor.setGreen(newSelectedSetColor[1]);
	selectedSetColor.setBlue(newSelectedSetColor[2]);
	selectedSetColor.setAlpha(newSelectedSetColor[3]);
}

// gets the color of the selected set
std::vector<double>* DataInterface::getSelectedSetColor() {
	return selectedSetColor.getColorComponents();
}





// private:
// a method to hold the basic intialization of the object fields
void DataInterface::init() {
	dataDimensions = std::vector<Dimension*>();
	// create and set the fields
	dataClasses = std::vector<DataClass>();
	dataClasses.push_back(DataClass(0, "Default"));
	dataSets = std::vector<DataSet>();

	selectedSetColor = ColorCustom();

	selectedSetIndex = 0;

	yMaxName = "1.0";
	yMinName = "0.0";
	xAxisName = "X-Axis";
	yAxisName = "Y-Axis";

}

std::vector<std::vector<std::string>*>* DataInterface::readFileIntoVector(std::string* fileName) {
	std::ifstream file(*fileName);
	std::string str;
	std::stringstream ss;
	std::vector<std::vector<std::string>*>* fileLines = new std::vector<std::vector<std::string>*>();
	// read data
	while (std::getline(file, str))
	{
		int tokenStart = 0;
		int tokenEnd = 0;
		// ignore empty lines
		if (str.size() == 0) {

		}
		else {
			// make new data set
			std::vector<std::string>* newTokens = tokenizeString(&str);
			fileLines->push_back(newTokens);
		}
	}
	ss.clear();
	file.close();
	// validate file
	// check that file had at least one none empty line
	if (fileLines->size() <= 0) {
		return nullptr;
	}

	return fileLines;
}

// takes the passed string and tokenizes it by commas
std::vector<std::string>* DataInterface::tokenizeString(std::string * stringToTokenize) {
	std::vector<std::string>* stringTokens = new std::vector<std::string>();
	if (stringToTokenize->size() <= 0) {
		return stringTokens;
	}
	int startToken = 0;
	int endToken = stringToTokenize->find_first_of(',', startToken);
	int lengthToken = endToken - startToken;
	if (endToken == std::string::npos) {
		endToken = stringToTokenize->size();
	}
	// parse string
	while (startToken < stringToTokenize->size()) {
		// parse token
		std::string currentToken = (stringToTokenize->substr(startToken, lengthToken));
		// add the new token to the next
		stringTokens->push_back(currentToken);
		// find next token
		startToken = endToken + 1;
		endToken = stringToTokenize->find_first_of(',', startToken);
		if (endToken == std::string::npos) {
			endToken = stringToTokenize->size();
		}
		lengthToken = endToken - startToken;
	}
	return stringTokens;
}

// removes duplicate strings from the passed vector
void DataInterface::removeDuplicates(std::vector<std::string>* stringList) {
	std::vector<std::string> uniqueList = std::vector<std::string>();
	for (int i = 0; i < stringList->size(); i++) {
		std::string newClassName = (*stringList)[i];
		// check if the class already exists
		bool isNewClass = true;
		for (int j = 0; j < uniqueList.size(); j++) {
			if (uniqueList[j] == newClassName) {
				isNewClass = false;
				j = uniqueList.size();
			}
		}
		if (isNewClass) {
			uniqueList.push_back(newClassName);
		}
	}
	stringList->clear();

	for (int i = 0; i < uniqueList.size(); i++) {
		stringList->push_back(uniqueList[i]);
	}
}

// reads the contents of the file, at fileName, into a vector
void DataInterface::readBasicFile(std::vector<std::vector<std::string>*>* fileContents) {
	// check that each line had the same number of tokens
	int tokenNumber = (*fileContents)[0]->size();
	for (int i = 0; i < fileContents->size(); i++) {
		if (tokenNumber != (*fileContents)[i]->size()) {
			return;
		}
	}

	// get number of sets
	int setNumber = fileContents->size();
	// get dimension names
	std::vector<std::string> headers = std::vector<std::string>((*fileContents)[0]->size());
	for (int i = 0; i < (*fileContents)[0]->size(); i++) {
		string newDimensionName = (*(*fileContents)[0])[i];
		dataDimensions.push_back(new Dimension(i, setNumber));
	}

	// create data sets
	for (int i = 0; i < setNumber; i++) {
		dataSets.push_back(DataSet(i, 0));
	}
	int temp = dataDimensions.size();
	temp = dataSets.size();
	// read data into dimensions
	for (int i = 0; i < (*fileContents)[0]->size(); i++) {
		Dimension* currentDimension = dataDimensions[i];
		for (int j = 0; j < fileContents->size(); j++) {
			double newData = std::stod((*(*fileContents)[j])[i]);
			currentDimension->setData(j, newData);
		}
		currentDimension->calibrateData();
	}

	dataClasses.clear();
	dataClasses.push_back(DataClass(0, "Default"));
}

// reads the contents of the file, at fileName, into a vector
void DataInterface::readCustomFile(std::vector<std::vector<std::string>*>* fileContents) {
	// check that each line had the same number of tokens
	int tokenNumber = (*fileContents)[0]->size();
	for (int i = 0; i < fileContents->size(); i++) {
		if (tokenNumber != (*fileContents)[i]->size()) {
			return;
		}
	}
	// get number of sets
	int setNumber = fileContents->size() - 1;
	// get dimension names
	std::vector<std::string> headers = std::vector<std::string>((*fileContents)[0]->size() - 2);
	for (int i = 2; i < (*fileContents)[0]->size(); i++) {
		string newDimensionName = (*(*fileContents)[0])[i];
		dataDimensions.push_back(new Dimension(i - 2, setNumber));
	}
	// get set classes
	std::vector<std::string>* setClassNames = new std::vector<std::string>();
	for (int i = 1; i < fileContents->size(); i++) {
		setClassNames->push_back((*(*fileContents)[i])[0]);
	}
	removeDuplicates(setClassNames);
	// create classes
	for (int i = 0; i < setClassNames->size(); i++) {
		dataClasses.push_back(DataClass(i + 1, (*setClassNames)[i]));
	}


	// create data sets

	for (int i = 1; i < fileContents->size(); i++) {
		std::string newSetName = (*(*fileContents)[i])[1];
		std::string setClassName = (*(*fileContents)[i])[0];
		int classIndex = 0;
		for (int j = 0; j < dataClasses.size(); i++) {
			if ((*setClassNames)[j] == setClassName) {
				classIndex = j + 1;
			}
		}
		dataSets.push_back(DataSet(i - 1, classIndex));
	}

	for (int i = 2; i < (*fileContents)[0]->size(); i++) {
		Dimension* currentDimension = dataDimensions[i - 2];
		for (int j = 1; j < fileContents->size(); j++) {
			double newData = std::stod((*(*fileContents)[j])[i]);
			currentDimension->setData(j - 1, newData);
		}
		currentDimension->calibrateData();
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





// an ascending(left to right) merge sort of the passed dimension list by the set at the passed index
std::list<Dimension*>* DataInterface::mergeSortAscending(std::list<Dimension*>* listToSort, int setIndex) {
	if (listToSort->size() <= 1) {
		return listToSort;
	}
	std::list<Dimension*> leftList = std::list<Dimension*>();
	std::list<Dimension*>* ptrLeftList = &leftList;
	std::list<Dimension*> rightList = std::list<Dimension*>();
	std::list<Dimension*>* ptrRightList = &rightList;
	// split list
	while (listToSort->size() > 0) {
		// pop element for left list
		Dimension* currentDimension = listToSort->front();
		listToSort->pop_front();
		leftList.push_back(currentDimension);
		// pop element for right list
		if (listToSort->size() > 0) {
			currentDimension = listToSort->back();
			listToSort->pop_back();
			ptrRightList->push_front(currentDimension);
		}
	}
	// sort the split list
	ptrLeftList = mergeSortAscending(ptrLeftList, setIndex);
	ptrRightList = mergeSortAscending(ptrRightList, setIndex);


	// merge lists back together in sorted order
	while (ptrLeftList->size() > 0 && ptrRightList->size() > 0) {
		double dataLeft = ptrLeftList->front()->getData(setIndex);
		double dataRight = ptrRightList->front()->getData(setIndex);
		// find which to take
		if (dataLeft <= dataRight) {
			listToSort->push_back(ptrLeftList->front());
			ptrLeftList->pop_front();
		}
		else {
			listToSort->push_back(ptrRightList->front());
			ptrRightList->pop_front();
		}
	}
	// get the remaining dimensions
	while (ptrLeftList->size() > 0) {
		listToSort->push_back(ptrLeftList->front());
		ptrLeftList->pop_front();
	}
	while (ptrRightList->size() > 0) {
		listToSort->push_back(ptrRightList->front());
		ptrRightList->pop_front();
	}
	return listToSort;
}

// an descending(left to right) merge sort of the passed dimension list by the set at the passed index
std::list<Dimension*>* DataInterface::mergeSortDescending(std::list<Dimension*>* listToSort, int setIndex) {
	if (listToSort->size() <= 1) {
		return listToSort;
	}

	std::list<Dimension*> leftList = std::list<Dimension*>();
	std::list<Dimension*>* ptrLeftList = &leftList;
	std::list<Dimension*> rightList = std::list<Dimension*>();
	std::list<Dimension*>* ptrRightList = &rightList;
	// split list
	while (listToSort->size() > 0) {
		// pop element for left list
		Dimension* currentDimension = listToSort->front();
		listToSort->pop_front();
		leftList.push_back(currentDimension);
		// pop element for right list
		if (listToSort->size() > 0) {
			currentDimension = listToSort->back();
			listToSort->pop_back();
			rightList.push_front(currentDimension);
		}
	}
	// sort the split list
	ptrLeftList = mergeSortDescending(ptrLeftList, setIndex);
	ptrRightList = mergeSortDescending(ptrRightList, setIndex);


	// merge lists back together in sorted order
	while (ptrLeftList->size() > 0 && ptrRightList->size() > 0) {
		double dataLeft = ptrLeftList->front()->getData(setIndex);
		double dataRight = ptrRightList->front()->getData(setIndex);
		// find which to take
		if (dataLeft >= dataRight) {
			listToSort->push_back(ptrLeftList->front());
			ptrLeftList->pop_front();
		}
		else {
			listToSort->push_back(ptrRightList->front());
			ptrRightList->pop_front();
		}
	}
	// get the remaining dimensions
	while (ptrLeftList->size() > 0) {
		listToSort->push_back(ptrLeftList->front());
		ptrLeftList->pop_front();
	}
	while (ptrRightList->size() > 0) {
		listToSort->push_back(ptrRightList->front());
		ptrRightList->pop_front();
	}
	return listToSort;
}

// sorts the dimensions to their original places in a merge sort
std::list<Dimension*>* DataInterface::mergeSortOriginal(std::list<Dimension*>* listToSort) {
	if (listToSort->size() <= 1) {
		return listToSort;
	}

	std::list<Dimension*> leftList = std::list<Dimension*>();
	std::list<Dimension*>* ptrLeftList = &leftList;
	std::list<Dimension*> rightList = std::list<Dimension*>();
	std::list<Dimension*>* ptrRightList = &rightList;
	// split list
	while (listToSort->size() > 0) {
		// pop element for left list
		Dimension* currentDimension = listToSort->front();
		listToSort->pop_front();
		leftList.push_back(currentDimension);
		// pop element for right list
		if (listToSort->size() > 0) {
			currentDimension = listToSort->back();
			listToSort->pop_back();
			rightList.push_front(currentDimension);
		}
	}
	// sort the split list
	ptrLeftList = mergeSortOriginal(ptrLeftList);
	ptrRightList = mergeSortOriginal(ptrRightList);


	// merge lists back together in sorted order
	while (ptrLeftList->size() > 0 && ptrRightList->size() > 0) {
		int indexLeft = ptrLeftList->front()->getOriginalIndex();
		int indexRight = ptrRightList->front()->getOriginalIndex();
		// find which to take
		if (indexLeft <= indexRight) {
			listToSort->push_back(ptrLeftList->front());
			ptrLeftList->pop_front();
		}
		else {
			listToSort->push_back(ptrRightList->front());
			ptrRightList->pop_front();
		}
	}
	// get the remaining dimensions
	while (ptrLeftList->size() > 0) {
		listToSort->push_back(ptrLeftList->front());
		ptrLeftList->pop_front();
	}
	while (ptrRightList->size() > 0) {
		listToSort->push_back(ptrRightList->front());
		ptrRightList->pop_front();
	}
	return listToSort;
}

