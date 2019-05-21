#pragma once

#include "stdafx.h"
#include "..\OpenGL.h"
#include "..\Form1.h"
#include "Samp17.h"

namespace OpenGLForm01 {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	Samp17::Samp17(System::Void){}
	Samp17::~Samp17(System::Void){}

	System::Void  Samp17::init(System::Void)
	{
		//---- デフォルト設定に戻す -----//
		opengl_default_setting();

		//---- 初期設定 ----//
		glClearColor( 0.0, 0.0, 0.25, 1.0 );
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, 640, 480, 0);
}

	System::Void Samp17::render(System::Void)
	{
		short i,x1,y1,x2,y2,x3,y3,cl;
		// マスク用の変数の宣言
		static unsigned int tile1[32]; /* 1番目のマスク */
		static unsigned int tile2[32]; /* 1番目のマスク */
		static unsigned int tile3[32]; /* 1番目のマスク */

 		GLfloat titleColor0[4] = { 1.0, 1.0, 1.0, 1.0 };
		const char *title= "-----  p.28 tilepaint(1) samp17.c  -----";
		// 必要
		//glLoadIdentity();									// Reset the current modelview matrix
		//glTranslatef(0.0f, -0.0f, -2.2f);	// Move Left And Into The Screen 調整

   	_clearscreen();
  		drawString(title, (320/9-strlen(title)/2)-2, 3,titleColor0);

 		for(i = 0 ; i < 32 ; i++) tile1[i] = 0xFFFFFFFF;
 		for(i = 0 ; i < 32 ; i++) tile2[i] = 0xF0F0F0F0;
 		for(i = 0 ; i < 32 ; i++) tile3[i] = 0xCCCCCCCC;

  		x1=100; y1=100; x2=540; y2=200; x3=340; y3=150; cl=6;
		
  		for( i=1; i<=3; i++){
    		int p[4][2] = {{x1,y1},{x2,y1},{x2,y2},{x1,y2}};

    		_setcolor(cl);
    		//_rectangle(_GFILLINTERIOR, x1, y1,x2,y2);
    		//_rectangle(_GBORDER, x1, y1,x2,y2);

    		switch(i) {
      		case 1:
					//	_setcolor(MAGENTA);
					_tilepaint(tile1);
					_fillPolygon(p,4);
					break;
      		case 2:
					//	_setcolor(YELLOW);
					_tilepaint(tile2);
					_fillPolygon(p,4);
					break;
      		case 3:
					//	_setcolor(CYAN);
					_tilepaint(tile3);
					_fillPolygon(p,4);
				break;
    		}
    		y1 +=100; y2 +=100; y3 = (y1+y2)/2; cl-=2;
  		}
  		glFlush();
   }
}
