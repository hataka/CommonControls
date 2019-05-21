#pragma once

#include "stdafx.h"
#include "..\OpenGL.h"
#include "..\Form1.h"
#include "Samp26.h"

namespace OpenGLForm01 {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	Samp26::Samp26(System::Void){}
	Samp26::~Samp26(System::Void){}

	System::Void  Samp26::init(System::Void)
	{
		//---- �f�t�H���g�ݒ�ɖ߂� -----//
		opengl_default_setting();

		//---- �����ݒ� ----//
		glClearColor( 0.0, 0.0, 0.25, 1.0 );
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, 640, 480, 0);
		gluPerspective(45.0f,(GLfloat)640.0/(GLfloat)480.0,0.1f,100.0f);
}

	System::Void Samp26::render(System::Void)
	{
  short i,no,r;      /*  ��,�p��,���a  */
  short x0,y0;       /*  �}�`�̊���W  */
  short cl;
  short sf;       /*  ���F,�g��W��   */
  double xp=0.0,yp=0.0;       /*  ���̒��S���W    */
  GLfloat titleColor0[4] = { 1.0, 1.0, 1.0, 1.0 };
	const char *title= "-----  p.58  star samp26.c  ------";

  //  _setvideomode(_98RESSCOLOR);

  //  _settextcolor(7);
  //  _settextposition(2,30);
  //  _outtext("�� �b����Ɗ�b�}�` ��\n");
  //  _settextposition(3,20);
  //  _outtext("-----  p.58  ���^�@�@�@�@  samp26.c  ------\n");

  cl=1;   no=5;   r=10;
  x0=320; y0=240; sf=10;

	gluPerspective(45.0f,(GLfloat)640.0/(GLfloat)480.0,0.1f,100.0f);
	//glViewport(0, 0, 640, 480);
  _clearscreen();
  //glClear(GL_COLOR_BUFFER_BIT);
 drawString(title, (320/9-strlen(title)/2), 0,titleColor0);
  for(i=1; i<=6; i++){
    cl++;   sf++;
    star11(no, r, xp, yp, x0, y0, cl, sf);
  }
  glFlush();

  //  _settextcolor(7);
  //  _settextposition(23,2);

   }
}
