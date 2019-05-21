#pragma once
#include <gl/glut.h>   // The GL Utility Toolkit (GLUT) Header

namespace OpenGLForm{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

//  ref class �ɂ��Ȃ��� managed code ��ݒu�ł��Ȃ�
//	public ref class Teapot
	public ref class Teapot
	{
		public:
			Teapot(void);
			~Teapot();
			static System::Void init(System::Void);
			static System::Void render(System::Void);
		private:
			//static array<GLuint>^ texture;
			static GLfloat rtri;				// Angle for the triangle
			static GLfloat rquad;				// Angle for the quad
	};
	
}
