#include "stdafx.h"
#include "DataSet.h"

DataSet::DataSet()
{
	currentIndex = -1;
	originalIndex = -1;
	setClass = 0;
	name = "-1";
}

DataSet::DataSet(int setIndex, int classIndex)
{
	currentIndex = setIndex;
	originalIndex = setIndex;
	setClass = classIndex;
	name = std::to_string(setIndex);
}

DataSet::~DataSet() {
}

int DataSet::getClass() const {
	return setClass;
}

int DataSet::setDataClass(int newClass) {
	int previousClass = setClass;
	setClass = newClass;
	return previousClass;
}

int DataSet::getIndex() const {
	return currentIndex;
}

int DataSet::setIndex(int newIndex) {
	int previousIndex = currentIndex;
	currentIndex = newIndex;
	return previousIndex;
}

int DataSet::getOriginalIndex() const {
	return originalIndex;
}

std::string* DataSet::getName() {
	return &(this->name);
}

void DataSet::setName(std::string &newName) {
	name = newName;
}
