#pragma once

#include "stdafx.h"
#include "Lesson11.h"

namespace OpenGLForm {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	Lesson11::Lesson11(System::Void){}
	Lesson11::~Lesson11(System::Void){}

	static float points[45][45][3];	// The Array For The Points On The Grid Of Our "Wave"
	
	System::Void Lesson11::init(System::Void)
	{
		//---- èâä˙ê›íË ----//
		xrot = 0;													// X Rotation
		yrot = 0;													// Y Rotation
		zrot = 0;													// Z Rotation
		wiggle_count = 0;	// Counter Used To Control How Fast Flag Waves
		hold = 0.0f;		// Temporarily Holds A Floating Point Value

		glEnable(GL_TEXTURE_2D);			// Enable Texture Mapping
		glPolygonMode(GL_BACK, GL_FILL);	// Back Face Is Filled In
		glPolygonMode(GL_FRONT, GL_LINE);	// Front Face Is Drawn With Lines

		//LoadTextures();	// Jump To Texture Loading Routine
		LoadTextures(L"F:\\cpp\\VC++2008\\Graphics\\OpenGLForm01\\data\\Tim.bmp");																// Jump To Our Texture Loading Routine
		if(texture == nullptr) exit(1);

		for(xx = 0; xx < 45; xx++) {			// Loop Through The X Plane
			for(yy = 0; yy < 45; yy++) {		// Loop Through The Y Plane
				// Apply The Wave To Our Mesh
				points[xx][yy][0] = (float) (xx / 5.0f) - 4.5f;
				points[xx][yy][1] = (float) (yy / 5.0f) - 4.5f;
				points[xx][yy][2] = (float) sin((((xx / 5.0f) * 40.0f) / 360.0f) * 3.141592654 * 2.0f);
			}
		}
	}

	System::Void Lesson11::render(System::Void)
	{
		//OpenGL->MySetCurrentGLRC();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear Screen And Depth Buffer
		glLoadIdentity();// Reset The Current Modelview Matrix

		glColor3f(1.0f,1.0f,1.0f);					// White
		glTranslatef(0.0f, 0.0f, -12.0f);	// Move Into The Screen 12.0 Units

		glRotatef(xrot, 1.0f, 0.0f, 0.0f);	// Rotate On The X Axis
		glRotatef(yrot, 0.0f, 1.0f, 0.0f);	// Rotate On The Y Axis
		glRotatef(zrot, 0.0f, 0.0f, 1.0f);	// Rotate On The Z Axis

		glBindTexture(GL_TEXTURE_2D, texture[0]);				// Select Our Texture
		glBegin(GL_QUADS);// Start Drawing Our Quads
			for(xx = 0; xx < 44; xx++ ) {		// Loop Through The X Plane 0-44 (45 Points)
				for(yy = 0; yy < 44; yy++ ) {	// Loop Through The Y Plane 0-44 (45 Points)
					float_x = xx / 44.0f;	// Create A Floating Point X Value
					float_y = yy / 44.0f;	// Create A Floating Point Y Value
					float_xb = (xx + 1) / 44.0f;// Create A Floating Point Y Value+0.0227f
					float_yb = (yy + 1) / 44.0f;// Create A Floating Point Y Value+0.0227f

					glTexCoord2f(float_x, float_y);				// First Texture Coordinate (Bottom Left)
					glVertex3f(points[xx][yy][0], points[xx][yy][1], points[xx][yy][2]);

					glTexCoord2f(float_x, float_yb);			// Second Texture Coordinate (Top Left)
					glVertex3f(points[xx][yy+1][0], points[xx][yy + 1][1], points[xx][yy + 1][2]);

					glTexCoord2f(float_xb, float_yb);			// Third Texture Coordinate (Top Right)
					glVertex3f(points[xx + 1][yy + 1][0], points[xx + 1][yy + 1][1], points[xx+1][yy + 1][2]);

					glTexCoord2f(float_xb, float_y);			// Fourth Texture Coordinate (Bottom Right)
					glVertex3f(points[xx + 1][yy][0], points[xx + 1][yy][1], points[xx + 1][yy][2]);
				}
			}
		glEnd();		// Done Drawing Our Quads

		if(wiggle_count == 2) {				// Used To Slow Down The Wave (Every 2nd Frame Only)
			for(yy = 0; yy < 45; yy++) {		// Loop Through The Y Plane
				hold = points[0][yy][2];		// Store Current Value One Left Side Of Wave
				for(xx = 0; xx < 44; xx++) {	// Loop Through The X Plane
					points[xx][yy][2] = points[xx + 1][yy][2];		// Current Wave Value Equals Value To The Right
				}
				points[44][yy][2] = hold;	// Last Value Becomes The Far Left Stored Value
			}
			wiggle_count = 0;				// Set Counter Back To Zero
		}
		wiggle_count++;	// Increase The Counter

		xrot += 0.3f;	// X Axis Rotation
		yrot += 0.2f;	// Y Axis Rotation
		zrot += 0.4f;	// Z Axis Rotation
	}

	System::Void Lesson11::LoadTextures(System::String^ filename)
	{
		if(texture == nullptr) texture = gcnew array<GLuint>(1);									// Our Texture

		//System::String^ filename = "F:\\cpp\\VC++2008\\Graphics\\OpenGLForm01\\data\\Crate.bmp";	// The File To Load
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
			//System::Drawing::Imaging::BitmapData^ bitmapData = bitmap->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format24bppRgb );
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
		//return texture;
	}
}
