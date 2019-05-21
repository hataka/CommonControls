#pragma once

//using namespace System;

namespace OpenGLForm{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

//  ref class Ç…ÇµÇ»Ç¢Ç∆ managed code Çê›íuÇ≈Ç´Ç»Ç¢
//	public ref class Sample01
	public class Sample01
	{
		public:
			Sample01(void);
			~Sample01();
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
