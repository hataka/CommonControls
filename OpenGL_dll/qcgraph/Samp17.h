#pragma once

#include "stdafx.h"
#include "..\OpenGL.h"
#include "..\Form1.h"
#include "glibgl.h"

namespace OpenGLForm01{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	public class Samp17 : GlibGL
	{
		public:
			Samp17(void);
			~Samp17();
			System::Void init(System::Void);
			System::Void render(System::Void);
		private:
	};
	
}
