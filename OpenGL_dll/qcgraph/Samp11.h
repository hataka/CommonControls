#pragma once

#include "stdafx.h"
#include "..\OpenGL.h"
#include "..\Form1.h"
#include "glibgl.h"
#include "..\font.h"

namespace OpenGLForm01{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

//int panel_width;

	public class Samp11 : GlibGL
	{
		public:
			Samp11(void);
			~Samp11();
			System::Void init(System::Void);
			System::Void render(System::Void);
		private:
			BitmapFont g_Font;	// 日本語フォント表示用.
//static array<GLuint>^ texture;
			//GLfloat rtri;				// Angle for the triangle
			//GLfloat rquad;				// Angle for the quad
			//float xrot;					// X Rotation
			//float yrot;					// Y Rotation
			//float zrot;					// Z Rotation

	};
	
}
