// これは メイン DLL ファイルです。

#include "stdafx.h"
#include "gl03_4.h"

#define PI_OVER_180 0.0174532925

namespace OpenGLForm {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	GL03_4::GL03_4(System::Void){}
	GL03_4::~GL03_4(System::Void){}

	System::Void  GL03_4::init(System::Void)
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

	System::Void GL03_4::render(System::Void)
	{

		glClearColor( 0,0,0,0 );
		glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );
		glLoadIdentity();									// Reset the current modelview matrix
		glTranslatef(0.0f, -0.0f, -3.5f);	// Move Left And Into The Screen 調整
		//glRotatef(rtri,0.0f,1.0f,0.0f);						// Rotate the triangle on the y axis 

		double x, y;
		double r = 0;

		//glClearColor(0 , 0 , 0 , 0);
		//glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0f , 0.0f , 1.0f);

		glPointSize(1);
		//glBegin(GL_POINTS);{
		//glBegin(GL_LINE_LOOP);{
		glBegin(GL_POLYGON);
		{
			for(r = 0; r<360; r++){
				x = 0.8*cos(r * PI_OVER_180);
				y = 0.5*sin(r * PI_OVER_180);
				glVertex3d(x,y,0);
			}
  		}
  	 	glEnd();
  		glFlush();
	}
}
