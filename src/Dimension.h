#ifndef Dimension_H
#define Dimension_H
#include "DataNode.h"
#include <vector>

using namespace std;

class Dimension {
public:
	Dimension(int startingIndex, int dimensionSize);
	const int getIndex();
	const int getOriginalIndex();
	void calibrateData();
	const double getData(unsigned int dataIndex);
	const double getOriginalData(unsigned int dataIndex);
	void setData(unsigned int dataIndex, double newData);
	void multiplyData(double multiplier);
	void divideData(double divisor);
	void addToData(double addend);
	int getDimensionSize();

private:
	vector<DataNode> data;
	int originalIndex;
	int currentIndex;
	const double getMaximum();
	const double getMinimum();

};

#endif