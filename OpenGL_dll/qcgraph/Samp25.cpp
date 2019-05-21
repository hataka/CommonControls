#pragma once

#include "stdafx.h"
#include "..\OpenGL.h"
#include "..\Form1.h"
#include "Samp25.h"

namespace OpenGLForm01 {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	Samp25::Samp25(System::Void){}
	Samp25::~Samp25(System::Void){}

	System::Void  Samp25::init(System::Void)
	{
		//---- �f�t�H���g�ݒ�ɖ߂� -----//
		opengl_default_setting();

		//---- �����ݒ� ----//
		glClearColor( 0.0, 0.0, 0.25, 1.0 );
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, 640, 480, 0);
}

	System::Void Samp25::render(System::Void)
	{
  short r1,r2,r3; /*  ���a r1,r1,r3   */
  short x0,y0;    /*  �}�`�̊���W  */
  short cl;       /*  ���F            */
  double x1,y1;   /*  �n�_���W        */
  double x2,y2;   /*  �I�_���W        */
  double t;       /*  �p�x            */

  GLfloat titleColor0[4] = { 1.0, 1.0, 1.0, 1.0 };
  const char *title= "-----  p.44 random pset samp24.c  -----";

  //  _setvideomode(_98RESSCOLOR);

  //  _settextcolor(7);
  //	_settextposition(2,30);
  //	_outtext("�� �b����Ɗ�b�}�` ��\n");
  //	_settextposition(3,20);
  //	_outtext("-----  p.46  ���ː���̐�  samp25.c  ------\n");
   _clearscreen();
  drawString(title, (320/9-strlen(title)/2)*Txx/640, 3,titleColor0);

  r1=30;  r2=280; r3=150;
  x0=320; y0=240; cl=1;

  //glClear(GL_COLOR_BUFFER_BIT);
  for(t=0; t<=2*3.14159265358; t+=3.14159265358/50){
    cl=(int)(t*50/PI)%5+1;
    x1=r1*cos(t);   y1=r1*sin(t);   /*  �n�_���W�̌v�Z  */
    x2=r2*cos(t);   y2=r3*sin(t);   /*  �I�_���W�̌v�Z  */
    draw11(x1,y1,x2,y2,x0,y0,cl);   /*  �����̕`��      */
  }
  glFlush();

   }
}
