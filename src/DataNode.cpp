#include "DataNode.h"

const double DataNode::getData() {
	return currentData;
}

const double DataNode::getOriginalData() {
	return originalData;
}

DataNode::DataNode(double data) {
	currentData = data;
	originalData = data;
}

void DataNode::setData(double newData) {
	currentData = newData;
	originalData = newData;
}

void DataNode::multiplyData(double multiplier) {
	currentData *= multiplier;
}

void DataNode::divideData(double divisor) {
	currentData /= divisor;
}

void DataNode::addToData(double addend) {
	currentData += addend;
}
