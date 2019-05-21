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

#include <stdlib.h>
#include <string.h>

//unsigned rndnum=13;	
//unsigned irnd(void);

	public class Samp24 : GlibGL
	{
		public:
			Samp24(void);
			~Samp24();
			System::Void init(System::Void);
			System::Void render(System::Void);
		private:
	};
/*
unsigned irnd(void)		
{
  rndnum=(rndnum*109+1021) % 32768;
  return(rndnum);
}
*/
}
