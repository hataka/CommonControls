#pragma once

#include "stdafx.h"
#include "Lesson06.h"

namespace OpenGLForm {

	using namespace System;
	using namespace System::Drawing; // Bitmapに必要
	using namespace System::Windows::Forms; //MessageBoxに必要

	Lesson06::Lesson06(System::Void){}
	Lesson06::~Lesson06(System::Void){}

	//GLuint	texture2[1];	

	System::Void Lesson06::init(System::Void)
	{
		//---- デフォルト設定に戻す -----//
		//opengl_default_setting();
		//---- 初期設定 ----//
		xrot = 0;													// X Rotation
		yrot = 0;													// Y Rotation
		zrot = 0;													// Z Rotation

		LoadTextures(L"F:\\cpp\\VC++2008\\Form01\\OpenGL_dll\\Data\\NeHe.bmp");	// Jump To Our Texture Loading Routine
		//LoadGLTextures();
		//if(texture == nullptr) exit(1);

		glEnable(GL_TEXTURE_2D);
		glEnable(GL_DEPTH_TEST);					// Override The Base Initialization's Depth Test
		glDisable(GL_BLEND);							// Enable Blending
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	// Back Face Is Filled In
	}

	System::Void Lesson06::render(System::Void)
	{
		glColor3f(1.0f,1.0f,1.0f);					// White
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear Screen And Depth Buffer
		glLoadIdentity();															// Reset The Current Modelview Matrix

		glTranslatef(0.0f, 0.0f, -5.0f);							// Move Into The Screen 5.0 Units

		glRotatef(xrot, 1.0f, 0.0f, 0.0f);						// Rotate On The X Axis
		glRotatef(yrot, 0.0f, 1.0f, 0.0f);						// Rotate On The Y Axis
		glRotatef(zrot, 0.0f, 0.0f, 1.0f);						// Rotate On The Z Axis

		glBindTexture(GL_TEXTURE_2D, texture[0]);			// Select Our Texture
		//glBindTexture(GL_TEXTURE_2D, texture2[0]);			// Select Our Texture

		glBegin(GL_QUADS);														// Draw A Cube Using Quads
			// Front Face
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);				// Bottom Left Of The Texture and Quad
			glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);				// Bottom Right Of The Texture and Quad
			glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);				// Top Right Of The Texture and Quad
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);				// Top Left Of The Texture and Quad
			// Back Face
			glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);				// Bottom Right Of The Texture and Quad
			glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);				// Top Right Of The Texture and Quad
			glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);				// Top Left Of The Texture and Quad
			glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);				// Bottom Left Of The Texture and Quad
			// Top Face
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);				// Top Left Of The Texture and Quad
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);				// Bottom Left Of The Texture and Quad
			glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);				// Bottom Right Of The Texture and Quad
			glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);				// Top Right Of The Texture and Quad
			// Bottom Face
			glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);				// Top Right Of The Texture and Quad
			glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);				// Top Left Of The Texture and Quad
			glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);				// Bottom Left Of The Texture and Quad
			glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);				// Bottom Right Of The Texture and Quad
			// Right Face
			glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);				// Bottom Right Of The Texture and Quad
			glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);				// Top Right Of The Texture and Quad
			glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);				// Top Left Of The Texture and Quad
			glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);				// Bottom Left Of The Texture and Quad
			// Left Face
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);				// Bottom Left Of The Texture and Quad
			glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);				// Bottom Right Of The Texture and Quad
			glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);				// Top Right Of The Texture and Quad
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);				// Top Left Of The Texture and Quad
		glEnd();

		xrot += 0.3f;																// X Axis Rotation
		yrot += 0.2f;																// Y Axis Rotation
		zrot += 0.4f;																// Z Axis Rotation
	}

	System::Void Lesson06::LoadTextures(System::String^ filename)
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

			//	おかしい 取り敢えずcommentout 
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
}
