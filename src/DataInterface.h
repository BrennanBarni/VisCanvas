#ifndef DataInterface_H
#define DataInterface_H
#include "DataNode.h"
#include "Dimension.h"
#include "Color.h"
#include <vector>

using namespace std;
class DataInterface {
public:
	DataInterface(string* filePath);
	void readFile(char* filePath);
	const int getClassAmount();
	const int getSetAmount(unsigned int indexOfClass);
	const int getSetAmount();
	const int getDimensionAmount();
	double getData(unsigned int setIndex, unsigned int indexOfData);
	const int getClassofSet(unsigned int setIndex);
	void moveData(unsigned int indexOfDimension, unsigned int indexBeforeInsertion);
	const string* getClassName(unsigned int classIndex);
	string* setClassName(unsigned int classIndex, string* newName);
	const string* getSetName(unsigned int classIndex, unsigned int setIndex);
	string* setSetName(unsigned int classIndex, unsigned int setIndex, string* newName);
	const string* getXAxisName();
	const string* getYAxisName();
	const string* getYMaxName();
	const string* getYMinName();
	void sortAscending(unsigned int setIndex);
	void sortDescending(unsigned int setIndex);
	void level(unsigned int setIndex);
	void calibrateData();
	const string* saveData(string* filePath);
	const int getSetIndex(unsigned int classIndex, unsigned int setIndex);

	const float* getColor(int classIndex);
	void setColor(int classIndex, float* newColor);

	void setSelectedSetIndex(int newSelectedSetIndex);
	const int getSelectedSetIndex();
	void setSelectedSetColor(float* newSelectedSetColor);
	const float* getSelectedSetColor();

private:
	vector<Dimension*> dataDimensions;


	vector<unsigned int> classSizes;
	vector<string*> classNames;
	vector<string*> setNames;
	vector<Color> classColors;
	Color selectedSetColor;
	int selectedSetIndex;

	string yMaxName;
	string yMinName;
	string xAxisName;
	string yAxisName;


	void sortAscending(unsigned int setIndex, unsigned int start, unsigned int end);
	void bubbleSortDataAscending(unsigned int setIndex, unsigned int start, unsigned int end);

	void sortDescending(unsigned int setIndex, unsigned int start, unsigned int end);
	void bubbleSortDataDescending(unsigned int setIndex, unsigned int start, unsigned int end);

	int countCharacters(vector<char>* characters, string* line);
};

#endif
