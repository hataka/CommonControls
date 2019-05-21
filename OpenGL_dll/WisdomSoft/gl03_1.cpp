
// これは メイン DLL ファイルです。
#pragma once
#include "stdafx.h"
#include "gl03_1.h"

namespace OpenGLForm {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	GL03_1::GL03_1(System::Void){}
	GL03_1::~GL03_1(System::Void){}

	System::Void  GL03_1::init(System::Void)
	{
		//---- デフォルト設定に戻す -----//
/*
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
*/
		//---- 初期設定 ----//
		//glLoadIdentity();
		//glOrtho(0, 640, 480, 0, -1, 1);
}

	System::Void GL03_1::render(System::Void)
	{
		glClearColor( 0,0,0,0 );
		glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_ACCUM_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		//glClear(GL_COLOR_BUFFER_BIT );
		glLoadIdentity();									// Reset the current modelview matrix
		glTranslatef(0.0f, -0.0f, -2.2f);	// Move Left And Into The Screen 調整
		//glRotatef(rtri,0.0f,1.0f,0.0f);						// Rotate the triangle on the y axis 

		glBegin(GL_TRIANGLES);
    		glColor3ub(0xFF , 0 , 0);
			glVertex2f(0.0f , 0.0f);
			glVertex2f(-1.0f , 0.9f);
			glVertex2f(1.0f , 0.9f);

			glVertex2f(0.0f , 0.0f);
			glVertex2f(-1.0f , -0.9f);
			glVertex2f(1.0f , -0.9f);
		glEnd();
		glFlush();
	}
}
