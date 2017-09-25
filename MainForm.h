// +2: EC
// -2: SVN: 
// -0.5: Unallowed warning
// -0.5: Didn't display filename
// -0.5: Didn't clear on read
// -0.5: Write input file name
// -2: EndsWith error
// -0.5: some data member are locals
// -0.5: On Close

//---------------------------------------------------------------------
// Name:    James Etten, Junsu Jeong, Vang Xiong.
// Project: Program 5, Using a Concordance with a document.
// Purpose: Interacts with the user to display, and manipulate the
//          elements within the Concordance file.
//---------------------------------------------------------------------

#pragma once

#include <msclr\marshal_cppstd.h> 
using namespace msclr::interop;
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Concordance.h"
using namespace std;


namespace Prog5 {

   using namespace System;
   using namespace System::ComponentModel;
   using namespace System::Collections;
   using namespace System::Windows::Forms;
   using namespace System::Data;
   using namespace System::Drawing;

   /// <summary>
   /// Summary for MainForm
   /// </summary>
   public ref class MainForm : public System::Windows::Forms::Form
   {

   public:
      MainForm(void)
      {
         InitializeComponent();
         conc = new Concordance();
      }

   protected:
      /// <summary>
      /// Clean up any resources being used.
      /// </summary>
      Concordance * conc;
      ~MainForm()
      {
         if (components)
         {
            delete components;
         }
      };
   private: System::Windows::Forms::Button^  btnStartsWith;
   private: System::Windows::Forms::MenuStrip^  menuStrip1;
   private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
   private: System::Windows::Forms::TextBox^  substringBox;
   private: System::Windows::Forms::Button^  btnEndsWith;
   private: System::Windows::Forms::Button^  btnContains;
   private: System::Windows::Forms::Label^  label1;
   private: System::Windows::Forms::ListBox^  wordListBox;
   private: System::Windows::Forms::Label^  label2;
   private: System::Windows::Forms::Button^  btnShowWord;
   private: System::Windows::Forms::Button^  btnDeleteWork;

   private: System::Windows::Forms::Label^  label3;
   private: System::Windows::Forms::Button^  btnClearDisplay;
   private: System::Windows::Forms::TextBox^  displayBox;


   private:
      /// <summary>
      /// Required designer variable.
      /// </summary>
      System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
      /// <summary>
      /// Required method for Designer support - do not modify
      /// the contents of this method with the code editor.
      /// </summary>
      void InitializeComponent(void)
      {
         this->btnStartsWith = (gcnew System::Windows::Forms::Button());
         this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
         this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->substringBox = (gcnew System::Windows::Forms::TextBox());
         this->btnEndsWith = (gcnew System::Windows::Forms::Button());
         this->btnContains = (gcnew System::Windows::Forms::Button());
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->wordListBox = (gcnew System::Windows::Forms::ListBox());
         this->label2 = (gcnew System::Windows::Forms::Label());
         this->btnShowWord = (gcnew System::Windows::Forms::Button());
         this->btnDeleteWork = (gcnew System::Windows::Forms::Button());
         this->label3 = (gcnew System::Windows::Forms::Label());
         this->btnClearDisplay = (gcnew System::Windows::Forms::Button());
         this->displayBox = (gcnew System::Windows::Forms::TextBox());
         this->menuStrip1->SuspendLayout();
         this->SuspendLayout();
         // 
         // btnStartsWith
         // 
         this->btnStartsWith->Location = System::Drawing::Point(12, 78);
         this->btnStartsWith->Name = L"btnStartsWith";
         this->btnStartsWith->Size = System::Drawing::Size(75, 23);
         this->btnStartsWith->TabIndex = 0;
         this->btnStartsWith->Text = L"Starts With";
         this->btnStartsWith->UseVisualStyleBackColor = true;
         this->btnStartsWith->Click += gcnew System::EventHandler(this, &MainForm::btnStartsWith_Click);
         // 
         // menuStrip1
         // 
         this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
         this->menuStrip1->Location = System::Drawing::Point(0, 0);
         this->menuStrip1->Name = L"menuStrip1";
         this->menuStrip1->Size = System::Drawing::Size(784, 24);
         this->menuStrip1->TabIndex = 1;
         this->menuStrip1->Text = L"menuStrip1";
         // 
         // fileToolStripMenuItem
         // 
         this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
            this->openToolStripMenuItem,
               this->saveToolStripMenuItem, this->exitToolStripMenuItem
         });
         this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
         this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
         this->fileToolStripMenuItem->Text = L"File";
         this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::fileToolStripMenuItem_Click);
         // 
         // openToolStripMenuItem
         // 
         this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
         this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
         this->openToolStripMenuItem->Text = L"Open";
         this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openToolStripMenuItem_Click);
         // 
         // saveToolStripMenuItem
         // 
         this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
         this->saveToolStripMenuItem->Size = System::Drawing::Size(103, 22);
         this->saveToolStripMenuItem->Text = L"Save";
         this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveToolStripMenuItem_Click);
         // 
         // exitToolStripMenuItem
         // 
         this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
         this->exitToolStripMenuItem->Size = System::Drawing::Size(103, 22);
         this->exitToolStripMenuItem->Text = L"Exit";
         this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem_Click);
         // 
         // substringBox
         // 
         this->substringBox->Location = System::Drawing::Point(12, 52);
         this->substringBox->Name = L"substringBox";
         this->substringBox->Size = System::Drawing::Size(237, 20);
         this->substringBox->TabIndex = 2;
         // 
         // btnEndsWith
         // 
         this->btnEndsWith->Location = System::Drawing::Point(93, 78);
         this->btnEndsWith->Name = L"btnEndsWith";
         this->btnEndsWith->Size = System::Drawing::Size(75, 23);
         this->btnEndsWith->TabIndex = 3;
         this->btnEndsWith->Text = L"Ends With";
         this->btnEndsWith->UseVisualStyleBackColor = true;
         this->btnEndsWith->Click += gcnew System::EventHandler(this, &MainForm::btnEndsWith_Click);
         // 
         // btnContains
         // 
         this->btnContains->Location = System::Drawing::Point(174, 78);
         this->btnContains->Name = L"btnContains";
         this->btnContains->Size = System::Drawing::Size(75, 23);
         this->btnContains->TabIndex = 4;
         this->btnContains->Text = L"Contains";
         this->btnContains->UseVisualStyleBackColor = true;
         this->btnContains->Click += gcnew System::EventHandler(this, &MainForm::btnContains_Click);
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Location = System::Drawing::Point(13, 33);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(85, 13);
         this->label1->TabIndex = 5;
         this->label1->Text = L"Type a substring";
         // 
         // wordListBox
         // 
         this->wordListBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left));
         this->wordListBox->FormattingEnabled = true;
         this->wordListBox->Location = System::Drawing::Point(12, 142);
         this->wordListBox->Name = L"wordListBox";
         this->wordListBox->Size = System::Drawing::Size(250, 290);
         this->wordListBox->TabIndex = 6;
         this->wordListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::wordListBox_SelectedIndexChanged);
         // 
         // label2
         // 
         this->label2->AutoSize = true;
         this->label2->Location = System::Drawing::Point(12, 123);
         this->label2->Name = L"label2";
         this->label2->Size = System::Drawing::Size(52, 13);
         this->label2->TabIndex = 7;
         this->label2->Text = L"Word List";
         // 
         // btnShowWord
         // 
         this->btnShowWord->Location = System::Drawing::Point(277, 142);
         this->btnShowWord->Name = L"btnShowWord";
         this->btnShowWord->Size = System::Drawing::Size(134, 23);
         this->btnShowWord->TabIndex = 8;
         this->btnShowWord->Text = L"Show Selected Word";
         this->btnShowWord->UseVisualStyleBackColor = true;
         this->btnShowWord->Click += gcnew System::EventHandler(this, &MainForm::btnShowWord_Click);
         // 
         // btnDeleteWork
         // 
         this->btnDeleteWork->Location = System::Drawing::Point(277, 186);
         this->btnDeleteWork->Name = L"btnDeleteWork";
         this->btnDeleteWork->Size = System::Drawing::Size(134, 23);
         this->btnDeleteWork->TabIndex = 9;
         this->btnDeleteWork->Text = L"Delete Selected Work";
         this->btnDeleteWork->UseVisualStyleBackColor = true;
         this->btnDeleteWork->Click += gcnew System::EventHandler(this, &MainForm::btnDeleteWork_Click);
         // 
         // label3
         // 
         this->label3->AutoSize = true;
         this->label3->Location = System::Drawing::Point(475, 122);
         this->label3->Name = L"label3";
         this->label3->Size = System::Drawing::Size(41, 13);
         this->label3->TabIndex = 11;
         this->label3->Text = L"Display";
         // 
         // btnClearDisplay
         // 
         this->btnClearDisplay->Location = System::Drawing::Point(630, 111);
         this->btnClearDisplay->Name = L"btnClearDisplay";
         this->btnClearDisplay->Size = System::Drawing::Size(94, 23);
         this->btnClearDisplay->TabIndex = 12;
         this->btnClearDisplay->Text = L"Clear Display";
         this->btnClearDisplay->UseVisualStyleBackColor = true;
         this->btnClearDisplay->Click += gcnew System::EventHandler(this, &MainForm::btnClearDisplay_Click);
         // 
         // displayBox
         // 
         this->displayBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left));
         this->displayBox->Location = System::Drawing::Point(474, 142);
         this->displayBox->Multiline = true;
         this->displayBox->Name = L"displayBox";
         this->displayBox->ReadOnly = true;
         this->displayBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
         this->displayBox->Size = System::Drawing::Size(250, 290);
         this->displayBox->TabIndex = 13;
         this->displayBox->TextChanged += gcnew System::EventHandler(this, &MainForm::displayBox_TextChanged);
         // 
         // MainForm
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(784, 461);
         this->Controls->Add(this->displayBox);
         this->Controls->Add(this->btnClearDisplay);
         this->Controls->Add(this->label3);
         this->Controls->Add(this->btnDeleteWork);
         this->Controls->Add(this->btnShowWord);
         this->Controls->Add(this->label2);
         this->Controls->Add(this->wordListBox);
         this->Controls->Add(this->label1);
         this->Controls->Add(this->btnContains);
         this->Controls->Add(this->btnEndsWith);
         this->Controls->Add(this->substringBox);
         this->Controls->Add(this->btnStartsWith);
         this->Controls->Add(this->menuStrip1);
         this->MainMenuStrip = this->menuStrip1;
         this->Name = L"MainForm";
         this->Text = L"Concordance";
         this->menuStrip1->ResumeLayout(false);
         this->menuStrip1->PerformLayout();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
      
#pragma endregion

   //------------------------------------------------------------------
   // Handles the opperation of the starts with button. If nothing is
   // entered into the substring box, an error message is output.
   // otherwise the entered word is searched for and displayed.
   //------------------------------------------------------------------
   private: System::Void btnStartsWith_Click(System::Object^  sender, System::EventArgs^  e)
   {
      if (substringBox->Text->Length == 0)
         MessageBox::Show("You must enter a substring.");
      else
      {
         string subStr = marshal_as<string>(substringBox->Text);
         conc->StartWith(subStr,wordListBox);

      }
   }

   //------------------------------------------------------------------
   // Handles the opperation of the ends with button. If nothing is
   // entered into the substring box, an error message is output.
   // otherwise the entered word is searched for and displayed.
   //------------------------------------------------------------------
   private: System::Void btnEndsWith_Click(System::Object^  sender, System::EventArgs^  e)
   {
      if (substringBox->Text->Length == 0)
         MessageBox::Show("You must enter a substring.");
      else
      {
         string subStr = marshal_as<string>(substringBox->Text);
         conc->EndWith(subStr, wordListBox);

      }
   }
   //------------------------------------------------------------------
   // Handles the opperation of the file button on the menu strip.
   //------------------------------------------------------------------
   private: System::Void fileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
   {

   }

   //------------------------------------------------------------------
   // Handles the opperation of the open button in the menu strip.
   // Opens a file for the program to read from.
   //------------------------------------------------------------------
   private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
   {
      OpenFileDialog ^ openFileDialog = gcnew OpenFileDialog();
      openFileDialog->InitialDirectory = "k:\\Courses\\CSSE\\CourseFiles\\CS2630\\Programs\\Prog5";
      if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
      {
         string line, str, word;
         String^msg;
         int lineNum = 1;
         String ^ filename = openFileDialog->FileName;
         string file = marshal_as<string>(filename);
         ifstream ifs(file);
         getline(ifs, line);
         while (!ifs.eof())
         {
            istringstream iss(line);
            iss >> word;
            while (iss)
            {
               conc->Add(word, lineNum);
               iss >> word;
            }
            lineNum++;
            getline(ifs, line);
         }
         ifs.close();
      }


   }

   //------------------------------------------------------------------
   // Handles the opperation of the save button in the menu strip.
   // Saves the information stored in the Concordance class to an
   // output file.
   //------------------------------------------------------------------
   private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
   {
      SaveFileDialog ^saveFileDialog = gcnew SaveFileDialog();
      saveFileDialog->InitialDirectory = "k:\\Courses";
      if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
      {
         String ^ fileName = saveFileDialog->FileName;
         string file = marshal_as<string>(fileName);
         ofstream ofs(file);
         ofs << file << endl;
         conc->Print(ofs);
         ofs.close();
      }
   }
   //------------------------------------------------------------------
   // Handles the opperation of the exit button in the menu strip.
   // Exits the Concordance program.
   //------------------------------------------------------------------
   private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
   {
      delete conc;
      _CrtDumpMemoryLeaks();
      Application::Exit();
   }
   //------------------------------------------------------------------
   // Handles the opperation of the contains button. If nothing is
   // entered into the substring box, an error message is output.
   // otherwise the entered word is searched for and displayed.
   //------------------------------------------------------------------
   private: System::Void btnContains_Click(System::Object^  sender, System::EventArgs^  e)
   {
      if (substringBox->Text->Length == 0)
         MessageBox::Show("You must enter a substring.");
      else
      {
         string subStr = marshal_as<string>(substringBox->Text);
         conc->Contains(subStr, wordListBox);

      }
   }

   //------------------------------------------------------------------
   // Handles the opperation of the word list box.
   //------------------------------------------------------------------
   private: System::Void wordListBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
   {

   }

   //------------------------------------------------------------------
   // Handles the opperation of the show word button. If a word is not
   // selected an error message is displayed. If a selected word does
   // not exist an error message is displayed. Otherwise the selected
   // word is displayed in the display box.
   //------------------------------------------------------------------
   private: System::Void btnShowWord_Click(System::Object^  sender, System::EventArgs^  e)
   {
      if (wordListBox->SelectedIndex < 0)
         MessageBox::Show("Select a Word to Display.");
      else
      {
         string disStr = marshal_as<string>(wordListBox->SelectedItem->ToString());
         bool exist = conc->Display(disStr, displayBox);
         if (!exist)
            MessageBox::Show("Word not in concordance.");

      }
   }

   //------------------------------------------------------------------
   // Handles the opperation of the delete work button. If a word is
   // not selected an appropriate error message is displayed. If the
   // word is not found an appropriate error message is displayed. If
   // the word is successfully deleted an appropriate message is
   // displayed.
   //------------------------------------------------------------------
   private: System::Void btnDeleteWork_Click(System::Object^  sender, System::EventArgs^  e)
   {
         if (wordListBox->SelectedIndex >= 0)
         {
            string delStr = marshal_as<string>(wordListBox->SelectedItem->ToString());
            bool exist = conc->Remove(delStr);
            if (!exist)
               MessageBox::Show("Word not in concordance.");
            else
               MessageBox::Show("Word deleted from concordance.");
         }
         else
            MessageBox::Show("Select word to delete.");
   }

   //------------------------------------------------------------------
   // Handles the opperation of the display box when the selected
   // index changed.
   //------------------------------------------------------------------
   private: System::Void displayBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
   {

   }

   //------------------------------------------------------------------
   // Handles the opperation of the clear display button.
   //------------------------------------------------------------------
   private: System::Void btnClearDisplay_Click(System::Object^  sender, System::EventArgs^  e)
   {
      displayBox->Clear();
   }

   //------------------------------------------------------------------
   // Handles the opperation of the display box when the text is
   // changed.
   //------------------------------------------------------------------
   private: System::Void displayBox_TextChanged(System::Object^  sender, System::EventArgs^  e)
   {

   }
   };
}
