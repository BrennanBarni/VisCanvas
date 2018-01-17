#include "VisCanvas.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args) 
{
	Application::EnableVisualStyles;
	Application::SetCompatibleTextRenderingDefault(false);
	VisCanvas::VisCanvas vc;
	Application::Run(%vc);
}