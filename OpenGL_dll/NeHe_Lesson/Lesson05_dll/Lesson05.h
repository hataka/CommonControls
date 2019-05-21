// Lesson05.h

#pragma once

using namespace System;

namespace OpenGLForm01{
	using namespace System;
//	using namespace System::ComponentModel;
//	using namespace System::Collections;
//	using namespace System::Windows::Forms;
//	using namespace System::Data;
//	using namespace System::Drawing;
//	using namespace OpenGLForm;

	public ref class Lesson05
	{
		public:
			Lesson05(void);
			~Lesson05();
			System::Void init(System::Void);
			System::Void render(System::Void);
		private:
			//static array<GLuint>^ texture;
			GLfloat rtri;				// Angle for the triangle
			GLfloat rquad;				// Angle for the quad
			//float xrot;					// X Rotation
			//float yrot;					// Y Rotation
			//float zrot;					// Z Rotation

	};
}
/*
namespace Lesson05 {

	public ref class Class1
	{
		// TODO: このクラスの、ユーザーのメソッドをここに追加してください。
	public:
		static int add(int a, int b)
    {
       return a + b;
    }
	};
}
*/
