#include "stdafx.h"
#include "ColorCustom.h"
#include <vector>

// create the color
ColorCustom::ColorCustom() {
	colorComponents = std::vector<double>();
	colorComponents.push_back(0.5);
	colorComponents.push_back(0.5);
	colorComponents.push_back(0.5);
	colorComponents.push_back(1.0);
	copyColorComponents = std::vector<double>();
	copyColorComponents.push_back(0.5);
	copyColorComponents.push_back(0.5);
	copyColorComponents.push_back(0.5);
	copyColorComponents.push_back(1.0);
}

// delete the color
ColorCustom::~ColorCustom() {
}

// gets vector of the color components
std::vector<double>* ColorCustom::getColorComponents() {
	for (int i = 0; i < 4; i++) {
		copyColorComponents[i] = colorComponents[i];
	}
	return &copyColorComponents;
}

// set the red color component value
void ColorCustom::setRed(double newValue) {
	if (newValue < 0.0) {
		newValue = 0.0;
	}
	else if (newValue > 1.0) {
		newValue = 1.0;
	}
	colorComponents[0] = newValue;
	copyColorComponents[0] = newValue;
}

// set the green color component value
void ColorCustom::setGreen(double newValue) {
	if (newValue < 0.0) {
		newValue = 0.0;
	}
	else if (newValue > 1.0) {
		newValue = 1.0;
	}
	colorComponents[1] = newValue;
	copyColorComponents[1] = newValue;
}

// set the blue color component value
void ColorCustom::setBlue(double newValue) {
	if (newValue < 0.0) {
		newValue = 0.0;
	}
	else if (newValue > 1.0) {
		newValue = 1.0;
	}
	colorComponents[2] = newValue;
	copyColorComponents[2] = newValue;
}

// set the alpha component value
void ColorCustom::setAlpha(double newValue) {
	if (newValue < 0.0) {
		newValue = 0.0;
	}
	else if (newValue > 1.0) {
		newValue = 1.0;
	}
	colorComponents[3] = newValue;
	copyColorComponents[3] = newValue;
}
/*
// checks if the color is visible or not
bool ColorCustom::isVisible() {
	if (colorComponents[3] < 0.0001) {
		return false;
	}
	return true;
}

// sets the color visible or not visible
void ColorCustom::setVisible(bool visible) {
	if (visible) {
		setAlpha(1.0);
	}
	else {
		setAlpha(0.00001);
	}
}
*/