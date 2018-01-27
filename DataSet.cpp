#include "stdafx.h"

DataSet::DataSet()
{
	currentIndex = -1;
	originalIndex = -1;
	name = "-1";
}

DataSet::DataSet(int setIndex, int classIndex)
{
	currentIndex = setIndex;
	originalIndex = setIndex;
	name = std::to_string(setIndex);
}

DataSet::~DataSet()
{
}

const int DataSet::getClass(){
	return setClass;
}

int DataSet::setDataClass(int newClass){
	int previousClass = setClass;
	setClass = newClass;
	return previousClass;
}

const int DataSet::getIndex()
{
	return currentIndex;
}


int DataSet::setIndex(int newIndex)
{
	int previousIndex = currentIndex;
	return previousIndex;
}

const int DataSet::getOriginalIndex()
{
	return originalIndex;
}

const std::string * DataSet::getName()
{
	return &name;
}

std::string * DataSet::setName(std::string * newName)
{
	std::string previousName = name;
	name = *newName;
	return &name;
}
