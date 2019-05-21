#pragma once

namespace OpenGLForm {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	//  ref class にしないと managed code を設置できない
	public ref class Lesson09
	{
		public:
			Lesson09(void);
			~Lesson09();
			static System::Void init(System::Void);
			static System::Void render(System::Void);
		private:
		private: static bool twinkle;					// Twinkling Stars On / Off
		private: static bool tp;							// T Pressed?
		private: static int num;						// Number Of Stars To Draw

	/* // マネージ型でここに置くとhangupする????
		private:
			ref struct Star {							// Create A Structure For Star
				byte r, g, b;						// Star's Color
				float dist;							// Star's Distance From Center
				float angle;							// Star's Current Angle
			};
		private: array<Star^>^  star;
	*/
		private: static float zoom;				// Viewing Distance Away From Stars
		private: static float tilt;				// Tilt The View
		private: static float spin;				// Spin Stars
		private: static Random^ rand;				// Randomizer

		private: static int loop;					// General Loop Variable
		static array<GLuint>^ texture;
		//gcroot<ManageClass^> m_manage;

		static System::Void LoadTextures(System::String^ filename);
/*
		GLfloat rtri;				// Angle for the triangle
		GLfloat rquad;				// Angle for the quad
		float xrot;					// X Rotation
		float yrot;					// Y Rotation
		float zrot;					// Z Rotation
		bool light;					// Lighting On / Off
		bool lp;						// L Pressed?
		bool fp;						// F Pressed?
		float xspeed;				// X Rotation Speed
		float yspeed;				// Y Rotation Speed
		float z;						// Depth Into Screen
		int filter;					// Which Filter To Use
*/
	};
}
