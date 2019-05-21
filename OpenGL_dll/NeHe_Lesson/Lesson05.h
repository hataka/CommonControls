// Lesson05.h

#pragma once

//using namespace System;

namespace OpenGLForm{
	using namespace System;

	public ref class Lesson05
	{
		public:
			Lesson05(void);
			~Lesson05();
			static System::Void init(System::Void);
			static System::Void render(System::Void);
		private:
			static GLfloat rtri;				// Angle for the triangle
			static GLfloat rquad;				// Angle for the quad
	};
}
