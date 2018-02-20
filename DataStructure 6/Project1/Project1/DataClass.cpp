#include "DataClass.h"
#include "ColorCustom.h"

DataClass::DataClass() {
	this->index = -1;
	this->name = "-1";
	this->color = ColorCustom();
	this->setNumber = 0;
}

DataClass::DataClass(int index, std::string name) {
	this->index = index;
	this->name = name;
	this->color = ColorCustom();
	this->setNumber = 0;
}

DataClass::~DataClass() {
}


int DataClass::getIndex() {
	return this->index;
}

int DataClass::setIndex(int newIndex) {
	int previousIndex = getIndex();
	index = newIndex;
	return previousIndex;
}

std::vector<double>* DataClass::getColor() {
	return color.getColorComponents();
}

void DataClass::setColor(std::vector<double>& newColor) {
	if (newColor.size() != 4) {
		return;
	}
	color.setRed(newColor[0]);
	color.setGreen(newColor[1]);
	color.setBlue(newColor[2]);
	color.setAlpha(newColor[3]);
}

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

std::string * DataClass::getName() {
	return &(this->name);
}

void DataClass::setName(std::string * newName){
	name = *newName;
}



int DataClass::getSetNumber() const
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
