#include "stdafx.h"

// create the color
ColorCustom::ColorCustom() {
	colorComponents = new float[4];
	colorComponents[0] = 0.5f;
	colorComponents[1] = 0.5f;
	colorComponents[2] = 0.5f;
	colorComponents[3] = 0.0f;
}

// delete the color
ColorCustom::~ColorCustom()
{
	delete colorComponents;
}

// get a pointer to the start of a copy of the color component array
float* ColorCustom::getColorComponents() {
	float* copyColorComponents = new float[4];
	copyColorComponents[0] = getRed();
	copyColorComponents[1] = getGreen();
	copyColorComponents[2] = getBlue();
	copyColorComponents[3] = getAlpha();

	return copyColorComponents;
}

// set the color components to the passed array
void ColorCustom::setColorComponents(float * newComponents) {
	colorComponents = newComponents;
}

// get the red color component value
const float ColorCustom::getRed() {
	return colorComponents[0];
}

// get the green color component value
const float ColorCustom::getGreen() {
	return colorComponents[1];
}

// get the blue color component value
const float ColorCustom::getBlue() {
	return colorComponents[2];
}

// get the alpha component value
const float ColorCustom::getAlpha() {
	return colorComponents[3];
}

// set the red color component value
void ColorCustom::setRed(float newValue) {
	if (newValue < 0.0f) {
		newValue = 0.0f;
	}
	else if (newValue > 1.0f) {
		newValue = 1.0f;
	}
	colorComponents[0] = newValue;
}

// set the green color component value
void ColorCustom::setGreen(float newValue) {
	if (newValue < 0.0f) {
		newValue = 0.0f;
	}
	else if (newValue > 1.0f) {
		newValue = 1.0f;
	}
	colorComponents[1] = newValue;
}

// set the blue color component value
void ColorCustom::setBlue(float newValue) {
	if (newValue < 0.0f) {
		newValue = 0.0f;
	}
	else if (newValue > 1.0f) {
		newValue = 1.0f;
	}
	colorComponents[2] = newValue;
}

// set the alpha component value
void ColorCustom::setAlpha(float newValue) {
	if (newValue < 0.0f) {
		newValue = 0.0f;
	}
	else if (newValue > 1.0f) {
		newValue = 1.0f;
	}
	colorComponents[3] = newValue;
}
