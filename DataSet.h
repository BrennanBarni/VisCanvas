#ifndef DataSet_H
#define DataSet_H
#include "DataClass.h"
/*
Author: Daniel Ortyn
Last Update: 2018/22/01
Purpose: CS 481 Project
*/



// a class to hold and manage data with a common index for several sets
class DataSet {
public:
	// create a set for index -1 and class -1
	DataSet();
	// create a dimension for the pass index(index) and passed size(size)
	DataSet(int setIndex, int classIndex);
	// delete the object
	~DataSet();
	// gets the class(data class) of this set
	int getClass() const;
	// sets the class(data class) of this set and returns the previous class
	int setDataClass(int newClass);
	// gets the index of the set
	int getIndex() const;
	// sets the index of the set, returns previous index
	int setIndex(int newIndex);
	// gets the original index of the set
	int getOriginalIndex() const;
	// gets the name of the set
	std::string* getName();
	// sets the name returns previous name
	void setName(std::string &newName);
	// checks if the set is visible or not
	bool isVisible();
	// sets the set visible or not visible and returns the old visibility
	bool setVisible(bool newVisible);


private:
	// the class(data class) of this set holding all the data
	int setClass;
	// gets the index the set was originally at
	int originalIndex;
	// gets the index the set is at
	int currentIndex;
	// the name of the set
	std::string name;
	// whether the set is visible or not
	bool visible;

};

#endif