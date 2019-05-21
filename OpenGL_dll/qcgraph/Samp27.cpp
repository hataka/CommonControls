#pragma once

#include "stdafx.h"
#include "..\OpenGL.h"
#include "..\Form1.h"
#include "Samp27.h"

namespace OpenGLForm01 {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	Samp27::Samp27(System::Void){}
	Samp27::~Samp27(System::Void){}

	System::Void  Samp27::init(System::Void)
	{
		//---- �f�t�H���g�ݒ�ɖ߂� -----//
		opengl_default_setting();

		//---- �����ݒ� ----//
		glClearColor( 0.0, 0.0, 0.25, 1.0 );
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, 640, 480, 0);
}

	System::Void Samp27::render(System::Void)
	{
 short i,r1,r2;      /*  ��,���a  */
  short x0,y0,m,cl;   /*  �}�`�̊���W,����ϐ�,���F  */
  double t,fx,fy;     /*  �p�x,���W�lfx,fy    */
  double tx,ty,th;    /*  ���s�ړ���,��]�p�x     */
  double sx,sy,shx,shy;   /*  �g��E�k���E���]�E����f    */
  GLfloat titleColor0[4] = { 1.0, 1.0, 1.0, 1.0 };



  //  _setvideomode(_98RESSCOLOR);

  //  _settextcolor(7);
  //  _settextposition(2,30);
  //  _outtext("�� �b����Ɗ�b�}�` ��\n");
  //  _settextposition(3,20);
  // _outtext("-----  p.78  �ȉ~�̕ϊ��@  samp27.c  ------\n");

  r1=200; r2=40;  x0=320; y0=250;
  cl=1;   tx=50.0;    ty=90.0;    th=3*PI/4;
  sx=0.5; sy=0.5; shx=0.1;    shy=0.9;

  _clearscreen();

  drawString("----- transformation  samp27.c p.78 -----", 14, 0,titleColor0);

  _setcolor(15);
  _moveto(0,250); _lineto(640,250);
  _moveto(320,0); _lineto(320,480);

  for(i=1; i<6; i++){
    m=1;    cl++;
    for(t=0; t<=2.1*PI; t+=PI/40){
      fx=r1*cos(t);   fy=r2*sin(t);
      switch (i) {
      case 2: trans2(&fx,&fy,tx,ty);
	break;
      case 3: rotat2(&fx,&fy,th);
	break;
      case 4: scale2(&fx,&fy,sx,sy);
	break;
      case 5: shear2(&fx,&fy,shx,shy);
	break;
      }
      draw22(fx,fy,x0,y0,&m,cl);
    }
  }
  glFlush();
   }
}
