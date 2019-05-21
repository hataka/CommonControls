#pragma once

#include "stdafx.h"
#include "gl04_1.h"

#define PI_OVER_180 0.0174532925

namespace OpenGLForm {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	GL04_1::GL04_1(System::Void){}
	GL04_1::~GL04_1(System::Void){}

	System::Void  GL04_1::init(System::Void)
	{
		//---- �f�t�H���g�ݒ�ɖ߂� -----//
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
		glLoadIdentity();
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_DEPTH_TEST);					// Override The Base Initialization's Depth Test
		glDisable(GL_BLEND);							// Enable Blending
		//http://www.myu.ac.jp/~makanae/CG2/cg2_7.html
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	// Back Face Is Filled In
		//glShadeModel(GL_FLAT);
		glMatrixMode(GL_MODELVIEW);

		//---- �����ݒ� ----//
		glLoadIdentity();
	}

	System::Void GL04_1::render(System::Void)
	{
		glClearColor( 0,0,0,0 );
		glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );
		glLoadIdentity();									// Reset the current modelview matrix
		glTranslatef(0.0f, -0.0f, -3.5f);	// Move Left And Into The Screen ����
		//glRotatef(rtri,0.0f,1.0f,0.0f);						// Rotate the triangle on the y axis 

		//glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
			glVertex2f(-0.9f , 0.9f);
			glVertex2f(-0.9f , -0.9f);
		glVertex2f(0.9f , 0.9f);
		glEnd();
		glFlush();
	}
}
