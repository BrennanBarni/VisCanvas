#pragma once

/*
Author: Shane Vance and Nico Espitia
Last Update: 2018/27/01
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

			// set the initial height and width for later
			this->worldWidth = iWidth;
			this->worldHeight = iHeight;

			this->file = new DataInterface();

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			// check if everything went A-Okay when creating the Child Handle
			if(m_hDC)
			{
				MySetPixelFormat(m_hDC);
				Reshape(iWidth, iHeight);
				glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
				//Init();
			}
		}

		// SET THE FILE PATH THAT WILL BE USED TO GRAPH THE DATA
		System::Void SetFilePath(std::string filepath)
		{	
			// read the file
			this->file->readFile(&filepath);

			// clear the view and initialize GL
			glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
			Init();
		}

		/// TEST BUTTON ///
		System::Void testButtonMethod()
		{
				 int setAmount = file->getSetAmount();
				 if(5>setAmount)
				 {
					 // do nothing
				 }else
				 {
					 double mean = file->getMean(5);
					 file->level(5,mean);
				 }
		}


		// SET THE RGB VALUES FOR THE COLOR PALETTE
		System::Void SetRGB(GLdouble Red, GLdouble Green, GLdouble Blue) 
		{
			this->R = Red;
			this->G = Green;
			this->B = Blue;
		}

		// RED BALUE 
		int getRed()
		{
			return (int) this->R;
		}

		// GREEN VALUE
		int getGreen()
		{
			return (int) this->G;
		}

		// BLUE VALUE
		int getBlue()
		{
			return (int) this->B;
		}

		// THIS ALLOWS FOR THE CHILD WINDOW TO BE RESIZED ACCORDINGLY 
		System::Void Resize(int x, int y, int width, int height, UINT uFlags)		
		{
			this->worldHeight = height;
			this->worldWidth= width;
			SetWindowPos((HWND)this->Handle.ToPointer(), NULL, x, y, width, height, uFlags);
			Reshape((GLsizei)width, (GLsizei)height);
		}

		System::Void Display(System::Void)
		{
			//Set the lines that will mark the x values of the window
			glClear(GL_COLOR_BUFFER_BIT);

			glColor3f(0.0, 0.0, 0.0);
			glBegin(GL_LINE_STRIP);
			glVertex2d(40, worldHeight * 0.75);
			glVertex2d(40, worldHeight * 0.1);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glVertex2d(80, worldHeight * 0.75);
			glVertex2d(80, worldHeight * 0.1);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glVertex2d(120, worldHeight * 0.75);
			glVertex2d(120, worldHeight * 0.1);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glVertex2d(160, worldHeight * 0.75);
			glVertex2d(160, worldHeight * 0.1);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glVertex2d(200, worldHeight * 0.75);
			glVertex2d(200, worldHeight * 0.1);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glVertex2d(240, worldHeight * 0.75);
			glVertex2d(240, worldHeight * 0.1);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glVertex2d(280, worldHeight * 0.75);
			glVertex2d(280, worldHeight * 0.1);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glVertex2d(320, worldHeight * 0.75);
			glVertex2d(320, worldHeight * 0.1);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glVertex2d(360, worldHeight * 0.75);
			glVertex2d(360, worldHeight * 0.1);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glVertex2d(400, worldHeight * 0.75);
			glVertex2d(400, worldHeight * 0.1);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glVertex2d(440, worldHeight * 0.75);
			glVertex2d(440, worldHeight * 0.1);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glVertex2d(480, worldHeight * 0.75);
			glVertex2d(480, worldHeight * 0.1);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glVertex2d(520, worldHeight * 0.75);
			glVertex2d(520, worldHeight * 0.1);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glVertex2d(560, worldHeight * 0.75);
			glVertex2d(560, worldHeight * 0.1);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glVertex2d(600, worldHeight * 0.75);
			glVertex2d(600, worldHeight * 0.1);
			glEnd();


			drawData();

			glFlush();
		}


		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC);
		}

	private:
		double worldWidth;  // Gets the initial window width
		double worldHeight; // Gets the initial window height

		GLdouble R; // Red
		GLdouble G; // Green
		GLdouble B; // Blue

		/* TODO: Convert to OpenGL RGB */
		/* to do this follow the example (ex: 233/255.0f where 233 is the RGB value */ 
		// GLdouble ogR; // Red
		// GLdouble ogG; // Green
		// GLdouble ogB; // Blue

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
				// left click
			case WM_LBUTTONDOWN:
				{						
					MessageBox::Show("THIS IS A TEST: LEFT BUTTON");
				}
				break;
			}

			NativeWindow::WndProc( msg );
		}






		// INITIALIZE THE GL SETTINGS
		GLvoid Init(GLvoid)										
		{
			glClearColor(1.0f, 1.0f, 1.0f, 0.0f);			    // background is white
			glColor3f(0.0f, 0.0f, 0.0f);				        // drawing color is black
			glPointSize(2.0);						            // 'dot' is 2x2 pixels
		}


		void drawData() 
		{

			for (int j = 0; j < file->getSetAmount(); j++){
				//const float* color = file->getColor(file->getSetClass(j));
				glBegin(GL_LINE_STRIP); // begins drawing lines
				glColor3f(0.8f,0.1f,0.1f);
				for (int i = 0; i < file->getDimensionAmount(); i++){
					double currentData = file->getData(j, i);
					glVertex2d(40.0 * (i + 1), currentData * (worldHeight * 0.5) + (0.175 * worldHeight));
				}
				glEnd(); // ends drawing line
			}
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
			gluOrtho2D((GLdouble)-width / 2.0f, (GLdouble)width, (GLdouble)-height / 2.0f, (GLdouble)height); // center the ortho

		}
	};
}
