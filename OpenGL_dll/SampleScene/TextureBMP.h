#pragma once
#include <iostream>
#include <gl/glut.h>   // The GL Utility Toolkit (GLUT) Header
#include <math.h>
#include "BMPLoader.h"

namespace OpenGLForm{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

//int panel_width;

//	public class TextureBMP : GlibGL
	public class TextureBMP
	{
		public:
			TextureBMP(void);
			~TextureBMP();
			static System::Void init(System::Void);
			static System::Void render(System::Void);
		private:
			static int WindowPositionX;// = 100;
			static int WindowPositionY;// = 100;
			static int WindowWidth;// = 512;
			static int WindowHeight;// = 512;
			//char WindowTitle[33];//  = "Texture Mapping (3) - BMP File -";
			static BMPImage texture;
	};
}
