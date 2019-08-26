#include "EncoderForm.h"
#include <windows.h>

using namespace System;
using namespace System::Windows::Forms;

using namespace System::Diagnostics;


[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	EncorderComponent::EncoderForm form;
	Application::Run(%form);

}


