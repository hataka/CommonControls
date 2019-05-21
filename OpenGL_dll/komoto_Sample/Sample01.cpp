// これは メイン DLL ファイルです。

#include "stdafx.h"
#include "Sample01.h"

namespace OpenGLForm {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	Sample01::Sample01(System::Void){}
	Sample01::~Sample01(System::Void){}

	//GLfloat pointSize = 5.0f;

	System::Void  Sample01::init(System::Void)
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
	}

	System::Void Sample01::render(System::Void)
	{
		glClearColor( 0,0,0,0 );
		glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );
		glLoadIdentity();									// Reset the current modelview matrix
		glTranslatef(0.0f, -0.18f, -2.5f);	// Move Left And Into The Screen 調整
		//glRotatef(rtri,0.0f,1.0f,0.0f);						// Rotate the triangle on the y axis 

 		glShadeModel( GL_SMOOTH );
		glDrawBuffer( GL_BACK );
		glEnable( GL_DEPTH_TEST );

	
		glClear(GL_COLOR_BUFFER_BIT);		// 画面を消去

		// 直線を描く
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_LINES);
			glVertex2f(-0.9f, 0.9f);
			glVertex2f(-0.6f, 0.6f);

			glVertex2f(-0.6f, 0.9f);
			glVertex2f(-0.9f, 0.6f);
		glEnd();

		// 連続線を描く
		glBegin(GL_LINE_STRIP);
			glVertex2f(-0.9f, 0.5f);
			glVertex2f(-0.9f, 0.2f);
			glVertex2f(-0.6f, 0.2f);
			glVertex2f(-0.6f, 0.5f);
		glEnd();

		// 直線で輪を描く
		glBegin(GL_LINE_LOOP);
			glVertex2f(-0.9f,  0.0f);
			glVertex2f(-0.9f, -0.3f);
			glVertex2f(-0.6f, -0.3f);
			glVertex2f(-0.6f,  0.0f);
		glEnd();

		// 三角形を描く
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_TRIANGLES);
			glVertex2f(-0.4f, 0.9f);
			glVertex2f(-0.4f, 0.7f);
			glVertex2f(-0.1f, 0.9f);

			glVertex2f(-0.1f, 0.8f);
			glVertex2f(-0.4f, 0.6f);
			glVertex2f(-0.1f, 0.6f);
		glEnd();

		//連続した三角形を描く
		glColor3f(1.0f, 1.0f, 0.0f);
		glBegin(GL_TRIANGLE_STRIP);
			glVertex2f(-0.4f, 0.5f);
			glVertex2f(-0.1f, 0.5f);
			glVertex2f(-0.4f, 0.3f);
			glVertex2f(-0.1f, 0.3f);
			glVertex2f(-0.4f, 0.1f);
		glEnd();

		// 連続した三角形で扇形を描く
		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(-0.1f, -0.3f);
			glVertex2f(-0.1f,  0.0f);
			glVertex2f(-0.3f, -0.1f);

			glVertex2f(-0.4f, -0.3f);

			glVertex2f(-0.3f, -0.5f);
		glEnd();

		// 四角形を描く
		glColor3f(0.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
			glVertex2f(0.1f, 0.9f);
			glVertex2f(0.1f, 0.7f);
			glVertex2f(0.4f, 0.7f);
			glVertex2f(0.4f, 0.9f);

			glVertex2f(0.1f, 0.6f);
			glVertex2f(0.2f, 0.4f);
			glVertex2f(0.3f, 0.4f);
			glVertex2f(0.4f, 0.6f);
		glEnd();

		// 連続した四角形を描く
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_QUAD_STRIP);
			glVertex2f(0.1f,  0.0f);
			glVertex2f(0.4f,  0.0f);
			glVertex2f(0.2f, -0.2f);
			glVertex2f(0.3f, -0.2f);

			glVertex2f(0.1f, -0.4f);
			glVertex2f(0.4f, -0.4f);

			glVertex2f(0.2f, -0.6f);
			glVertex2f(0.3f, -0.6f);
		glEnd();

		// 多角形を描く
		glColor3f(1.0f, 0.0f, 1.0f);
		glBegin(GL_POLYGON);
			glVertex2f(0.7f, 0.9f);
			glVertex2f(0.5f, 0.5f);
			glVertex2f(0.5f, 0.3f);
			glVertex2f(0.6f, 0.1f);
			glVertex2f(0.8f, 0.1f);
			glVertex2f(0.9f, 0.3f);
			glVertex2f(0.9f, 0.5f);
		glEnd();
		glFlush();
	}
}
