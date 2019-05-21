#pragma once

#include "stdafx.h"
#include "..\OpenGL.h"
#include "..\Form1.h"
#include "Samp24.h"

namespace OpenGLForm01 {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	Samp24::Samp24(System::Void){}
	Samp24::~Samp24(System::Void){}

	System::Void  Samp24::init(System::Void)
	{
		//---- ƒfƒtƒHƒ‹ƒgİ’è‚É–ß‚· -----//
		opengl_default_setting();

		//---- ‰Šúİ’è ----//
		glClearColor( 0.0, 0.0, 0.25, 1.0 );
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, 640, 480, 0);
}

	System::Void Samp24::render(System::Void)
	{
  short i,j,k;
  short j1,j2;
  short x1,y1,x2,y2;
  double cl,dark;
  GLfloat titleColor0[4] = { 1.0, 1.0, 1.0, 1.0 };
  const char *title= "-----  p.44 random pset samp24.c  -----";

   _clearscreen();
  drawString(title, (320/9-strlen(title)/2)*Txx/640, 2,titleColor0);


  //  _setvideomode(_98RESSCOLOR);
  // _setbkcolor(DARK_BLUE);
  //  _settextcolor(7);
  // _settextposition(2,30);
  // _outtext("Ÿ ‚bŒ¾Œê‚ÆŠî‘b}Œ` Ÿ\n");
  //  _settextposition(3,20);
  //  _outtext("----- p.44  —”‚É‚æ‚é”Z’W  samp24.c ------\n");

  x1=100; y1=100;
  x2=540; y2=200;
  cl=6;

  for(i=1; i<=3; i++){
    _setcolor(cl);

    _rectangle(_GBORDER,x1,y1,x2,y2);

    j1=100+100*(i-1);
    j2=200+100*(i-1);
    for(j=j1; j<=j2; j++) {
      for(k=100; k<=540; k++){
	dark=(irnd()/3276.7);
	/* dark = (rand()/RAND_MAX)*10.0; */
	if(dark <= i*2 ) _setpixel(k,j);
	/* _setpixel(k,j); */
      }
    }

   y1+=100;
    y2+=100;
    cl--;
  }

  //  _settextcolor(7);
  //  _settextposition(23,2);
  glFlush();
   }
}
