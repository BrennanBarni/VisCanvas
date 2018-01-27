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
	const int getClass();
	// sets the class(data class) of this set and returns the previous class
	int setDataClass(int newClass);
	// gets the index of the set
	const int getIndex();
	// sets the index of the set, returns previous index
	int setIndex(int newIndex);
	// gets the original index of the set
	const int getOriginalIndex();
	// gets the name of the set
	const std::string* getName();
	// sets the name returns previous name
	std::string* setName(std::string* newName);


private:
	// the class(data class) of this set holding all the data
	int setClass;
	// gets the index the set was originally at
	int originalIndex;
	// gets the index the set is at
	int currentIndex;
	// the name of the set
	std::string name;

};

#endif