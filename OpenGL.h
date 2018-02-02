#pragma once

/*
Authors: Shane Vance, Nico Espitia, Brennan Barni, Daniel Ortyn
Last Update: 2018/29/01
Purpose: CS 481 Project
*/

#include "stdafx.h"
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
			cp->Y = 0;
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

			this->file = new DataInterface();

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			// check if everything went A-Okay when creating the Child Handle
			if(m_hDC)
			{
				MySetPixelFormat(m_hDC);
				Reshape(iWidth, iHeight);
				Init();
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
			if(selectedSetIndex>=this->file->getSetAmount()){
				selectedSetIndex = 0;
			}
			this->file->setSelectedSetIndex(selectedSetIndex);
		}

		System::Void decrementSelectedSet(System::Void)
		{
			int selectedSetIndex = this->file->getSelectedSetIndex();
			selectedSetIndex--;
			if(selectedSetIndex<0){
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
			// do something
			MessageBox::Show("hypercube");
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

		// Sets the background color
		System::Void Background(int R, int G, int B)
		{
			GLfloat Red = R / 255.0f;
			GLfloat Green = G / 255.0f;
			GLfloat Blue = B / 255.0f;
			glClearColor(Red, Green, Blue, 0.0f);
		}

		// SET THE RGB VALUES FOR THE COLOR PALETTE
		System::Void SetRGB(GLdouble Red, GLdouble Green, GLdouble Blue) 
		{
			this->R = Red;
			this->G = Green;
			this->B = Blue;
		}

		// This is if the options panel is open
		System::Void ReshapeToPanels(int width, int height)
		{
			Reshape(width, height);
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
			Display();
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

		
		// THIS IS WHERE ANY BUTTON CLICKS GO // the parent window will need to handle the other key presses
		virtual void WndProc( Message %msg ) override
		{
			switch (msg.Msg)
			{

			case WM_LBUTTONDOWN:
				{			
				//	MessageBox::Show("THIS IS A TEST: LEFT BUTTON");
				}
				break;
			}

			NativeWindow::WndProc( msg );
		}
		



		GLvoid Display(GLvoid)
		{
			//Set the lines that will mark the x values of the window
			glLineWidth(2.0);
			glClear(GL_COLOR_BUFFER_BIT);
			double xAxisIncrement = worldWidth/(this->file->getDimensionAmount()+2);
			glColor3f(0.0f, 0.0f, 0.0f);

			for (int i = 0; i < file->getDimensionAmount(); i++)
			{
				double shiftAmount = this->file->getDimensionShift(i);
				glBegin(GL_LINE_STRIP);
				glVertex2d((xAxisIncrement) * i, shiftAmount * (worldHeight * 0.5) + worldHeight * 0.75);
				glVertex2d((xAxisIncrement) * i, shiftAmount * (worldHeight * 0.5) + worldHeight * 0.1);
				glEnd();
			}

			drawData();
			glFlush();

		}

		// Graphs the data to the world
		GLvoid drawData(GLvoid) 
		{
			glLineWidth(3.0);
			double xAxisIncrement = worldWidth/(this->file->getDimensionAmount()+2);
			for (int j = 0; j < file->getSetAmount(); j++)
			{
				std::vector<double>* colorOfCurrent = this->file->getSetColor(j);
				glColor4d((*colorOfCurrent)[0],(*colorOfCurrent)[1],(*colorOfCurrent)[2], (*colorOfCurrent)[3]);
				glBegin(GL_LINE_STRIP); // begins drawing lines
				for (int i = 0; i < file->getDimensionAmount(); i++)
				{
					double currentData = this->file->getData(j, i);
					glVertex2d((xAxisIncrement) * i, currentData * (worldHeight * 0.5) + (0.175 * worldHeight));
				}
				glEnd(); // ends drawing line
			}
		}


		// INITIALIZE THE GL SETTINGS
		GLvoid Init(GLvoid)										
		{
			Background(194, 206, 218);	             		    // background is white
			glColor3f(0.0f, 0.0f, 0.0f);				        // drawing color is black
			glPointSize(4.0);						            // 'dot' is 2x2 pixels
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
			gluOrtho2D(((GLdouble)-width + 100.0) / 2.0, (GLdouble) width + 100.0, ((GLdouble)-height + 100.0) / 2.0, (GLdouble)height + 100.0);
		}
	};
}