#pragma once

namespace OpenGLForm{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	public class GL06_1
	{
		public:
			GL06_1(void);
			~GL06_1();
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
