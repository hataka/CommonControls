#pragma once

#include <math.h>

namespace OpenGLForm{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	public class GL03_4
	{
		public:
			GL03_4(void);
			~GL03_4();
			static System::Void init(System::Void);
			static System::Void render(System::Void);
		private:
			//static array<GLuint>^ texture;
			//GLfloat rtri;				// Angle for the triangle
			//GLfloat rquad;				// Angle for the quad
			//float xrot;					// X Rotation
			//float yrot;					// Y Rotation
			//float zrot;					// Z Rotation
	};
	
}
