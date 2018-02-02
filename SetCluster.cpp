#include "SetCluster.h"
#include <algorithm>    // std::sort



// creates a blank cluster
SetCluster::SetCluster(ColorCustom &clusterColor) {
	color = clusterColor;
	setsInCluster = std::vector<int>();
	minimumValues = std::vector<double>();
	meanValues = std::vector<double>();
	maximumValues = std::vector<double>();
}

// creates the cluster with the passed sets
SetCluster::SetCluster(ColorCustom &clusterColor, std::vector<int>* newSetsInCluster) {
	color = clusterColor;
	setsInCluster = std::vector<int>();
	minimumValues = std::vector<double>();
	meanValues = std::vector<double>();
	maximumValues = std::vector<double>();
	for (int i = 0; i < newSetsInCluster->size(); i++) {
		setsInCluster.push_back((*newSetsInCluster)[i]);
	}
	std::sort(setsInCluster.begin(), setsInCluster.end());
}

// creates the cluster with the passed sets and values from the passed dimensions
SetCluster::SetCluster(ColorCustom &clusterColor, std::vector<int>* newSetsInCluster, std::vector<Dimension>* dimensionsToCalculateWith) {
	// intialize fields
	color = clusterColor;
	setsInCluster = std::vector<int>();
	minimumValues = std::vector<double>();
	meanValues = std::vector<double>();
	maximumValues = std::vector<double>();

	// put sets into the cluster
	for (int i = 0; i < newSetsInCluster->size(); i++) {
		setsInCluster.push_back((*newSetsInCluster)[i]);
	}
	std::sort(setsInCluster.begin(), setsInCluster.end());
	// get the values from the dimensions
	// check if there are any dimensions passed
	if (dimensionsToCalculateWith->size() <= 0) {
		// do nothing dimensions cannot be used for this cluster
	}
	// check if then largest set index is is within the dimensions passed
	if (setsInCluster[setsInCluster.size() - 1] >= (*dimensionsToCalculateWith)[0].size()) {
		// do nothing dimensions cannot be used for this cluster
	}
	else {
		// there are enough sets in the dimensions to use the passed dimensions
		// so get the data for this cluster
		for (int i = 0; i < dimensionsToCalculateWith->size(); i++) {
			double min = getMinimumValue(&(*dimensionsToCalculateWith)[i], &setsInCluster);
			double mean = getMeanValue(&(*dimensionsToCalculateWith)[i], &setsInCluster);
			double max = getMaximumValue(&(*dimensionsToCalculateWith)[i], &setsInCluster);
			minimumValues.push_back(min);
			meanValues.push_back(mean);
			maximumValues.push_back(max);
		}
	}
}



// deletes object
SetCluster::~SetCluster() {
}


// gets the calculates the minimum value of dimension for the sets whose indexes are passed(setIndexes)
double SetCluster::getMinimumValue(Dimension* dimension, std::vector<int>* setIndexes) {
	double minimum = 0.0;
	std::sort(setIndexes->begin(), setIndexes->end());
	// check if the dimension has enough sets for the sets in the passed vector(setIndexes)
	if ((*setIndexes)[setIndexes->size() - 1] >= dimension->size()) {
		return minimum;
	}
	// calculate the minimum
	for (int i = 0; i < setIndexes->size(); i++) {
		double dataValue = dimension->getCalibratedData((*setIndexes)[i]);
		if (dataValue < minimum) {
			minimum = dataValue;
		}

	}
	return minimum;
}

// gets the calculates the mean value of dimension for the sets whose indexes are passed(setIndexes)
double SetCluster::getMeanValue(Dimension * dimension, std::vector<int>* setIndexes) {
	double sum = 0.0;
	std::sort(setIndexes->begin(), setIndexes->end());
	// check if the dimension has enough sets for the sets in the passed vector(setIndexes)
	if ((*setIndexes)[setIndexes->size() - 1] >= dimension->size()) {
		return sum;
	}
	// calculate the minimum
	for (int i = 0; i < setIndexes->size(); i++) {
		double dataValue = dimension->getCalibratedData((*setIndexes)[i]);
		sum += dataValue;

	}
	return sum / ((double)setIndexes->size());
}

// gets the calculates the maximum value of dimension for the sets whose indexes are passed(setIndexes)
double SetCluster::getMaximumValue(Dimension* dimension, std::vector<int>* setIndexes) {
	double maximum = 0.0;
	std::sort(setIndexes->begin(), setIndexes->end());
	// check if the dimension has enough sets for the sets in the passed vector(setIndexes)
	if ((*setIndexes)[setIndexes->size() - 1] >= dimension->size()) {
		return maximum;
	}
	// calculate the minimum
	for (int i = 0; i < setIndexes->size(); i++) {
		double dataValue = dimension->getCalibratedData((*setIndexes)[i]);
		if (dataValue > maximum) {
			maximum = dataValue;
		}

	}
	return maximum;
}




// adds the passed set index(setIndex) to the list of sets
// returns true if the set is added and false if the set was already in the cluster
bool SetCluster::addSet(int setIndex) {
	for (int i = 0; i < setsInCluster.size(); i++) {
		if (setsInCluster[i] == setIndex) {
			return false;
		}
	}
	setsInCluster.push_back(setIndex);
	std::sort(setsInCluster.begin(), setsInCluster.end());
	return true;
}

// removes the set index(setIndex) to the list of sets
// returns true if the set is removed and false if the set not in the cluster
bool SetCluster::removeSet(int setIndex) {
	for (int i = 0; i < setsInCluster.size(); i++) {
		if (setsInCluster[i] == setIndex) {
			setsInCluster.erase(setsInCluster.begin() + i);
			return true;
		}
	}
	return false;
}

// gets the number of sets in the cluster
int SetCluster::getSetNumber() {
	return setsInCluster.size();
}

// gets the index of the set in this cluster for the set at the passed index(clusterRelativeIndex), which is the index the set index is stored at
int SetCluster::getIndexOfSet(int clusterRelativeIndex) {
	if (clusterRelativeIndex >= setsInCluster.size() || clusterRelativeIndex < 0) {
		return -1;
	}
	return setsInCluster[clusterRelativeIndex];
}




// gets the minimum value in the cluster for the dimension at the passed index 
double SetCluster::getMinimum(int dimensionIndex) {
	if (dimensionIndex >= minimumValues.size() || dimensionIndex < 0) {
		return 0.0;
	}
	return minimumValues[dimensionIndex];
}

// gets the mean value in the cluster for the dimension at the passed index 
double SetCluster::getMean(int dimensionIndex) {
	if (dimensionIndex >= meanValues.size() || dimensionIndex < 0) {
		return 0.0;
	}
	return meanValues[dimensionIndex];
}

// gets the maximum value in the cluster for the dimension at the passed index 
double SetCluster::getMaximum(int dimensionIndex) {
	if (dimensionIndex >= maximumValues.size() || dimensionIndex < 0) {
		return 0.0;
	}
	return maximumValues[dimensionIndex];
}




// recalculates the values for the cluster using the passed dimensions
void SetCluster::calculateValues(std::vector<Dimension>* dimensionsToCalculateWith) {
	// get the values from the dimensions
	// check if there are any dimensions passed
	if (dimensionsToCalculateWith->size() <= 0) {
		// do nothing dimensions cannot be used for this cluster
	}
	// check if then largest set index is is within the dimensions passed
	if (setsInCluster[setsInCluster.size() - 1] >= (*dimensionsToCalculateWith)[0].size()) {
		// do nothing dimensions cannot be used for this cluster
	}
	else {
		// there are enough sets in the dimensions to use the passed dimensions
		// so get the data for this cluster
		for (int i = 0; i < dimensionsToCalculateWith->size(); i++) {
			double min = getMinimumValue(&(*dimensionsToCalculateWith)[i], &setsInCluster);
			double mean = getMeanValue(&(*dimensionsToCalculateWith)[i], &setsInCluster);
			double max = getMaximumValue(&(*dimensionsToCalculateWith)[i], &setsInCluster);
			minimumValues.push_back(min);
			meanValues.push_back(mean);
			maximumValues.push_back(max);
		}
	}
}




// inverts the values of the set at the passed index
void SetCluster::invertValues(int dimensionToInvertValuesAt) {
	if (dimensionToInvertValuesAt >= minimumValues.size() || dimensionToInvertValuesAt < 0) {
		return;
	}
	minimumValues[dimensionToInvertValuesAt] = 1 - minimumValues[dimensionToInvertValuesAt];
	meanValues[dimensionToInvertValuesAt] = 1 - meanValues[dimensionToInvertValuesAt];
	maximumValues[dimensionToInvertValuesAt] = 1 - maximumValues[dimensionToInvertValuesAt];
}

// move the position of the values in the set(at originalIndex) to the index after indexBeforeNewIndex
void SetCluster::moveValues(int originalIndex, int indexOfInsertion) {
	if (originalIndex >= minimumValues.size() || originalIndex < 0) {
		return;
	}
	if (indexOfInsertion > minimumValues.size()) {
		indexOfInsertion = minimumValues.size();
	}
	if (indexOfInsertion < 0) {
		indexOfInsertion = 0;
	}
	if (originalIndex == indexOfInsertion) {
		return;
	}
	// check if the insertion at the end
	if (indexOfInsertion == minimumValues.size()) {
		minimumValues.push_back(minimumValues[originalIndex]);
		meanValues.push_back(meanValues[originalIndex]);
		maximumValues.push_back(maximumValues[originalIndex]);
		minimumValues.erase(minimumValues.begin() + originalIndex);
		meanValues.erase(meanValues.begin() + originalIndex);
		maximumValues.erase(maximumValues.begin() + originalIndex);
		return;
	}
	// place the dimension in the new position
	minimumValues.insert(minimumValues.begin() + indexOfInsertion, minimumValues[originalIndex]);
	meanValues.insert(meanValues.begin() + indexOfInsertion, meanValues[originalIndex]);
	maximumValues.insert(maximumValues.begin() + indexOfInsertion, maximumValues[originalIndex]);
	// remove the dimension from the old position
	if (originalIndex <= indexOfInsertion) {
		minimumValues.erase(minimumValues.begin() + originalIndex);
		meanValues.erase(meanValues.begin() + originalIndex);
		maximumValues.erase(maximumValues.begin() + originalIndex);
	}
	else {
		minimumValues.erase(minimumValues.begin() + originalIndex + 1);
		meanValues.erase(meanValues.begin() + originalIndex + 1);
		maximumValues.erase(maximumValues.begin() + originalIndex + 1);
	}
}
