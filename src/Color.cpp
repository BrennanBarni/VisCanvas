#include "Color.h"



Color::Color() {
	colorComponents[0] = 0.0f;
	colorComponents[1] = 0.0f;
	colorComponents[2] = 0.0f;
	colorComponents[3] = 0.0f;
}


Color::~Color() {
	delete colorComponents;
}

float* Color::getColorComponents() {
	float* copyColorComponents = new float[4];
	copyColorComponents[0] = getRed();
	copyColorComponents[1] = getGreen();
	copyColorComponents[2] = getBlue();
	copyColorComponents[3] = getAlpha();

	return copyColorComponents;
}

void Color::setColorComponents(float * newComponents) {
	colorComponents = newComponents;
}

const float Color::getRed() {
	return colorComponents[0];
}

const float Color::getGreen() {
	return colorComponents[1];
}

const float Color::getBlue() {
	return colorComponents[2];
}

const float Color::getAlpha() {
	return colorComponents[3];
}

void Color::setRed(float newValue) {
	if (newValue < 0.0f) {
		newValue = 0.0f;
	}
	else if (newValue > 1.0f) {
		newValue = 1.0f;
	}
	colorComponents[0] = newValue;
}

void Color::setGreen(float newValue) {
	if (newValue < 0.0f) {
		newValue = 0.0f;
	}
	else if (newValue > 1.0f) {
		newValue = 1.0f;
	}
	colorComponents[1] = newValue;
}

void Color::setBlue(float newValue) {
	if (newValue < 0.0f) {
		newValue = 0.0f;
	}
	else if (newValue > 1.0f) {
		newValue = 1.0f;
	}
	colorComponents[2] = newValue;
}

void Color::setAlpha(float newValue) {
	if (newValue < 0.0f) {
		newValue = 0.0f;
	}
	else if (newValue > 1.0f) {
		newValue = 1.0f;
	}
	colorComponents[3] = newValue;
}
