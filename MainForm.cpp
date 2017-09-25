//---------------------------------------------------------------------
// Name:    James Etten, Junsu Jeong, Vang Xiong.
// Project: Program 5, Using a Concordance with a document.
// Purpose: Interacts with the user to display, and manipulate the
//          elements within the Concordance file.
//---------------------------------------------------------------------

#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main()
{
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);
   Application::Run(gcnew Prog5::MainForm);
}
