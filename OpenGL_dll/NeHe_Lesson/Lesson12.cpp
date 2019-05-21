#pragma once

#include "stdafx.h"
#include "Lesson12.h"

namespace OpenGLForm {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;


static GLfloat boxcol[5][3]=
{
	{1.0f,0.0f,0.0f},{1.0f,0.5f,0.0f},{1.0f,1.0f,0.0f},{0.0f,1.0f,0.0f},{0.0f,1.0f,1.0f}
};

static GLfloat topcol[5][3]=
{
	{.5f,0.0f,0.0f},{0.5f,0.25f,0.0f},{0.5f,0.5f,0.0f},{0.0f,0.5f,0.0f},{0.0f,0.5f,0.5f}
};
/*
static	unsigned box;														// The Box Display List
static	unsigned top;														// The Top Display List
static	unsigned xloop;														// Loop For X Axis
static	unsigned yloop;														// Loop For Y Axis
static	float xrot;														// Rotates Cube On X Axis
static	float yrot;														// Rotates Cube On Y Axis
*/
	Lesson12::Lesson12(System::Void)
	{
		box = 0;														// The Box Display List
		top = 0;														// The Top Display List
		xloop = 0;														// Loop For X Axis
		yloop = 0;														// Loop For Y Axis
		xrot =0.0f;														// Rotates Cube On X Axis
		yrot = 0.0f;														// Rotates Cube On Y Axis
	}

	Lesson12::~Lesson12(System::Void){}

	System::Void Lesson12::init(System::Void)
	{
		//---- デフォルト設定に戻す -----//
			glEnable(GL_TEXTURE_2D);													// Enable Texture Mapping
			glEnable(GL_LIGHT0);														// Quick And Dirty Lighting (Assumes Light0 Is Set Up)
			glEnable(GL_LIGHTING);														// Enable Lighting
			glEnable(GL_COLOR_MATERIAL);												// Enable Material Coloring

			LoadTextures(L"F:\\cpp\\VC++2008\\Graphics\\OpenGLForm01\\data\\Cube.bmp");																// Jump To Our Texture Loading Routine

			BuildLists();																// Jump To Display List Creation Routine
	}

	System::Void Lesson12::render(System::Void)
	{
		glColor3f(1.0f,1.0f,1.0f);					// White
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear Screen And Depth Buffer
		glLoadIdentity();															// Reset The Current Modelview Matrix

		//glTranslatef(0.0f, 0.0f, -5.0f);							// Move Into The Screen 5.0 Units

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);							// Clear Screen And Depth Buffer

			glBindTexture(GL_TEXTURE_2D, texture[0]);									// Select Our Texture

			for(yloop = 1; yloop < 6; yloop++) {										// Loop Through The Y Plane
				for(xloop = 0; xloop < yloop; xloop++) {								// Loop Through The X Plane
					glLoadIdentity();													// Reset The View
					// Position The Cubes On The Screen
					glTranslatef(1.4f + (xloop * 2.8f) - (yloop * 1.4f), ((6.0f - yloop) * 2.4f) - 7.0f, -20.0f);
					glRotatef(45.0f - (2.0f * yloop) + xrot, 1.0f, 0.0f, 0.0f);			// Tilt The Cubes Up And Down
					glRotatef(45.0f + yrot, 0.0f, 1.0f, 0.0f);							// Spin Cubes Left And Right
					glColor3fv(boxcol[yloop - 1]);										// Select A Box Color
					glCallList(box);													// Draw The Box
					glColor3fv(topcol[yloop - 1]);										// Select The Top Color
					glCallList(top);													// Draw The Top
				}
			}
	}

	System::Void Lesson12::LoadTextures(System::String^ filename)
	{
		if(texture == nullptr) texture = gcnew array<GLuint>(1);									// Our Texture

		System::Drawing::Bitmap^ bitmap = nullptr;								// The Bitmap Image For Our Texture
	
		// http://msdn.microsoft.com/ja-jp/library/5ey6h79d(VS.80).aspx
		// The Rectangle For Locking The Bitmap In Memory
		System::Drawing::Imaging::BitmapData^ bitmapData = nullptr;		// The Bitmap's Pixel Data
	
	// Load The Bitmap
		try {
			Bitmap^ bitmap = gcnew Bitmap( filename );
			bitmap->RotateFlip(RotateFlipType::RotateNoneFlipY);		// Flip The Bitmap Along The Y-Axis
			System::Drawing::Rectangle rect = System::Drawing::Rectangle(0,0,bitmap->Width,bitmap->Height);
		
			// Get The Pixel Data From The Locked Bitmap
			// http://msdn.microsoft.com/ja-jp/library/5ey6h79d.aspx
			System::Drawing::Imaging::BitmapData^ bitmapData = bitmap->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, bitmap->PixelFormat );

			glGenTextures(1, (GLuint *)texture[0]);												// Create One Texture
			glBindTexture(GL_TEXTURE_2D, texture[0]);								// Typical Texture Generation Using Data From The Bitmap

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);		// Linear Filtering
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);		// Linear Filtering
			// Generate The Texture
			glTexImage2D(GL_TEXTURE_2D, 0, (int)GL_RGB8, bitmap->Width, bitmap->Height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, ((const GLvoid *)(bitmapData->Scan0)));
		}
		catch(System::Exception^ e) {
			// Handle Any Exceptions While Loading Textures, Exit App
			String^ errorMsg = L"An Error Occurred While Loading Texture:\n\t" + filename + "\n" + L"\n\nStack Trace:\n\t" + e->StackTrace + L"\n";
			MessageBox::Show(errorMsg, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Stop);
			exit(1); //return nullptr;
		}
		finally {
			if(bitmap != nullptr) {
				bitmap->UnlockBits(bitmapData);										// Unlock The Pixel Data From Memory
				delete(bitmap);													// Clean Up The Bitmap
			}
		}
	}

	System::Void Lesson12::KeyDown(int keycode)
	{
		switch (keycode)
		{
			case Keys::Up: 					// Is Up Arrow Being Pressed?
				xrot -= 2.0f;															// Tilt Cubes Up
				break;
			case Keys::Down: 					// Is Up Arrow Being Pressed?
				xrot += 2.0f;															// Tilt Cubes Down
				break;
			case Keys::Left: 					// Is Up Arrow Being Pressed?
				yrot -= 2.0f;															// Spin Cubes Left
				break;
			case Keys::Right: 				// Is Up Arrow Being Pressed?
				yrot += 2.0f;															// Spin Cubes Left
				break;
		}
	}



		// --- Lesson Methods ---
		//#region Lesson12::BuildLists()
		/// <summary>
		/// Creates display lists.
		/// </summary>
		void Lesson12::BuildLists() {
			box = glGenLists(2);														// Generate 2 Display Lists

			glNewList(box, GL_COMPILE);													// Start With The box Display List
				glBegin(GL_QUADS);														// Start Drawing Quads
					// Bottom Face
					glNormal3f(0.0f, -1.0f, 0.0f);										// Normal Pointing Down
					glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);			// Top Right Of The Texture and Quad
					glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);			// Top Left Of The Texture and Quad
					glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);			// Bottom Left Of The Texture and Quad
					glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);			// Bottom Right Of The Texture and Quad
					// Front Face
					glNormal3f(0.0f, 0.0f, 1.0f);										// Normal Pointing Towards Viewer
					glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);			// Bottom Left Of The Texture and Quad
					glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);			// Bottom Right Of The Texture and Quad
					glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);			// Top Right Of The Texture and Quad
					glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);			// Top Left Of The Texture and Quad
					// Back Face
					glNormal3f(0.0f, 0.0f, -1.0f);										// Normal Pointing Away From Viewer
					glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);			// Bottom Right Of The Texture and Quad
					glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);			// Top Right Of The Texture and Quad
					glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);			// Top Left Of The Texture and Quad
					glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);			// Bottom Left Of The Texture and Quad
					// Right face
					glNormal3f(1.0f, 0.0f, 0.0f);										// Normal Pointing Right
					glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);			// Bottom Right Of The Texture and Quad
					glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);			// Top Right Of The Texture and Quad
					glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);			// Top Left Of The Texture and Quad
					glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);			// Bottom Left Of The Texture and Quad
					// Left Face
					glNormal3f(-1.0f, 0.0f, 0.0f);										// Normal Pointing Left
					glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);			// Bottom Left Of The Texture and Quad
					glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);			// Bottom Right Of The Texture and Quad
					glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);			// Top Right Of The Texture and Quad
					glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);			// Top Left Of The Texture and Quad
				glEnd();																// Done Drawing Quads
			glEndList();																// Done Building The box Display List

			top = box + 1;																// top List Value Is box List Value + 1

			glNewList(top, GL_COMPILE);													// Now The top Display List
				glBegin(GL_QUADS);														// Start Drawing Quad
					// Top Face
					glNormal3f(0.0f, 1.0f, 0.0f);										// Normal Pointing Up
					glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);			// Top Left Of The Texture and Quad
					glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f,  1.0f);			// Bottom Left Of The Texture and Quad
					glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f,  1.0f);			// Bottom Right Of The Texture and Quad
					glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);			// Top Right Of The Texture and Quad
				glEnd();																// Done Drawing Quad
			glEndList();																// Done Building The top Display List
		}
		//#endregion BuildLists()
}
