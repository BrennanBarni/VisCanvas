#ifndef ColorCustom_H
#define ColorCustom_H
/*
Author: Daniel Ortyn
Last Update: 2018/22/01
Purpose: CS 481 Project
*/


// a simple class to hold float values for color for a color(r,g,b, alpha) in a float array of size 4

class ColorCustom
{
public:
	// create the color
	ColorCustom();
	// delete the color
	~ColorCustom();

	// get a pointer to the start of a copy of the color component array
	float* getColorComponents();
	// set the color components to the passed array
	void setColorComponents(float* newComponents);
	// get the red color component value
	const float getRed();
	// get the green color component value
	const float getGreen();
	// get the blue color component value
	const float getBlue();
	// get the alpha component value
	const float getAlpha();
	// set the red color component value
	void setRed(float newValue);
	// set the green color component value
	void setGreen(float newValue);
	// set the blue color component value
	void setBlue(float newValue);
	// set the alpha component value
	void setAlpha(float newValue);

	
private:
	// the array holding all the color components
	float* colorComponents;
};


#endif
