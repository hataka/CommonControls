// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。

#pragma once

// TODO: プログラムに必要な追加ヘッダーをここで参照してください。
#include <windows.h>		// Header File For Windows
#include <GL/gl.h>		// Header File For The OpenGL32 Library
#include <GL/glu.h>		// Header File For The GLu32 Library
#include <gl/glaux.h>	// Header File For The Glaux Library
#include <stdio.h>		// Header File For Standard Input/Output
#include <math.h>
//#include <string>
//#include <vector> 
//#include <cstdio>
//#include <cstdarg>
//#include <cassert>

void opengl_default_setting(void);

#ifndef OPENGL_DEFAULT_SETTING
#define OPENGL_DEFAULT_SETTING \
		/*---- デフォルト設定に戻す -----*/ \
		glDisable(GL_LIGHTING); \
		glDisable(GL_LIGHT0); \
		glDisable(GL_LIGHT1); \
		glLoadIdentity(); \
		glDisable(GL_TEXTURE_2D); \
		glDisable(GL_CULL_FACE);	\
		glEnable(GL_DEPTH_TEST);	 \
		glDisable(GL_BLEND);							/* Enable Blending */ \
		/* http://www.myu.ac.jp/~makanae/CG2/cg2_7.html */ \
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	/* Back Face Is Filled In */ \
		/* glShadeModel(GL_FLAT); */ \
		glMatrixMode(GL_MODELVIEW); 
#endif /* OPENGL_DEFAULT_SETTING */

//int panel_width;

