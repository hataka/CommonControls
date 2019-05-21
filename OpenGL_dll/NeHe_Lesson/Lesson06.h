#pragma once

#include <vcclr.h>

namespace OpenGLForm{

	using namespace System;
	using namespace System::Drawing; // Bitmapに必要
	using namespace System::Windows::Forms; //MessageBoxに必要

	//  ref class にしないと managed code を設置できない staticだめ解決
//public class Lesson06
	// ひとまず refで行く
	public ref class Lesson06
	{
		public:
			Lesson06(void);
			~Lesson06();
			static System::Void init(System::Void);
			static System::Void render(System::Void);
		private:
			//static gcroot<array<GLuint>^> texture;
			static array<GLuint>^ texture;
			static System::Void LoadTextures(System::String^ filename);
			static GLfloat rtri;				// Angle for the triangle
			static GLfloat rquad;				// Angle for the quad
			static float xrot;					// X Rotation
			static float yrot;					// Y Rotation
			static float zrot;					// Z Rotation
	};
}
