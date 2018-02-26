#ifndef DataInterface_H
#define DataInterface_H
#include "DataNode.h"
#include "Dimension.h"
#include "ColorCustom.h"
#include "DataClass.h"
#include "DataSet.h"
#include "GraphNote.h"
#include "SetCluster.h"

#include <vector>
#include <list>
#include <string> 
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
/*
Author: Daniel Ortyn
Last Update: 2018/22/01
Purpose: CS 481 Project
*/






// a class to hold several sets of data and manage interactions with the data
class DataInterface {
public:
	// create a blank class without any data
	DataInterface();
	// create a class with data taken from the file at the passed path(filePath)
	DataInterface(std::string* filePath);
	// delete the object
	~DataInterface();

	// read data from the file at the passed path(filePath) and 
	bool readFile(std::string* filePath);
	// saves the data and all settings to the file at the passed location
	bool saveToFile(std::string * filePath);

	// get the amounts of class for the data
	int getClassAmount() const;
	// gets the total amount of data sets
	int getSetAmount() const;
	// gets the number of dimensions in the data
	int getDimensionAmount() const;
	// gets the data in the set of the passed index(setIndex), for the passed dimension(indexOfData)
	double getData(int setIndex, int indexOfData) const;
	// gets the original data in the set of the passed index(setIndex), for the passed dimension(indexOfData)
	double getOriginalData(int setIndex, int indexOfData) const;
	// sets the data in the set of the passed index(setIndex), for the passed dimension(indexOfData), to the passed value(newDataValue)
	double setData(int setIndex, int indexOfData, double newDataValue);
	// moves the dimension at the passed index(indexOfDimension) to the spot after the other index(indexBeforeInsertion)
	bool moveData(int indexOfDimension, int indexBeforeInsertion);


	// gets the name of the class at the passed index(classIndex)
	std::string* getDimensionName(int dimensionIndex);
	// sets the name of the class at the passed index(classIndex) to the passed string(newName)
	void setDimensionName(int dimensionIndex, std::string* newName);

	// gets whether the calibration for the dimension(dimensionIndex) is artificial or relative
	bool isArtificiallyCalibrated(int dimensionIndex);
	// sets the calibration to use the data's(not the artificial) maximum and minimum in dimension at the passed index(dimensionIndex)
	void clearArtificialCalibration(int dimensionIndex);
	// sets the bounds to be used for artificial calibration at the passed index(dimensionIndex)
	void setCalibrationBounds(int dimensionIndex, double newMaximum, double newMinimum);
	// gets the artificial maximum for the dimension at the passed index(dimensionIndex)
	double getArtificialMaximum(int dimensionIndex) const;
	// gets the artificial minimum for the dimension at the passed index(dimensionIndex)
	double getArtificialMinimum(int dimensionIndex) const;

	// add the passed double(amountToAdd) to all the data in the dimension at the index(dimensionIndex)
	void addToDimension(int dimensionIndex, double amountToAdd);


	// gets the name of the class at the passed index(classIndex)
	std::string* getClassName(int classIndex);
	// sets the name of the class at the passed index(classIndex) to the passed string(newName)
	void setClassName(int classIndex, std::string* newName);
	// adds a new class to the list of classes
	void addClass();
	// delete a class from the list of classes
	void deleteClass(int classIndex);
	/*
	Gets the number of sets in the class at the passed index(classIndex)
	*/
	int getSetAmount(int classIndex) const;
	// gets a list of sets in the class
	std::vector<int>* getSetsInClass(int classIndex);
	// gets the color for the class at the passed class index
	std::vector<double>* getClassColor(int classIndex);
	// sets the color for the class at the passed class index(classIndex) to the passed color(newColor)
	void setClassColor(int classIndex, std::vector<double>* newColor);




	// gets the name of the set in the class at the passed index(classIndex) at the passed class relative index(setIndex)
	std::string* getSetName(int setIndex);
	// sets the name of the set at the passed index(setIndex)
	void setSetName(int setIndex, std::string &newName);
	// get the data class index for the set at the passed index
	int getClassOfSet(int setIndex) const;
	// get the data set name for the class at the passed index
	std::string* getSetOfClass(int classIndex, int setIndex);
	// sets the index data class of the set at the passed index(setIndex)
	int setSetClass(int setIndex, int newClassIndex);
	// gets the color the set should be painted
	std::vector<double>* getSetColor(int setIndex);
	// checks whether the set is visible or not
	bool isVisible(int setIndex);
	// sets the set visible or not visible
	bool setVisible(int setIndex, bool newVisible);





	// gets the amount the dimension is shifted by
	double getDimensionShift(int dimensionIndex);
	// changes the shift of the dimension at the passed int to the passsed double
	void setDimensionShift(int dimensionIndex, double shiftMod);

	// gets the name of the x-axis
	std::string* getXAxisName();
	// gets the name of the y-axis
	std::string* getYAxisName();
	// gets the name of maximum y value
	std::string* getYMaxName();
	// gets the name of minimum y value
	std::string* getYMinName();


	// sorts the data by the set at the passed index, in ascending order(left to right)
	void sortAscending(int setIndex);
	// sorts the data by the set at the passed index, in descending order(left to right)
	void sortDescending(int setIndex);
	// places the dimensions back in the original order
	void sortOriginal();


	/* adjusts the data of each dimension by shifting the data of each dimension by the
	amount necessary to put the dat of the set at the passed index(setIndex) to the passed value(levelValue)*/
	void level(int setIndex, double levelValue);
	// gets the mean data value of the passed set
	double getMean(int setIndex) const;
	// gets the median data value of the passed set
	double getMedian(int setIndex) const;
	// calibrates each dimension's data to the [0,1] space, dimensions calibrated individually
	void calibrateData();
	// zero shifts in the dimensions
	void zeroShifts();

	// gets the title of the note at the passed index(noteIndex)
	std::string* getNoteTitle(int noteIndex);
	// gets the message of the note at the passed index(noteIndex)
	std::string* getNoteMessage(int noteIndex);
	// gets the x coordinate of the note at the passed index(noteIndex)
	double getNoteX(int noteIndex);
	// gets the y coordinate of the note at the passed index(noteIndex)
	double getNoteY(int noteIndex);
	// gets the number of notes
	int getNoteAmount();
	// deletes of the note at the passed index(noteIndex)
	void deleteNote(int noteIndex);






	// compares the data of a each set to the set at the passed index and checks if the data is within the radius of the data of the passed set
	void hypercube(int setIndex, double radius);
	// returns whether the clusters will use mean or median
	bool isUseMeanForClusters();
	// sets whether the clusters will use mean or median
	void setUseMeanForClusters(bool newUseMean);




	// sets the index of the selected set to the passed index(newSelectedSetIndex)
	void setSelectedSetIndex(int newSelectedSetIndex);
	// gets the index of the selected set
	int getSelectedSetIndex() const;
	// sets the selected set's color to the colors in the passed double array(newSelectedSetColor)
	void setSelectedSetColor(std::vector<double> &newSelectedSetColor);
	// gets the color of the selected set
	std::vector<double>* getSelectedSetColor();

	// whether to paint the clusters or not
	bool isPaintClusters() const;
	// toggles whether to paint the clusters or not
	bool togglePaintClusters();
	// gets amount of clusters
	int getClusterAmount();
	// the minimum value for the cluster data
	double getClusterMinimum(int clusterIndex, int dimensionIndex) const;
	// the mean value for the cluster data
	double getClusterMiddle(int clusterIndex, int dimensionIndex) const;
	// the maximum value for the cluster data
	double getClusterMaximum(int clusterIndex, int dimensionIndex) const;
	// gets the color of the cluster
	std::vector<double>* getClusterColor(int clusterIndex);
	// sets the color of the cluster at the passed index
	void setClusterColor(int clusterIndex, std::vector<double>* newColor);
	// deletes the cluster at the passed index
	void deleteCluster(int classIndex);
	// gets the name of the cluster
	std::string* getClusterName(int clusterIndex);
	// sets the name of the cluster
	void setClusterName(int clusterIndex, std::string* newName);
	// gets a list of the sets in the class
	std::vector<int>* getClusterSets(int clusterIndex);






private:
	// a vector to hold the dimensions containing the data for the sets
	std::vector<Dimension*> dataDimensions;

	// a vector to hold the data class
	std::vector<DataClass> dataClasses;
	// a vector to hold the data sets
	std::vector<DataSet> dataSets;
	// a field to hold the color of the selected set
	ColorCustom selectedSetColor;
	// a field to hold the index of the selected set
	int selectedSetIndex;
	// holds the clusters of the data
	std::vector<SetCluster> clusters;
	// holds the boolean of whether to paint the cluster or not
	bool paintClusters;
	// holds the boolean of whether clusters use mean or median
	bool useMean;
	// holds the graph notes
	std::vector<GraphNote> notes;

	// a field to hold the name of the maximum y value
	std::string yMaxName;
	// a field to hold the name of the minimum y value
	std::string yMinName;
	// a field to hold the name of the x axis
	std::string xAxisName;
	// a field to hold the name of the y axis
	std::string yAxisName;

	// a method to hold the basic intialization of the object fields
	void init();
	// a method to hold the setup of fields to be performed after everything else
	void finalInit();

	// reads the contents of the file, at fileName, into a vector
	std::vector<std::vector<std::string>*>* readFileIntoVector(std::string* fileName);

	// takes the passed string and tokenizes it by commas
	std::vector<std::string>* tokenizeString(std::string* stringToTokenize);

	// removes duplicate strings from the passed vector
	void removeDuplicates(std::vector<std::string>* stringList);

	// reads the contents of the file, at fileName, into a vector
	bool readBasicFile(std::vector<std::vector<std::string>*>* fileContents);

	// reads the contents of the file, at fileName, into a vector
	void readCustomFile(std::vector<std::vector<std::string>*>* fileContents);

	// parses a command line from a save file
	void parseLine(std::vector<std::string>* lineTokens);

	// counts the number of characters in the passed string(line) that are one of the characters in the passed vector(characters)
	int countCharacters(vector<char>* characters, string* line);



	// an ascending(left to right) merge sort of the passed dimension list by the set at the passed index
	std::list<Dimension*>* mergeSortAscending(std::list<Dimension*>* listToSort, int setIndex);

	// an descending(left to right) merge sort of the passed dimension list by the set at the passed index
	std::list<Dimension*>* mergeSortDescending(std::list<Dimension*>* listToSort, int setIndex);

	// sorts the dimensions to their original places in a merge sort
	std::list<Dimension*>* mergeSortOriginal(std::list<Dimension*>* listToSort);

};

#endif