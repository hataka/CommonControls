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
		//---- デフォルト設定に戻す -----//
		opengl_default_setting();

		//---- 初期設定 ----//
		glClearColor( 0.0, 0.0, 0.25, 1.0 );
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, 640, 480, 0);
		gluPerspective(45.0f,(GLfloat)640.0/(GLfloat)480.0,0.1f,100.0f);
}

	System::Void Samp26::render(System::Void)
	{
  short i,no,r;      /*  回数,角数,半径  */
  short x0,y0;       /*  図形の基準座標  */
  short cl;
  short sf;       /*  線色,拡大係数   */
  double xp=0.0,yp=0.0;       /*  星の中心座標    */
  GLfloat titleColor0[4] = { 1.0, 1.0, 1.0, 1.0 };
	const char *title= "-----  p.58  star samp26.c  ------";

  //  _setvideomode(_98RESSCOLOR);

  //  _settextcolor(7);
  //  _settextposition(2,30);
  //  _outtext("◆ Ｃ言語と基礎図形 ◆\n");
  //  _settextposition(3,20);
  //  _outtext("-----  p.58  星型　　　　  samp26.c  ------\n");

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
