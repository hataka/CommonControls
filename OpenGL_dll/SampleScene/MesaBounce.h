#pragma once
#include <gl/glut.h>   // The GL Utility Toolkit (GLUT) Header
#include <math.h>

namespace OpenGLForm{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	public class MesaBounce
	{
		public:
			MesaBounce(void);
			~MesaBounce();
			static System::Void init(System::Void);
			static System::Void render(System::Void);
		private:
			static GLboolean IndexMode;
			static GLuint Ball;
			static GLenum Mode;
			static GLfloat Zrot,Zstep;
			static GLfloat Xpos,Ypos;
			static GLfloat Xvel, Yvel;
			static GLfloat Xmin, Xmax;
			static GLfloat Ymin, Ymax;
			static GLfloat G;
			static unsigned MakeBall();
	};
	
}
