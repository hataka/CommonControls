// -*- mode: cpp -*-  Time-stamp: <2010-11-04 16:50:01 kahata>
/*================================================================
 * title: 
 * file: Teapot.cpp
 * path: F:\cpp\OpenGL\NeHe_glut\Teapot\Teapot.cpp
 * url:  http://localhost/cpp/OpenGL/NeHe_glut/Teapot/Teapot.cpp
 * created: Time-stamp: <2010-11-04 16:50:01 kahata>
 * revision: $Id$
 * Programmed By: kahata
 * To compile:
 * To run: 
 * link: 
 * description: 
 *================================================================*/

#include <windows.h>   // Standard Header For MSWindows Applications
#include <gl/glut.h>   // The GL Utility Toolkit (GLUT) Header
//#include "glut.h"

// Window Size
#define WIDTH  (800) //CW_USEDEFAULT
#define HEIGHT (600) //CW_USEDEFAULT
// center
int posx = ( GetSystemMetrics( SM_CXSCREEN ) - WIDTH ) / 2;
int posy = ( GetSystemMetrics( SM_CYSCREEN ) - HEIGHT ) / 2;

// The Following Directive Fixes The Problem With Extra Console Window
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

void reshape(int width, int height)
{
	static GLfloat lightPosition[4] = {0.25f, 1.0f, 0.25f, 0.0f};
	static GLfloat lightDiffuse[3] = {1.0f, 1.0f, 1.0f};
	static GLfloat lightAmbient[3] = {0.25f, 0.25f, 0.25f};
	static GLfloat lightSpecular[3] = {1.0f, 1.0f, 1.0f};

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glShadeModel(GL_SMOOTH);

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)width / (double)height, 0.1, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.5, 1.5, 2.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
}


void display()
{
	static GLfloat diffuse[3] = {1.0f, 0.0f, 0.0f};
	static GLfloat ambient[3] = {0.25f, 0.25f, 0.25f};
	static GLfloat specular[3] = {1.0f, 1.0f, 1.0f};
	static GLfloat shininess[1] = {32.0f};

	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glutSolidTeapot(0.5);

	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
//	glutInitWindowPosition(100, 100);
	glutInitWindowPosition(posx,posy);
//	glutInitWindowSize(640, 480);
  	glutInitWindowSize  ( WIDTH, HEIGHT ); // If glutFullScreen wasn't called this is the window size
	glutCreateWindow("Solid Teapot");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
