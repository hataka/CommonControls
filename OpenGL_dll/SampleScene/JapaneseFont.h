#pragma once
#include <gl/glut.h>   // The GL Utility Toolkit (GLUT) Header
#include <math.h>
#include "font.h"

namespace OpenGLForm{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

//int panel_width;

//	public class JapaneseFont : GlibGL
	public class JapaneseFont
	{
		public:
			JapaneseFont(void);
			~JapaneseFont();
			static System::Void init(System::Void);
			static System::Void render(System::Void);
		private:
			static int g_WndWidth;// = 800;
			static int g_WndHeight;// = 600;
			static BitmapFont g_Font;	// 日本語フォント表示用.
			static unsigned int g_FrameCount;// = 0;
			static void Render2D();
			static void Render3D();
	};
}
