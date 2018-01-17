#include <iostream>
#include <fstream>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glut.h"
#include "VisCanvas_Window.h"

void setViewport(float left, float right, float bottom, float top){
	glViewport(left, bottom, right - left, top - bottom); // openGL viewport function
} // setViewport maps coords to window coords

void setWindow(float left, float right, float bottom, float top){
	glMatrixMode(GL_PROJECTION); // sets matrix mode to projection
	glLoadIdentity(); // loads matrix
	gluOrtho2D(left, right, bottom, top);
} // setWindow sets world coords of drawing

void adaptShape(GLsizei W, GLsizei H){
	if (R > W/H)
		setViewport(0, W, 0, W/R);
	else
		setViewport(0, H * R, 0, H);
} // adaptShape ensures that the visualization maintains a constant aspect ratio, regardless of ratio of window

void drawParallel(){ 
	glColor3f(0.0, 0.0, 0.0); // sets drawing color to black
	glBegin(GL_LINES); // openGL function that draws lines between two points
		glVertex2f(58.1, 50);
		glVertex2f(58.1, 430);

		glVertex2f(116.2, 50);
		glVertex2f(116.2, 430);

		glVertex2f(174.3, 50);
		glVertex2f(174.3, 430);

		glVertex2f(232.4, 50);
		glVertex2f(232.4, 430);

		glVertex2f(290.5, 50);
		glVertex2f(290.5, 430);   

		glVertex2f(348.6, 50);
		glVertex2f(348.6, 430);

		glVertex2f(406.7, 50);
		glVertex2f(406.7, 430);

		glVertex2f(464.8, 50);
		glVertex2f(464.8, 430);

		glVertex2f(522.9, 50);
		glVertex2f(522.9, 430);

		glVertex2f(581.0, 50);
		glVertex2f(581.0, 430);
	glEnd();
	glFlush(); 
} // drawParallel function draws the parallel coordinate lines 
  // [TO DO: WRITE ALGORITHM THAT WILL DRAW ONLY AS MANY LINES AS ARE NECESSARY; CURRENTLY JUST DRAWS 10]

void readFile(char* fileName){
	std :: fstream inStream; // calls function to read from file
	inStream.open(fileName); // open the file

	if (inStream.fail())
		return; // if there is no file, end function
	
	GLint numLines, numDimensions;
	inStream >> numLines; // reads from the file the number of lines
	inStream >> numDimensions; // reads from the file the number of dimensions
	float x; // x will hold values from the file

	for (int i = 0; i < numLines; i++){ // for loop that iterates for each line to draw
		glBegin(GL_LINE_STRIP); // begin drawing line
		for(int j = 1; j <= numDimensions; j++) { // embedded for loop that iterates for each dimension
			inStream >> x; // reads next number and assigns to x
			glVertex2f(58.1 * j, x);
		}
		glEnd(); // ends drawing line
	}
	glFlush(); // pushes drawings to screen
	inStream.close(); // closes the text file
} // readFile function will read 

void Display(){
	glClear(GL_COLOR_BUFFER_BIT);
	drawParallel();
	// [TO DO: WRITE ALGORITHM THAT CHOOSES COLORS FOR A VARIABLE NUMBER OF FILES; CURRENTLY ALLOWS FOR 3 W/ R G B LINES]
	
	glColor3f(1.0, 0.0, 0.0); // set color to red
	char* fileA = ""; //getFileName(A); [TO DO: WRITE getFileName()]
	readFile(fileA);

	glColor3f(0.0, 1.0, 0.0); // set color to green
	char* fileB = ""; //getFileName(B);
	readFile(fileB);

	glColor3f(0.0, 0.0, 1.0); // set color to blue
	char* fileC = ""; //getFileName(C);
	readFile(fileC);

	glFlush();
} // Display function sets colors and calls readFile to draw lines

void Init(){
	glClearColor(1.0,1.0,1.0,0.0); // sets background color to white
	glColor3f(0.0f, 0.0f, 0.0f); // sets drawing color to black
	glPointSize(4.0); // sets point size to 4 pixels
	glMatrixMode(GL_PROJECTION); // sets matrix mode to projection
	glLoadIdentity(); // loads matrix
	gluOrtho2D(1.0, 640.0, 0.0, 480.0); // sets clipping area of 2D orthographic view to fit the visualization; will need tweaks
}

void main (int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480); 
	glutInitWindowPosition(100, 150);
	glutCreateWindow("VISCANVAS_WINDOW_TEST");
	glutDisplayFunc(Display);
	glutReshapeFunc(adaptShape);
	Init();
	glutMainLoop();
} // main function for testing purposes; will be deprecated in integration




