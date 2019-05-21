// ����� ���C�� DLL �t�@�C���ł��B

#include "stdafx.h"
#include "Sample01.h"

namespace OpenGLForm {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	Sample01::Sample01(System::Void){}
	Sample01::~Sample01(System::Void){}

	//GLfloat pointSize = 5.0f;

	System::Void  Sample01::init(System::Void)
	{
		//---- �f�t�H���g�ݒ�ɖ߂� -----//
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
		glLoadIdentity();
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_DEPTH_TEST);					// Override The Base Initialization's Depth Test
		glDisable(GL_BLEND);							// Enable Blending
		//http://www.myu.ac.jp/~makanae/CG2/cg2_7.html
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	// Back Face Is Filled In
		//glShadeModel(GL_FLAT);
		glMatrixMode(GL_MODELVIEW);

		//---- �����ݒ� ----//
	}

	System::Void Sample01::render(System::Void)
	{
		glClearColor( 0,0,0,0 );
		glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );
		glLoadIdentity();									// Reset the current modelview matrix
		glTranslatef(0.0f, -0.18f, -2.5f);	// Move Left And Into The Screen ����
		//glRotatef(rtri,0.0f,1.0f,0.0f);						// Rotate the triangle on the y axis 

 		glShadeModel( GL_SMOOTH );
		glDrawBuffer( GL_BACK );
		glEnable( GL_DEPTH_TEST );

	
		glClear(GL_COLOR_BUFFER_BIT);		// ��ʂ�����

		// ������`��
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_LINES);
			glVertex2f(-0.9f, 0.9f);
			glVertex2f(-0.6f, 0.6f);

			glVertex2f(-0.6f, 0.9f);
			glVertex2f(-0.9f, 0.6f);
		glEnd();

		// �A������`��
		glBegin(GL_LINE_STRIP);
			glVertex2f(-0.9f, 0.5f);
			glVertex2f(-0.9f, 0.2f);
			glVertex2f(-0.6f, 0.2f);
			glVertex2f(-0.6f, 0.5f);
		glEnd();

		// �����ŗւ�`��
		glBegin(GL_LINE_LOOP);
			glVertex2f(-0.9f,  0.0f);
			glVertex2f(-0.9f, -0.3f);
			glVertex2f(-0.6f, -0.3f);
			glVertex2f(-0.6f,  0.0f);
		glEnd();

		// �O�p�`��`��
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_TRIANGLES);
			glVertex2f(-0.4f, 0.9f);
			glVertex2f(-0.4f, 0.7f);
			glVertex2f(-0.1f, 0.9f);

			glVertex2f(-0.1f, 0.8f);
			glVertex2f(-0.4f, 0.6f);
			glVertex2f(-0.1f, 0.6f);
		glEnd();

		//�A�������O�p�`��`��
		glColor3f(1.0f, 1.0f, 0.0f);
		glBegin(GL_TRIANGLE_STRIP);
			glVertex2f(-0.4f, 0.5f);
			glVertex2f(-0.1f, 0.5f);
			glVertex2f(-0.4f, 0.3f);
			glVertex2f(-0.1f, 0.3f);
			glVertex2f(-0.4f, 0.1f);
		glEnd();

		// �A�������O�p�`�Ő�`��`��
		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(-0.1f, -0.3f);
			glVertex2f(-0.1f,  0.0f);
			glVertex2f(-0.3f, -0.1f);

			glVertex2f(-0.4f, -0.3f);

			glVertex2f(-0.3f, -0.5f);
		glEnd();

		// �l�p�`��`��
		glColor3f(0.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
			glVertex2f(0.1f, 0.9f);
			glVertex2f(0.1f, 0.7f);
			glVertex2f(0.4f, 0.7f);
			glVertex2f(0.4f, 0.9f);

			glVertex2f(0.1f, 0.6f);
			glVertex2f(0.2f, 0.4f);
			glVertex2f(0.3f, 0.4f);
			glVertex2f(0.4f, 0.6f);
		glEnd();

		// �A�������l�p�`��`��
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_QUAD_STRIP);
			glVertex2f(0.1f,  0.0f);
			glVertex2f(0.4f,  0.0f);
			glVertex2f(0.2f, -0.2f);
			glVertex2f(0.3f, -0.2f);

			glVertex2f(0.1f, -0.4f);
			glVertex2f(0.4f, -0.4f);

			glVertex2f(0.2f, -0.6f);
			glVertex2f(0.3f, -0.6f);
		glEnd();

		// ���p�`��`��
		glColor3f(1.0f, 0.0f, 1.0f);
		glBegin(GL_POLYGON);
			glVertex2f(0.7f, 0.9f);
			glVertex2f(0.5f, 0.5f);
			glVertex2f(0.5f, 0.3f);
			glVertex2f(0.6f, 0.1f);
			glVertex2f(0.8f, 0.1f);
			glVertex2f(0.9f, 0.3f);
			glVertex2f(0.9f, 0.5f);
		glEnd();
		glFlush();
	}
}
