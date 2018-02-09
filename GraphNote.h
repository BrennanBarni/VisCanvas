#ifndef GraphNote_H
#define GraphNote_H
#include <string>

class GraphNote
{
public:
	// creates a blank note
	GraphNote();
	// creates a note with the passed argments for its fields
	GraphNote(std::string* newTitle, std::string* newContent, double newXCord, double newYCord);
	~GraphNote();

	// get a point to the string for the title of this note
	std::string* getTitle();
	// set the title of this note, to the passed string(newtitle) and return the old title
	void setTitle(std::string* newTitle);
	// get a point to the string for the content of this note
	std::string* getContent();
	// set the content of this note, to the passed string(newContent) and return the old content
	void setContent(std::string* newContent);
	// get the double for the x coordinate location of this note
	double getXCord() const;
	// set the double for the x coordinate location of this note to the passed double(newXCord) and return the old value
	double setXCord(double newXCord);
	// get the double for the y coordinate location of this note
	double getYCord() const;
	// set the double for the y coordinate location of this note to the passed double(newYCord) and return the old value
	double setYCord(double newYCord);

private:
	std::string title;
	std::string content;
	double xPosition;
	double yPosition;

};

#endif