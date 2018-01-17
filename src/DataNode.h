#ifndef DataNode_H
#define DataNode_H

class DataNode {
public:
	const double getData();
	const double getOriginalData();
	DataNode(double data);
	void setData(double newData);
	void multiplyData(double multiplier);
	void divideData(double divisor);
	void addToData(double addend);

private:

	double originalData;
	double currentData;

};

#endif