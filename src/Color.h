#pragma once
class Color
{
public:
	Color();
	~Color();

	float* getColorComponents();
	void setColorComponents(float* newComponents);
	const float getRed();
	const float getGreen();
	const float getBlue();
	const float getAlpha();
	void setRed(float newValue);
	void setGreen(float newValue);
	void setBlue(float newValue);
	void setAlpha(float newValue);

	
private:
	float* colorComponents = new float[4];
};

