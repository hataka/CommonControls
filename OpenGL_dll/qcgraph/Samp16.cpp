#pragma once

#include "stdafx.h"
#include "..\OpenGL.h"
#include "..\Form1.h"
#include "Samp16.h"

namespace OpenGLForm01 {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	Samp16::Samp16(System::Void){}
	Samp16::~Samp16(System::Void){}

	System::Void  Samp16::init(System::Void)
	{
		//---- �f�t�H���g�ݒ�ɖ߂� -----//
		opengl_default_setting();

		//---- �����ݒ� ----//
		glClearColor( 0.0, 0.0, 0.25, 1.0 );
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//gluOrtho2D(0, 640, 480, 0);
		glOrtho(0, 640, 480, 0, -1, 1);
}

	System::Void Samp16::render(System::Void)
	{
		// �K�v
		//glLoadIdentity();									// Reset the current modelview matrix
		//glTranslatef(0.0f, -0.0f, -2.2f);	// Move Left And Into The Screen ����

  		int p[][2] = {{320,120},{120,320},{520,320}};
  		unsigned int mask[32];
  		int iCount;

  		GLfloat titleColor0[4] = { 1.0, 1.0, 1.0, 1.0 };
  		const char *title= "-----  p.19 triangle(3) samp16.c  -----";

  		_clearscreen();
			drawString(title, (320/9-strlen(title)/2)-2, 3,titleColor0);

  		for(iCount = 0 ; iCount < 32 ; iCount++) mask[iCount] = 0xF0F0F0F0;
		  _setcolor(YELLOW);
  			_tilepaint(mask);
  			_fillPolygon(p,3);
  		glFlush();
  }
}
