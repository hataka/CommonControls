/*
 * ================================================================
 *
 *	glibgl.h
 *
 *		1999/12/07		Komoto Masahiro
 *
 * ================================================================
 * glut���C�u�������g�����AOpenGL�̃T���v���v���O�����ł��B
 * ���̃T���v���ł́A�Q�c�}�`��`���܂��B
 * ================================================================
 */
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#pragma once

#ifndef GLIBGL_H
#define GLIBGL_H

#include<GL/glut.h>
#include<GL/gl.h>
#include<math.h>
#include <stdio.h>

//#include "..\stdafx.h"
//#include "..\OpenGL.h"
//#include "..\SampleScene.h"

namespace OpenGLForm01 {
//	using namespace System;
//	using namespace System::ComponentModel;
//	using namespace System::Collections;
//	using namespace System::Windows::Forms;
//	using namespace System::Data;
//	using namespace System::Drawing;
//	using namespace OpenGLForm;

	/// <summary>
	/// Form1 �̊T�v
	///
	/// �x��: ���̃N���X�̖��O��ύX����ꍇ�A���̃N���X���ˑ����邷�ׂĂ� .resx �t�@�C���Ɋ֘A�t����ꂽ
	///          �}�l�[�W ���\�[�X �R���p�C�� �c�[���ɑ΂��� 'Resource File Name' �v���p�e�B��
	///          �ύX����K�v������܂��B���̕ύX���s��Ȃ��ƁA
	///          �f�U�C�i�ƁA���̃t�H�[���Ɋ֘A�t����ꂽ���[�J���C�Y�ς݃��\�[�X�Ƃ��A
	///          ���������݂ɗ��p�ł��Ȃ��Ȃ�܂��B
	/// </summary>
	public class GlibGL
	{
	public:
		GlibGL(void){
			Txx=0, Txy=0;
			rndnum=13;	
		}
	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~GlibGL(){}

		int Lpx, Lpy;
		int Txx, Txy;

		enum {	BLACK = 0,
				BLUE,
				GREEN,
				CYAN,
				RED,
				MAGENTA,	YELLOW,
				WHITE,
				DARK_GRAY,    // 8: dark_gray
				DARK_BLUE,    // 9: dark_blue
				DARK_GREEN,   //10: dark_green
				DARK_CYAN,    //11: dark_cyan
				DARK_RED,     //12: dark_red
				DARK_MAGENTA, //13: dark_magenta
				DARK_YELLOW,  //14: dark_yellow
				GRAY	      //15: gray
			};
			
			unsigned rndnum;	
			unsigned irnd(void)		
			{
				rndnum=(rndnum*109+1021) % 32768;
				return(rndnum);
		}

		GLfloat glx(GLfloat x)
		{
  			return (-1.0 + x/320.0)*1.2;
		}

		GLfloat gly(GLfloat y)
		{
  			return ( 1.0 - y/240.0) *1.2/ 1.4 ;
		}

		void _clearscreen ()
		{
  			// ��ʂ�����
  			//void glClear(GLbitfield mask);
  			//glClear(mask);
  			//glClear(GL_COLOR_BUFFER_BIT);
				glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );
				glLoadIdentity();									// Reset the current modelview matrix
				glTranslatef(0.0f, -0.0f, -2.2f);	// Move Left And Into The Screen ����
		}


		void setcolor (int red, int green, int blue)
		{
  			glColor3ub(red , green , blue);
		}

		void _setcolor( int i )
		{
  			// �O���t�B�b�N���� foreground �̕ύX
    		switch (i){
    		case 0:    glColor3f(0.0, 0.0, 0.0);  break;  // black
    		case 1:    glColor3f(0.0, 0.0, 1.0);  break;  // blue
    		case 2:    glColor3f(0.0, 1.0, 0.0);  break;  // green
    		case 3:    glColor3f(0.0, 1.0, 1.0);  break;  // cyan
    		case 4:    glColor3f(1.0, 0.0, 0.0);  break;  // red
    		case 5:    glColor3f(1.0, 0.0, 1.0);  break;  // magenta
    		case 6:    glColor3f(1.0, 1.0, 0.0);  break;  // yellow
    		case 7:    glColor3f(1.0, 1.0, 1.0);  break;  // white
    		case 8:    glColor3f(0.0, 0.0, 0.0);  break;  // black
    		case 9:    glColor3f(0.0, 0.0, 0.5);  break;  // darkblue
    		case 10:   glColor3f(0.0, 0.5, 0.0);  break;  // darkgreen
    		case 11:   glColor3f(0.0, 0.5, 0.5);  break;  // darkcyan
    		case 12:   glColor3f(0.5, 0.0, 0.0);  break;  // darkred
    		case 13:   glColor3f(0.5, 0.0, 0.5);  break;  // darkmagenta
    		case 14:   glColor3f(0.5, 0.5, 0.0);  break;  // yellow4
    		case 15:   glColor3f(0.5, 0.5, 0.5);  break;  // gray50
    		default :   return;
      	break;
    		}
    		return;
		}

		void setbkcolor (int red, int green, int blue, int alpha)
		{
			GLclampf glred, glgreen, glblue, glalpha;
			glred = (GLclampf)red/255.0;
			glgreen = (GLclampf)green/255.0;
  			glblue = (GLclampf)blue/255.0;
  			glalpha = (GLclampf)alpha/255.0;
  			glClearColor(glred, glgreen, glblue, glalpha);
		}

		#define _GFILLINTERIOR 0
		#define _GBORDER 1
		void _rectangle(int style, short x1, short y1, short x2, short y2)
		{
  			if (style == _GBORDER) {
    			glBegin(GL_LINE_LOOP);{
      			glVertex2i(x1 , y1);
      			glVertex2i(x2 , y1);
      			glVertex2i(x2 , y2);
      			glVertex2i(x1 , y2);}
    			glEnd();
  			}
  			else {
    			glBegin(GL_QUADS);{
      			glVertex2i(x1 , y1);
      			glVertex2i(x2 , y1);
      			glVertex2i(x2 , y2);
      			glVertex2i(x1 , y2);}
    			glEnd();
  			}
		}

		void _setpixel(short x,short y)
		{
  			glPointSize(1);
  			glBegin(GL_POINTS);
      		glVertex3d(glx(x),gly(y),0);
  				glEnd();
		}

		void _moveto (int x, int y)
		{
			Lpx = x, Lpy = y;
		}

		void _lineto (double x, double y)
		{
			glBegin(GL_LINES);
				glVertex2f(glx(Lpx), gly(Lpy));
    		glVertex2f(glx(x), gly(y));
				//glVertex2f(Lpx, Lpy);
    		//glVertex2f(x, y);
  		glEnd();
			Lpx = (int)x; Lpy = (int)y;
		}

		//*******************************************
		//  _setlinestyle(unsigned short mask);
		//  �d�l�ύX
		//*******************************************
		void _setlinestyle(GLushort pattern)
		{
  			glEnable(GL_LINE_STIPPLE);

  			//void glLineStipple(GLint factor, GLushort pattern);
  			//pattern: 2�i���Ŕj����`�悷��s�N�Z����16�r�b�g�̐��l�Ŏw��
  			//�^����ꂽ2�i���̂��� 1 �͕`�悷��s�N�Z���A0 �͕`�悵�Ȃ��s�N�Z��
  			glLineStipple(1, pattern);
		}

		void drawString( const char *string, GLfloat x, GLfloat y,
			const GLfloat color[4] )
		{
   		glColor4fv( color );
   		//glRasterPos2f( x*9, y*18 );
   		//glRasterPos2f((GLfloat)(-1.0 + x*9/320.0), (GLfloat)( 1.0 - y*18/240.0));
   		glRasterPos2f( glx(x*9), gly(y*18) );

   		while ( *string ) {
     			glutBitmapCharacter(  GLUT_BITMAP_HELVETICA_18, *string );
      		string++;
   		}
		}

		void PrintString(const char *s)
		{
  			while (*s) {
    			glutBitmapCharacter(GLUT_BITMAP_8_BY_13, (int) *s);
    			s++;
  			}
		}

		#define PI_OVER_180 0.0174532925
		void _ellipse(int style, short x1, short y1, short x2, short y2)
		{
  			int th = 0, step=1;
  			int xx0=0, yy0=0;

  			double width, height, r, aspect;
  			short x0,y0;  // ���S���W
  			width = (x2-x1); height=(y2-y1); x0 = (x1+x2)/2; y0 = (y1+y2)/2;
  			r = width/2.0; aspect = height/width;

  			glBegin(style == _GBORDER ? GL_LINE_LOOP : GL_POLYGON);
      		for(th = 0;th<360;th+=step){
					xx0 = r * cos(th * PI_OVER_180) + x0;
					yy0 = r * aspect * sin(th * PI_OVER_180) + y0;
					glVertex2i(xx0,yy0);
      		}
  			glEnd();
		}

		// ����
		void _circle(int style, double x,double y,double r)
		{
  			int th = 0, step=1;
  			int xx0=0, yy0=0;
  			glBegin(style == _GBORDER ? GL_LINE_LOOP : GL_POLYGON);
      		for(th = 0;th<360;th+=step){
					xx0 = r * cos(th * PI_OVER_180) + x;
					yy0 = r * sin(th * PI_OVER_180) + y;
					glVertex2i(xx0,yy0);
      		}
  			glEnd();
		}

		void _fillPolygon(int v[50][2],int n)
		{
			int i;
			GLfloat w[50][2];
			for(i = 0; i< 50; i++) {
				w[i][0] = glx(v[i][0]);
				w[i][1] = gly(v[i][1]);
			}

				glBegin(GL_POLYGON);{
    			for (i = 0; i < n; i++) {
//      		glVertex2iv(v[i]);
      			glVertex2fv(w[i]);
    			}
  			}
  			glEnd();
		}

		void _tilepaint(unsigned int mask[32])
		{
  			glEnable(GL_POLYGON_STIPPLE);
  			glPolygonStipple((GLubyte *)mask);
		}

		// OpenGL settings
		void InitMiscGL( void )
		{
  			// clear color
  			glClearColor( 0.0, 0.0, 0.25, 1.0 );
  			// ���W�n�̐ݒ�
  			glMatrixMode(GL_PROJECTION);
  			glLoadIdentity();
  			gluOrtho2D(0, 640, 480, 0);
		}

		void circle(double x,double y,double r,int c,double t)
		{
  			// int col;
  			double x1,y1,x2,y2, width, height;

  			if (t<1.0){
    			x1=x-r;y1=y-t*r;x2=x+r;y2=y+t*r;
    			width = 2.0 *r ; height = 2 * t * r;
  			}
  			else {
    			x1=x-r/t;y1=y-r;x2=x+r/t;y2=y+r;
    			width = 2.0 * r /t ; height = 2.0 * r;
  			}

  			_setcolor(c);
  			_ellipse(_GBORDER, x1, y1, x2, y2);
		}

		//
		//	�E�C���h�E�T�C�Y�X�V���̏���
		//
		void reshape_func(int width, int height)
		{
  			// �\���͈͐ݒ�
  			glViewport(0, 0, width, height);
  			Txx=width;
		}

		#define PI 3.14159
		#define DIST -1.0           /*  �Ђ��ݕ␳�W��  */
		//----------------------------------------------------------------
		//	��}�i�P�j  �����̕`��      draw11.c
		//x1,y1:�n�_���W, x2,y2:�I�_���W, x0,y0:����W, cl:���F
		//-----------------------------------------------------------------
		void draw11(double x1, double y1, double x2, double y2, short x0, short y0, short cl)
		{
			_setcolor(cl);
			_moveto((short)x1+x0,(short)y1*DIST+y0);
			_lineto((short)x2+x0,(short)y2*DIST+y0);
		}

		//----------------------------------------------------------------
		//��}�i�P�j  �����̕`��      draw22.c
		//xx,yy:��}���W, x0,y0:����W, mm:����ϐ�,cl:���F
		//-----------------------------------------------------------------
		void draw22(short xx, short yy, short x0, short y0, short *mm, short cl)
		{
  			if(*mm == 1.0) {
    			*mm=2.0;
    			_moveto((int)(xx+x0), (int)(yy*DIST+y0));
			}
  			else {
    		_setcolor((int)cl);
    		_lineto((int)(xx+x0),(int)(yy*DIST+y0));
  			}
		}

void star11(short no, short r, double xp, double yp,
	   short x0, short y0, short cl, short sf)
{
  short i,j,m;       /*  i:��, j,m:����W��    */
  double dt,t,x,y;       /*  dt,t:�p�x,  x,y:���W    */
  double ro;       /*  ro:���a                 */

  m=1;
  //  p[0].x = (int)x0; p[0].y = (int)y0;
  for(i=1; i<=no*2+1; i++){
    dt=2*3.14159/no;      /*  ���^�̊p��              */
    t=dt*(i-1)/2+3.14159/2;       /*  �p�̕ω���              */
    j=(i%2);    if(j==1) ro=r;      /*  �O�a                    */
    else    ro=r/2;       /*  ���a                    */
    x=ro*cos(t)*sf+xp;
    y=ro*sin(t)*sf+yp;
    //   p[i].x = (int)(x+x0) ; p[i].y = (int)(y+y0);
    draw22((short)x,(short)y,(short)x0,(short)y0,&m,cl);
  }
}

void trans2(double *x, double *y, double tx, double ty)
{
	*x+=tx;
	*y+=ty;
}

void scale2(double *x, double *y, double sx, double sy)
{
	*x*=sx;
	*y*=sy;
}

void shear2(double *x, double *y, double shx, double shy)
{
	double sxx,syy;

	sxx=*x+shx**y;
	syy=*y+shy**x;
	*x=sxx;
	*y=syy;
}

void rotat2(double *x, double *y, double dt)
{
  double rxx,ryy;      /*  ��]��̍��W    */

  rxx=*x*cos(dt)-*y*sin(dt);
  ryy=*x*sin(dt)+*y*cos(dt);
  *x=rxx;
  *y=ryy;
}

/*
void scale2(double *x, double *y, double sx, double sy)
{
	*x*=sx;
	*y*=sy;
}
*/
/*
 *	main�֐�
 *	glut���g���ăE�C���h�E�����Ȃǂ̏���������
int main(int argc, char *argv[])
{
  // glut�̏�����
  glutInit(&argc, argv);

  // ��ʕ\���̐ݒ�
  glutInitDisplayMode(GLUT_RGB);

  // �E�C���h�E�̏����T�C�Y���w��
  //  glutInitWindowSize(400,400);
  glutInitWindowSize(640,480);

  // �E�C���h�E�����
//  glutCreateWindow(argv[0]);
  glutCreateWindow(TITLE);

  // ��ʍX�V�p�̊֐���o�^
  glutDisplayFunc(display_func);

  //setbkcolorlClearColor(0.0, 0.0, 1.0, 1.0);

 // �E�C���h�E�̃T�C�Y�ύX���̊֐���o�^
  glutReshapeFunc(reshape_func);

  // initialize OpenGL settings
  InitMiscGL();

  // �C�x���g�����Ȃǂ��n�߂�
  glutMainLoop();
  return 0;
}
*/

	private:
	}; //public class GlibGL
} //namespace OpenGLForm01
#endif // GLIBGL_H
