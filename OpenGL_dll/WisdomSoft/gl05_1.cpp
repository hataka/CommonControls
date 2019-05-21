#pragma once

#include "stdafx.h"
#include "gl05_1.h"

#define PI_OVER_180 0.0174532925

namespace OpenGLForm {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	GL05_1::GL05_1(System::Void){}
	GL05_1::~GL05_1(System::Void){}

	System::Void  GL05_1::init(System::Void)
	{
		//---- デフォルト設定に戻す -----//
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

		//---- 初期設定 ----//
		glLoadIdentity();
	}

	System::Void GL05_1::render(System::Void)
	{
		GLfloat fore[4] , back[4];

		glGetFloatv(GL_CURRENT_COLOR , back);
		glGetFloatv(GL_COLOR_CLEAR_VALUE , fore);

		glClearColor(back[0] , back[1] , back[2] , back[3]);
		glClear(GL_COLOR_BUFFER_BIT);
		//glClearColor( 0,0,0,0 );
		//glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );
		glLoadIdentity();									// Reset the current modelview matrix
		glTranslatef(0.0f, -0.0f, -3.5f);	// Move Left And Into The Screen 調整
		//glRotatef(rtri,0.0f,1.0f,0.0f);						// Rotate the triangle on the y axis 

		//glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(back[0] , back[1] , back[2] , back[3]);
		glClear(GL_COLOR_BUFFER_BIT);

		glColor3fv(fore);
		glBegin(GL_TRIANGLES);
			glVertex2f(0 , -0.9f);
			glVertex2f(-0.9f , 0.9f);
			glVertex2f(0.9f , 0.9f);
		glEnd();
		glFlush();
	}
}
