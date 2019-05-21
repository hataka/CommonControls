#pragma once

#include "stdafx.h"
#include "..\OpenGL.h"
#include "..\Form1.h"
#include "Samp23.h"

namespace OpenGLForm01 {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	Samp23::Samp23(System::Void){}
	Samp23::~Samp23(System::Void){}

	System::Void  Samp23::init(System::Void)
	{
		//---- デフォルト設定に戻す -----//
		opengl_default_setting();

		//---- 初期設定 ----//
		glClearColor( 0.0, 0.0, 0.25, 1.0 );
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, 640, 480, 0);
}

	System::Void Samp23::render(System::Void)
	{
  short i,x1,y1,x2,y2,cl;
  static GLushort dash0 = 0xFFFF, // {4},
    dash1 = 0xF0F0, //{4,4,4,4},
    dash2 = 0x1010, //{1,1,1,1},
    dash3 = 0x3333, //{2,2,2,2},
    dash4 = 0xF22F, //{5,2,2,2,5},
    dash5 = 0x8888; //{4,2,1,3,1,1,4};

  //_settextposition(2,30);
  //_outtext("◆ Ｃ言語と基礎図形 ◆");
  //_settextposition(3,20);
  //_outtext("------- p.40  直線の型　　 samp23.c -------");
  GLfloat titleColor0[4] = { 1.0, 1.0, 1.0, 1.0 };
  const char *title= "-----  p.40 line style samp23.c  -----";

  _clearscreen();

  drawString(title, (320/9-strlen(title)/2), 2,titleColor0);

  x1=120; y1=120; x2=520;
  y2=y1; cl=6;

//  XSetLineAttributes(_d,_gc,1,LineOnOffDash, CapButt, JoinMiter);
  for(i=0; i<6; i++){
    switch (i) {
      case 0:
	_setlinestyle(dash0);
      break;
    case 1:
      _setlinestyle(dash1);
      break;
    case 2:
      _setlinestyle(dash2);
      break;
    case 3:
      _setlinestyle(dash3);
      break;
    case 4:
      _setlinestyle(dash4);
      break;
    case 5:
      _setlinestyle(dash5);
      break;
    }

    _setcolor(cl);
    _moveto(x1,y1);
    _lineto(x2,y2);
    y1+=50; y2+=50; cl--;
  }
  glFlush();
   }
}
