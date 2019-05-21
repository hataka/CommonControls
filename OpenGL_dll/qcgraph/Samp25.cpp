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
		//---- デフォルト設定に戻す -----//
		opengl_default_setting();

		//---- 初期設定 ----//
		glClearColor( 0.0, 0.0, 0.25, 1.0 );
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, 640, 480, 0);
}

	System::Void Samp25::render(System::Void)
	{
  short r1,r2,r3; /*  半径 r1,r1,r3   */
  short x0,y0;    /*  図形の基準座標  */
  short cl;       /*  線色            */
  double x1,y1;   /*  始点座標        */
  double x2,y2;   /*  終点座標        */
  double t;       /*  角度            */

  GLfloat titleColor0[4] = { 1.0, 1.0, 1.0, 1.0 };
  const char *title= "-----  p.44 random pset samp24.c  -----";

  //  _setvideomode(_98RESSCOLOR);

  //  _settextcolor(7);
  //	_settextposition(2,30);
  //	_outtext("◆ Ｃ言語と基礎図形 ◆\n");
  //	_settextposition(3,20);
  //	_outtext("-----  p.46  放射線状の線  samp25.c  ------\n");
   _clearscreen();
  drawString(title, (320/9-strlen(title)/2)*Txx/640, 3,titleColor0);

  r1=30;  r2=280; r3=150;
  x0=320; y0=240; cl=1;

  //glClear(GL_COLOR_BUFFER_BIT);
  for(t=0; t<=2*3.14159265358; t+=3.14159265358/50){
    cl=(int)(t*50/PI)%5+1;
    x1=r1*cos(t);   y1=r1*sin(t);   /*  始点座標の計算  */
    x2=r2*cos(t);   y2=r3*sin(t);   /*  終点座標の計算  */
    draw11(x1,y1,x2,y2,x0,y0,cl);   /*  直線の描画      */
  }
  glFlush();

   }
}
