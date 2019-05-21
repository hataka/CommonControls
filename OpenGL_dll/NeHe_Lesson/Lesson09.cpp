#pragma once

#include "stdafx.h"
#include "Lesson09.h"

namespace OpenGLForm {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	// アンマネージ型のglobal変数にせざるを得ない??? Time-stamp: <2010-12-16 22:28:58 kahata>
	struct Star {							// Create A Structure For Star
		byte r, g, b;						// Star's Color
		float dist;							// Star's Distance From Center
		float angle;							// Star's Current Angle
	};
	Star star[50];

	Lesson09::Lesson09(System::Void){}
	Lesson09::~Lesson09(System::Void){}
	
	System::Void Lesson09::init(System::Void)
	{
		//star = gcnew array<Star^>(50);

		zoom = -15.0f;				// Viewing Distance Away From Stars
		tilt = 90.0f;				// Tilt The View
		if(rand == nullptr) rand = gcnew Random();		// Randomizer

		//opengl_default_setting();

		glDisable(GL_DEPTH_TEST);					// Override The Base Initialization's Depth Test
		glEnable(GL_TEXTURE_2D);					// Enable Texture Mapping
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);			// Set The Blending Function For Translucency
		glEnable(GL_BLEND);							// Enable Blending
		//http://www.myu.ac.jp/~makanae/CG2/cg2_7.html
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	// Back Face Is Filled In
		//glPolygonMode(GL_FRONT, GL_FILL);	// Front Face Is Drawn With Lines

		Lesson09::LoadTextures(L"F:\\cpp\\VC++2008\\Form01\\OpenGL_dll\\Data\\Star.bmp");																// Jump To Our Texture Loading Routine

		for(loop = 0; loop < 50; loop++) {			// Loop Through All The Stars
			star[loop].angle = 0.0f;				// Start All The Stars At Angle Zero
			star[loop].dist = ((float) loop / 50.0f) * 5.0f;							// Calculate Distance From The Center
			star[loop].r = (byte) (rand->Next() % 256);// Give star[loop] A Random Red Intensity
			star[loop].g = (byte) (rand->Next() % 256);// Give star[loop] A Random Green Intensity
			star[loop].b = (byte) (rand->Next() % 256);// Give star[loop] A Random Blue Intensity
		}
	}

	System::Void Lesson09::render(System::Void)
	{
		//OpenGL->MySetCurrentGLRC();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);							// Clear Screen And Depth Buffer
		glBindTexture(GL_TEXTURE_2D, texture[0]);									// Select Our Texture

		for(loop = 0; loop < 50; loop++) {			// Loop Through All The Stars
			glLoadIdentity();						// Reset The View Before We Draw Each Star
			glTranslatef(0.0f, 0.0f, zoom);			// Zoom Into The Screen (Using The Value In 'zoom')
			glRotatef(tilt, 1.0f, 0.0f, 0.0f);		// Tilt The View (Using The Value In 'tilt')
			glRotatef((GLfloat)(star[loop].angle), 0.0f, 1.0f, 0.0f);							// Rotate To The Current Star's Angle
			glTranslatef((GLfloat)(star[loop].dist), 0.0f, 0.0f);// Move Forward On The X Plane
			glRotatef(-(GLfloat)(star[loop].angle), 0.0f, 1.0f, 0.0f);							// Cancel The Current Star's Angle
			glRotatef(-(GLfloat)(tilt), 1.0f, 0.0f, 0.0f);		// Cancel The Screen Tilt

			if(twinkle) {							// If Twinkling Stars Enabled
				// Assign A Color Using Bytes
				glColor4ub((GLubyte)(star[(num-loop)-1].r), (GLubyte)(star[(num-loop)-1].g), (GLubyte)(star[(num-loop)-1].b), 255);
				glBegin(GL_QUADS);					// Begin Drawing The Textured Quad
					glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
					glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 0.0f);
					glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, 0.0f);
					glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, 0.0f);
				glEnd();							// Done Drawing The Textured Quad
			}
			glRotatef(spin, 0.0f, 0.0f, 1.0f);		// Rotate The Star On The Z Axis
			glColor4ub((GLubyte)(star[loop].r), (GLubyte)(star[loop].g), (GLubyte)(star[loop].b), 255);				// Assign A Color Using Bytes
			glBegin(GL_QUADS);						// Begin Drawing The Textured Quad
				glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 0.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, 0.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, 0.0f);
			glEnd();// Done Drawing The Textured Quad

			spin += 0.01f;							// Used To Spin The Stars
			star[loop].angle += ((float) loop / 50.0f);// Changes The Angle Of A Star
			star[loop].dist  -= 0.01f;				// Changes The Distance Of A Star
			if(star[loop].dist < 0.0f) {			// Is The Star In The Middle Yet
				star[loop].dist += 5.0f;			// Move The Star 5 Units From The Center
				star[loop].r = (byte) (rand->Next() % 256);							// Give It A New Red Value
				star[loop].g = (byte) (rand->Next() % 256);							// Give It A New Green Value
				star[loop].b = (byte) (rand->Next() % 256);							// Give It A New Blue Value
			}
		}
	}

	System::Void Lesson09::LoadTextures(System::String^ filename)
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
			//System::Drawing::Imaging::BitmapData^ bitmapData = bitmap->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format24bppRgb );
			System::Drawing::Imaging::BitmapData^ bitmapData = bitmap->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadOnly, System::Drawing::Imaging::PixelFormat::Format24bppRgb );
				            //                                    bitmapData = bitmap.LockBits(rectangle, ImageLockMode.ReadOnly, System.Drawing.Imaging.PixelFormat.Format24bppRgb);

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
