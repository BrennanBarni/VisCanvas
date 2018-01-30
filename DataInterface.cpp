#include "stdafx.h"

using namespace std;
/*
int main() {
	std::string fileName = "C:\\Users\\Shane Vance\\Desktop\\test1.txt";
	DataInterface* test = new DataInterface();
	test->readFile(&fileName);
	std::cout << test->getClassAmount();
	std::cout << test->getSetAmount();
	std::cout << test->getSetAmount();
	for (unsigned int i = 0; i < test->getSetAmount(); i++) {
		std::cout << "\n" << *(test->getSetName(i));
		for (unsigned int j = 0; j < test->getDimensionAmount(); j++) {
			std::cout << "\t" << test->getData(i, j);
		}
	}
	system("Pause");
}
*/
DataInterface::DataInterface() {
	init();
}

// create the data interface
// full implementation after file parsing
DataInterface::DataInterface(string* filePath) {
	// create and set the fields
	init();

	// read data from file
	readFile(filePath);

}

DataInterface::~DataInterface() {
	for (unsigned int i = 0; i < dataDimensions.size(); i++) {
		delete dataDimensions[i];
	}
}

// parse the data in the file at the passed path into the object
void DataInterface::readFile(string * filePath) {
	// reset the appropriate fields
	dataDimensions.clear();
	dataClasses.clear();
	dataClasses.push_back(DataClass(0, "Default"));
	dataSets.clear();
	selectedSetIndex = 0;

	// read the file
	std::fstream inStream; // calls function to read from file
	inStream.open(*filePath); // open the file

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
	// calculate the number of dimensions, -1 for header line, -1 for empty line at end
	int numberOfLines = lines.size() - 2;
	// make list of possible seperators
	vector<char> seperators = vector<char>();
	seperators.push_back(',');
	seperators.push_back(';');
	int numberOfDimensions = countCharacters(&seperators, &lines[1]) + 1;
	for (unsigned int i = 0; i < numberOfDimensions; i++) {
		dataDimensions.push_back(new Dimension(i, numberOfLines));
	}


	// parse lines
	for (unsigned int i = 1; i < numberOfLines + 1; i++) {
		string currentLine = lines[i];
		dataSets.push_back(DataSet(i, 0));
		dataClasses[0].decrementSetNumber();
		int start = 0;
		int tokenLength = 0;
		for (unsigned int j = 0; j < numberOfDimensions; j++) {
			int nextToken = -1;
			// find index of next seperator
			for (unsigned int k = 0; k < seperators.size(); k++) {
				// check each seperator and find the smallest token
				int indexOfSeperator = currentLine.find_first_of(seperators[k]);
				if (indexOfSeperator > 0) {
					if (indexOfSeperator < nextToken || nextToken == -1) {
						nextToken = indexOfSeperator;
					}
				}
			}
			// find the length of the current token
			if (nextToken > 0) {
				tokenLength = nextToken;
			}
			else {
				tokenLength = currentLine.size();
			}
			// get the token
			string currentToken = currentLine.substr(start, tokenLength);
			// remove token from the current string
			if (tokenLength == currentLine.size()) {
				currentLine = "";
			}
			else {
				currentLine = currentLine.substr(tokenLength + 1, currentLine.size() - tokenLength); 
			}
			/* STOD CAUSING AN ERROR HERE USE THE FOLLOWING AS A FIX MAYBE? */   
			//regex regex_pattern("-?[0-9]+.?[0-9]+");
			//if(regex_match(currentToken, regex_pattern))
			// parse token into number and add it to the data structure in the correct place
			
			string::size_type sz;     // alias of size_t
			double newNumber = stod(currentToken, &sz);
			dataDimensions[j]->setData(i - 1, newNumber);
		}
	}
	calibrateData();
}



// gets the number of classes in the data
const int DataInterface::getClassAmount() {
	return dataClasses.size();
}


/*
 Gets the total number of sets in the data
 full implementation after file parsing
*/
const int DataInterface::getSetAmount() {
	if (dataDimensions.size() == 0) {
		return 0;
	}
	return (*dataDimensions[0]).getDimensionSize();
}

/*
Gets the number of sets in the class at the passed index(classIndex)
*/
const int DataInterface::getSetAmount(int classIndex) {
	if (classIndex < 0 || classIndex >= getClassAmount()) {
		return -1;
	}
	return dataClasses[classIndex].getSetNumber();
}

// gets the number of dimensions in the data
const int DataInterface::getDimensionAmount() {
	return dataDimensions.size();
}

// gets the data in the passed set at the passed index
double DataInterface::getData(int indexOfSet, int indexOfData) {
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
returns the index of the class containing the set at the passed index
returns -1 if the passed set index is out of bounds
*/
const int DataInterface::getClassofSet(int indexOfSet) {
	// check if indexes are in bounds
	if (indexOfSet >= dataDimensions.size() || indexOfSet < 0) {
		return -1;
	}
	this->dataSets[indexOfSet].getClass();
}

/*
moves the position of a dimensions from the passed index(indexOfDimension) to after the other passed index(indexBeforeInsertion)
Note: the new position is calculated before the dimension being moved is removed from its place so if the data had dimensions 0,1,2,3
and the call moveData(1, 2) was made the dimensions would become 0,2,1,3 not 0,2,3,1
*/
void DataInterface::moveData(int indexOfDimension, int indexOfInsertion) {
	if (indexOfDimension >= getDimensionAmount() || indexOfDimension < 0) {
		return;
	}
	if (indexOfInsertion > getDimensionAmount() || indexOfInsertion < 0) {
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

// gets the name of the class at the passed index
// full implementation after file parsing
const string* DataInterface::getClassName(unsigned int classIndex) {
	if (dataClasses.size() >= classIndex) {
		return nullptr;
	}
	return dataClasses[classIndex].getName();
}

// sets the name of the class at the passed index to the passed string and returns the old name
// full implementation after file parsing
string* DataInterface::setClassName(unsigned int classIndex, string* newName) {
	if (dataClasses.size() >= classIndex) {
		return nullptr;
	}

	return dataClasses[classIndex].setName(newName);
}

// gets the name of the set at the pased index
// full implementation after file parsing
const string* DataInterface::getSetName(unsigned int setIndex) {
	// check for invalid indexes
	if (setIndex >= this->getSetAmount()) {
		return nullptr;
	}
	// get the set name
	return dataSets[setIndex].getName();
}

// sets the name of the set at the passed index to the passed string and returns the old name
// full implementation after file parsing
string* DataInterface::setSetName(unsigned int setIndex, string* newName) {
	// check for invalid indexes
	if (setIndex >= this->getSetAmount()) {
		return nullptr;
	}
	// get the set name
	return dataSets[setIndex].setName(newName);
}

// gets the index of the data class of the set at the passed index
const int DataInterface::getSetClass(unsigned int setIndex) {
	if (setIndex >= this->getSetAmount()) {
		return 0;
	}

	return dataSets[setIndex].getClass();
}

// sets the index data class of the set at the passed index(setIndex)
int DataInterface::setSetClass(unsigned int setIndex, unsigned int newClassIndex) {
	if (setIndex >= this->getSetAmount()) {
		return -1;
	}
	if (newClassIndex >= this->getClassAmount()) {
		return -1;
	}
	dataClasses[dataSets[setIndex].getClass()].decrementSetNumber();
	dataClasses[newClassIndex].decrementSetNumber();
	return dataSets[setIndex].setDataClass(newClassIndex);
}

// gets a copy of the color the set should be painted
const float * DataInterface::getSetColor(unsigned int setIndex)
{
	if (setIndex >= this->getSetAmount()) {
		return dataClasses[0].getColor();
	}
	if (setIndex == this->getSelectedSetIndex()) {
		return getSelectedSetColor();
	}
	return dataClasses[dataSets[setIndex].getClass()].getColor();
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

// shifts all the data of the passed set to the passed value
void DataInterface::level(unsigned int setIndex, double levelValue) {
	// don't accept out of bounds data set indexes
	if (setIndex >= getSetAmount()) {
		return;
	}
	// adjust each data point to the new 0 amount for its dimension
	for (unsigned int i = 0; i < getDimensionAmount(); i++) {
		double currentData = getData(setIndex, i);
		double change = levelValue - currentData;
		// change data
		(*dataDimensions[i]).addToData(change);
	}
}

// gets the mean data value of the set at the passed index
const double DataInterface::getMean(unsigned int setIndex) {
	// don't accept out of bounds data set indexes
	if (setIndex >= getSetAmount()) {
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
const double DataInterface::getMedian(unsigned int setIndex) {
	// don't accept out of bounds data set indexes
	if (setIndex >= getSetAmount()) {
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

// creates a string representation of the data and settings in this class
// full implementation after file parsing
const string* DataInterface::saveData(string* filePath) {

	return nullptr;
}


const float * DataInterface::getColor(unsigned int classIndex) {
	if (classIndex < 0) {
		classIndex = 0;
	}
	else if (classIndex >= dataClasses.size()) {
		classIndex = 0;
	}
	return dataClasses[classIndex].getColor();
}

void DataInterface::setColor(unsigned int classIndex, float * newColor) {
	if (classIndex >= dataClasses.size()) {
		return;
	}

	dataClasses[classIndex].setColor(newColor);
}

void DataInterface::setSelectedSetIndex(unsigned int newSelectedSetIndex) {
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


void DataInterface::init() {
	dataDimensions = vector<Dimension*>();
	// create and set the fields
	dataClasses = vector<DataClass>();
	dataClasses.push_back(DataClass(0, "Default"));
	dataSets = vector<DataSet>();
	selectedSetColor = ColorCustom();
	selectedSetIndex = 0;
	yMaxName = "1.0";
	yMinName = "0.0";
	xAxisName = "X-Axis";
	yAxisName = "Y-Axis";

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
			if ((*dataDimensions[firstCounter]).getData(setIndex) < (*dataDimensions[secondCounter]).getData(setIndex)) {
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
			if ((*(dataDimensions[i])).getData(setIndex) > (*(dataDimensions[j])).getData(setIndex)) {
				double dataOne = (*(dataDimensions[i])).getData(setIndex);
				double dataTwo = (*(dataDimensions[j])).getData(setIndex);
				(*(dataDimensions[i])).setData(setIndex, dataTwo);
				(*(dataDimensions[j])).setData(setIndex, dataOne);
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
			if ((*(dataDimensions[firstCounter])).getData(setIndex) > (*(dataDimensions[secondCounter])).getData(setIndex)) {
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
			if ((*(dataDimensions[i])).getData(setIndex) < (*(dataDimensions[j])).getData(setIndex)) {
				double dataOne = (*(dataDimensions[i])).getData(setIndex);
				double dataTwo = (*(dataDimensions[j])).getData(setIndex);
				(*(dataDimensions[i])).setData(setIndex, dataTwo);
				(*(dataDimensions[j])).setData(setIndex, dataOne);
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

