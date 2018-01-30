#pragma once

/*
Author: Shane Vance
Last Update: 2018/28/01
Purpose: CS 481 Project
*/

#include "OpenGL.h"
#include <string>

namespace VisCanvas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	/// <summary>
	/// Summary for VisCanvas
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class VisCanvas : public System::Windows::Forms::Form {

	public:

		VisCanvas(void) {
			InitializeComponent();		
			/* Setup OpenGL for this Parent Window */
			OpenGL = gcnew COpenGL(this, this->Width, this->Height); 
		}

	protected:

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VisCanvas() {
			if (components) {
				delete components;
			}
		}

	private: System::ComponentModel::IContainer^  components;
	protected: 

			 // TIMER FOR PAINTING OPENGL
	private: System::Windows::Forms::Timer^  timer1;

			 // STATUS STRIP
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;

			 // PANELS
	private: System::Windows::Forms::Panel^  Tools;
	private: System::Windows::Forms::Panel^  Options;

			 // CHECK LIST ITEMS
	private: System::Windows::Forms::CheckedListBox^  checkedListBox1;

			 // LABELS
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;

			 // RADIO BUTTONS
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;

			 // RGB TOGGLES 
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;

			 // COLOR SELECTOR
	private: Nevron::Nov::WinFormControls::NHsbColorPickerControl^  nHsbColorPickerControl1; // CLASS SELECTOR
	private: Nevron::Nov::WinFormControls::NColorBoxControl^  nColorBoxControl1; // BACKGROUND SELECTOR

			 // I DO NOT KNOW WHAT THIS IS FOR
	private: System::Windows::Forms::TextBox^  textBox1;	

			 // MENU BAR ITEMS
	private: System::Windows::Forms::MenuStrip^  menubar;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem4;	
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  reorderToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  descendingSortToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  colorblindFilterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  parallelCoordinatesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  shiftedParallelCoordinatesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  sortingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;	
	private: System::Windows::Forms::ToolStripMenuItem^  resetToolStripMenuItem;

			 // TOOL BUTTONS
	private: Nevron::Nov::WinFormControls::NToggleButtonControl^  reorderNToggleButtonControl1;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl1;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl2;
	private: System::Windows::Forms::Button^  button1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		OpenGLForm::COpenGL ^ OpenGL;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VisCanvas::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->menubar = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->parallelCoordinatesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->shiftedParallelCoordinatesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->colorblindFilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->resetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sortingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->descendingSortToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reorderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Tools = (gcnew System::Windows::Forms::Panel());
			this->nColorBoxControl1 = (gcnew Nevron::Nov::WinFormControls::NColorBoxControl());
			this->nButtonControl2 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
			this->nButtonControl1 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
			this->reorderNToggleButtonControl1 = (gcnew Nevron::Nov::WinFormControls::NToggleButtonControl());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->Options = (gcnew System::Windows::Forms::Panel());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->nHsbColorPickerControl1 = (gcnew Nevron::Nov::WinFormControls::NHsbColorPickerControl());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->statusStrip1->SuspendLayout();
			this->menubar->SuspendLayout();
			this->Tools->SuspendLayout();
			this->Options->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &VisCanvas::timer1_Tick);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
			this->statusStrip1->Location = System::Drawing::Point(0, 667);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1184, 22);
			this->statusStrip1->TabIndex = 0;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(143, 17);
			this->toolStripStatusLabel1->Text = L"Mouse Position goes here";
			// 
			// menubar
			// 
			this->menubar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->fileToolStripMenuItem, 
				this->viewToolStripMenuItem, this->toolsToolStripMenuItem1, this->helpToolStripMenuItem});
			this->menubar->Location = System::Drawing::Point(0, 0);
			this->menubar->Name = L"menubar";
			this->menubar->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menubar->Size = System::Drawing::Size(1184, 24);
			this->menubar->TabIndex = 1;
			this->menubar->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->openToolStripMenuItem, 
				this->saveToolStripMenuItem, this->toolStripMenuItem4, this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(143, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {this->parallelCoordinatesToolStripMenuItem, 
				this->shiftedParallelCoordinatesToolStripMenuItem, this->toolStripMenuItem2, this->colorblindFilterToolStripMenuItem, this->toolStripMenuItem1, 
				this->toolsToolStripMenuItem, this->optionsToolStripMenuItem, this->toolStripMenuItem3, this->resetToolStripMenuItem});
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// parallelCoordinatesToolStripMenuItem
			// 
			this->parallelCoordinatesToolStripMenuItem->Name = L"parallelCoordinatesToolStripMenuItem";
			this->parallelCoordinatesToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->parallelCoordinatesToolStripMenuItem->Text = L"Parallel Coordinates";
			// 
			// shiftedParallelCoordinatesToolStripMenuItem
			// 
			this->shiftedParallelCoordinatesToolStripMenuItem->Name = L"shiftedParallelCoordinatesToolStripMenuItem";
			this->shiftedParallelCoordinatesToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->shiftedParallelCoordinatesToolStripMenuItem->Text = L"Shifted Parallel Coordinates";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(216, 6);
			// 
			// colorblindFilterToolStripMenuItem
			// 
			this->colorblindFilterToolStripMenuItem->Name = L"colorblindFilterToolStripMenuItem";
			this->colorblindFilterToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->colorblindFilterToolStripMenuItem->Text = L"Colorblind Filter";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(216, 6);
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->Checked = true;
			this->toolsToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
				| System::Windows::Forms::Keys::T));
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->toolsToolStripMenuItem->Text = L"Tools Panel";
			this->toolsToolStripMenuItem->ToolTipText = L"Tools Panel";
			this->toolsToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::toolsToolStripMenuItem_Click);
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->Checked = true;
			this->optionsToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
				| System::Windows::Forms::Keys::O));
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->optionsToolStripMenuItem->Text = L"Options Panel";
			this->optionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::classesToolStripMenuItem_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(216, 6);
			// 
			// resetToolStripMenuItem
			// 
			this->resetToolStripMenuItem->Name = L"resetToolStripMenuItem";
			this->resetToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->resetToolStripMenuItem->Text = L"Reset";
			// 
			// toolsToolStripMenuItem1
			// 
			this->toolsToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->sortingToolStripMenuItem, 
				this->descendingSortToolStripMenuItem, this->reorderToolStripMenuItem});
			this->toolsToolStripMenuItem1->Name = L"toolsToolStripMenuItem1";
			this->toolsToolStripMenuItem1->Size = System::Drawing::Size(47, 20);
			this->toolsToolStripMenuItem1->Text = L"Tools";
			// 
			// sortingToolStripMenuItem
			// 
			this->sortingToolStripMenuItem->Name = L"sortingToolStripMenuItem";
			this->sortingToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->sortingToolStripMenuItem->Text = L"Ascending Sort";
			// 
			// descendingSortToolStripMenuItem
			// 
			this->descendingSortToolStripMenuItem->Name = L"descendingSortToolStripMenuItem";
			this->descendingSortToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->descendingSortToolStripMenuItem->Text = L"Descending Sort";
			// 
			// reorderToolStripMenuItem
			// 
			this->reorderToolStripMenuItem->Name = L"reorderToolStripMenuItem";
			this->reorderToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->reorderToolStripMenuItem->Text = L"Reorder";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->aboutToolStripMenuItem, 
				this->helpToolStripMenuItem1});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::aboutToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem1
			// 
			this->helpToolStripMenuItem1->Name = L"helpToolStripMenuItem1";
			this->helpToolStripMenuItem1->Size = System::Drawing::Size(107, 22);
			this->helpToolStripMenuItem1->Text = L"Help";
			// 
			// Tools
			// 
			this->Tools->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->Tools->Controls->Add(this->button1);
			this->Tools->Controls->Add(this->nColorBoxControl1);
			this->Tools->Controls->Add(this->nButtonControl2);
			this->Tools->Controls->Add(this->nButtonControl1);
			this->Tools->Controls->Add(this->reorderNToggleButtonControl1);
			this->Tools->Controls->Add(this->label4);
			this->Tools->Dock = System::Windows::Forms::DockStyle::Left;
			this->Tools->Location = System::Drawing::Point(0, 24);
			this->Tools->Name = L"Tools";
			this->Tools->Size = System::Drawing::Size(71, 643);
			this->Tools->TabIndex = 2;
			// 
			// nColorBoxControl1
			// 
			this->nColorBoxControl1->AutoSize = false;
			this->nColorBoxControl1->DesignTimeState = resources->GetString(L"nColorBoxControl1.DesignTimeState");
			this->nColorBoxControl1->Location = System::Drawing::Point(7, 281);
			this->nColorBoxControl1->Name = L"nColorBoxControl1";
			this->nColorBoxControl1->Size = System::Drawing::Size(55, 34);
			this->nColorBoxControl1->TabIndex = 13;
			// 
			// nButtonControl2
			// 
			this->nButtonControl2->AutoSize = false;
			this->nButtonControl2->DesignTimeState = resources->GetString(L"nButtonControl2.DesignTimeState");
			this->nButtonControl2->Location = System::Drawing::Point(17, 150);
			this->nButtonControl2->Name = L"nButtonControl2";
			this->nButtonControl2->Size = System::Drawing::Size(36, 36);
			this->nButtonControl2->TabIndex = 12;
			// 
			// nButtonControl1
			// 
			this->nButtonControl1->AutoSize = false;
			this->nButtonControl1->DesignTimeState = resources->GetString(L"nButtonControl1.DesignTimeState");
			this->nButtonControl1->Location = System::Drawing::Point(17, 94);
			this->nButtonControl1->Name = L"nButtonControl1";
			this->nButtonControl1->Size = System::Drawing::Size(36, 36);
			this->nButtonControl1->TabIndex = 11;
			// 
			// reorderNToggleButtonControl1
			// 
			this->reorderNToggleButtonControl1->AutoSize = false;
			this->reorderNToggleButtonControl1->DesignTimeState = resources->GetString(L"reorderNToggleButtonControl1.DesignTimeState");
			this->reorderNToggleButtonControl1->Location = System::Drawing::Point(17, 38);
			this->reorderNToggleButtonControl1->Name = L"reorderNToggleButtonControl1";
			this->reorderNToggleButtonControl1->Size = System::Drawing::Size(36, 36);
			this->reorderNToggleButtonControl1->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(54, 3);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(14, 17);
			this->label4->TabIndex = 7;
			this->label4->Text = L"x";
			this->label4->Click += gcnew System::EventHandler(this, &VisCanvas::label4_Click);
			this->label4->MouseLeave += gcnew System::EventHandler(this, &VisCanvas::leavingToolBoxHoverColor1);
			this->label4->MouseHover += gcnew System::EventHandler(this, &VisCanvas::toolBoxExitHoverColor1);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioButton1->Location = System::Drawing::Point(13, 38);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(99, 36);
			this->radioButton1->TabIndex = 6;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Parallel\r\nCoordinates";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &VisCanvas::radioButton1_CheckedChanged);
			// 
			// Options
			// 
			this->Options->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->Options->BackColor = System::Drawing::SystemColors::Control;
			this->Options->Controls->Add(this->radioButton2);
			this->Options->Controls->Add(this->label5);
			this->Options->Controls->Add(this->radioButton1);
			this->Options->Controls->Add(this->numericUpDown3);
			this->Options->Controls->Add(this->numericUpDown2);
			this->Options->Controls->Add(this->numericUpDown1);
			this->Options->Controls->Add(this->textBox1);
			this->Options->Controls->Add(this->nHsbColorPickerControl1);
			this->Options->Controls->Add(this->label3);
			this->Options->Controls->Add(this->label2);
			this->Options->Controls->Add(this->label1);
			this->Options->Controls->Add(this->checkedListBox1);
			this->Options->Dock = System::Windows::Forms::DockStyle::Right;
			this->Options->Location = System::Drawing::Point(1020, 24);
			this->Options->Name = L"Options";
			this->Options->Size = System::Drawing::Size(164, 643);
			this->Options->TabIndex = 3;
			this->Options->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &VisCanvas::Classes_Paint);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioButton2->Location = System::Drawing::Point(13, 82);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(119, 36);
			this->radioButton2->TabIndex = 17;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Shifted Parallel \r\nCoordinates";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label5->Location = System::Drawing::Point(147, 3);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(14, 17);
			this->label5->TabIndex = 16;
			this->label5->Text = L"x";
			this->label5->Click += gcnew System::EventHandler(this, &VisCanvas::label5_Click);
			this->label5->MouseLeave += gcnew System::EventHandler(this, &VisCanvas::label5_MouseLeave);
			this->label5->MouseHover += gcnew System::EventHandler(this, &VisCanvas::label5_MouseHover);
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(114, 482);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->ReadOnly = true;
			this->numericUpDown3->Size = System::Drawing::Size(38, 20);
			this->numericUpDown3->TabIndex = 15;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(63, 482);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->ReadOnly = true;
			this->numericUpDown2->Size = System::Drawing::Size(38, 20);
			this->numericUpDown2->TabIndex = 14;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(13, 482);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->ReadOnly = true;
			this->numericUpDown1->Size = System::Drawing::Size(38, 20);
			this->numericUpDown1->TabIndex = 13;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(13, 436);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(139, 22);
			this->textBox1->TabIndex = 12;
			// 
			// nHsbColorPickerControl1
			// 
			this->nHsbColorPickerControl1->AutoSize = false;
			this->nHsbColorPickerControl1->DesignTimeState = nullptr;
			this->nHsbColorPickerControl1->Location = System::Drawing::Point(13, 305);
			this->nHsbColorPickerControl1->Name = L"nHsbColorPickerControl1";
			this->nHsbColorPickerControl1->Size = System::Drawing::Size(139, 126);
			this->nHsbColorPickerControl1->TabIndex = 11;
			this->nHsbColorPickerControl1->SelectedColorChanged += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NValueChangeEventArgs^ >(this, &VisCanvas::nHsbColorPickerControl1_SelectedColorChanged_1);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(111, 463);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(20, 16);
			this->label3->TabIndex = 10;
			this->label3->Text = L"B:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(60, 463);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(21, 16);
			this->label2->TabIndex = 9;
			this->label2->Text = L"G:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(10, 463);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 16);
			this->label1->TabIndex = 8;
			this->label1->Text = L"R:";
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Class 1", L"Class 2", L"Class 3", L"Class 4", 
				L"Class 5"});
			this->checkedListBox1->Location = System::Drawing::Point(13, 159);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(139, 106);
			this->checkedListBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(17, 204);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(36, 40);
			this->button1->TabIndex = 14;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &VisCanvas::button1_Click);
			// 
			// VisCanvas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->ClientSize = System::Drawing::Size(1184, 689);
			this->Controls->Add(this->Options);
			this->Controls->Add(this->Tools);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menubar);
			this->DoubleBuffered = true;
			this->MainMenuStrip = this->menubar;
			this->MinimumSize = System::Drawing::Size(1200, 726);
			this->Name = L"VisCanvas";
			this->Text = L"VisCanvas";
			this->Resize += gcnew System::EventHandler(this, &VisCanvas::ResizeMe);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->menubar->ResumeLayout(false);
			this->menubar->PerformLayout();
			this->Tools->ResumeLayout(false);
			this->Tools->PerformLayout();
			this->Options->ResumeLayout(false);
			this->Options->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

			 /* PAINTS TO THE VIEWING WINDOW */
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 // display our OpenGL to the Parent Form
				 OpenGL->Display();	
				 OpenGL->SwapOpenGLBuffers();				 
			 }
			 /* THIS WILL RESIZE THE SCREEN */
	private: System::Void ResizeMe(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->Resize(0, 0, this->Width, this->Height, SWP_NOSENDCHANGING | SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOMOVE);
			 }
			 /* CREATES A CHECKED OR UNCHECKED STATE - OPTIONS PANEL */
	private: System::Void classesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 optionPanel();
			 }
			 /* TODO: UPDATE THIS MAYBE? */
	private: System::Void editToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 }

			 /* THIS IS FOR THE OPEN DIALOGBOX */
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 openFile();
			 }

			 /* TODO: UPDATE THESE */
	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

			 }

			 /* THIS ALLOWS US TO CHANGE COLORS USING A COLOR PALETTE */
	private: System::Void nHsbColorPickerControl1_SelectedColorChanged_1(Nevron::Nov::Dom::NValueChangeEventArgs^  arg) {
				 Nevron::Nov::Graphics::NColor selectedColor = (Nevron::Nov::Graphics::NColor)arg->NewValue;
				 System::String^ hex = selectedColor.GetHEX();
				 const char* toRGB = (const char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi( hex ).ToPointer(); // converts System::String^ to char*
				 std::string s(toRGB); // create a string of the HEX char value
				 s = s.substr(1, s.length()); // remove the "#" from the front of the string
				 char* str = (char*)s.c_str(); // convert back to a dynamic char array
				 int R, G, B;
				 sscanf_s(str, "%02x%02x%02x", &R, &G, &B); // convert HEX to RGB	

				 OpenGL->SetRGB((GLdouble)R, (GLdouble)G, (GLdouble)B);

				 /* update the textbox color on RGB update */
				 this->textBox1->BackColor = System::Drawing::Color::FromArgb(OpenGL->getRed(), OpenGL->getGreen(), OpenGL->getBlue());

				 /* clean up the const char* toRGB memory */
				 System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)toRGB));
			 }

	private: System::Void Classes_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }

			 /* TOOLS PANEL HIDE BUTTON */
	private: System::Void toolBoxExitHoverColor1(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 this->label4->ForeColor = System::Drawing::Color::LightGray;		 
			 }
			 /* TOOLS PANEL HIDE BUTTON */
	private: System::Void leavingToolBoxHoverColor1(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 this->label4->ForeColor = System::Drawing::Color::Black;		 
			 }
			 /* TOOLS PANEL HIDE BUTTON */
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 toolPanel();
			 }
			 /* PUT A CHECK IN THE MENU BAR FOR THE TOOL PANEL VIEW */
	private: System::Void toolsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 toolPanel();
			 }
			 /* OPTIONS PANEL HIDE BUTTON */
	private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 optionPanel();
			 }
			 /* WHEN THE USER HOVERS OVER THE EXIT COMMAND IT WILL HIGHLIGHT GRAY (OPTIONS PANEL) */
	private: System::Void label5_MouseHover(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 this->label5->ForeColor = System::Drawing::Color::LightGray;
			 }
			 /* WHEN THE USER LEAVES THE HOVER STATE OF THE EXIT COMMAND IT WILL GO BACK TO THE DEFAULT COLOR (OPTIONS PANEL) */
	private: System::Void label5_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 this->label5->ForeColor = System::Drawing::Color::Black;
			 }
			 /* ABOUT DIALOG */
	private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 MessageBox::Show("Design by Shane Vance, Daniel Ortyn, Nico Espitia and Brennan Barni\r                                         "
					 + "For Dr. Boris Kovalerchuk\r                                                 2018 © VisCanvas");
			 }

	protected:

		/* HOTKEYS: GET THE KEY COMBINATION AND THEN WE'LL SEND A MESSAGE TO THE OTHER CLASS */
		virtual bool ProcessCmdKey(Message% msg, Keys keyData) override {
			// Open File Dialog
			if (keyData == (Keys::Control | Keys::O)) {
				openFile();				 
			}
			// Save File Dialog
			if (keyData == (Keys::Control | Keys::S)) {
				// TODO: add the savefiledialog stuff here
			}
			// Tools Panel
			if (keyData == (Keys::Control | Keys::Alt | Keys::T)) {
				toolPanel();				
			}
			// Options Panel
			if  (keyData == (Keys::Control | Keys::Alt | Keys::O)) {
				optionPanel();
			}
			return true;
		}

	private:

		System::Void openFile() {
			// TODO: last used directory method
			OpenFileDialog^ ofd = gcnew OpenFileDialog;
			ofd->InitialDirectory = ""; // NOTE "c:\\" for future reference.
			ofd->Filter = "Text Files (*.csv, *.txt, *.text)|*.csv; *.txt; *.text"; // we can add this later if needed (needs error handling if so) |All Files (*.*)|*.*";
			ofd->FilterIndex = 1;
			ofd->RestoreDirectory = true;

			if(ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				/* Convert System::String^ to a std::string */
				System::String^ path = ofd->FileName;
				const char* location = (const char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi( path ).ToPointer();
				std::string FILE_PATH(location);

				/* Pass the FILE_PATH to OpenGL for reading the file */
				OpenGL->SetFilePath(FILE_PATH);

				/* Clean up the const char* location memory */
				System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)location));
			}
		}

		System::Void toolPanel() {
			// is it checked 
			if (this->toolsToolStripMenuItem->Checked) {
				this->Tools->Dock = System::Windows::Forms::DockStyle::None;
				this->toolsToolStripMenuItem->Checked = false;
			} else {
				this->Tools->Dock = System::Windows::Forms::DockStyle::Left;
				this->toolsToolStripMenuItem->Checked = true;
			}
			this->Tools->Visible = this->toolsToolStripMenuItem->Checked;
		}

		System::Void optionPanel() {
			// is it checked
			if (this->optionsToolStripMenuItem->Checked) {
				this->Options->Dock = System::Windows::Forms::DockStyle::None;
				this->optionsToolStripMenuItem->Checked = false;
			} else {
				this->Options->Dock = System::Windows::Forms::DockStyle::Right;
				this->optionsToolStripMenuItem->Checked = true;
			}
			this->Options->Visible = this->optionsToolStripMenuItem->Checked;
		}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 OpenGL->testButtonMethod();
			 }
};

}