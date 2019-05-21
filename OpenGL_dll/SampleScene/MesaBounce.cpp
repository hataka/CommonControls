#pragma once

#include "stdafx.h"
#include "MesaBounce.h"

namespace OpenGLForm {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

#define COS(X)   cos( (X) * 3.14159/180.0 )
#define SIN(X)   sin( (X) * 3.14159/180.0 )

#define RED 1
#define WHITE 2
#define CYAN 3
/*
GLboolean IndexMode = GL_FALSE;
GLuint Ball;
GLenum Mode;
GLfloat Zrot = 0.0, Zstep = 180.0;
GLfloat Xpos = 0.0, Ypos = 1.0;
GLfloat Xvel = 2.0, Yvel = 0.0;
GLfloat Xmin = -4.0, Xmax = 4.0;
GLfloat Ymin = -3.8, Ymax = 4.0;
GLfloat G = -9.8;
*/
	GLboolean MesaBounce::IndexMode;
	GLuint MesaBounce::Ball;
	GLenum MesaBounce::Mode;
	GLfloat MesaBounce::Zrot = 0.0,MesaBounce::Zstep = 180.0;
	GLfloat MesaBounce::Xpos= 0.0,MesaBounce::Ypos= 1.0;
	GLfloat MesaBounce::Xvel = 2.0, MesaBounce::Yvel = 0.0;
	GLfloat MesaBounce::Xmin = -4.0, MesaBounce::Xmax = 4.0;
	GLfloat MesaBounce::Ymin = -3.8, MesaBounce::Ymax = 4.0;
	GLfloat MesaBounce::G = -9.8;


	MesaBounce::MesaBounce(System::Void)
	{
		IndexMode = GL_FALSE;
		Zrot = 0.0, Zstep = 180.0;
		Xpos = 0.0, Ypos = 1.0;
		Xvel = 2.0, Yvel = 0.0;
		Xmin = -4.0, Xmax = 4.0;
		Ymin = -3.8, Ymax = 4.0;
		G = -9.8;
	}

	MesaBounce::~MesaBounce(System::Void){}

	System::Void  MesaBounce::init(System::Void)
	{
		Ball = MakeBall();
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);
		glDisable(GL_DITHER);
		glShadeModel(GL_FLAT);
	}

	System::Void MesaBounce::render(System::Void)
	{
		GLint i;

		//glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// 必要
		glLoadIdentity();									// Reset The Current Modelview Matrix
		glTranslatef(0.0f, -0.0f, -15.0f);	// Move Into The Screen 調整

		glIndexi(CYAN);
  		glColor3f(0, 1, 1);
  		glBegin(GL_LINES);
  			for (i = -5; i <= 5; i++) {
    			glVertex2i(i, -5);
    			glVertex2i(i, 5);
  			}
  			for (i = -5; i <= 5; i++) {
    			glVertex2i(-5, i);
    			glVertex2i(5, i);
  			}
  			for (i = -5; i <= 5; i++) {
    			glVertex2i(i, -5);
    			glVertex2f(i * 1.15, -5.9);
  			}
  			glVertex2f(-5.3, -5.35);
			glVertex2f(5.3, -5.35);
  			glVertex2f(-5.75, -5.9);
  			glVertex2f(5.75, -5.9);
  		glEnd();

		glPushMatrix();
		glTranslatef(Xpos, Ypos, 0.0);
		glScalef(2.0, 2.0, 2.0);
		glRotatef(8.0, 0.0, 0.0, 1.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glRotatef(Zrot, 0.0, 0.0, 1.0);

		glCallList(Ball);

		glPopMatrix();

		glFlush();

	// mesa bounce.c のidlefunc をここに入れる
		static float vel0 = -100.0;
  		static double t0 = -1.;
  		double t, dt;
		// #include <glut.h> 必要
  		t = glutGet(GLUT_ELAPSED_TIME) / 1000.;
  		if (t0 < 0.)
     		t0 = t;
  		dt = t - t0;
  		t0 = t;

		Zrot += Zstep*dt;

		Xpos += Xvel*dt;
		if (Xpos >= Xmax) {
			Xpos = Xmax;
			Xvel = -Xvel;
			Zstep = -Zstep;
  		}
		if (Xpos <= Xmin) {
			Xpos = Xmin;
			Xvel = -Xvel;
			Zstep = -Zstep;
		}
		Ypos += Yvel*dt;
		Yvel += G*dt;
		if (Ypos < Ymin) {
			Ypos = Ymin;
			if (vel0 == -100.0)
				vel0 = fabs(Yvel);
			Yvel = vel0;
  		}
	}

	unsigned MesaBounce::MakeBall()
	{
		GLuint list;
		GLfloat a, b;
		GLfloat da = 18.0, db = 18.0;
		GLfloat radius = 1.0;
		GLuint color;
		GLfloat x, y, z;

		list = glGenLists(1);

		glNewList(list, GL_COMPILE);

		color = 0;
		for (a = -90.0; a + da <= 90.0; a += da) {
			glBegin(GL_QUAD_STRIP);
			for (b = 0.0; b <= 360.0; b += db) {
				if (color) {
					glIndexi(RED);
					glColor3f(1, 0, 0);
      		} else {
					glIndexi(WHITE);
        			glColor3f(1, 1, 1);
				}

				x = radius * COS(b) * COS(a);
				y = radius * SIN(b) * COS(a);
				z = radius * SIN(a);
				glVertex3f(x, y, z);

				x = radius * COS(b) * COS(a + da);
				y = radius * SIN(b) * COS(a + da);
				z = radius * SIN(a + da);
				glVertex3f(x, y, z);

				color = 1 - color;
    		}
    		glEnd();

  		}
  		glEndList();
  		return list;
	}
}
