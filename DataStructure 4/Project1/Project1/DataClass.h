#ifndef DataClass_H
#define DataClass_H
#include "ColorCustom.h"
#include <string>
/*
Author: Daniel Ortyn
Last Update: 2018/22/01
Purpose: CS 481 Project
*/


// a class to hold and manage data with a common index for several sets
class DataClass {
public:
	// create a class at index -1 with a "-1" string for a name
	DataClass();
	// create a class at index(index) and the passed string for a name(name)
	DataClass(int index, std::string name);
	// delete the object
	~DataClass();
	// gets the index of the class
	int getIndex();
	// sets the index of the class, returns previous index
	int setIndex(int newIndex);
	// gets a copy of the color components for this class
	std::vector<double>* getColor();
	// sets the color for this class
	void setColor(std::vector<double> &newColor);
	// sets the color for this class
	void setColor(std::vector<double>* newColor);
	// gets the name of the class
	std::string* getName();
	// sets the name of the class, returns previous name
	void setName(std::string* newName);
	// gets the number of sets in this class
	int getSetNumber() const;
	// increments the number of sets in this class, and returns the new number of sets
	int incrementSetNumber();
	// decrements the number of sets in this class, and returns the new number of sets
	int decrementSetNumber();

private:
	// the vector holding all the data
	int index;
	// gets the color data of this class should be painted
	ColorCustom* color;
	// gets the name of this class
	std::string name;
	//a field holding the number of sets in this data class
	int setNumber;
};

#endif