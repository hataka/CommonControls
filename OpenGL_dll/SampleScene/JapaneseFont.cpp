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
	BitmapFont JapaneseFont::g_Font;	// ���{��t�H���g�\���p.
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
	// Desc : 2�����V�[���̕`��.
	//--------------------------------------------------------------------------------------------------
	void JapaneseFont::Render2D()
	{
		//�@3D�@���@2D
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, g_WndWidth, g_WndHeight, 0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		//
		// ������`��.
		//
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glRasterPos2i(30, 30);
		g_Font.DrawStringW(L"���{��\���T���v���v���O����");
		glRasterPos2i(30, 55);
		g_Font.DrawStringW(L"OpenGL�̃E�B���h�E��ɓ��{���\�����Ă��܂�");
		glRasterPos2i(30, 80);
		g_Font.DrawStringW(L"���݂̃t���[���J�E���g:%d", g_FrameCount);

		//�@2D�@���@3D
		glPopMatrix();
		glLoadIdentity();
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
	}

	//--------------------------------------------------------------------------------------------------
	// Name : Render3D()
	// Desc : 3�����V�[���̕`��.
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
		//---- �f�t�H���g�ݒ�ɖ߂� -----//
		//opengl_default_setting();

		//---- �����ݒ� ----//
		glClearColor(0.39, 0.58, 0.92, 1.0);
		glEnable(GL_DEPTH_TEST);
		glShadeModel(GL_SMOOTH);
		g_Font.CreateW(L"���C���I", 24);
	}

	System::Void JapaneseFont::render(System::Void)
	{
		// �K�v
		//glLoadIdentity();							// Reset the current modelview matrix
		//glTranslatef(0.0f, -0.0f, -2.2f);	// Move Left And Into The Screen ����

		//�@�o�b�N�o�b�t�@���N���A.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//�@���f���r���[�s��̐ݒ�.
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		//�@���_�̐ݒ�.
		gluLookAt(
			0.0, 0.0, -5.0,
			0.0, 0.0, 0.0,
			0.0, 1.0, 0.0);	

		//
		glPushMatrix();
	
		//�@3D�V�[���̕`��.
		Render3D();	

		//�@2D�V�[���̕`��.
		Render2D();
	
		glPopMatrix();

		//----- �ȉ���reshapefunc�̓��ڂ͂��� ----
		//double aspectRatio = 1.0;

		//g_WndWidth = w;
		//g_WndHeight = h;
		//aspectRatio = (double)800/(double)600;

		//glViewport(0, 0, g_WndWidth, g_WndHeight);
		//glMatrixMode(GL_PROJECTION);
		//glLoadIdentity();
		//gluPerspective(45.0, aspectRatio, 0.1, 1000.0);
		
		//�_�u���o�b�t�@.
		//glutSwapBuffers();
		//-------------------------------------
		g_FrameCount++;
	}
}
