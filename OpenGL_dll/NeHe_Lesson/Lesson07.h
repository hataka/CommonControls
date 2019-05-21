#pragma once

#include <vcclr.h>

namespace OpenGLForm{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

//  ref class Ç…ÇµÇ»Ç¢Ç∆ managed code Çê›íuÇ≈Ç´Ç»Ç¢
	public ref class Lesson07
	{
		public:
			Lesson07(void);
			~Lesson07();
			static System::Void init(System::Void);
			static System::Void render(System::Void);
			static System::Void KeyDown(int keycode);
		private:
			static array<GLuint>^ texture;
			static System::Void LoadTextures(System::String^ filename);

			static GLfloat rtri;				// Angle for the triangle
			static GLfloat rquad;				// Angle for the quad
			static float xrot;					// X Rotation
			static float yrot;					// Y Rotation
			static float zrot;					// Z Rotation
			static bool light;					// Lighting On / Off
			static bool lp;						// L Pressed?
			static bool fp;						// F Pressed?
			static float xspeed;				// X Rotation Speed
			static float yspeed;				// Y Rotation Speed
			static float z;						// Depth Into Screen
			static int filter;					// Which Filter To Use
	};
}
