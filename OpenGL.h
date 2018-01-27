#pragma once

/*
Author: Shane Vance
Last Update: 2018/25/01
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
			
				// Specify the form as the parent.
	     		cp->Parent = parentForm->Handle;

				// Create as a child of the specified parent and make OpenGL compliant (no clipping)
				cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
				
				// Create the actual window
				this->CreateHandle(cp);

				// Set the initial height and width for later
				this->iWidth = iWidth;
				this->iHeight = iHeight;

				this->file = new DataInterface();

				m_hDC = GetDC((HWND)this->Handle.ToPointer());
			
				// Check if everything went A-Okay when creating the Child Handle
				if(m_hDC)
				{
					MySetPixelFormat(m_hDC);
					Reshape(iWidth, iHeight);
					glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
					//Init();
				}
		}

		
		System::Void SetFilePath(std::string filepath)
		{	
			/* Read the file */
			this->file->readFile(&filepath);
			glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
			Init();
		}
	
		System::Void SetRGB(GLdouble Red, GLdouble Green, GLdouble Blue) 
		{
			this->R = Red;
			this->G = Green;
			this->B = Blue;
		}

		int getRed()
		{
			return (int) this->R;
		}

		int getGreen()
		{
			return (int) this->G;
		}

		int getBlue()
		{
			return (int) this->B;
		}

		// This allows for the child window to be resized accordingly
		System::Void Resize(int x, int y, int width, int height, UINT uFlags)		
		{
				this->iHeight = height;
				this->iWidth= width;
				SetWindowPos((HWND)this->Handle.ToPointer(), NULL, x, y, width, height, uFlags);
				Reshape((GLsizei)width, (GLsizei)height);
		}

		System::Void Display(System::Void)
		{
				//Set the lines that will mark the x values of the window
				glClear(GL_COLOR_BUFFER_BIT);

				glColor3f(0.0, 0.0, 0.0);
				glBegin(GL_LINE_STRIP);
					glVertex2d(40, 435);
					glVertex2d(40, iHeight * .1);
				glEnd();
				/*
				glBegin(GL_LINE_STRIP);
					glVertex2d(80, 435);
					glVertex2d(80, iHeight * .1);
				glEnd();
				*/
				glBegin(GL_LINE_STRIP);
					glVertex2d(120, 435);
					glVertex2d(120, iHeight * .1);
				glEnd();
				/*
				glBegin(GL_LINE_STRIP);
					glVertex2d(160, 435);
					glVertex2d(160, iHeight * .1);
				glEnd();
				*/
				glBegin(GL_LINE_STRIP);
					glVertex2d(200, 435);
					glVertex2d(200, iHeight * .1);
				glEnd();
				/*
				glBegin(GL_LINE_STRIP);
					glVertex2d(240, 435);
					glVertex2d(240, iHeight * .1);
				glEnd();
				*/
				glBegin(GL_LINE_STRIP);
					glVertex2d(280, 435);
					glVertex2d(280, iHeight * .1);
				glEnd();
				/*
				glBegin(GL_LINE_STRIP);
					glVertex2d(320, 435);
					glVertex2d(320, iHeight * .1);
				glEnd();
				*/
				glBegin(GL_LINE_STRIP);
					glVertex2d(360, 435);
					glVertex2d(360, iHeight * .1);
				glEnd();
				/*
				glBegin(GL_LINE_STRIP);
					glVertex2d(400, 435);
					glVertex2d(400, iHeight * .1);
				glEnd();
				*/
				glBegin(GL_LINE_STRIP);
					glVertex2d(440, 435);
					glVertex2d(440, iHeight * .1);
				glEnd();
				/*
				glBegin(GL_LINE_STRIP);
					glVertex2d(480, 435);
					glVertex2d(480, iHeight * .1);
				glEnd();
				*/
				glBegin(GL_LINE_STRIP);
					glVertex2d(520, 435);
					glVertex2d(520, iHeight * .1);
				glEnd();
				/*
				glBegin(GL_LINE_STRIP);
					glVertex2d(560, 435);
					glVertex2d(560, iHeight * .1);
				glEnd();
				*/
				glBegin(GL_LINE_STRIP);
					glVertex2d(600, 435);
					glVertex2d(600, iHeight * .1);
				glEnd();
				glFlush();
				

		}


		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC);
		}

	private:
		int iWidth;  // Gets the initial window width
		int iHeight; // Gets the initial window height

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


		// DO NOT REMOVE OR MODIFY THIS 
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

		bool Init(GLvoid)										// All setup for OpenGL goes here
		{
			glClearColor(1.0, 1.0, 1.0, 0.0);			        //Background is white
			glColor3f(0.0f, 0.0f, 0.0f);				        //Drawing color is black
			glPointSize(2.0);						            //'dot' is 2x2 pixels
			return TRUE;										// Initialisation went OK!
		}

		/* Resize and initialise the GL window */
		GLvoid Reshape(GLsizei width, GLsizei height)		    
		{
				// Compute aspect ratio of the new window
			   if (height == 0) 
			   {
				   height = 1;                // To prevent divide by 0
			   }
 
			   // Set the viewport to cover the new window
			   glViewport(0, 0, width, height);

			   // set the orthosphere and keep center of the screen
			   glMatrixMode(GL_PROJECTION);
			   glLoadIdentity();
			   gluOrtho2D((GLdouble)-width / 2.0, (GLdouble)width, (GLdouble)-height / 2.0, (GLdouble)height); // center the ortho to the center

		}
	};
}