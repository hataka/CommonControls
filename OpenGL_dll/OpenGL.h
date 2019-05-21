#pragma once

#include "stdafx.h"
#include "SampleScene.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace OpenGLForm 
{
	public ref class COpenGL: public System::Windows::Forms::NativeWindow
	{
	public:
		COpenGL(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight);
		COpenGL(System::Windows::Forms::Panel^ parentForm, GLsizei iWidth, GLsizei iHeight);
		COpenGL::COpenGL(System::String^ SampleScene, System::Windows::Forms::Panel^ parentForm, GLsizei iWidth, GLsizei iHeight);
		System::Void Render(System::Void);
		System::Void COpenGL::KeyDown(int keycode);
		System::Void SwapOpenGLBuffers(System::Void);

	public: GLvoid ReSizeGLScene(GLsizei width, GLsizei height);
	public: virtual System::Void MySetCurrentGLRC();
	public: bool InitGL(GLvoid);
	public: 
		// 独立クラス化で直接アクセスを可能にする Time-stamp: <2010-12-16 13:51:14 kahata>
		// array<GLuint>^ LoadTextures(System::String^ filename)
		static cli::array<GLuint>^ LoadTextures(System::String^ filename);
	private:
		HDC m_hDC;
		HGLRC m_hglrc;
		GLfloat	rtri;				// Angle for the triangle
		GLfloat	rquad;				// Angle for the quad
		static cli::array<GLuint>^ texture;
		String^ m_SampleScene;
		Lesson05^ lesson05;

	protected:
		~COpenGL(System::Void);
		GLint MySetPixelFormat(HDC hdc);
	};
}
