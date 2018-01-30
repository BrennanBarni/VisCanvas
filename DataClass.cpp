#include "stdafx.h"

DataClass::DataClass() {
	index = -1;
	name = "-1";
	color = new ColorCustom();
}

DataClass::DataClass(int index, std::string name) {
	this->index = index;
	this->name = name;
	this->color = new ColorCustom();
}

DataClass::~DataClass() {

}

float* DataClass::getColor() {
	return (*(this->color)).getColorComponents();
}

void DataClass::setColor(float* newColor) {
	(*(this->color)).setColorComponents(newColor);
}

std::string* DataClass::getName()
{
	return &name;
}

std::string* DataClass::setName(std::string * newName)
{
	std::string previousName = name;
	name = *newName;
	return &previousName;
}

const int DataClass::getSetNumber()
{
	return setNumber;
}

int DataClass::incrementSetNumber()
{
	setNumber++;
	return setNumber;
}

int DataClass::decrementSetNumber()
{
	setNumber--;
	return setNumber;
}

int DataClass::getIndex() {
	return this->index;
}

int DataClass::setIndex(int newIndex) {
	int previousIndex = getIndex();
	index = newIndex;
	return previousIndex;
}
