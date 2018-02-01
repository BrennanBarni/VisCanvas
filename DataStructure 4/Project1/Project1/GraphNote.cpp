#include "GraphNote.h"



// creates a blank note
GraphNote::GraphNote() {
	title = "";
	content = "";
	xPosition = 0.0;
	yPosition = 0.0;
}

// creates a note with the passed argments for its fields
GraphNote::GraphNote(std::string* newTitle, std::string* newContent, double newXCord, double newYCord) {
	title = *newTitle;
	content = *newContent;
	xPosition = newXCord;
	yPosition = newYCord;
}

GraphNote::~GraphNote() {
}

// get a point to the string for the title of this note
std::string * GraphNote::getTitle() {
	return &title;
}

// set the title of this note, to the passed string(newtitle) and return the old title
void GraphNote::setTitle(std::string* newTitle) {
	title = *newTitle;
}

// get a point to the string for the content of this note
std::string * GraphNote::getContent() {
	return &content;
}

// set the content of this note, to the passed string(newContent) and return the old content
void GraphNote::setContent(std::string* newContent) {
	content = *newContent;
}

// get the double for the x coordinate location of this note
double GraphNote::getXCord() const {
	return xPosition;
}

// set the double for the x coordinate location of this note to the passed double(newXCord) and return the old value
double GraphNote::setXCord(double newXCord) {
	double oldXCord = xPosition;
	xPosition = newXCord;
	return oldXCord;
}

// get the double for the y coordinate location of this note
double GraphNote::getYCord() const {
	return yPosition;
}

// set the double for the y coordinate location of this note to the passed double(newYCord) and return the old value
double GraphNote::setYCord(double newYCord) {
	double oldYCord = yPosition;
	yPosition = newYCord;
	return oldYCord;
}
