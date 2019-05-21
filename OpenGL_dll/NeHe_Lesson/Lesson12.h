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
//	public class Lesson12
	public ref class Lesson12
	{
		public:
			Lesson12(void);
			~Lesson12();
			static System::Void init(System::Void);
			static System::Void render(System::Void);
			static System::Void KeyDown(int keycode);
		private:
			static array<GLuint>^ texture;
			static void Lesson12::BuildLists();
			static System::Void Lesson12::LoadTextures(System::String^ filename);

			static unsigned box;														// The Box Display List
			static unsigned top;														// The Top Display List
			static unsigned xloop;														// Loop For X Axis
			static unsigned yloop;														// Loop For Y Axis
			static float xrot;														// Rotates Cube On X Axis
			static float yrot;														// Rotates Cube On Y Axis

/*
			float[][] boxcol = new float[5][] {						// Array For Box Colors
				float[] {1.0f, 0.0f, 0.0f},							// Bright Red
				float[] {1.0f, 0.5f, 0.0f},							// Bright Orange
				float[] {1.0f, 1.0f, 0.0f},							// Bright Yellow
				float[] {0.0f, 1.0f, 0.0f},							// Bright Green
				float[] {0.0f, 1.0f, 1.0f}								// Bright Blue
			};

			float[][] topcol = new float[5][] {						// Array For Top Colors
				new float[] {0.5f, 0.0f,  0.0f},						// Dark Red
				new float[] {0.5f, 0.25f, 0.0f},						// Dark Orange
				new float[] {0.5f, 0.5f,  0.0f},						// Dark Yellow
				new float[] {0.0f, 0.5f,  0.0f},						// Dark Green
				new float[] {0.0f, 0.5f,  0.5f}						// Dark Blue
		};
*/
	};
}
