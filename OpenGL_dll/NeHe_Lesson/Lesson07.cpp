#pragma once

#include "stdafx.h"
#include "Lesson07.h"

namespace OpenGLForm {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	Lesson07::Lesson07(System::Void){}
	Lesson07::~Lesson07(System::Void){}
	
	System::Void Lesson07::init(System::Void)
	{
		//---- デフォルト設定に戻す -----//
		//opengl_default_setting();

		//---- 初期設定 ----//
		glEnable(GL_TEXTURE_2D);
		// Jump To Our Texture Loading Routine
		LoadTextures(L"F:\\cpp\\VC++2008\\Graphics\\OpenGLForm01\\data\\Crate.bmp");
		if(texture == nullptr) exit(1);

		light = false;							// Lighting On / Off
		lp = false;								// L Pressed?
		fp = false;								// F Pressed?
		xrot = 0;								// X Rotation
		yrot = 0;								// Y Rotation
		zrot = 0;								// Z Rotation
		xspeed = 0;								// X Rotation Speed
		yspeed = 0;								// Y Rotation Speed
		z = -5.0f;
		filter = 0;								// Which Filter To Use

		// Depth Into Screen
		static GLfloat LightAmbient[] = {0.5f, 0.5f, 0.5f, 1.0f};
		static GLfloat LightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};	// Diffuse Light Values
		static GLfloat LightPosition[] = {0.0f, 0.0f, 2.0f, 1.0f};	// Light Position
		glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);					// Setup The Ambient Light
		glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);					// Setup The Diffuse Light
		glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);				// Position The Light
		glEnable(GL_LIGHT1);														// Enable Light One
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_DEPTH_TEST);					// Override The Base Initialization's Depth Test
		glDisable(GL_BLEND);							// Enable Blending
		//http://www.myu.ac.jp/~makanae/CG2/cg2_7.html
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	// Back Face Is Filled In
		//glPolygonMode(GL_FRONT, GL_FILL);	// Front Face Is Drawn With Lines
	}

	System::Void Lesson07::render(System::Void)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
		glLoadIdentity();													// Reset The Current Modelview Matrix

		glTranslatef(0.0f, 0.0f, z);									// Translate Into/Out Of The Screen By z

		glRotatef(xrot, 1.0f, 0.0f, 0.0f);					// Rotate On The X Axis By xrot
		glRotatef(yrot, 0.0f, 1.0f, 0.0f);					// Rotate On The Y Axis By yrot

		glBindTexture(GL_TEXTURE_2D, texture[filter]);			// Select A Texture Based On filter

		glColor3f(1.0f,1.0f,1.0f);					// White
		glBegin(GL_QUADS);												// Start Drawing Quads
			// Front Face
			glNormal3f(0.0f, 0.0f, 1.0f);											// Normal Pointing Towards Viewer
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);	// Point 1 (Front)
			glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);	// Point 2 (Front)
			glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);	// Point 3 (Front)
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);	// Point 4 (Front)
			// Back Face
			glNormal3f(0.0f, 0.0f, -1.0f);										// Normal Pointing Away From Viewer
			glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Point 1 (Back)
			glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);	// Point 2 (Back)
			glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);	// Point 3 (Back)
			glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);	// Point 4 (Back)
			// Top Face
			glNormal3f(0.0f, 1.0f, 0.0f);											// Normal Pointing Up
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);	// Point 1 (Top)
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);	// Point 2 (Top)
			glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);	// Point 3 (Top)
			glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);	// Point 4 (Top)
			// Bottom Face
			glNormal3f(0.0f, -1.0f, 0.0f);										// Normal Pointing Down
			glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Point 1 (Bottom)
			glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);	// Point 2 (Bottom)
			glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);	// Point 3 (Bottom)
			glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);	// Point 4 (Bottom)
			// Right face
			glNormal3f(1.0f, 0.0f, 0.0f);											// Normal Pointing Right
			glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);	// Point 1 (Right)
			glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);	// Point 2 (Right)
			glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);	// Point 3 (Right)
			glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);	// Point 4 (Right)
			// Left Face
			glNormal3f(-1.0f, 0.0f, 0.0f);										// Normal Pointing Left
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Point 1 (Left)
			glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);	// Point 2 (Left)
			glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);	// Point 3 (Left)
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);	// Point 4 (Left)
		glEnd();																			// Done Drawing Quads

		xrot += xspeed;																// Add xspeed To xrot
		yrot += yspeed;																// Add yspeed To yrot
	}

	System::Void Lesson07::KeyDown(int keycode)
	{
		switch (keycode)
		{
			case Keys::Up: 					// Is Up Arrow Being Pressed?
				xspeed -= 0.01f;				// If So, Decrease xspeed
				break;
			case Keys::Down: 					// Is Up Arrow Being Pressed?
				xspeed += 0.01f;				// If So, Decrease xspeed
				break;
			case Keys::Left: 					// Is Up Arrow Being Pressed?
				yspeed -= 0.01f;				// If So, Decrease xspeed
				break;
			case Keys::Right: 				// Is Up Arrow Being Pressed?
				yspeed += 0.01f;				// If So, Decrease xspeed
				break;
			case Keys::PageUp: 				// Is Up Arrow Being Pressed?
				z -= 0.02f;							// If So, Decrease xspeed
				break;
			case Keys::PageDown: 			// Is Up Arrow Being Pressed?
				z += 0.02f;							// If So, Decrease xspeed
				break;
			case Keys::Space: 				// Is Up Arrow Being Pressed?
				xspeed = 0.0f;					// If So, Decrease xspeed
				yspeed = 0.0f;					// If So, Decrease xspeed
				break;
			case Keys::L:							// Is L Key Being Pressed And Not Held Down?
				lp = true;							// lp Becomes true
				light = !light;					// Toggle Light true / false
				if(!light) {						// If Not Light
					glDisable(GL_LIGHTING);	// Disable Lighting
				}
				else {							// Otherwise
					glEnable(GL_LIGHTING);	// Enable Lighting
				}
				//UpdateInputHelp();			// Update The Input Help Screen
				break;
			case Keys::F:						// Is F Key Being Pressed And Not Held Down?
				fp = true;						// fp Becomes true
				filter += 1;					// filter Value Increases By One
				if(filter > 2) {				// Is Value Greater Than 2?
					filter = 0;					// If So, Set filter To 0
				}
				break;
				//UpdateInputHelp();				// Update The Input Help Screen
			//if(!KeyState[(int) Keys.F]) {	// Has F Key Been Released?
			//	fp = false;							// If So, fp Becomes false
			//}
		}
	}


		// 独立クラス化で直接アクセスを可能にする Time-stamp: <2010-12-16 13:51:14 kahata>
		// array<GLuint>^ LoadTextures(System::String^ filename)
		// NeHe Lesson07用
		System::Void Lesson07::LoadTextures(System::String^ filename)
	{
		if(texture == nullptr) texture = gcnew array<GLuint>(3);									// Our Texture

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

			glGenTextures(3, (GLuint *)texture[0]);												// Create 3 Textures

			// Create Nearest Filtered Texture
			glBindTexture(GL_TEXTURE_2D, texture[0]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); 
			glTexImage2D(GL_TEXTURE_2D, 0, (int) GL_RGB8, bitmap->Width, bitmap->Height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, ((const GLvoid *)(bitmapData->Scan0)));

			// Create Linear Filtered Texture
			glBindTexture(GL_TEXTURE_2D, texture[1]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
			glTexImage2D(GL_TEXTURE_2D, 0, (int) GL_RGB8, bitmap->Width, bitmap->Height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, ((const GLvoid *)(bitmapData->Scan0)));

			// Create MipMapped Texture
			glBindTexture(GL_TEXTURE_2D, texture[2]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
			gluBuild2DMipmaps(GL_TEXTURE_2D, (int) GL_RGB8, bitmap->Width, bitmap->Height, GL_BGR_EXT, GL_UNSIGNED_BYTE, ((const GLvoid *)(bitmapData->Scan0)));
		}
		catch(System::Exception^ e) {
			// Handle Any Exceptions While Loading Textures, Exit App
			String^ errorMsg = L"An Error Occurred While Loading Texture:\n\t" + filename + "\n" + L"\n\nStack Trace:\n\t" + e->StackTrace + L"\n";
			MessageBox::Show(errorMsg, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Stop);
			exit(1);//return nullptr;
		}
		finally {
			if(bitmap != nullptr) {
				bitmap->UnlockBits(bitmapData);										// Unlock The Pixel Data From Memory
				delete(bitmap);													// Clean Up The Bitmap
			}
		}
//		return texture;
	}
}
