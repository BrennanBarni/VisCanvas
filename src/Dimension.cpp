#include "Dimension.h"
#include "DataNode.h"
#include <vector>

using namespace std;

Dimension::Dimension(int startingIndex, int dimensionSize) {
	originalIndex = startingIndex;
	currentIndex = startingIndex;

	data = vector<DataNode>();
	for (int i = 0; i < dimensionSize; i++) {
		data.push_back(DataNode(0.0));
	}
}

const int Dimension::getIndex() {
	return currentIndex;
}

const int Dimension::getOriginalIndex() {
	return originalIndex;
}


void Dimension::calibrateData() {
	double maximum = getMaximum();
	double minimum = getMinimum();
	double range = maximum - minimum;
	for (unsigned int i = 0; i < data.size(); i++) {
		data[i].addToData(minimum);
		data[i].divideData(range);
	}
}

const double Dimension::getData(unsigned int dataIndex) {
	return data[dataIndex].getData();
}

const double Dimension::getOriginalData(unsigned int dataIndex) {
	return data[dataIndex].getOriginalData();
}

void Dimension::setData(unsigned int dataIndex, double newData) {
	return data[dataIndex].setData(newData);
}

void Dimension::multiplyData(double multiplier) {
	for (unsigned int i = 0; i < data.size(); i++) {
		data[i].divideData(multiplier);
	}
}

void Dimension::divideData(double divisor) {
	for (unsigned int i = 0; i < data.size(); i++) {
		data[i].divideData(divisor);
	}
}

void Dimension::addToData(double addend) {
	for (unsigned int i = 0; i < data.size(); i++) {
		data[i].addToData(addend);
	}
}

int Dimension::getDimensionSize() {
	return data.size();
}


// private:

// gets the maximum value in this dimension
const double Dimension::getMaximum() {
	double maximum = data[0].getData();
	for (unsigned int i = 1; i < data.size(); i++) {
		if (maximum > data[i].getData()) {
			maximum = data[i].getData();
		}
	}
	return maximum;
}

// gets the minimum value in this dimension
const double Dimension::getMinimum() {
	double minimum = data[0].getData();
	for (unsigned int i = 1; i < data.size(); i++) {
		if (minimum < data[i].getData()) {
			minimum = data[i].getData();
		}
	}
	return minimum;
}
