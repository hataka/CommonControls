/***********************************************************************
	BMP Texture Mapping
	Date : Oct 11, 2007
	Version : 1.0
	Author : Pocol
	Memo :
*************************************************************************/
#pragma once

//#include <iostream>
//#include <GL/glut.h>
#include "stdafx.h"
#include "TextureBMP.h"

namespace OpenGLForm {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	int TextureBMP::WindowPositionX = 100;
	int TextureBMP::WindowPositionY = 100;
	int TextureBMP::WindowWidth = 512;
	int TextureBMP::WindowHeight = 512;
	//char WindowTitle[33];//  = "Texture Mapping (3) - BMP File -";
	BMPImage TextureBMP::texture;


	TextureBMP::TextureBMP(System::Void)
	{
		WindowPositionX = 100;
		WindowPositionY = 100;
		WindowWidth = 512;
		WindowHeight = 512;
		//WindowTitle = "Texture Mapping (3) - BMP File -";
	}

	TextureBMP::~TextureBMP(System::Void){}

	System::Void  TextureBMP::init(System::Void)
	{
		//---- �f�t�H���g�ݒ�ɖ߂� -----//
		//---- �����ݒ� ----//
		glClearColor(0.3, 0.3, 1.0, 1.0);
		glEnable(GL_DEPTH_TEST);
		//�@�e�N�X�`���̃��[�h
		texture.Load("F:\\cpp\\VC++2008\\Graphics\\OpenGLForm01\\Data\\TextureBMP_sample.bmp");
	}

	System::Void TextureBMP::render(System::Void)
	{
		double size = 0.5;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// �K�v
		glLoadIdentity();									// Reset The Current Modelview Matrix
		glTranslatef(0.0f, -0.0f, -2.0f);	// Move Into The Screen ����

		//�@�e�N�X�`���}�b�s���O�L����
		glEnable(GL_TEXTURE_2D);
		//�@�e�N�X�`�����o�C���h
		glBindTexture(GL_TEXTURE_2D, texture.ID);
		//�@�F�̎w��
		glColor4f(1.0, 1.0, 1.0, 1.0);
		//�@�l�p�`���e�N�X�`�����W���ŕ`��
		glBegin(GL_QUADS);
			glTexCoord2d(0.0, 0.0);	glVertex3d(-size, -size, 0.0);
			glTexCoord2d(0.0, 1.0);	glVertex3d(-size, size, 0.0);
			glTexCoord2d(1.0, 1.0);		glVertex3d(size, size, 0.0);
			glTexCoord2d(1.0, 0.0);	glVertex3d(size, -size, 0.0);
		glEnd();
		glFlush();
		//�@
		glBindTexture(GL_TEXTURE_2D, 0);
		//�@�e�N�X�`���}�b�s���O������
		glDisable(GL_TEXTURE_2D);
		//glutSwapBuffers();

	}
}
