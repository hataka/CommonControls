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

//  ref class Ç…ÇµÇ»Ç¢Ç∆ managed code Çê›íuÇ≈Ç´Ç»Ç¢
//	public ref class MesaGears
	public class MesaGears
	{
		public:
			MesaGears(void);
			~MesaGears();
			static System::Void init(System::Void);
			static System::Void render(System::Void);
		private:
			static System::Void MakeGears();
			static void MakeGear(double inner_radius, double outer_radius, double width, int teeth, double tooth_depth);
			static double rotx;// = 20.0;									// View's X-Axis Rotation
			static double roty;// = 30.0;									// View's Y-Axis Rotation
			static double rotz;// = 0.0;									// View's Z-Axis Rotation
			static unsigned int gear1;											// Display List For Red Gear
			static unsigned int gear2;											// Display List For Green Gear
			static unsigned int gear3;											// Display List For Blue Gear
			static float rAngle;// = 0.0f;								// Rotation Angle
	};
}
