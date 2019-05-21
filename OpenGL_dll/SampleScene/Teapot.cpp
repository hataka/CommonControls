// http://localhost/cpp/VC++2008/Graphics/OpenGLForm01/SampleScene/Teapot.cpp
#pragma once

#include "stdafx.h"
#include "Teapot.h"

namespace OpenGLForm {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	Teapot::Teapot(System::Void){}
	Teapot::~Teapot(System::Void){}

	System::Void  Teapot::init(System::Void)
	{
		//opengl_default_setting();
		static GLfloat lightPosition[4] = {0.25f, 1.0f, 0.25f, 0.0f};
		static GLfloat lightDiffuse[3] = {1.0f, 1.0f, 1.0f};
		static GLfloat lightAmbient[3] = {0.25f, 0.25f, 0.25f};
		static GLfloat lightSpecular[3] = {1.0f, 1.0f, 1.0f};

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);

		glShadeModel(GL_SMOOTH);

	//glViewport(0, 0, 640.0, 480.0);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0, 640.0 / 480.0, 0.1, 100.0);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.5, 1.5, 2.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

		glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
		glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
		glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
	}

	System::Void Teapot::render(System::Void)
	{
		//glClearColor( 0,0,0,0 );
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear screen and depth buffer
		//glLoadIdentity();									// Reset the current modelview matrix
		//glTranslatef(-1.5f,0.0f,-6.0f);						// Move left 1.5 units and into the screen 6.0
		//glRotatef(rtri,0.0f,1.0f,0.0f);						// Rotate the triangle on the y axis 
	static GLfloat diffuse[3] = {1.0f, 0.0f, 0.0f};
	static GLfloat ambient[3] = {0.25f, 0.25f, 0.25f};
	static GLfloat specular[3] = {1.0f, 1.0f, 1.0f};
	static GLfloat shininess[1] = {32.0f};

	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0f,1.0f,1.0f);					// White

	glutSolidTeapot(0.5);

	glFlush();;												// Done drawing the quad
	static GLfloat lightPosition[4] = {0.25f, 1.0f, 0.25f, 0.0f};
	static GLfloat lightDiffuse[3] = {1.0f, 1.0f, 1.0f};
	static GLfloat lightAmbient[3] = {0.25f, 0.25f, 0.25f};
	static GLfloat lightSpecular[3] = {1.0f, 1.0f, 1.0f};

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glShadeModel(GL_SMOOTH);

	//glViewport(0, 0, 640.0, 480.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 640.0 / 480.0, 0.1, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.5, 1.5, 2.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
//		rtri+=1.0f;											// Increase the rotation variable for the triangle
//		rquad-=0.75f;										// Decrease the rotation variable for the quad
	}
}
