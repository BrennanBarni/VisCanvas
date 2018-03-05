#include "stdafx.h"
#include "DataClass.h"
#include "ColorCustom.h"


// create a class at index -1 with a "-1" string for a name
DataClass::DataClass() {
	this->index = -1;
	this->name = "-1";
	this->color = ColorCustom();
	sets = std::vector<int>();
}

// create a class at index(index) and the passed string for a name(name)
DataClass::DataClass(int index, std::string name) {
	this->index = index;
	this->name = name;
	this->color = ColorCustom();
	sets = std::vector<int>();
}

// delete the object
DataClass::~DataClass() {
}


// gets the index of the class
int DataClass::getIndex() {
	return this->index;
}

// sets the index of the class, returns previous index
int DataClass::setIndex(int newIndex) {
	int previousIndex = getIndex();
	index = newIndex;
	return previousIndex;
}

// gets a copy of the color components for this class
std::vector<double>* DataClass::getColor() {
	return color.getColorComponents();
}

// sets the color for this class
void DataClass::setColor(std::vector<double>& newColor) {
	if (newColor.size() != 4) {
		return;
	}
	color.setRed(newColor[0]);
	color.setGreen(newColor[1]);
	color.setBlue(newColor[2]);
	color.setAlpha(newColor[3]);
}

// sets the color for this class
void DataClass::setColor(std::vector<double>* newColor) {
	if (newColor == nullptr) {
		return;
	}
	if (newColor->size() != 4) {
		return;
	}
	color.setRed((*newColor)[0]);
	color.setGreen((*newColor)[1]);
	color.setBlue((*newColor)[2]);
	color.setAlpha((*newColor)[3]);
}

// gets the name of the class
std::string * DataClass::getName() {
	return &(this->name);
}

// sets the name of the class, returns previous name
void DataClass::setName(std::string * newName) {
	name = *newName;
}



// gets the number of sets in this class
int DataClass::getSetNumber() const
{
	return sets.size();
}

// gets the sets in the class
std::vector<int>* DataClass::getSetsInClass() {
	return &sets;
}

// gets the sets in the class
void DataClass::addSet(int setIndex){
	// check if set is in class
	for (int i = 0; i < sets.size(); i++) {
		if (sets[i] == setIndex) {
			return;
		}
	}
	sets.push_back(setIndex);
}

// removes set from the class
void DataClass::removeSet(int setIndex) {
	for (int i = 0; i < sets.size(); i++) {
		if (sets[i] == setIndex) {
			sets.erase(sets.begin() + i);
			return;
		}
	}
}
