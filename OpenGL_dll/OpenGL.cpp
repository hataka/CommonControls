// これは メイン DLL ファイルです。

#include "stdafx.h"
#include "OpenGL.h"
//#include "Lesson05.h"

namespace OpenGLForm 
{
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Reflection;

	COpenGL::COpenGL(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight)
	{
		CreateParams^ cp = gcnew CreateParams;

		// Set the position on the form
		cp->X = 0;
		cp->Y = 0;
		cp->Height = iHeight;
		cp->Width = iWidth;

	// Specify the form as the parent.
	cp->Parent = parentForm->Handle;

	// Create as a child of the specified parent and make OpenGL compliant (no clipping)
	cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	// Create the actual window
	COpenGL::CreateHandle(cp); //koko

	m_hDC = GetDC((HWND)this->Handle.ToInt32());
			
	if(m_hDC)
	{
		MySetPixelFormat(m_hDC);
		ReSizeGLScene(iWidth, iHeight);
		InitGL();
	}
}

	COpenGL::COpenGL(System::Windows::Forms::Panel^ parentForm, GLsizei iWidth, GLsizei iHeight)
		{
			CreateParams^ cp = gcnew CreateParams;

			// Set the position on the form
			cp->X = 0;
			cp->Y = 0;
			cp->Height = iHeight;
			cp->Width = iWidth;

			// Specify the form as the parent.
			cp->Parent = parentForm->Handle;

			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
			// Create the actual window
			this->CreateHandle(cp); //koko

			m_hDC = GetDC((HWND)this->Handle.ToInt32());
			
			if(m_hDC)
			{
				MySetPixelFormat(m_hDC);
				ReSizeGLScene(iWidth, iHeight);
				InitGL();
			}
		}

	COpenGL::COpenGL(System::String^ SampleScene, System::Windows::Forms::Panel^ parentForm, GLsizei iWidth, GLsizei iHeight)
		{
			this->m_SampleScene = SampleScene;
		
			CreateParams^ cp = gcnew CreateParams;

			// Set the position on the form
			cp->X = 0;
			cp->Y = 0;
			cp->Height = iHeight;
			cp->Width = iWidth;

			// Specify the form as the parent.
			cp->Parent = parentForm->Handle;

			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
			// Create the actual window
			this->CreateHandle(cp); //koko

			m_hDC = GetDC((HWND)this->Handle.ToInt32());
			
			if(m_hDC)
			{
				MySetPixelFormat(m_hDC);
				ReSizeGLScene(iWidth, iHeight);
				InitGL();
				if(this->m_SampleScene == "Lesson05")
				{
					//Assembly^ testasm = Assembly::LoadFrom("F:\\cpp\\VC++2008\\ProgramExplorer01\\OpenGL_dll\\NeHe_Lesson\\Lesson05_dll\\Debug\\Lesson05.dll");

					Lesson05::init();
				}
				else if(this->m_SampleScene == "Lesson06") Lesson06::init();
				else if(this->m_SampleScene == "Lesson07") Lesson07::init();
				else if(this->m_SampleScene == "Lesson09") Lesson09::init();
				else if(this->m_SampleScene == "Lesson11") Lesson11::init();
				else if(this->m_SampleScene == "Lesson12") Lesson12::init();
				else if(this->m_SampleScene == "Teapot") Teapot::init();
				else if(this->m_SampleScene == "MesaGears") MesaGears::init();
				else if(this->m_SampleScene == "MesaBounce") MesaBounce::init();
				else if(this->m_SampleScene == "JapaneseFont") JapaneseFont::init();
				else if(this->m_SampleScene == "TextureBMP") TextureBMP::init();
				else if(this->m_SampleScene == "Sample01") Sample01::init();
				else if(this->m_SampleScene == "gl03_1") GL03_1::init();
				else if(this->m_SampleScene == "gl03_2") GL03_2::init();
				else if(this->m_SampleScene == "gl03_3") GL03_3::init();
				else if(this->m_SampleScene == "gl03_4") GL03_4::init();
				else if(this->m_SampleScene == "gl04_1") GL04_1::init();
				else if(this->m_SampleScene == "gl05_1") GL05_1::init();
				else if(this->m_SampleScene == "gl06_1") GL06_1::init();
				else if(this->m_SampleScene == "gl06_2") GL06_2::init();
			}
		}

	System::Void COpenGL::Render(System::Void)
	{
		MySetCurrentGLRC();
		if(this->m_SampleScene == "Lesson05") Lesson05::render();
		else if(this->m_SampleScene == "Lesson06") Lesson06::render();
		else if(this->m_SampleScene == "Lesson07") Lesson07::render();
		else if(this->m_SampleScene == "Lesson09") Lesson09::render();
		else if(this->m_SampleScene == "Lesson11") Lesson11::render();
		else if(this->m_SampleScene == "Lesson12") Lesson12::render();
		else if(this->m_SampleScene == "Teapot") Teapot::render();
		else if(this->m_SampleScene == "MesaGears") MesaGears::render();
		else if(this->m_SampleScene == "MesaBounce") MesaBounce::render();
		else if(this->m_SampleScene == "JapaneseFont") JapaneseFont::render();
		else if(this->m_SampleScene == "TextureBMP") TextureBMP::render();
		else if(this->m_SampleScene == "Sample01") Sample01::render();
		else if(this->m_SampleScene == "gl03_1") GL03_1::render();
		else if(this->m_SampleScene == "gl03_2") GL03_2::render();
		else if(this->m_SampleScene == "gl03_3") GL03_3::render();
		else if(this->m_SampleScene == "gl03_4") GL03_4::render();
		else if(this->m_SampleScene == "gl04_1") GL04_1::render();
		else if(this->m_SampleScene == "gl05_1") GL05_1::render();
		else if(this->m_SampleScene == "gl06_1") GL06_1::render();
		else if(this->m_SampleScene == "gl06_2") GL06_2::render();
	}

	System::Void COpenGL::KeyDown(int keycode)
	{
		MySetCurrentGLRC();
		if(this->m_SampleScene == "Lesson07") Lesson07::KeyDown(keycode);
		else if(this->m_SampleScene == "Lesson12") Lesson12::KeyDown(keycode);
	}


	System::Void COpenGL::SwapOpenGLBuffers(System::Void)
	{
		SwapBuffers(m_hDC) ;
	}

	GLvoid COpenGL::ReSizeGLScene(GLsizei width, GLsizei height)
		{ // Resize and initialise the gl window
			
			MySetCurrentGLRC();
			
			if (height==0) // Prevent A Divide By Zero By
			{
				height=1; // Making Height Equal One
			}

			glViewport(0,0,width,height); // Reset The Current Viewport
			glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
			glLoadIdentity(); // Reset The Projection Matrix
			// Calculate The Aspect Ratio Of The Window
			gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

			glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
			glLoadIdentity(); // Reset The Modelview Matrix
			UINT flags = SWP_NOZORDER | SWP_NOACTIVATE;
			SetWindowPos((HWND)this->Handle.ToPointer() , 0, 0, 0, 
			width, height, flags);
		}

	System::Void COpenGL::MySetCurrentGLRC() 
		{ 
			if(m_hDC)
			{
				if((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
				{
					MessageBox::Show("wglMakeCurrent Failed");
				}
			}
		}

	 bool COpenGL::InitGL(GLvoid)								// All setup for opengl goes here
		{
			glShadeModel(GL_SMOOTH);							// Enable smooth shading
			glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black background
			glClearDepth(1.0f);									// Depth buffer setup
			glEnable(GL_DEPTH_TEST);							// Enables depth testing
			// 
			glDisable(GL_TEXTURE_2D);
			
			glDepthFunc(GL_LEQUAL);								// The type of depth testing to do
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really nice perspective calculations
			return TRUE;										// Initialisation went ok
		}

	 
		// 独立クラス化で直接アクセスを可能にする Time-stamp: <2010-12-16 13:51:14 kahata>
		// array<GLuint>^ LoadTextures(System::String^ filename)
	  cli::array<GLuint>^ COpenGL::LoadTextures(System::String^ filename)
		{
			//texture = gcnew array<GLuint>(1);									// Our Texture
			texture = gcnew cli::array<GLuint>(1);									// Our Texture
			System::Drawing::Bitmap^ bitmap = nullptr;						// The Bitmap Image For Our Texture

			// http://msdn.microsoft.com/ja-jp/library/5ey6h79d(VS.80).aspx
			// The Rectangle For Locking The Bitmap In Memory
			System::Drawing::Imaging::BitmapData^ bitmapData = nullptr;		// The Bitmap's Pixel Data
	
			// Load The Bitmap
			try {
				Bitmap^ bitmap = gcnew Bitmap( filename );
				bitmap->RotateFlip(RotateFlipType::RotateNoneFlipY);		// Flip The Bitmap Along The Y-Axis
				System::Drawing::Rectangle rect = System::Drawing::Rectangle(0,0,bitmap->Width,bitmap->Height);

				// Get The Pixel Data From The Locked Bitmap
				// http://msdn.microsoft.com/ja-jp/library/5ey6h79d.aspx
				System::Drawing::Imaging::BitmapData^ bitmapData = bitmap->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, bitmap->PixelFormat );

				glGenTextures(1, (GLuint *)texture[0]);								// Create One Texture
				glBindTexture(GL_TEXTURE_2D, texture[0]);								// Typical Texture Generation Using Data From The Bitmap
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);		// Linear Filtering
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);		// Linear Filtering
				// Generate The Texture
				glTexImage2D(GL_TEXTURE_2D, 0, (int)GL_RGB8, bitmap->Width, bitmap->Height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, ((const GLvoid *)(bitmapData->Scan0)));
			}
			catch(System::Exception^ e) {
				// Handle Any Exceptions While Loading Textures, Exit App
				String^ errorMsg = L"An Error Occurred While Loading Texture:\n\t" + filename + "\n" + L"\n\nStack Trace:\n\t" + e->StackTrace + L"\n";
				MessageBox::Show(errorMsg, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Stop);
				return nullptr;
			}
			finally {
				if(bitmap != nullptr) {
					bitmap->UnlockBits(bitmapData);				// Unlock The Pixel Data From Memory
					delete(bitmap);									// Clean Up The Bitmap
				}
			}
			return texture;
		}
	/*
		HDC m_hDC;
		HGLRC m_hglrc;
		//GLfloat	rtri;				// Angle for the triangle
		//GLfloat	rquad;				// Angle for the quad
		static array<GLuint>^ texture;
*/
		COpenGL::~COpenGL(System::Void)
		{
			COpenGL::DestroyHandle();
		}

		GLint COpenGL::MySetPixelFormat(HDC hdc)
		{
			static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
				{
					sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
					1,											// Version Number
					PFD_DRAW_TO_WINDOW |						// Format Must Support Window
					PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
					PFD_DOUBLEBUFFER,							// Must Support Double Buffering
					PFD_TYPE_RGBA,								// Request An RGBA Format
					16,										// Select Our Color Depth
					0, 0, 0, 0, 0, 0,							// Color Bits Ignored
					0,											// No Alpha Buffer
					0,											// Shift Bit Ignored
					0,											// No Accumulation Buffer
					0, 0, 0, 0,									// Accumulation Bits Ignored
					16,											// 16Bit Z-Buffer (Depth Buffer)  
					0,											// No Stencil Buffer
					0,											// No Auxiliary Buffer
					PFD_MAIN_PLANE,								// Main Drawing Layer
					0,											// Reserved
					0, 0, 0										// Layer Masks Ignored
				};
			
			GLint  iPixelFormat; 
		 
			// get the device context's best, available pixel format match 
			if((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}
			 
			// make that match the device context's current pixel format 
			if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}

			if((m_hglrc = wglCreateContext(m_hDC)) == NULL)
			{
				MessageBox::Show("wglCreateContext Failed");
				return 0;
			}

			if((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return 0;
			}
			return 1;
		}


}

