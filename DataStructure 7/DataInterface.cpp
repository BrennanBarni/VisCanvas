#include "DataInterface.h"
#include "DataNode.h"
#include "Dimension.h"
#include "ColorCustom.h"
#include "DataClass.h"
#include "DataSet.h"
#include "SetCluster.h"

#include <vector>
#include <list>
#include <string> 
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;


int main() {
	std::string fileName = "C:\\Users\\danie\\Desktop\\test.csv";
	std::string fileName2 = "C:\\Users\\danie\\\Desktop\\Book3 - Copy.csv";
	DataInterface* test = new DataInterface();
	test->readFile(&fileName);
	// print sizes
	std::cout << "Class Amount: " << test->getClassAmount();
	std::cout << "\nSet Amount: " << test->getSetAmount();
	for (unsigned int i = 0; i < test->getSetAmount(); i++) {
		std::cout << "\n" << *(test->getSetName(i));
		for (unsigned int j = 0; j < test->getDimensionAmount(); j++) {
			std::cout << "\t" << test->getOriginalData(i, j);
		}
	}
	std::vector<double>* color = test->getSetColor(0);
	std::cout << "\n\n" << (*color)[0] << ", " << (*color)[1];
	std::cout << ", " << (*color)[2] << ", " << (*color)[3];

	/*
	test->addClass();
	std::string newClassName = "test";
	test->setClassName(1,&newClassName);
	std::vector<double> newColor = std::vector<double>();
	newColor.push_back(0.0);
	newColor.push_back(0.0);
	newColor.push_back(1.0);
	newColor.push_back(1.0);
	test->setClassColor(1, &newColor);
	test->setSetClass(0, 1);
	*/

	test->setUseMeanForClusters(true);
	//test->setCalibrationBounds(1, 10.0, -1.0);
	//test->sortAscending(4);
	test->level(4, test->getMean(4));
	//test->hypercube(2, 0.3);

	test->saveToFile(&fileName2);
	system("Pause");
}








// create a blank class without any data
DataInterface::DataInterface() {
	init();
	finalInit();
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
bool DataInterface::readFile(string * filePath) {
	std::vector<std::vector<std::string>*>* fileLines = readFileIntoVector(filePath);
	if (fileLines == nullptr) {
		return false;
	}
	if (fileLines->size() < 2) {
		return false;
	}
	if ((*fileLines)[0]->size() <= 0) {
		return false;
	}
	// find if a custom file or a basic file
	// find first none blank line
	bool isCustomFileFormat = false;
	if (isCustomFileFormat = ((*(*fileLines)[0])[0] == "VisCanvas Save File Format")) {
		isCustomFileFormat = true;
	}

	for (unsigned int i = 0; i < dataDimensions.size(); i++) {
		delete dataDimensions[i];
	}
	dataDimensions.clear();
	dataClasses.clear();
	dataSets.clear();
	clusters.clear();
	notes.clear();
	init();

	try {
		if (isCustomFileFormat) {
			readCustomFile(fileLines);
		}
		else {
			readBasicFile(fileLines);
		}
	}
	catch (...) {
		dataDimensions.clear();
		dataClasses.clear();
		dataSets.clear();
		clusters.clear();
		notes.clear();
		init();
		finalInit();
		return false;
	}
	// perform final setup operations
	finalInit();
	return true;
}


// saves the data and all settings to the file at the passed location
bool DataInterface::saveToFile(std::string * filePath) {
	ofstream saveFile;
	saveFile.open(*filePath);
	// check if file is open
	if (saveFile.is_open() == false) {
		return false;
	}
	// write file type identifier
	saveFile << "VisCanvas Save File Format,";
	saveFile << ",";
	// write dimension names
	for (int i = 0; i < getDimensionAmount(); i++) {
		saveFile << *(dataDimensions[i]->getName());
		if (i < getDimensionAmount() - 1) {
			saveFile << ",";
		}
	}
	saveFile << "\n";
	// write data sets, their class and data
	for (int j = 0; j < getSetAmount(); j++) {
		// write set class and name
		std::string className = *(getClassName(getClassOfSet(j)));
		std::string setName = *(getSetName(j));
		saveFile << className << "," << setName << ",";
		for (int i = 0; i < getDimensionAmount(); i++) {
			double currentData = dataDimensions[i]->getOriginalData(j);
			saveFile << currentData;
			if (i < getDimensionAmount() - 1) {
				saveFile << ",";
			}
		}
		saveFile << "\n";
	}
	// put space between data and commands
	saveFile << "\n\n";

	// write set classes
	saveFile << "classes\n";
	for (int i = 1; i < getClassAmount(); i++) {
		std::vector<double>* color = getClassColor(i);
		saveFile << (*getClassName(i)) << ",";
		saveFile << (*color)[0] << "," << (*color)[1] << "," << (*color)[2] << "," << (*color)[3];
		saveFile << "\n";
	}
	saveFile << "\n\n";



	saveFile << "Commands\n";


	// print dimension shifts
	for (int i = 0; i < getDimensionAmount(); i++) {
		double shift = dataDimensions[i]->getShift();
		// make sure shift is large enough to bother with
		if (abs(shift) > 0.001) {
			saveFile << "shift," << i << "," << shift << "\n";
		}
	}

	// print dimension bounds
	for (int i = 0; i < getDimensionAmount(); i++) {
		double min = dataDimensions[i]->getArtificialMinimum();
		double max = dataDimensions[i]->getArtificialMaximum();
		// make the artificial calibration exists
		if (dataDimensions[i]->isArtificiallyCalibrated()) {
			saveFile << "bounds," << i << "," << max << "," << min << "\n";
		}
	}

	// print dimension order
	saveFile << "original indexes,";
	for (int i = 0; i < getDimensionAmount(); i++) {
		int originalIndex = this->dataDimensions[i]->getOriginalIndex();
		saveFile << originalIndex;
		if (i < getDimensionAmount() - 1) {
			saveFile << ",";
		}
	}
	saveFile << "\n";

	/*
	// print class colors
	for (int i = 1; i < getClassAmount(); i++) {
	std::vector<double>* colorComponents = getClassColor(i);
	double red = (*colorComponents)[0];
	double green = (*colorComponents)[1];
	double blue = (*colorComponents)[2];
	double alpha = (*colorComponents)[3];
	// make the artificial calibration exists
	saveFile << "class Color," << *(getClassName(i)) << "," << i << "," << red << "," << green << "," << blue << "," << alpha << "\n";
	}
	*/

	// put hypercubes in file
	// hypercube,setindex,radius
	// read data
	for (int i = 0; i < getClusterAmount(); i++) {
		saveFile << "hypercube,";
		saveFile << clusters[i].getOriginalSet() << ",";
		saveFile << clusters[i].getRadius() << "\n";
	}

	// print whether to use mean or median for clusters
	saveFile << "useMean,";
	saveFile << useMean << "\n";

	// put artificial calibration in the list of 'commands'
	for (int i = 0; i < getDimensionAmount(); i++) {
		saveFile << "artificial calibration,";
		saveFile << i << ",";
		saveFile << dataDimensions[i]->isArtificiallyCalibrated() << ",";
		saveFile << dataDimensions[i]->getArtificialMaximum() << ",";
		saveFile << dataDimensions[i]->getArtificialMinimum() << "\n";
	}

	// put default class color in
	std::vector<double>* defaultClassColor = getClassColor(0);
	saveFile << "Default Class Color,";
	saveFile << (*defaultClassColor)[0] << ",";
	saveFile << (*defaultClassColor)[1] << ",";
	saveFile << (*defaultClassColor)[2] << ",";
	saveFile << (*defaultClassColor)[3] << ",";



	saveFile << "\n";
	saveFile.close();
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
double DataInterface::getData(int setIndex, int indexOfData) const {
	// check if indexes are in bounds
	if (setIndex >= getSetAmount() || setIndex < 0) {
		return 0.0;
	}
	if (indexOfData >= getDimensionAmount() || indexOfData < 0) {
		return 0.0;
	}

	// get data
	return (*dataDimensions[indexOfData]).getData(setIndex);
}

// gets the original data in the set of the passed index(setIndex), for the passed dimension(indexOfData)
double DataInterface::getOriginalData(int setIndex, int dimensionIndex) const {
	// check if indexes are in bounds
	if (setIndex >= getSetAmount() || setIndex < 0) {
		return 0.0;
	}
	if (dimensionIndex >= getDimensionAmount() || dimensionIndex < 0) {
		return 0.0;
	}

	// get data
	return (*dataDimensions[dimensionIndex]).getOriginalData(setIndex);
}


// sets the data in the set of the passed index(setIndex), for the passed dimension(indexOfData), to the passed value(newDataValue)
double DataInterface::setData(int setIndex, int indexOfData, double newDataValue) {
	// check if indexes are in bounds
	if (setIndex >= getSetAmount() || setIndex < 0) {
		return 0.0;
	}
	if (indexOfData >= getDimensionAmount() || indexOfData < 0) {
		return 0.0;
	}

	// get data
	double oldData = (*dataDimensions[indexOfData]).getOriginalData(setIndex);
	(*dataDimensions[indexOfData]).setData(setIndex, newDataValue);
	(*dataDimensions[indexOfData]).calibrateData();
	return oldData;
}

/*
moves the position of a dimensions from the passed index(indexOfDimension) to at the other passed index(indexOfInsertion)
Note: the new position is calculated before the dimension being moved is removed from its place so if the data had dimensions 0,1,2,3
and the call moveData(1, 3) was made the dimensions would become 0,2,1,3 not 0,2,3,1
*/
bool DataInterface::moveData(int indexOfDimension, int indexOfInsertion) {
	if (indexOfInsertion == -1 || indexOfDimension == -1) {
		return false;
	}
	if (indexOfInsertion >= getDimensionAmount() || indexOfDimension >= getDimensionAmount()) {
		return false;
	}

	// this will swap the data 
	Dimension *temp = dataDimensions[indexOfDimension];
	dataDimensions[indexOfDimension] = dataDimensions[indexOfInsertion];
	dataDimensions[indexOfInsertion] = temp;

	return true;
}




// gets the name of the class at the passed index(classIndex) to the passed string(newName)
std::string * DataInterface::getDimensionName(int dimensionIndex) {
	if (dimensionIndex >= dataDimensions.size() || dimensionIndex < 0) {
		return nullptr;
	}
	return dataDimensions[dimensionIndex]->getName();
}

// sets the name of the class at the passed index(classIndex)
void DataInterface::setDimensionName(int dimensionIndex, string * newName) {
	if (dimensionIndex >= dataDimensions.size() || dimensionIndex < 0) {
		return;
	}
	dataDimensions[dimensionIndex]->setName(newName);
}

// gets whether the calibration for the dimension(dimensionIndex) is artificial or relative
bool DataInterface::isArtificiallyCalibrated(int dimensionIndex) {
	if (dimensionIndex >= dataDimensions.size() || dimensionIndex < 0) {
		return false;
	}
	return dataDimensions[dimensionIndex]->isArtificiallyCalibrated();
}

// sets the calibration to use the data's(not the artificial) maximum and minimum in dimension at the passed index(dimensionIndex)
void DataInterface::clearArtificialCalibration(int dimensionIndex) {
	if (dimensionIndex >= dataDimensions.size() || dimensionIndex < 0) {
		return;
	}
	dataDimensions[dimensionIndex]->clearArtificialCalibration();
}

// sets the bounds to be used for artificial calibration at the passed index(dimensionIndex)
void DataInterface::setCalibrationBounds(int dimensionIndex, double newMaximum, double newMinimum) {
	if (dimensionIndex >= dataDimensions.size() || dimensionIndex < 0) {
		return;
	}

	// take care of this if the user puts the wrong input for min-max
	if (newMinimum > newMaximum) {
		// swap them
		double temp = newMinimum;
		newMinimum = newMaximum;
		newMaximum = temp;
	}

	dataDimensions[dimensionIndex]->setCalibrationBounds(newMaximum, newMinimum);
}
// gets the artificial maximum for the dimension at the passed index(dimensionIndex)
double DataInterface::getArtificialMaximum(int dimensionIndex) const {
	if (dimensionIndex >= dataDimensions.size() || dimensionIndex < 0) {
		return 0.0;
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
	if (classIndex >= dataClasses.size() || classIndex < 0) {
		return nullptr;
	}
	return dataClasses[classIndex].getName();
}

// sets the name of the class at the passed index to the passed string and returns the old name
// full implementation after file parsing
void DataInterface::setClassName(int classIndex, string* newName) {
	if (dataClasses.size() <= classIndex || classIndex < 0) {
		return;
	}
	dataClasses[classIndex].setName(newName);
}

// adds a new class to the list of classes
void DataInterface::addClass() {
	dataClasses.push_back(DataClass(dataClasses.size(), "Class " + std::to_string(dataClasses.size())));
}

// delete a class from the list of classes
void DataInterface::deleteClass(int classIndex) {
	// do not allow deletion of default class
	if (classIndex <= 0 || classIndex >= getClassAmount()) {
		return;
	}

	// put the sets in the class to be deleted in the default class
	for (int i = 0; i < this->getSetAmount(); i++) {
		if (dataSets[i].getClass() == classIndex) {
			dataSets[i].setDataClass(0);
		}
	}

	// delete the class
	dataClasses.erase(dataClasses.begin() + classIndex);
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

std::vector<int>* DataInterface::getSetsInClass(int classIndex) {
	// do not allow deletion of default class
	if (classIndex <= 0 || classIndex >= getClassAmount()) {
		return nullptr;
	}
	return dataClasses[classIndex].getSetsInClass();
}

// sets the name of the class at the passed index(classIndex) to the passed string(newName)
std::vector<double>* DataInterface::getClassColor(int classIndex) {
	if (classIndex < 0 || classIndex >= dataClasses.size()) {
		return dataClasses[0].getColor();
	}
	return dataClasses[classIndex].getColor();
}

/*
Gets the number of sets in the class at the passed index(classIndex)
*/
void DataInterface::setClassColor(int classIndex, std::vector<double>* newColor) {
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
int DataInterface::getClassOfSet(int setIndex) const {
	// check if indexes are in bounds
	if (setIndex >= this->getSetAmount() || setIndex < 0) {
		return -1;
	}
	return this->dataSets[setIndex].getClass();
}

// get the data set name for the class at the passed index
std::string *DataInterface::getSetOfClass(int classIndex, int setIndex) {
	if (setIndex >= this->getSetAmount() || setIndex < 0)
	{
		return nullptr;
	}

	if (classIndex >= this->getClassAmount() || classIndex < 0)
	{
		return nullptr;
	}
	std::string str = std::string("");
	if (this->dataSets[setIndex].getClass() == classIndex)
	{
		return this->dataSets[setIndex].getName();
	}
	else {
		return &str;
	}
}

// sets the index data class of the set at the passed index(setIndex)
int DataInterface::setSetClass(int setIndex, int newClassIndex) {
	if (setIndex >= this->getSetAmount() || setIndex < 0) {
		return -1;
	}
	if (newClassIndex >= this->getClassAmount() || newClassIndex < 0) {
		return -1;
	}
	dataClasses[dataSets[setIndex].getClass()].removeSet(setIndex);
	dataClasses[newClassIndex].addSet(setIndex);
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
	std::vector<double>* color = dataClasses[dataSets[setIndex].getClass()].getColor();
	if (isVisible(setIndex) == false) {
		(*color)[3] = 0.0;
	}
	return color;
}


// checks whether the set is visible or not
bool DataInterface::isVisible(int setIndex) {
	if (setIndex >= this->getSetAmount() || setIndex < 0) {
		return false;
	}
	if (setIndex == selectedSetIndex) {
		return getSelectedSetColor();
	}
	return dataSets[setIndex].isVisible();
}

// sets the set visible or not visible and returns the old visibility
bool DataInterface::setVisible(int setIndex, bool newVisible) {
	if (setIndex >= this->getSetAmount() || setIndex < 0) {
		return false;
	}
	if (setIndex == selectedSetIndex) {
		return getSelectedSetColor();
	}
	return dataSets[setIndex].setVisible(newVisible);
}





// gets the amount the dimension is shifted by
double DataInterface::getDimensionShift(int dimensionIndex) {
	if (dimensionIndex >= this->getDimensionAmount() || dimensionIndex < 0) {
		return 0.0;
	}
	return (*dataDimensions[dimensionIndex]).getShift();


}

// changes the shift of the dimension at the passed int to the passsed double
void DataInterface::setDimensionShift(int dimensionIndex, double shiftMod) {
	if (dimensionIndex >= this->getDimensionAmount() || dimensionIndex < 0) {
		return;
	}
	double currentShift = (*dataDimensions[dimensionIndex]).getShift();
	return (*dataDimensions[dimensionIndex]).shiftDataBy(shiftMod - currentShift);
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
	for (int i = 0; i < getClusterAmount(); i++) {
		clusters[i].calculateValues(&dataDimensions);
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
	for (int i = 0; i < getClusterAmount(); i++) {
		clusters[i].calculateValues(&dataDimensions);
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
	for (int i = 0; i < getClusterAmount(); i++) {
		clusters[i].calculateValues(&dataDimensions);
	}
}





// shifts all the data of the passed set to the passed value
void DataInterface::level(int setIndex, double levelValue) {
	// don't accept out of bounds data set indexes
	if (setIndex >= getSetAmount() || setIndex < 0) {
		return;
	}
	zeroShifts();
	// adjust each data point to the new 0 amount for its dimension
	for (unsigned int i = 0; i < getDimensionAmount(); i++) {
		double currentData = (*dataDimensions[i]).getCalibratedData(setIndex);
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
		double currentData = (*dataDimensions[i]).getCalibratedData(setIndex);
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
		double currentData = (*dataDimensions[i]).getCalibratedData(setIndex);
		setData.push_back(currentData);
	}
	stable_sort(setData.begin(), setData.end());
	// acount for an even number of dimensions
	if (setData.size() % 2 == 0) {
		double first = setData[setData.size() / 2];
		double second = setData[setData.size() / 2 - 1];
		return (first + second) / 2.0;
	}
	return setData[setData.size() / 2];

}

// calibrate each dimension to the [0,1] space
void DataInterface::calibrateData() {
	for (unsigned int i = 0; i < getDimensionAmount(); i++) {
		(*dataDimensions[i]).calibrateData();
	}
}

// zero shifts in the dimensions
void DataInterface::zeroShifts() {
	for (unsigned int i = 0; i < getDimensionAmount(); i++) {
		double shift = (*dataDimensions[i]).getShift();
		(*dataDimensions[i]).shiftDataBy(-shift);
	}
}




// gets the title of the note at the passed index(noteIndex)
std::string * DataInterface::getNoteTitle(int noteIndex) {
	if (noteIndex >= getNoteAmount() || noteIndex < 0) {
		return nullptr;
	}
	return notes[noteIndex].getTitle();
}

// gets the message of the note at the passed index(noteIndex)
std::string * DataInterface::getNoteMessage(int noteIndex) {
	if (noteIndex >= getNoteAmount() || noteIndex < 0) {
		return nullptr;
	}
	return notes[noteIndex].getContent();
}

// gets the x coordinate of the note at the passed index(noteIndex)
double DataInterface::getNoteX(int noteIndex) {
	if (noteIndex >= getNoteAmount() || noteIndex < 0) {
		return 0.0;
	}
	return notes[noteIndex].getXCord();
}

// gets the y coordinate of the note at the passed index(noteIndex)
double DataInterface::getNoteY(int noteIndex) {
	if (noteIndex >= getNoteAmount() || noteIndex < 0) {
		return 0.0;
	}
	return notes[noteIndex].getYCord();
}

// gets the number of notes
int DataInterface::getNoteAmount()
{
	return notes.size();
}

// deletes of the note at the passed index(noteIndex)
void DataInterface::deleteNote(int noteIndex)
{
	if (noteIndex >= getNoteAmount() || noteIndex < 0) {
		return;
	}
	notes.erase(notes.begin() + noteIndex);
}




// compares the data of a each set to the set at the passed index and checks if the data is within the radius of the data of the passed set
// if the passed bool(meanMedian) is true the mean will be used and otherwise the median will be
void DataInterface::hypercube(int setIndex, double radius) {
	// don't accept out of bounds data set indexes
	if (setIndex >= getSetAmount() || setIndex < 0) {
		return;
	}
	if (radius < 0) {
		return;
	}
	for (int i = 0; i < dataDimensions[0]->size(); i++) {
		int clusterSets = 0;
	}
	std::vector<int> selectedSets = std::vector<int>();
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
		if (setIsWithinMargin) {
			selectedSets.push_back(i);
		}

	}

	ColorCustom clusterColor = ColorCustom();
	int originalSetClass = getClassOfSet(setIndex);
	std::vector<double>* colorConponents = getClassColor(originalSetClass);
	clusterColor.setRed((*colorConponents)[0]);
	clusterColor.setGreen((*colorConponents)[1]);
	clusterColor.setBlue((*colorConponents)[2]);
	clusterColor.setAlpha((*colorConponents)[3]);
	clusters.push_back(SetCluster(clusterColor, &selectedSets, &dataDimensions));
	clusters[clusters.size() - 1].setRadius(radius);
	clusters[clusters.size() - 1].getOriginalSet(setIndex);
	std::string clusterName = *(dataSets[setIndex].getName()) + " " + std::to_string(radius);
	clusters[clusters.size() - 1].setName(&clusterName);
	if (useMean) {
		clusters[clusters.size() - 1].setUseMean(useMean);
		clusters[clusters.size() - 1].calculateValues(&dataDimensions);
	}


	paintClusters = true;
}

// returns whether the clusters will use mean or median
bool DataInterface::isUseMeanForClusters() {
	return useMean;
}

// returns whether the clusters will use mean or median
void DataInterface::setUseMeanForClusters(bool newUseMean) {
	useMean = newUseMean;
	for (int i = 0; i < getClusterAmount(); i++) {
			clusters[i].setUseMean(newUseMean);
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




// whether to paint the clusters or not
bool DataInterface::isPaintClusters() const {
	return paintClusters;
}

// toggles whether to paint the clusters or not
bool DataInterface::togglePaintClusters() {
	paintClusters = !paintClusters;
	return paintClusters;
}

// gets amount of clusters
int DataInterface::getClusterAmount() {
	return clusters.size();
}

// the minimum value for the cluster data
double DataInterface::getClusterMinimum(int clusterIndex, int dimensionIndex) const {
	if (dimensionIndex >= getDimensionAmount() || dimensionIndex < 0) {
		return 0.0;
	}
	return clusters[clusterIndex].getMinimum(dimensionIndex) + dataDimensions[dimensionIndex]->getShift();
}

// the mean value for the cluster data
double DataInterface::getClusterMiddle(int clusterIndex, int dimensionIndex) const {
	if (dimensionIndex >= getDimensionAmount() || dimensionIndex < 0) {
		return 0.0;
	}
	return clusters[clusterIndex].getMiddle(dimensionIndex) + dataDimensions[dimensionIndex]->getShift();
}

// the maximum value for the cluster data
double DataInterface::getClusterMaximum(int clusterIndex, int dimensionIndex) const {
	if (dimensionIndex >= getDimensionAmount() || dimensionIndex < 0) {
		return 0.0;
	}
	return clusters[clusterIndex].getMaximum(dimensionIndex) + dataDimensions[dimensionIndex]->getShift();
}

// gets the color of the cluster
std::vector<double>* DataInterface::getClusterColor(int clusterIndex) {
	if (clusterIndex <0 || clusterIndex>getClusterAmount()) {
		return nullptr;
	}
	return clusters[clusterIndex].getColor();
}

// sets the color of the cluster at the passed index
void DataInterface::setClusterColor(int clusterIndex, std::vector<double>* newColor) {
	if (clusterIndex < 0 || clusterIndex >= getClusterAmount()) {
		return;
	}
	clusters[clusterIndex].setColor(newColor);
}

// delete a class from the list of classes
void DataInterface::deleteCluster(int clusterIndex) {
	// do not allow deletion of default class
	if (clusterIndex < 0 || clusterIndex >= getClusterAmount()) {
		return;
	}
	// delete the class
	clusters.erase(clusters.begin() + clusterIndex);
}

// gets the name of the cluster
std::string * DataInterface::getClusterName(int clusterIndex) {
	if (clusterIndex < 0 || clusterIndex >= getClusterAmount()) {
		return nullptr;
	}
	return clusters[clusterIndex].getName();
}

// sets the name of the cluster
void DataInterface::setClusterName(int clusterIndex, std::string* newName) {
	if (clusterIndex < 0 || clusterIndex >= getClusterAmount()) {
		return;
	}
	return clusters[clusterIndex].setName(newName);
}

// gets a list of the sets in the class
std::vector<int>* DataInterface::getClusterSets(int clusterIndex) {
	if (clusterIndex < 0 || clusterIndex >= getClusterAmount()) {
		return nullptr;
	}
	return clusters[clusterIndex].getSets();
}






// private:
// a method to hold the basic intialization of the object fields
void DataInterface::init() {
	dataDimensions = std::vector<Dimension*>();
	// create and set the fields
	dataClasses = std::vector<DataClass>();
	dataClasses.push_back(DataClass(0, "Default"));
	std::vector<double> newColor = std::vector<double>();
	newColor.push_back(0.0);
	newColor.push_back(0.0);
	newColor.push_back(1.0);
	newColor.push_back(1.0);
	dataClasses[0].setColor(newColor);
	dataSets = std::vector<DataSet>();
	clusters = std::vector<SetCluster>();

	selectedSetColor = ColorCustom();
	selectedSetColor.setRed(1.0);
	selectedSetColor.setGreen(1.0);
	selectedSetColor.setBlue(0.0);
	selectedSetColor.setAlpha(0.85);


	selectedSetIndex = 0;

	yMaxName = "1.0";
	yMinName = "0.0";
	xAxisName = "X-Axis";
	yAxisName = "Y-Axis";
	paintClusters = false;
	useMean = false;
}

// a method to hold the setup of fields to be performed after everything else
void DataInterface::finalInit() {

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
		// make new data set
		std::vector<std::string>* newTokens = tokenizeString(&str);
		fileLines->push_back(newTokens);
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
bool DataInterface::readBasicFile(std::vector<std::vector<std::string>*>* fileContents) {
	try {
		// ensure file has data
		if (fileContents->size() < 2) {
			return false;
		}
		int lastDataLine = 0;
		// find the last line of data
		int tokenNumber = (*fileContents)[0]->size();
		for (int i = 1; i < fileContents->size(); i++) {
			if (tokenNumber != (*fileContents)[i]->size()) {
				i = fileContents->size();
			}
			else {
				lastDataLine = i;
			}
		}
		if (lastDataLine < 1) {
			return false;
		}

		// get number of sets
		int setNumber = fileContents->size() - 1;
		// get dimension names
		std::vector<std::string> headers = std::vector<std::string>((*fileContents)[0]->size());
		for (int i = 1; i < (*fileContents)[0]->size() - 1; i++) {
			std::string newDimensionName = (*(*fileContents)[0])[i];
			dataDimensions.push_back(new Dimension(i - 1, setNumber));
			dataDimensions[i - 1]->setName(&newDimensionName);
		}

		int temp = dataDimensions.size();
		temp = dataSets.size();
		// read data into dimensions
		for (int i = 1; i < (*fileContents)[0]->size() - 1; i++) {
			Dimension* currentDimension = dataDimensions[i - 1];
			for (int j = 1; j <= lastDataLine; j++) {
				double newData = std::stod((*(*fileContents)[j])[i]);
				currentDimension->setData(j - 1, newData);
			}
			currentDimension->calibrateData();
		}

		// create data classes
		// create default class
		dataClasses.clear();
		dataClasses.push_back(DataClass(0, "Default"));
		std::vector<double> newColor = std::vector<double>();
		newColor.push_back(0.0);
		newColor.push_back(0.0);
		newColor.push_back(1.0);
		newColor.push_back(1.0);
		dataClasses[0].setColor(newColor);
		// create the classes
		for (int i = 1; i <= lastDataLine; i++) {
			std::string setClassName = (*(*fileContents)[i])[(*fileContents)[i]->size() - 1];
			bool newClass = true;
			for (int j = 0; j < dataClasses.size(); j++) {
				if (dataClasses[j].getName()->compare(setClassName) == 0) {
					newClass = false;
					j = dataClasses.size();
				}
			}
			if (newClass) {
				this->addClass();
				dataClasses[getClassAmount() - 1].setName(&setClassName);
			}
		}

		// create data sets
		for (int i = 1; i <= lastDataLine; i++) {
			std::string newSetName = (*(*fileContents)[i])[0];
			std::string setClassName = (*(*fileContents)[i])[(*fileContents)[i]->size() - 1];
			int classIndex = 0;
			for (int j = 0; j < dataClasses.size(); j++) {
				if (dataClasses[j].getName()->compare(setClassName) == 0) {
					classIndex = j;
					j = dataClasses.size();
				}
			}
			dataSets.push_back(DataSet(i - 1, classIndex));
			dataSets[i - 1].setName(newSetName);
			dataClasses[classIndex].addSet(i - 1);
		}

	}
	catch (...) {
		return false;
	}

	return true;
}

// reads the contents of the file, at fileName, into a vector
void DataInterface::readCustomFile(std::vector<std::vector<std::string>*>* fileContents) {
	// ensure file has data
	if (fileContents->size() < 2) {
		return;
	}
	int lastDataLine = 0;
	// find the last line of data
	int tokenNumber = (*fileContents)[0]->size();
	for (int i = 1; i < fileContents->size(); i++) {
		if (tokenNumber != (*fileContents)[i]->size()) {
			i = fileContents->size();
		}
		else {
			lastDataLine = i;
		}
	}
	if (lastDataLine < 1) {
		return;
	}
	// create the data classes
	// find the start of the class section
	int classSectionFirstLine = lastDataLine + 1;
	for (int i = classSectionFirstLine; i < fileContents->size(); i++) {
		if ((*(*fileContents)[i]).size() > 0) {
			if ((*(*fileContents)[i])[0].compare("classes") == 0) {
				classSectionFirstLine = i + 1;
				i = fileContents->size();
			}
		}
	}
	// find the line after the end of the class section
	int classSectionAfterLastLine = classSectionFirstLine;
	for (int i = classSectionFirstLine; i < fileContents->size(); i++) {
		if ((*(*fileContents)[i]).size() <= 0) {
			classSectionAfterLastLine = i;
			i = fileContents->size();
		}
		else if ((*(*fileContents)[i])[0].compare("") == 0) {
		}
	}
	dataClasses.clear();
	dataClasses.push_back(DataClass(0, "Default"));
	std::vector<double> newColor = std::vector<double>();
	newColor.push_back(0.0);
	newColor.push_back(0.0);
	newColor.push_back(1.0);
	newColor.push_back(1.0);
	dataClasses[0].setColor(newColor);
	// check if there are classes to create
	if (classSectionFirstLine < classSectionAfterLastLine) {
		// create the classes
		for (int i = classSectionFirstLine; i < classSectionAfterLastLine; i++) {
			std::string className = (*(*fileContents)[i])[0];
			std::vector<double> colorComponents = std::vector<double>();
			colorComponents.push_back(stod((*(*fileContents)[i])[1]));
			colorComponents.push_back(stod((*(*fileContents)[i])[2]));
			colorComponents.push_back(stod((*(*fileContents)[i])[3]));
			colorComponents.push_back(stod((*(*fileContents)[i])[4]));
			this->addClass();
			dataClasses[getClassAmount() - 1].setName(&className);
			dataClasses[getClassAmount() - 1].setColor(colorComponents);
		}

	}

	// get number of sets
	int setNumber = lastDataLine;
	// get dimension names
	std::vector<std::string> headers = std::vector<std::string>((*fileContents)[0]->size() - 2);
	for (int i = 2; i < (*fileContents)[0]->size(); i++) {
		std::string newDimensionName = (*(*fileContents)[0])[i];
		dataDimensions.push_back(new Dimension(i - 2, setNumber));
		dataDimensions[i - 2]->setName(&newDimensionName);
	}

	// create data sets
	for (int i = 1; i <= lastDataLine; i++) {
		std::string newSetName = (*(*fileContents)[i])[1];
		std::string setClassName = (*(*fileContents)[i])[0];
		int classIndex = 0;
		for (int j = 0; j < dataClasses.size(); j++) {
			if (dataClasses[j].getName()->compare(setClassName) == 0) {
				classIndex = j;
				j = dataClasses.size();
			}
		}
		dataSets.push_back(DataSet(i - 1, classIndex));
	}

	// add data structure
	for (int i = 2; i < (*fileContents)[0]->size(); i++) {
		Dimension* currentDimension = dataDimensions[i - 2];
		for (int j = 1; j <= lastDataLine; j++) {
			double newData = std::stod((*(*fileContents)[j])[i]);
			currentDimension->setData(j - 1, newData);
		}
		currentDimension->calibrateData();
	}

	for (int i = classSectionAfterLastLine + 1; i < fileContents->size(); i++) {
		parseLine((*fileContents)[i]);
	}
}
// parses a command line from a save file
void DataInterface::parseLine(std::vector<std::string>* lineTokens) {
	if (lineTokens == nullptr) {
		// do nothing
	}
	if (lineTokens->size() == 0) {
		// do nothing
	}
	// read data
	else if ((*lineTokens)[0].compare("shift") == 0) {
		if (lineTokens->size() >= 3) {
			int index = stoi((*lineTokens)[1]);
			double shift = stod((*lineTokens)[2]);
			if (index < 0 || index >= this->getSetAmount()) {
				return;
			}
			else {
				this->dataDimensions[index]->shiftDataBy(shift);
			}
		}
	}
	else if ((*lineTokens)[0].compare("bounds") == 0) {
		if (lineTokens->size() >= 4) {
			int dimIndex = stoi((*lineTokens)[1]);
			double max = stod((*lineTokens)[2]);
			double min = stod((*lineTokens)[3]);
			if (dimIndex < 0 || dimIndex >= getDimensionAmount()) {
				return;
			}
			dataDimensions[dimIndex]->setCalibrationBounds(max, min);
		}
	}
	else if ((*lineTokens)[0].compare("original indexes") == 0) {
		if (lineTokens->size() >= this->getDimensionAmount() + 1) {
			for (int i = 0; i < getDimensionAmount(); i++) {
				int originalIndex = stoi((*lineTokens)[i + 1]);
				this->dataDimensions[i]->setOriginalIndex(originalIndex);
			}
		}
	}
	else if ((*lineTokens)[0].compare("hypercube") == 0) {
		if (lineTokens->size() >= 3) {
			int index = stoi((*lineTokens)[1]);
			double radius = stod((*lineTokens)[2]);
			if (index < 0 || index >= this->getSetAmount()) {
				return;
			}
			else {
				if (radius < 0) {
					radius *= -1;
				}
				this->hypercube(index, radius);
			}
		}
	}
	else if ((*lineTokens)[0].compare("useMean") == 0) {
		if (lineTokens->size() >= 2) {
			bool newUseMean = stoi((*lineTokens)[1]);
			this->setUseMeanForClusters(newUseMean);
		}
	}
	else if ((*lineTokens)[0].compare("artificial calibration") == 0) {
		if (lineTokens->size() >= 5) {
			int index = stoi((*lineTokens)[1]);
			bool isCalibrated = stod((*lineTokens)[2]);
			double maximum = stod((*lineTokens)[3]);
			double minimum = stod((*lineTokens)[4]);
			if (index < 0 || index >= this->getDimensionAmount()) {
				return;
			}
			this->setCalibrationBounds(index, maximum, minimum);
			if (isCalibrated == false) {
				this->dataDimensions[index]->clearArtificialCalibration();
			}
		}
	}
	else if ((*lineTokens)[0].compare("Default Class Color") == 0) {
		if (lineTokens->size() >= 5) {
			double red = stod((*lineTokens)[1]);
			double green = stod((*lineTokens)[2]);
			double blue = stod((*lineTokens)[3]);
			double alpha = stod((*lineTokens)[4]);
			std::vector<double> color = std::vector<double>();
			color.push_back(red);
			color.push_back(green);
			color.push_back(blue);
			color.push_back(alpha);
			dataClasses[0].setColor(&color);
		}
	}
	/*
	else if ((*lineTokens)[0].compare("class Color") == 0) {
	if (lineTokens->size() >= 7) {
	int classIndex = stoi((*lineTokens)[2]);
	if (classIndex < 0 || classIndex >= getClassAmount()) {
	return;
	}
	// std::string className = stoi(lineArgs[2]);
	double red = stod((*lineTokens)[3]);
	double green = stod((*lineTokens)[4]);
	double blue = stod((*lineTokens)[5]);
	double alpha = stod((*lineTokens)[6]);
	std::vector<double> colorComponents = std::vector<double>();
	colorComponents.push_back(red);
	colorComponents.push_back(green);
	colorComponents.push_back(blue);
	colorComponents.push_back(alpha);
	dataClasses[classIndex].setColor(colorComponents);
	}
	}
	*/
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