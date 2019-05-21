#pragma once

#include "stdafx.h"
#include "MesaGears.h"

namespace OpenGLForm {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;
/*
	float pos[] = {5.0f, 5.0f, 10.0f, 0.0f};		// Light Position
	float red[] = {0.8f, 0.1f, 0.0f, 1.0f};		// Red Material
	float green[] = {0.0f, 0.8f, 0.2f, 1.0f};	// Green Material
	float blue[] = {0.2f, 0.2f, 1.0f, 1.0f};		// Blue Material
*/

	double MesaGears::rotx= 20.0;									// View's X-Axis Rotation
	double MesaGears::roty= 30.0;									// View's Y-Axis Rotation
	double MesaGears::rotz = 0.0;									// View's Z-Axis Rotation
	unsigned int MesaGears::gear1;											// Display List For Red Gear
	unsigned int MesaGears::gear2;											// Display List For Green Gear
	unsigned int MesaGears::gear3;											// Display List For Blue Gear
	float MesaGears::rAngle;// = 0.0f;								// Rotation Angle

	MesaGears::MesaGears(System::Void){
			MesaGears::rotx = 20.0;									// View's X-Axis Rotation
			MesaGears::roty = 30.0;									// View's Y-Axis Rotation
			MesaGears::rotz = 0.0;									// View's Z-Axis Rotation
			MesaGears::rAngle = 0.0f;								// Rotation Angle
	}

	MesaGears::~MesaGears(System::Void){}

	System::Void MesaGears::init(System::Void)
	{
		//opengl_default_setting();

		static float pos[] = {5.0f, 5.0f, 10.0f, 0.0f};		// Light Position
		static float red[] = {0.8f, 0.1f, 0.0f, 1.0f};		// Red Material
		static float green[] = {0.0f, 0.8f, 0.2f, 1.0f};	// Green Material
		static float blue[] = {0.2f, 0.2f, 1.0f, 1.0f};		// Blue Material

		glLightfv(GL_LIGHT0, GL_POSITION, pos);		// Create A Light
		//glEnable(GL_CULL_FACE). ï–ñ ï\é¶ÇóLå¯Ç…ÇµÇ‹Ç∑ÅB
		glEnable(GL_CULL_FACE);								// Enable Culling
		glEnable(GL_LIGHTING);								// Enable Lighting
		glEnable(GL_LIGHT0);									// Enable Light Zero

		MakeGears();											// Make The Gears

		glEnable(GL_NORMALIZE);								// Enable Normalized Normals
		glTranslatef(0.0, -0.02, -20.0);					// Move Into The Screen 20 Units
	}

	System::Void MesaGears::render(System::Void)
	{
		//glClearColor( 0,0,0,0 );
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear screen and depth buffer
		//glLoadIdentity();									// Reset the current modelview matrix
		//glTranslatef(-0.0f,0.05f,-0.0f);						// Move left 1.5 units and into the screen 6.0
		//glRotatef(rtri,0.0f,1.0f,0.0f);						// Rotate the triangle on the y axis 

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer

		glPushMatrix();
		glRotated(rotx, 1.0, 0.0, 0.0);								// Position The World
		glRotated(roty, 0.0, 1.0, 0.0);
		glRotated(rotz, 0.0, 0.0, 1.0);
		glTranslated(10.0, -7.0, -14.0);

		glPushMatrix();
		glTranslated(-3.0, -2.0, 0.0);						// Position The Red Gear
		glRotatef(rAngle, 0.0f, 0.0f, 1.0f);			// Rotate The Red Gear
		glCallList(MesaGears::gear1);												// Draw The Red Gear
		glPopMatrix();

		glPushMatrix();
		glTranslated(3.1, -2.0, 0.0);									// Position The Green Gear
		glRotated(-2.0 * rAngle - 9.0, 0.0, 0.0, 1.0);			// Rotate The Green Gear
		glCallList(gear2);												// Draw The Green Gear
		glPopMatrix();

		glPushMatrix();
		glTranslated(-3.1, 4.2, 0.0);									// Position The Blue Gear
		glRotated(-2.0 * rAngle - 25.0, 0.0, 0.0, 1.0);			// Rotate The Blue Gear
		glCallList(gear3);												// Draw The Blue Gear
		glPopMatrix();
		glPopMatrix();

		glFlush();;												// Done drawing the quad

		//rAngle += 0.2f;													// Increase The Rotation
		MesaGears::rAngle += 1.0f;													// Increase The Rotation
	}

		// --- Lesson Methods ---
		/// <summary>
		/// Creates a single gear.
		/// </summary>
		/// <param name="inner_radius">Radius of hole at center.</param>
		/// <param name="outer_radius">Radius at center of teeth.</param>
		/// <param name="width">Width of gear.</param>
		/// <param name="teeth">Number of teeth.</param>
		/// <param name="tooth_depth">Depth of tooth.</param>
	System::Void MesaGears::MakeGear(double inner_radius, double outer_radius, double width, int teeth, double tooth_depth)
	{
		int i;
		double r0;
		double r1;
		double r2;
		double angle;
		double da;
		double u;
		double v;
		double len;

		r0 = inner_radius;
		r1 = outer_radius - tooth_depth / 2.0;
		r2 = outer_radius + tooth_depth / 2.0;

		da = 2.0 * 3.14159265358 / teeth / 4.0;
		glShadeModel(GL_FLAT);

		glNormal3d(0.0, 0.0, 1.0);

		// draw front face
		glBegin(GL_QUAD_STRIP);
			for(i = 0; i <= teeth; i++) {
				angle = i * 2.0 * 3.14159265358 / teeth;
				glVertex3d(r0 * cos(angle), r0 * sin(angle), width * 0.5);
				glVertex3d(r1 * cos(angle), r1 * sin(angle), width * 0.5);
				glVertex3d(r0 * cos(angle), r0 * sin(angle), width * 0.5);
				glVertex3d(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), width * 0.5);
			}
		glEnd();

		/* draw front sides of teeth */
		glBegin(GL_QUADS);
			da = 2.0 * 3.14159265358 / teeth / 4.0;
			for(i = 0; i < teeth; i++) {
				angle = i * 2.0 * 3.14159265358 / teeth;

				glVertex3d(r1 * cos(angle), r1 * sin(angle), width * 0.5);
				glVertex3d(r2 * cos(angle + da), r2 * sin(angle + da), width * 0.5);
				glVertex3d(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da), width * 0.5);
				glVertex3d(r1 * cos(angle + 3 * da), r1 *sin(angle + 3 * da), width * 0.5);
			}
		glEnd();

		glNormal3d(0.0, 0.0, -1.0);

		// draw back face
		glBegin(GL_QUAD_STRIP);
			for(i = 0; i <= teeth; i++) {
				angle = i * 2.0 * 3.14159265358 / teeth;
				glVertex3d(r1 * cos(angle), r1 * sin(angle), -width * 0.5);
				glVertex3d(r0 * cos(angle), r0 * sin(angle), -width * 0.5);
				glVertex3d(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), -width * 0.5);
				glVertex3d(r0 * cos(angle), r0 * sin(angle), -width * 0.5);
			}
		glEnd();

		// draw back sides of teeth
		glBegin(GL_QUADS);
			da = 2.0 * 3.14159265358 / teeth / 4.0;
			for(i = 0; i < teeth; i++) {
				angle = i * 2.0 * 3.14159265358 / teeth;

				glVertex3d(r1 * cos((float)(angle + 3 * da)), r1 * sin((float)(angle + 3 * da)), -width * 0.5);
				glVertex3d(r2 * cos((float)(angle + 2 * da)), r2 * sin((float)(angle + 2 * da)), -width * 0.5);
				glVertex3d(r2 * cos((float)(angle + da)), r2 * sin((float)(angle + da)), -width * 0.5);
				glVertex3d(r1 * cos((float)(angle)), r1 * sin((float)(angle)), -width * 0.5);
			}
		glEnd();

		// draw outward faces of teeth
		glBegin(GL_QUAD_STRIP);
			for(i = 0; i < teeth; i++) {
				angle = i * 2.0 * 3.14159265358 / teeth;

				glVertex3d(r1 * cos(angle), r1 * sin(angle), width * 0.5);
				glVertex3d(r1 * cos(angle), r1 * sin(angle), -width * 0.5);
				u = r2 * cos(angle + da) - r1 * cos(angle);
				v = r2 * sin(angle + da) - r1 * sin(angle);
				len = sqrt(u * u + v * v);
				u /= len;
				v /= len;
				glNormal3d(v, -u, 0.0);
				glVertex3d(r2 * cos(angle + da), r2 * sin(angle + da), width * 0.5);
				glVertex3d(r2 * cos(angle + da), r2 * sin(angle + da), -width * 0.5);
				glNormal3d(cos(angle), sin(angle), 0.0);
				glVertex3d(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da), width * 0.5);
				glVertex3d(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da), -width * 0.5);
				u = r1 * cos(angle + 3 * da) - r2 * cos(angle + 2 * da);
				v = r1 * sin(angle + 3 * da) - r2 * sin(angle + 2 * da);
				glNormal3d(v, -u, 0.0);
				glVertex3d(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), width * 0.5);
				glVertex3d(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), -width * 0.5);
				glNormal3d(cos(angle), sin(angle), 0.0);
			}
			glVertex3d(r1 * cos((float)(0)), r1 * sin((float)(0)), width * 0.5);
			glVertex3d(r1 * cos((float)(0)), r1 * sin((float)(0)), -width * 0.5);
		glEnd();

		glShadeModel(GL_SMOOTH);

		// draw inside radius cylinder */
		glBegin(GL_QUAD_STRIP);
			for(i = 0; i <= teeth; i++) {
				angle = i * 2.0 * 3.14159265358 / teeth;
				glNormal3d(-cos(angle), -sin(angle), 0.0);
				glVertex3d(r0 * cos(angle), r0 * sin(angle), -width * 0.5);
				glVertex3d(r0 * cos(angle), r0 * sin(angle), width * 0.5);
			}
		glEnd();
	}

	/// <summary>
	/// Creates the red, green, and blue gears.
	/// </summary>
	System::Void MesaGears::MakeGears()
	{
		static float pos[] = {5.0f, 5.0f, 10.0f, 0.0f};		// Light Position
		static float red[] = {0.8f, 0.1f, 0.0f, 1.0f};		// Red Material
		static float green[] = {0.0f, 0.8f, 0.2f, 1.0f};	// Green Material
		static float blue[] = {0.2f, 0.2f, 1.0f, 1.0f};		// Blue Material

		// Make The Gears
		gear1 = glGenLists(1);											// Generate A Display List For The Red Gear
		glNewList(gear1, GL_COMPILE);									// Create The Display List
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);	// Create A Red Material
		MakeGear(1.0, 4.0, 1.0, 20, 0.7);							// Make The Gear
		glEndList();														// Done Building The Red Gear's Display List

		gear2 = glGenLists(1);											// Generate A Display List For The Green Gear
		glNewList(gear2, GL_COMPILE);									// Create The Display List
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, green);// Create A Green Material
		MakeGear(0.5, 2.0, 2.0, 10, 0.7);							// Make The Gear
		glEndList();														// Done Building The Green Gear's Display List

		gear3 = glGenLists(1);											// Generate A Display List For The Blue Gear
		glNewList(gear3, GL_COMPILE);									// Create The Display List
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);	// Create A Blue Material
		MakeGear(1.3, 2.0, 0.5, 10, 0.7);							// Make The Gear
		glEndList();														// Done Building The Blue Gear's Display List
	}
}
