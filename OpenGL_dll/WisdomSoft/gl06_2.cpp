// これは メイン DLL ファイルです。

#include "stdafx.h"
#include "GL06_2.h"

namespace OpenGLForm {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	GL06_2::GL06_2(System::Void){}
	GL06_2::~GL06_2(System::Void){}

	//GLfloat pointSize = 5.0f;

	System::Void  GL06_2::init(System::Void)
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

	System::Void GL06_2::render(System::Void)
	{
		//glGetFloatv(GL_LINE_WIDTH , &width);
		// void glLineWidth(GLfloat width);

		glClearColor( 0,0,0,0 );
		glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );
		glLoadIdentity();									// Reset the current modelview matrix
		glTranslatef(0.0f, -0.0f, -3.5f);	// Move Left And Into The Screen 調整

		glLineWidth(5.0f);
  		glBegin(GL_LINE_LOOP);
    		glVertex2f(0.0f , -0.9f);
    		glVertex2f(-0.9f , 0.9f);
    		glVertex2f(0.9f , 0.9f);
  		glEnd();
  		glFlush();
	}
}
