#include "stdafx.h"
#include "DataSet.h"

// create a set for index -1 and class -1
DataSet::DataSet()
{
	currentIndex = -1;
	originalIndex = -1;
	setClass = 0;
	name = "-1";
	visible = true;
}

// create a dimension for the pass index(index) and passed size(size)
DataSet::DataSet(int setIndex, int classIndex)
{
	currentIndex = setIndex;
	originalIndex = setIndex;
	setClass = classIndex;
	name = std::to_string(setIndex);
	visible = true;
}

// delete the object
DataSet::~DataSet() {
}

// gets the class(data class) of this set
int DataSet::getClass() const {
	return setClass;
}

// sets the class(data class) of this set and returns the previous class
int DataSet::setDataClass(int newClass) {
	int previousClass = setClass;
	setClass = newClass;
	return previousClass;
}

// gets the index of the set
int DataSet::getIndex() const {
	return currentIndex;
}

// sets the index of the set, returns previous index
int DataSet::setIndex(int newIndex) {
	int previousIndex = currentIndex;
	currentIndex = newIndex;
	return previousIndex;
}

// gets the original index of the set
int DataSet::getOriginalIndex() const {
	return originalIndex;
}

// gets the name of the set
std::string* DataSet::getName() {
	return &(this->name);
}

// sets the name returns previous name
void DataSet::setName(std::string &newName) {
	name = newName;
}

// checks if the set is visible or not
bool DataSet::isVisible() {
	return visible;
}

// sets the set visible or not visible
bool DataSet::setVisible(bool newVisible) {
	bool oldVisibility = visible;
	visible = newVisible;
	return oldVisibility;
}
