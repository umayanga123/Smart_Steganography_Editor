#include "MainForm.h"
#include <windows.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MainComponent::MainForm form;
	Application::Run(%form);

}


