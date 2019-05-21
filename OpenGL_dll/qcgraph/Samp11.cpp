#pragma once

#include "stdafx.h"
#include "..\OpenGL.h"
#include "..\Form1.h"
#include "Samp11.h"
#include "..\font.h"

namespace OpenGLForm01 {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	Samp11::Samp11(System::Void){}
	Samp11::~Samp11(System::Void){}

	System::Void  Samp11::init(System::Void)
	{
		//---- �f�t�H���g�ݒ�ɖ߂� -----//
		opengl_default_setting();

		//---- �����ݒ� ----//
		//BitmapFont g_Font = new BitmapFont;
		g_Font.CreateW(L"���C���I", 24);
		glClearColor( 0.0, 0.0, 0.25, 1.0 );
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, 640, 480, 0, -1, 1);
	}

	System::Void Samp11::render(System::Void)
	{
		// �K�v
		glLoadIdentity();									// Reset the current modelview matrix
		//glTranslatef(0.0f, -0.0f, -2.2f);	// Move Left And Into The Screen ����
		
		GLfloat titleColor0[4] = { 1.0, 1.0, 1.0, 1.0 };
  	_clearscreen();
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glRasterPos2i(glx(18*9), gly(3*18));
	//glRasterPos2i(30, 30);
		g_Font.DrawStringW(L"���{��\���T���v���v���O����");
  	drawString("-----  line(1) samp11.c  p.2  ------", 18, 3,titleColor0);
  	_setcolor(6);
  	_moveto(120,240);
  	_lineto(520,240);
		glFlush();
	}
}
