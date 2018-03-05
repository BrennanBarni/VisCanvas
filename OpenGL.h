#pragma once

/*
Authors: Shane Vance, Nico Espitia, Brennan Barni, Daniel Ortyn
Last Update: 2018/22/02
Purpose: CS 481 Project
*/

#include "stdafx.h"
#include <atlstr.h>
#include <vector>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace System::Windows::Forms;

namespace OpenGLForm 
{

	public ref class COpenGL: public System::Windows::Forms::NativeWindow
	{

	public:		

		COpenGL(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight)
		{				

			CreateParams^ cp = gcnew CreateParams;

			//Set the position on the form
			cp->X = 0;
			cp->Y = 22; // accounts for the height of the status strip
			cp->Width = iWidth;
			cp->Height = iHeight;

			// specify the form as the parent.
			cp->Parent = parentForm->Handle;

			// create as a child of the specified parent and make OpenGL compliant (no clipping)
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			// create the actual window
			this->CreateHandle(cp);

			// set the world height and width for later
			this->worldWidth = iWidth;
			this->worldHeight = iHeight;

			// Create the data interface
			this->file = new DataInterface();

			this->uploadFile = false;

			// disable the toggle buttons by default
			this->drawingDragged = false;		
			this->shiftHorizontal = false;
			this->shiftVertical = false;

			this->textEnabled = true;
			this->textTop = false;
			this->textBottom = true;
			this->invertDimensionToggled = false;

			this->zoom = 0;

			this->clickedDimension = -1;

			this->font_list_base_2d = 2000;


			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			// check if everything went A-Okay when creating the Child Handle
			if(m_hDC)
			{
				this->MySetPixelFormat(m_hDC);
				this->Reshape(iWidth, iHeight);
				this->Init();
			}
		}

		// SET THE FILE PATH THAT WILL BE USED TO GRAPH THE DATA
		bool SetFilePath(std::string filepath)
		{	

			this->zoom = 0;
			this->tempXWorldMouseDifference = 0;
			this->tempYWorldMouseDifference = 0;

			try
			{
				// read the file
				if (!(this->file->readFile(&filepath))) 
				{
					throw std::exception();
				} else {
					this->uploadFile = true;
					return false;
				}
			} catch(...) {
				// display an error message
				DialogResult result = MessageBox::Show("WARNING: VisCanvas is unable to open the file. Click 'Retry' to try again.", "Trouble Opening File", MessageBoxButtons::RetryCancel, MessageBoxIcon::Warning);
				this->uploadFile = false;
				if (result == DialogResult::Retry)
				{
					return true; // reopen the file dialog
				}
				if (result == DialogResult::Cancel)
				{
					return false; // don't proceed to the file dialog
				}
			}

		}

		// BUTTON METHODS GO HERE //
		System::Void incrementSelectedSet(System::Void)
		{
			this->file->incrementSelectedSetIndex();
		}

		System::Void decrementSelectedSet(System::Void)
		{
			this->file->decrementSelectedSetIndex();
		} 

		System::Void ascendingSort(System::Void)
		{
			int selectedSetIndex = this->file->getSelectedSetIndex();
			this->file->sortAscending(selectedSetIndex);
		}

		System::Void descendingSort(System::Void)
		{
			int selectedSetIndex = this->file->getSelectedSetIndex();
			this->file->sortDescending(selectedSetIndex);
		}

		System::Void originalSort(System::Void)
		{
			int selectedSetIndex = this->file->getSelectedSetIndex();
			this->file->sortOriginal();
		}

		System::Void mean(System::Void)
		{
			int selectedSetIndex = this->file->getSelectedSetIndex();
			double meanOfSet = this->file->getMean(selectedSetIndex);
			this->file->level(selectedSetIndex, meanOfSet);

		}

		System::Void median(System::Void)
		{
			int selectedSetIndex = this->file->getSelectedSetIndex();
			double medianOfSet = this->file->getMedian(selectedSetIndex);
			this->file->level(selectedSetIndex, medianOfSet);
		}

		System::Void originalData(System::Void)
		{
			this->file->zeroShifts();
		}
		System::Void toggleClusters(System::Void)
		{
			this->file->togglePaintClusters();
		}
		System::Void hypercube(System::Void)
		{
			int selectedSetIndex = this->file->getSelectedSetIndex();
			this->file->hypercube(selectedSetIndex, file->getRadius());
		}

		// Set the toggle for manual sort
		System::Void setManualSortToggle(bool isToggled)
		{
			this->shiftHorizontal = isToggled;
			if (isToggled) {
				this->zoom = 0;
				this->tempXWorldMouseDifference = 0;
				this->tempYWorldMouseDifference = 0;
			}
		}


		// Set the toggle for manual invert
		System::Void setManualInvertToggle(bool isToggled)
		{
			this->invertDimensionToggled = isToggled;
			if (isToggled) {
				this->zoom = 0;
				this->tempXWorldMouseDifference = 0;
				this->tempYWorldMouseDifference = 0;
			}
		}

		// Get the toggle for manual invert
		bool getManualInvertToggle(System::Void)
		{
			return this->invertDimensionToggled;
		}

		// Get the toggle for manual sort
		bool getManualSortToggle(System::Void)
		{
			return this->shiftHorizontal;
		}

		// Set the toggle for manual shift
		System::Void setManualShiftToggle(bool isToggled)
		{
			this->shiftVertical = isToggled;
			if (isToggled) {
				this->zoom = 0;
				this->tempXWorldMouseDifference = 0;
				this->tempYWorldMouseDifference = 0;
			}
		}

		// Get the toggle for manual shift
		bool getManualShiftToggle(System::Void)
		{
			return this->shiftVertical;
		}

		System::Void save(std::string *filePath)
		{
			this->file->saveToFile(filePath);
		}

		// Adds a class
		System::Void addClass(System::Void)
		{
			this->file->addClass();	
		}

		// Delete a class
		System::Void removeClass(int selectedIndex)
		{
			this->file->deleteClass(selectedIndex);
		}

		// Sets the class name
		System::Void setClassName(int classIndex, std::string *newName)
		{
			this->file->setClassName(classIndex, newName);
		}

		// Sets the color for the class
		System::Void setClassColor(int classIndex, std::vector<double> *newColor)
		{
			this->file->setClassColor(classIndex, newColor);
		}

		// Gets the color for the class
		std::vector<double>* getClassColor(int index)
		{
			return this->file->getClassColor(index);
		}


		// Give the set a name
		System::Void setSetName(int setIndex, std::string &newName)
		{
			this->file->setSetName(setIndex, newName);
		}

		// Assign a set to a class
		System::Void setSetClass(int setIndex, int newClassIndex)
		{
			this->file->setSetClass(setIndex, newClassIndex);
		}

		// Gets the class of a set
		int getClassOfSet(int setIndex)
		{
			return this->file->getClassOfSet(setIndex);
		}


		// Sets the color of a cluster
		System::Void setClusterColor(int clusterIndex, std::vector<double> *newColor)
		{
			this->file->setClusterColor(clusterIndex, newColor);
		}

		// Gets the amount of glusters
		int getClusterAmount(System::Void)
		{
			return this->file->getClusterAmount();
		}

		// Deletes a cluster
		System::Void deleteCluster(int classIndex)
		{
			this->file->deleteCluster(classIndex);
		}

		// Edits the set data at the pass set index and dimensioon
		double setData(int setIndex, int indexOfDimension, double newDataValue)
		{
			return this->file->setData(setIndex, indexOfDimension, newDataValue);
		}

		// Get the dimension amount for settings window
		int getDimensionAmount(System::Void)
		{
			return this->file->getDimensionAmount();
		}

		// Sets the dimension name for the settings window
		System::Void setDimensionName(int dimensionIndex, string *newName) {
			this->file->setDimensionName(dimensionIndex, newName);
		}

		// Get the dimension name for settings window
		std::string* getDimensionName(int dimensionIndex)
		{
			std::string* str = this->file->getDimensionName(dimensionIndex);
			return str;
		}


		// sets the bounds to be used for artificial calibration at the passed index(dimensionIndex)
		System::Void setCalibrationBounds(int dimensionIndex, double newMaximum, double newMinimum)
		{
			this->file->setCalibrationBounds(dimensionIndex, newMaximum, newMinimum);
		}

		// sets the maximum bound
		double getArtificialMaximum(int dimensionIndex)
		{
			return this->file->getArtificialMaximum(dimensionIndex);
		}

		double getArtificialMinimum(int dimensionIndex)
		{
			return this->file->getArtificialMinimum(dimensionIndex);
		}

		// get whether callibrated data is set
		bool isArtificiallyCalibrated(int dimensionIndex) {
			return this->file->isArtificiallyCalibrated(dimensionIndex);
		}

		// clears the artificial calibration
		System::Void clearArtificialCalibration(int dimensionIndex)
		{
			this->file->clearArtificialCalibration(dimensionIndex);
		}



		// Gets the original data of the sets and will display in the settings dialog
		// dimension tab
		double getOriginalData(int setIndex, int dimensionIndex)
		{
			return this->file->getOriginalData(setIndex, dimensionIndex);
		}



		// Get the set amount for settings window
		int getSetAmount(System::Void)
		{
			return this->file->getSetAmount();
		}

		// Get the set name for settings window
		std::string* getSetName(int setIndex)
		{
			std::string* str = this->file->getSetName(setIndex);
			return str;
		}

		// Get the class amount for settings window
		int getClassAmount(System::Void)
		{
			return this->file->getClassAmount();
		}

		// Get the class name for settings window
		std::string* getClassName(int classIndex)
		{
			std::string* str = this->file->getClassName(classIndex);
			return str;
		}

		// Checks if we uploaded a file
		bool uploadedFile(System::Void)
		{
			return this->uploadFile;
		}

		// Sets whether the 
		System::Void setAppliedClassChanges(bool applied)
		{
			this->applied = applied;
		}

		// Checks if we applied any changes
		bool appliedClassChanges(System::Void)
		{
			return this->applied;
		}

		std::string *getSetOfClass(int classIndex, int setIndex)
		{
			std::string *str = this->file->getSetOfClass(classIndex, setIndex);
			return str;
		}



		// Sets the background color
		System::Void Background(int r, int g, int b)
		{
			GLfloat red =   ((GLfloat)r) / 255.0f;
			GLfloat green = ((GLfloat)g) / 255.0f;
			GLfloat blue =  ((GLfloat)b) / 255.0f;
			glClearColor(red, green, blue, 0.0f);
		}

		// SET THE RGB VALUES FOR THE COLOR PALETTE
		System::Void SetRGB(GLdouble red, GLdouble green, GLdouble blue) 
		{
			this->R = red;
			this->G = green;
			this->B = blue;
		}


		// both text enabled
		bool textOnEnabled(System::Void)
		{
			return this->textEnabled;
		}

		// text top
		bool textOnTop(System::Void)
		{
			return this->textTop;
		}	

		// both text enabled
		bool textOnBottom(System::Void)
		{
			return this->textBottom;
		}

		System::Void setTextOnEnabled(bool enable)
		{
			this->textEnabled = enable;
		}

		// text top
		System::Void setTextOnTop(bool enable)
		{
			this->textTop = enable;
		}	

		// both text enabled
		System::Void setTextOnBottom(bool enable)
		{
			this->textBottom = enable;
		}

		// zoom setting
		System::Void zoomSet(int i)
		{
			this->zoom = i * 2;
		}

		bool isVisible(int setIndex)
		{
			return this->file->isVisible(setIndex);
		}

		bool resetZoomPan(System::Void)
		{
			this->zoom = 0;
			this->tempXWorldMouseDifference = 0;
			this->tempYWorldMouseDifference = 0;
			return true;
		}


		// THIS ALLOWS FOR THE CHILD WINDOW TO BE RESIZED ACCORDINGLY 
		System::Void Resize(int x, int y, int width, int height, UINT uFlags)		
		{
			this->worldHeight = height;
			this->worldWidth = width;
			SetWindowPos((HWND)this->Handle.ToPointer(), NULL, x, y, width, height, uFlags);
			Reshape((GLsizei)width, (GLsizei)height);
		}

		System::Void Render(System::Void)
		{
			this->Display();
		}


		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC);
		}

		DataInterface* file; // Create the DataInterface for reading the file



	private:

		double worldWidth;  // Set the world width
		double worldHeight; // Set the world height

		GLdouble R; // Red
		GLdouble G; // Green
		GLdouble B; // Blue


		int clickedDimension; // Holds the clicked dimension

		double mouseX; // Holds mouse X coord
		double mouseY; // Holds mouse Y coord

		double worldMouseX; // Holds mouse X coord when mapped to world
		double worldMouseY; // Holds mouse Y coord when mapped to world
		double worldMouseYOnClick; // Holds the world mouse Y when clicked
		double worldMouseXOnClick;

		double tempXWorldMouseDifference;
		double tempYWorldMouseDifference;


		double shiftAmount;

		bool uploadFile; // Checks to see if the file has been uploaded
		bool applied; // checks if changes to the class have been applied
		bool drawingDragged; // Is made true via mouselistener when dragging the mouse
		bool invertDimensionToggled;

		bool shiftHorizontal;
		bool shiftVertical;

		int font_list_base_2d; // set the start of the display lists for the 2d font
		const char *font; // sets the font
		int size; // sets the size of the font

		// text for dimensions
		bool textEnabled;
		bool textTop;
		bool textBottom;

		// zoom variabls
		int zoom;

		HDC m_hDC;
		HGLRC m_hglrc;

	protected:
		~COpenGL(System::Void)
		{
			this->DestroyHandle();
		}

		/* DO NOT REMOVE OR MODIFY THIS */
		/* THIS IS USED TO DRAW OPENGL  */
		/* IN WINDOWS FORMS             */
		GLint MySetPixelFormat(HDC hdc)
		{
			PIXELFORMATDESCRIPTOR pfd = { 
				sizeof(PIXELFORMATDESCRIPTOR),  //  size of this pfd  
				1,                     // version number  
				PFD_DRAW_TO_WINDOW |   // support window  
				PFD_SUPPORT_OPENGL |   // support OpenGL  
				PFD_DOUBLEBUFFER,      // double buffered  
				PFD_TYPE_RGBA,         // RGBA type  
				24,                    // 24-bit color depth  
				0, 0, 0, 0, 0, 0,      // color bits ignored  
				0,                     // no alpha buffer  
				0,                     // shift bit ignored  
				0,                     // no accumulation buffer  
				0, 0, 0, 0,            // accum bits ignored  
				32,                    // 32-bit z-buffer      
				0,                     // no stencil buffer  
				0,                     // no auxiliary buffer  
				PFD_MAIN_PLANE,        // main layer  
				0,                     // reserved  
				0, 0, 0                // layer masks ignored  
			}; 


			GLint  iPixelFormat; 

			// get the device context's best, available pixel format match 
			if((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}

			// make that match the device context's current pixel format 
			if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}

			if((m_hglrc = wglCreateContext(m_hDC)) == NULL)
			{
				MessageBox::Show("wglCreateContext Failed");
				return 0;
			}

			if((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return 0;
			}


			this->glEnableText("Callibri", 22);
			this->glTextBegin();

			return 1;
		}

		// Call this to enable the text such as its font and size
		System::Void glEnableText(const char *font, int size) 
		{
			if (size < 0)
			{
				return;
			}
			this->font = font;
			this->size = size;
		}

		// call this to create the handle of the text to be drawn
		System::Void glTextBegin(System::Void) 
		{
			HFONT font = CreateFont(this->size, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, 0, 0, 0, 0, (LPCTSTR)this->font); // can only use true type fonts 

			// make the system font the device context's selected font  
			SelectObject (m_hDC, font); 

			// create the bitmap display lists  
			// we're making images of glyphs 0 thru 254  
			// the display list numbering starts at 2000, an arbitrary choice  
			wglUseFontBitmaps (m_hDC, 0, 255, this->font_list_base_2d); 
		}

		System::Void glTextColor2d(double red, double green, double blue, double alpha)
		{
			glColor4d(red, green, blue, alpha);
		}


		System::Void glText2d(double x, double y, const char *text)
		{
			glRasterPos2d(x, y);
			int length = (int)std::strlen(text);
			glListBase(this->font_list_base_2d);
			glCallLists(length, GL_UNSIGNED_BYTE, text);
		}


		double getWorldMouseX() {

			// this will get the mouse position relative to the child window
			LPPOINT pts = new POINT;
			GetCursorPos(pts);

			::ScreenToClient((HWND)this->Handle.ToPointer(), pts); // gets the mouse coordinate relative to the OpenGL view

			double xWorld = pts->x - ((this->worldWidth) / 2.0); //::Control::MousePosition.X;

			//MessageBox::Show(""+xWorld);

			// divide by panel width to get the porportion of the window
			xWorld /= this->worldWidth;
			// multiply by the world width to parse the porportion of the window into the world
			xWorld *= this->worldWidth;
			delete pts;
			return xWorld;
		} // Converts raw mouse X coordinates to world coordinates

		double getWorldMouseY() {

			// this will get the mouse position relative to the child window
			LPPOINT pts = new POINT;
			GetCursorPos(pts);

			::ScreenToClient((HWND)this->Handle.ToPointer(), pts); // Gets the mouse position relative to the OpenGL view

			double yWorld = pts->y - (this->worldHeight); //::Control::MousePosition.Y;
			// divide by panel height to get the proportion of the window
			yWorld /= this->worldHeight;
			// multiply by the world height to parse the proportion of the window into the world
			yWorld *= this->worldHeight;
			delete pts;
			return yWorld;
		} // Converts raw mouse Y coordinates to world coordinates


		// this method takes the passed mouse click coordinates and finds the dimension clicked on
		int findClickedDimension(double xMouseWorldPosition, double yMouseWorldPosition){
			double xAxisIncrement = (this->worldWidth) / (this->file->getDimensionAmount() + 1); // +1 instead of +2

			for (int i = 0; i < file->getDimensionAmount(); i++)
			{
				double shiftAmount = this->file->getDimensionShift(i);
				double dimensionX = ((-this->worldWidth) / 2.0) + ((xAxisIncrement) * (i + 1));

				double dimensionYMax = (shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.75);
				double dimensionYMin = (shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.1);

				// creates the bound for the parallel lines
				if (xMouseWorldPosition - (dimensionX) >= -15 && xMouseWorldPosition - (dimensionX) <= 15) {
					return i;
				}
			}
			return -1;
		}

		GLvoid drawDraggedDimension(double x, int dimensionIndex)
		{			

			double xAxisIncrement = this->worldWidth / (this->file->getDimensionAmount() + 1);
			double shiftAmount = this->file->getDimensionShift(dimensionIndex);

			// this will draw the current selected dimension line at half alpha
			glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
			glBegin(GL_LINE_STRIP);
			glVertex2d(x, shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.75);
			glVertex2d(x, shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.1);
			glEnd();

			glLineWidth(3.0);
			glPointSize(3.0);

			// this will draw the current selected dimension text at half alpha
			if (this->textEnabled) {
				glTextColor2d(0.0, 0.0, 0.0, 0.5);
				std::string name = (*this->file->getDimensionName(dimensionIndex));
				std::string temp = "1-";
				temp = temp.append(name);
				if (this->textBottom) {
					if (this->file->isDimensionInverted(dimensionIndex)) {
						glText2d(x - ((temp.length() * 10.0) / 2.0), (shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.05), temp.c_str());
					} else {
						glText2d(x - ((name.length() * 10.0) / 2.0), (shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.05), name.c_str());
					}
				} else {
					if (this->file->isDimensionInverted(dimensionIndex)) {
						glText2d(x - ((temp.length() * 10.0) / 2.0), (shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.78), temp.c_str());
					} else {
						glText2d(x - ((name.length() * 10.0) / 2.0), (shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.78), name.c_str());
					}
				}
				glEnd();
			}

			for (int j = 0; j < file->getSetAmount(); j++)
			{
				std::vector<double>* colorOfCurrent = this->file->getSetColor(j);

				double colorAlpha = (*colorOfCurrent)[3];
				colorAlpha *= 0.5;
				double currentData = this->file->getData(j, dimensionIndex);
				glColor4d((*colorOfCurrent)[0],(*colorOfCurrent)[1],(*colorOfCurrent)[2], colorAlpha);
				glBegin(GL_POINTS); // draws points
				glVertex2d(x, currentData * (worldHeight * 0.5) + (0.175 * worldHeight));
				glEnd(); // ends drawing line
			}
		}


		GLvoid Display(GLvoid) {
			//Set the lines that will mark the x values of the window

			glLineWidth(2.0);
			glClear(GL_COLOR_BUFFER_BIT);

			// Enables the transparency using alpha
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_BLEND);

			// This is an example of how to make text using OpenGL
			// Made by Shane Vance

			/*
			glEnableText("Calibri", 50);
			glTextBegin();
			glTextColor2d(0.0, 0.0, 1.0, 1.0);
			glText2d(-(this->worldWidth / 2.0), this->worldHeight / 2.0, "HELLO THIS IS A TEST TO SEE HOW MANY CHARACTERS I CAN PUT ON THE SCREEN!");
			glFlush();
			*/
			if (this->uploadedFile()) {
				double xAxisIncrement = this->worldWidth / (this->file->getDimensionAmount() + 1); // +1 instead of +2
				glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
				for (int i = 0; i < this->file->getDimensionAmount(); i++)
				{
					double shiftAmount = this->file->getDimensionShift(i);
					glBegin(GL_LINE_STRIP);
					// was (xAxisIncrement) * i
					glVertex2d((-this->worldWidth / 2.0) + ((xAxisIncrement) * (i + 1)), (shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.75));
					glVertex2d((-this->worldWidth / 2.0) + ((xAxisIncrement) * (i + 1)), (shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.1));
					glEnd();

				}
				glFlush();

				// this will display the text for the dimension
				if (this->textEnabled) {
					glTextColor2d(0.0, 0.0, 0.0, 1.0);
					for (int i = 0; i < this->file->getDimensionAmount(); i++) {
						// display dimension text
						double shiftAmount = this->file->getDimensionShift(i);
						std::string name = (*this->file->getDimensionName(i));
						std::string temp = "1-";
						temp = temp.append(name);
						if (this->textBottom) {
							if (this->file->isDimensionInverted(i)) {
								glText2d(((-this->worldWidth - (temp.length() * 10.0)) / 2.0) + ((xAxisIncrement) * (i + 1)), (shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.05), temp.c_str());
							} else {
								glText2d(((-this->worldWidth - (name.length() * 10.0)) / 2.0) + ((xAxisIncrement) * (i + 1)), (shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.05), name.c_str());
							}
						} else {
							if (this->file->isDimensionInverted(i)) {
								glText2d(((-this->worldWidth - (temp.length() * 10.0)) / 2.0) + ((xAxisIncrement) * (i + 1)), (shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.78), temp.c_str());
							} else {
								glText2d(((-this->worldWidth - (name.length() * 10.0)) / 2.0) + ((xAxisIncrement) * (i + 1)), (shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.78), name.c_str());
							}
						}
						glEnd();
					}
					glFlush();
				}

				drawData();
				glFlush();

				if(this->drawingDragged && shiftHorizontal) {

					if (this->clickedDimension != -1){
						this->drawDraggedDimension(this->worldMouseX, this->clickedDimension);
						glFlush();
					} 

				}
			}
		}

		// Graphs the data to the world
		GLvoid drawData(GLvoid) 
		{
			glLineWidth(3.0);
			double xAxisIncrement = this->worldWidth / (this->file->getDimensionAmount()+1);
			if (this->file->isPaintClusters()) {
				for (int j = 0; j < this->file->getClusterAmount(); j++) {
					std::vector<double>* colorOfCurrent = this->file->getClusterColor(j);
					glColor4d((*colorOfCurrent)[0], (*colorOfCurrent)[1], (*colorOfCurrent)[2], (*colorOfCurrent)[3]);
					// draw minimum of cluster
					glBegin(GL_LINE_STRIP); // begins drawing lines
					for (int i = 0; i < this->file->getDimensionAmount(); i++)
					{
						double currentData = this->file->getClusterMinimum(j, i);
						glVertex2d((-this->worldWidth / 2.0) + ((xAxisIncrement) * (i + 1)), (currentData * (this->worldHeight * 0.5)) + (0.175 * this->worldHeight));
					}
					glEnd(); // ends drawing line

					// draw cluster mean
					glBegin(GL_LINE_STRIP); // begins drawing lines
					for (int i = 0; i < this->file->getDimensionAmount(); i++)
					{
						double currentData = this->file->getClusterMiddle(j, i);
						glVertex2d((-this->worldWidth / 2.0) + ((xAxisIncrement) * (i + 1)), (currentData * (this->worldHeight * 0.5)) + (0.175 * this->worldHeight));
					}
					glEnd(); // ends drawing line

					// draw cluster maximum
					glBegin(GL_LINE_STRIP); // begins drawing lines
					for (int i = 0; i < this->file->getDimensionAmount(); i++)
					{
						double currentData = this->file->getClusterMaximum(j, i);
						glVertex2d((-this->worldWidth / 2.0) + ((xAxisIncrement) * (i + 1)), (currentData * (this->worldHeight * 0.5)) + (0.175 * this->worldHeight));
					}
					glEnd(); // ends drawing line
				}
			} else {

				for (int j = 0; j < this->file->getSetAmount(); j++)
				{
					std::vector<double>* colorOfCurrent = this->file->getSetColor(j);
					glColor4d((*colorOfCurrent)[0], (*colorOfCurrent)[1], (*colorOfCurrent)[2], (*colorOfCurrent)[3]);
					glBegin(GL_LINE_STRIP); // begins drawing lines
					for (int i = 0; i < this->file->getDimensionAmount(); i++)
					{
						double currentData = this->file->getData(j, i);
						glVertex2d((-this->worldWidth / 2.0) + ((xAxisIncrement) * (i + 1)), (currentData * (this->worldHeight * 0.5)) + (0.175 * this->worldHeight));
					}
					glEnd(); // ends drawing line
				}
			}
			if (!this->file->togglePaintClusters()) {
				std::vector<int> *list = this->file->getSetsInClass(this->file->getSelectedClassIndex());
				for(int  i = 0; i< list->size(); i++){
					int currentIndex = (*list)[i];
					// set color to the color of the set currentIndex
					// paint set
					std::vector<double>* colorOfCurrent = this->file->getSetColor(currentIndex);
					glColor4d((*colorOfCurrent)[0], (*colorOfCurrent)[1], (*colorOfCurrent)[2], (*colorOfCurrent)[3]);
					glBegin(GL_LINE_STRIP);
					for (int j = 0; j < this->file->getDimensionAmount(); j++)
					{
						double currentData = this->file->getData(currentIndex, j);
						glVertex2d((-this->worldWidth / 2.0) + ((xAxisIncrement) * (j + 1)), (currentData * (this->worldHeight * 0.5)) + (0.175 * this->worldHeight));
					}
					glEnd();
				}
			}

			int selectedSetIndex = file->getSelectedSetIndex();
			std::vector<double>* colorOfCurrent = this->file->getSetColor(selectedSetIndex);
			glColor4d((*colorOfCurrent)[0], (*colorOfCurrent)[1], (*colorOfCurrent)[2], (*colorOfCurrent)[3]);
			glBegin(GL_LINE_STRIP); // begins drawing lines
			for (int i = 0; i < this->file->getDimensionAmount(); i++)
			{
				double currentData = this->file->getData(selectedSetIndex, i);
				glVertex2d((-this->worldWidth / 2.0) + ((xAxisIncrement) * (i + 1)), (currentData * (this->worldHeight * 0.5)) + (0.175 * this->worldHeight));
			}
			glEnd(); // ends drawing line
		}


		// INITIALIZE THE GL SETTINGS
		GLvoid Init(GLvoid)										
		{
			this->Background(194, 206, 218);	        // background is blue-ish gray
		}

		// RESIZE AND INITIALIZE THE GL WINDOW
		GLvoid Reshape(GLsizei width, GLsizei height)		    
		{
			// compute aspect ratio of the new window
			if (height == 0) 
			{
				height = 1; // To prevent divide by 0
			}

			// set the viewport to cover the new window
			glViewport(0, 0, width, height);

			// set the orthosphere and keep center of the screen
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D((((GLdouble)-width + this->tempXWorldMouseDifference) + this->zoom) / 2.0, (((GLdouble)width + this->tempXWorldMouseDifference) - this->zoom) / 2.0, ((((GLdouble)-height / 2.5) + this->zoom) - this->tempYWorldMouseDifference), ((((GLdouble)height - this->zoom) + 100) - this->tempYWorldMouseDifference));
		}


		// THIS IS WHERE ANY BUTTON CLICKS GO // the parent window will need to handle the other key presses
		virtual void WndProc( Message %msg ) override
		{


			switch (msg.Msg)
			{

			case WM_LBUTTONDOWN:
				{
					// get the X and Y coordinates of the mouse position
					this->worldMouseX = this->getWorldMouseX();
					this->worldMouseY = this->getWorldMouseY();

					this->worldMouseYOnClick = this->getWorldMouseY();
					this->worldMouseXOnClick = this->getWorldMouseX();

					// ensures that the clicked dimension is valid
					this->clickedDimension = this->findClickedDimension(this->worldMouseX, this->worldMouseY); //1					


					if (this->invertDimensionToggled)
					{
						this->file->invertDimension(this->clickedDimension);
					}


					double shiftAmount = this->file->getDimensionShift(clickedDimension);
					this->drawingDragged = true;								
				}
				break;

			case WM_MOUSEMOVE:
				{					

					// get the X and Y coordinates of the mouse position
					this->worldMouseX = this->getWorldMouseX();
					this->worldMouseY = this->getWorldMouseY();

					// get the dropped dimension
					int droppedDimension = this->findClickedDimension(this->worldMouseX, this->worldMouseY);

					// update by swapping while passing over dimension
					if (this->drawingDragged && this->shiftHorizontal && this->file->moveData(this->clickedDimension, droppedDimension)) {
						this->clickedDimension = droppedDimension;							
					} else if (this->drawingDragged && this->shiftVertical) {
						this->file->setDimensionShift(this->clickedDimension, (this->shiftAmount + (this->worldMouseYOnClick - this->worldMouseY)/(this->worldHeight * 0.65)));
					} else if (this->drawingDragged && !this->shiftVertical && !this->shiftHorizontal && !this->invertDimensionToggled) {
						this->tempXWorldMouseDifference = worldMouseXOnClick - this->getWorldMouseX();
						this->tempYWorldMouseDifference = worldMouseYOnClick - this->getWorldMouseY();
					}

				}
				break;
			case WM_LBUTTONUP:
				{

					if (this->drawingDragged) {
						// get the X and Y coordinates of the mouse position
						/*this->worldMouseX = this->getWorldMouseX();
						this->worldMouseY = this->getWorldMouseY();
						int droppedDimension = this->findClickedDimension(this->worldMouseX, this->worldMouseY);
						this->file->moveData(this->clickedDimension, droppedDimension);*/
						shiftAmount = 0.0;
						this->drawingDragged = false;
					}

				}
				break;
			}


			NativeWindow::WndProc( msg );

		}

	};
}




// Zooming call reshape 