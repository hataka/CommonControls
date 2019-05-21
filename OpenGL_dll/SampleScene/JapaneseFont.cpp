#pragma once

//#include <iostream>
//#include <GL/glut.h>
#include "stdafx.h"
#include "JapaneseFont.h"

namespace OpenGLForm {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	int JapaneseFont::g_WndWidth  = 800;
	int JapaneseFont::g_WndHeight = 600;
	BitmapFont JapaneseFont::g_Font;	// 日本語フォント表示用.
	unsigned int JapaneseFont::g_FrameCount = 0;

	JapaneseFont::JapaneseFont(System::Void)
	{
		g_WndWidth = 800;
		g_WndHeight = 600;
		g_FrameCount = 0;
	
	}
	JapaneseFont::~JapaneseFont(System::Void){}

	//--------------------------------------------------------------------------------------------------
	// Name : Render2D()
	// Desc : 2次元シーンの描画.
	//--------------------------------------------------------------------------------------------------
	void JapaneseFont::Render2D()
	{
		//　3D　→　2D
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, g_WndWidth, g_WndHeight, 0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		//
		// 文字列描画.
		//
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glRasterPos2i(30, 30);
		g_Font.DrawStringW(L"日本語表示サンプルプログラム");
		glRasterPos2i(30, 55);
		g_Font.DrawStringW(L"OpenGLのウィンドウ上に日本語を表示しています");
		glRasterPos2i(30, 80);
		g_Font.DrawStringW(L"現在のフレームカウント:%d", g_FrameCount);

		//　2D　→　3D
		glPopMatrix();
		glLoadIdentity();
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
	}

	//--------------------------------------------------------------------------------------------------
	// Name : Render3D()
	// Desc : 3次元シーンの描画.
	//--------------------------------------------------------------------------------------------------
	void JapaneseFont::Render3D()
	{
		const float dif[4] = { 1.0, 1.0, 1.0, 1.0 };
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
		glColor4f(0.0f, 1.0f, 0.25f, 1.0f);
		glRotatef((float)g_FrameCount, 1.0f, 1.0f, 1.0f);
		glutSolidTeapot(1.0);
	}

	System::Void  JapaneseFont::init(System::Void)
	{
		//---- デフォルト設定に戻す -----//
		//opengl_default_setting();

		//---- 初期設定 ----//
		glClearColor(0.39, 0.58, 0.92, 1.0);
		glEnable(GL_DEPTH_TEST);
		glShadeModel(GL_SMOOTH);
		g_Font.CreateW(L"メイリオ", 24);
	}

	System::Void JapaneseFont::render(System::Void)
	{
		// 必要
		//glLoadIdentity();							// Reset the current modelview matrix
		//glTranslatef(0.0f, -0.0f, -2.2f);	// Move Left And Into The Screen 調整

		//　バックバッファをクリア.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//　モデルビュー行列の設定.
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		//　視点の設定.
		gluLookAt(
			0.0, 0.0, -5.0,
			0.0, 0.0, 0.0,
			0.0, 1.0, 0.0);	

		//
		glPushMatrix();
	
		//　3Dシーンの描画.
		Render3D();	

		//　2Dシーンの描画.
		Render2D();
	
		glPopMatrix();

		//----- 以下のreshapefuncの搭載はだめ ----
		//double aspectRatio = 1.0;

		//g_WndWidth = w;
		//g_WndHeight = h;
		//aspectRatio = (double)800/(double)600;

		//glViewport(0, 0, g_WndWidth, g_WndHeight);
		//glMatrixMode(GL_PROJECTION);
		//glLoadIdentity();
		//gluPerspective(45.0, aspectRatio, 0.1, 1000.0);
		
		//ダブルバッファ.
		//glutSwapBuffers();
		//-------------------------------------
		g_FrameCount++;
	}
}
