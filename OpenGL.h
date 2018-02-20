#pragma once

/*
Authors: Shane Vance, Nico Espitia, Brennan Barni, Daniel Ortyn
Last Update: 2018/15/02
Purpose: CS 481 Project
*/

#include "stdafx.h"
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


			this->drawingDragged = false;
			this->clickedDimension = -1;

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
		System::Void SetFilePath(std::string filepath)
		{	
			// read the file
			this->file->readFile(&filepath);
		}

		// BUTTON METHODS GO HERE //
		System::Void incrementSelectedSet(System::Void)
		{
			int selectedSetIndex = this->file->getSelectedSetIndex();
			selectedSetIndex++;
			if(selectedSetIndex >= this->file->getSetAmount()){
				selectedSetIndex = 0;
			}
			this->file->setSelectedSetIndex(selectedSetIndex);
		}

		System::Void decrementSelectedSet(System::Void)
		{
			int selectedSetIndex = this->file->getSelectedSetIndex();
			selectedSetIndex--;
			if(selectedSetIndex < 0){
				selectedSetIndex = this->file->getSetAmount()-1;
			}
			this->file->setSelectedSetIndex(selectedSetIndex);
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

		System::Void hypercube(System::Void)
		{
			if(this->file->isPaintCluster())
			{
				this->file->togglePaintCluster();
			}else{
				int selectedSetIndex = this->file->getSelectedSetIndex();
				this->file->hypercube(selectedSetIndex, 0.2);
			}
		}

		/*
		System::Void save(System::Void)
		{
		std::string fileName = "testOutput.txt";
		file->readFile(&fileName);
		std::cout << "VisCanvas Custom Output" << std::endl;
		for(unsigned int i = 0; i < file->getSetAmount(); i++)
		{
		std::cout << file->getSetName(i);
		for(unsigned int j = 0; j < file->getDimensionAmount(); j++)
		{
		if(j == 0)
		{
		std::cout << file->getSetName(i) << ",";
		}
		else if(j == file->getDimensionAmount() - 1)
		{
		std::cout << file->getData(i,j) << std::endl;
		}
		else
		{
		std::cout << file->getDimensionData(i,j) << ",";
		}
		}
		}

		}
		*/


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

		// Gets the color for the set
		std::vector<double>* getSetColor(int setIndex)
		{
			return this->file->getSetColor(setIndex);
		}


		// Get the dimension amount for settings window
		int getDimensionAmount(System::Void)
		{
			return this->file->getDimensionAmount();
		}

		// Get the dimension name for settings window
		std::string* getDimensionName(int dimensionIndex)
		{
			std::string* str = this->file->getDimensionName(dimensionIndex);
			return str;
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

	private:

		double worldWidth;  // Set the world width
		double worldHeight; // Set the world height

		GLdouble R; // Red
		GLdouble G; // Green
		GLdouble B; // Blue

		/* Create the DataInterface for reading the file */
		DataInterface* file;

		int clickedDimension;

		double mouseX; // Holds mouse X coord
		double mouseY; // Holds mouse Y coord

		double worldMouseX; // Holds mouse X coord when mapped to world
		double worldMouseY; // Holds mouse Y coord when mapped to world





		bool drawingDragged; // Is made true via mouselistener when dragging the mouse


		HDC m_hDC;
		HGLRC m_hglrc;

	protected:
		~COpenGL(System::Void)
		{
			this->DestroyHandle();
		}

		/* DO NOT REMOVE OR MODIFY THIS */
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

			return 1;
		}




		
		double getWorldMouseX(){

			// this will get the mouse position relative to the child window
			LPPOINT pts = new POINT;
			GetCursorPos(pts);
			::ScreenToClient((HWND)this->Handle.ToPointer(), pts);

			double xWorld = pts->x - (worldWidth / 2.0); //::Control::MousePosition.X;
			// divide by panel width to get the porportion of the window
			xWorld /= worldWidth;
			// multiply by the world width to parse the porportion of the window into the world
			xWorld *= worldWidth;

			return xWorld;
		} // Converts raw mouse X coordinates to world coordinates

		double getWorldMouseY(){

			// this will get the mouse position relative to the child window
			LPPOINT pts = new POINT;
			GetCursorPos(pts);
			::ScreenToClient((HWND)this->Handle.ToPointer(), pts);

			double yWorld = pts->y - (worldHeight / 2.0); //::Control::MousePosition.Y;
			// divide by panel height to get the proportion of the window
			yWorld /= worldHeight;
			// multiply by the world height to parse the proportion of the window into the world
			yWorld *= worldHeight;

			return yWorld;
		} // Converts raw mouse Y coordinates to world coordinates


		// this method takes the passed mouse click coordinates and finds the dimension clicked on
		int findClickedDimension(double xMouseWorldPosition, double yMouseWorldPosition){
			double xAxisIncrement = this->worldWidth / (this->file->getDimensionAmount() + 1); // +1 instead of +2

			for (int i = 0; i < file->getDimensionAmount(); i++)
			{
				double shiftAmount = this->file->getDimensionShift(i);
				double dimensionX = (-this->worldWidth / 2.0) + ((xAxisIncrement) * (i + 1));

				double dimensionYMax = (shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.75);
				double dimensionYMin = (shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.1);

				// creates the bound for the parallel lines
				if (xMouseWorldPosition - (dimensionX) >= -6 && xMouseWorldPosition - (dimensionX) <= 6) {
					if ((dimensionYMax / 2.0) - dimensionYMin >= yMouseWorldPosition) {
							return i;
					}
				}
			}
			return -1;
		}

		GLvoid drawDraggedDimension(double x, double y, int dimensionIndex)
		{			
			
			double xAxisIncrement = worldWidth / (this->file->getDimensionAmount() + 1);
			double shiftAmount = this->file->getDimensionShift(dimensionIndex);

			glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
			glBegin(GL_LINE_STRIP);
				glVertex2d(x, shiftAmount * (worldHeight * 0.5) + worldHeight * 0.75);
				glVertex2d(x, shiftAmount * (worldHeight * 0.5) + worldHeight * 0.1);
			glEnd();

			glLineWidth(3.0);
			glPointSize(3.0);

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
			glEnable( GL_BLEND );


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


			drawData();
			glFlush();


			if(this->drawingDragged) {
				if (this->clickedDimension != -1){
					drawDraggedDimension(this->worldMouseX, this->worldMouseY, this->clickedDimension);
					glFlush();
				}
			}

		}

		// Graphs the data to the world
		GLvoid drawData(GLvoid) 
		{
			glLineWidth(3.0);
			double xAxisIncrement = this->worldWidth / (this->file->getDimensionAmount()+1);
			if (this->file->isPaintCluster()) {
				std::vector<double>* colorOfCurrent = this->file->getClusterColor();
				glColor4d((*colorOfCurrent)[0], (*colorOfCurrent)[1], (*colorOfCurrent)[2], (*colorOfCurrent)[3]);
				// draw minimum of cluster
				glBegin(GL_LINE_STRIP); // begins drawing lines
				for (int i = 0; i < this->file->getDimensionAmount(); i++)
				{
					double currentData = this->file->getClusterMinimum(i);
					glVertex2d((-this->worldWidth / 2.0) + ((xAxisIncrement) * (i + 1)), (currentData * (this->worldHeight * 0.5)) + (0.175 * this->worldHeight));
				}
				glEnd(); // ends drawing line

				// draw cluster mean
				glBegin(GL_LINE_STRIP); // begins drawing lines
				for (int i = 0; i < this->file->getDimensionAmount(); i++)
				{
					double currentData = this->file->getClusterMean(i);
					glVertex2d((-this->worldWidth / 2.0) + ((xAxisIncrement) * (i + 1)), (currentData * (this->worldHeight * 0.5)) + (0.175 * this->worldHeight));
				}
				glEnd(); // ends drawing line

				// draw cluster maximum
				glBegin(GL_LINE_STRIP); // begins drawing lines
				for (int i = 0; i < this->file->getDimensionAmount(); i++)
				{
					double currentData = this->file->getClusterMaximum(i);
					glVertex2d((-this->worldWidth / 2.0) + ((xAxisIncrement) * (i + 1)), (currentData * (this->worldHeight * 0.5)) + (0.175 * this->worldHeight));
				}
				glEnd(); // ends drawing line

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
			gluOrtho2D((GLdouble)-width / 2.0, (GLdouble)width / 2.0, (GLdouble)-height / 2.5, (GLdouble)height + 100);

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

					// ensures that the clicked dimension is valid
					this->clickedDimension = this->findClickedDimension(this->worldMouseX, this->worldMouseY); //1					
											
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
					if (this->drawingDragged && this->file->moveData(this->clickedDimension, droppedDimension)) {
						this->clickedDimension = droppedDimension;							
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
						this->drawingDragged = false;
					}


				}
				break;
			}



			NativeWindow::WndProc( msg );

		}




	};
}