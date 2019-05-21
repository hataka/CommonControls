#pragma once

#include <math.h>

namespace OpenGLForm{

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

//  ref class Ç…ÇµÇ»Ç¢Ç∆ managed code static array<GLuint>^ texture;Çê›íuÇ≈Ç´Ç»Ç¢
//	public class Lesson11
	public ref class Lesson11
	{
		public:
			Lesson11(void);
			~Lesson11();
			static System::Void init(System::Void);
			static System::Void render(System::Void);
		private:
			static array<GLuint>^ texture;
			static System::Void LoadTextures(System::String^ filename);
//			GLfloat rtri;				// Angle for the triangle
//			GLfloat rquad;				// Angle for the quad
			static float xrot;					// X Rotation
			static float yrot;					// Y Rotation
			static float zrot;					// Z Rotation
			static int wiggle_count;// = 0;	// Counter Used To Control How Fast Flag Waves
			static float hold;// = 0.0f;		// Temporarily Holds A Floating Point Value
			static int xx, yy;					// Loop Variables
			static float float_x, float_y, float_xb, float_yb;	// Used To Break The Flag Into Tiny Quads
	};
	
}
