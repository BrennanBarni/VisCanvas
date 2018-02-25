#pragma once

/*
Author: Shane Vance
Last Update: 2018/02/18
Purpose: CS 481 Project
*/

#include "OpenGL.h"
#include <string>
#include "AdditionalSettings.h"
#include "Settings.h"
#include "VisCanvasHelp.h"

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
			OpenGL = gcnew COpenGL(this, this->Width, this->Height - this->menubar->Height);
			this->previousClassAmount = 0;
			this->sortToggleState = false;
			this->shifToggleState = false;
			this->prevZoom = 100;
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

			 // PANELS
	private: System::Windows::Forms::Panel^  Tools;
	private: System::Windows::Forms::Panel^  Options;

			 // LABELS
	private: System::Windows::Forms::Label^  label4; // hide tools
	private: System::Windows::Forms::Label^  label5; // hide options

			 // BACKGROUND COLOR SELECTOR
	private: Nevron::Nov::WinFormControls::NColorBoxControl^  nColorBoxControl1; // BACKGROUND SELECTOR

			 // MENU BAR ITEMS
	private: System::Windows::Forms::MenuStrip^  menubar;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem4;	

	private: System::Windows::Forms::ToolStripMenuItem^  reorderToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  descendSortToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  ascendSortToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;	
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem5;
	private: System::Windows::Forms::ToolStripMenuItem^  meanLevelToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  medianLevelToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  originalDataToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem6;
	private: System::Windows::Forms::ToolStripMenuItem^  dimensionShiftingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  settingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sortOriginalToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  hypercubeToolStripMenuItem;

			 // TOOL BUTTONS
	private: System::Windows::Forms::Button^  manualSort;
	private: System::Windows::Forms::Button^  manualShift;
	private: System::Windows::Forms::Button^  sortAscend;
	private: System::Windows::Forms::Button^  sortDescend;
	private: System::Windows::Forms::Button^  sortOrig;
	private: System::Windows::Forms::Button^  hypercube;
	private: System::Windows::Forms::Button^  meanLevel;
	private: System::Windows::Forms::Button^  medianLevel;
	private: System::Windows::Forms::Button^  origData;

			 // COLOR PICKER
	private: Nevron::Nov::WinFormControls::NHsbColorPickerControl^  nHsbColorPickerControl1;
			 // this will display the currently selected color

			 // SELECT THE CLASS YOU WANT VISIBLE OR CHANGE ITS COLOR




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		OpenGLForm::COpenGL ^ OpenGL;
	private: System::Windows::Forms::DataGridView^  dataGridView1;



	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ToolStripMenuItem^  resetHypercubeToolStripMenuItem;
	private: Nevron::Nov::WinFormControls::NSliderControl^  nSliderControl1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem1;








	private: System::Windows::Forms::ComboBox^  comboBox1;


#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VisCanvas::typeid));
				 System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
				 System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
				 this->menubar = (gcnew System::Windows::Forms::MenuStrip());
				 this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolsToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->reorderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->dimensionShiftingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolStripMenuItem6 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->ascendSortToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->descendSortToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->sortOriginalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->hypercubeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->resetHypercubeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->meanLevelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->medianLevelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->originalDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->helpToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->Tools = (gcnew System::Windows::Forms::Panel());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->origData = (gcnew System::Windows::Forms::Button());
				 this->nColorBoxControl1 = (gcnew Nevron::Nov::WinFormControls::NColorBoxControl());
				 this->sortAscend = (gcnew System::Windows::Forms::Button());
				 this->hypercube = (gcnew System::Windows::Forms::Button());
				 this->medianLevel = (gcnew System::Windows::Forms::Button());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->manualShift = (gcnew System::Windows::Forms::Button());
				 this->meanLevel = (gcnew System::Windows::Forms::Button());
				 this->sortDescend = (gcnew System::Windows::Forms::Button());
				 this->manualSort = (gcnew System::Windows::Forms::Button());
				 this->sortOrig = (gcnew System::Windows::Forms::Button());
				 this->Options = (gcnew System::Windows::Forms::Panel());
				 this->panel1 = (gcnew System::Windows::Forms::Panel());
				 this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
				 this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
				 this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
				 this->nHsbColorPickerControl1 = (gcnew Nevron::Nov::WinFormControls::NHsbColorPickerControl());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->nSliderControl1 = (gcnew Nevron::Nov::WinFormControls::NSliderControl());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->optionsToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menubar->SuspendLayout();
				 this->Tools->SuspendLayout();
				 this->Options->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
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
				 this->statusStrip1->Location = System::Drawing::Point(0, 667);
				 this->statusStrip1->Name = L"statusStrip1";
				 this->statusStrip1->Size = System::Drawing::Size(1184, 22);
				 this->statusStrip1->TabIndex = 0;
				 this->statusStrip1->Text = L"statusStrip1";
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
				 this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->openToolStripMenuItem, 
					 this->saveToolStripMenuItem, this->toolStripMenuItem3, this->optionsToolStripMenuItem1, this->toolStripMenuItem4, this->exitToolStripMenuItem});
				 this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
				 this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
				 this->fileToolStripMenuItem->Text = L"File";
				 // 
				 // openToolStripMenuItem
				 // 
				 this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
				 this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
				 this->openToolStripMenuItem->Size = System::Drawing::Size(152, 22);
				 this->openToolStripMenuItem->Text = L"Open";
				 this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::openToolStripMenuItem_Click);
				 // 
				 // saveToolStripMenuItem
				 // 
				 this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
				 this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
				 this->saveToolStripMenuItem->Size = System::Drawing::Size(152, 22);
				 this->saveToolStripMenuItem->Text = L"Save";
				 this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::saveToolStripMenuItem_Click);
				 // 
				 // toolStripMenuItem4
				 // 
				 this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
				 this->toolStripMenuItem4->Size = System::Drawing::Size(149, 6);
				 // 
				 // exitToolStripMenuItem
				 // 
				 this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
				 this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
				 this->exitToolStripMenuItem->Text = L"Exit";
				 this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::exitToolStripMenuItem_Click);
				 // 
				 // viewToolStripMenuItem
				 // 
				 this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolsToolStripMenuItem, 
					 this->optionsToolStripMenuItem, this->toolStripMenuItem1, this->settingsToolStripMenuItem});
				 this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
				 this->viewToolStripMenuItem->Size = System::Drawing::Size(44, 20);
				 this->viewToolStripMenuItem->Text = L"View";
				 // 
				 // toolsToolStripMenuItem
				 // 
				 this->toolsToolStripMenuItem->Checked = true;
				 this->toolsToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
				 this->toolsToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
					 | System::Windows::Forms::Keys::T));
				 this->toolsToolStripMenuItem->Size = System::Drawing::Size(214, 22);
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
				 this->optionsToolStripMenuItem->Size = System::Drawing::Size(214, 22);
				 this->optionsToolStripMenuItem->Text = L"Options Panel";
				 this->optionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::classesToolStripMenuItem_Click);
				 // 
				 // toolStripMenuItem1
				 // 
				 this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
				 this->toolStripMenuItem1->Size = System::Drawing::Size(211, 6);
				 // 
				 // settingsToolStripMenuItem
				 // 
				 this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
				 this->settingsToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
					 | System::Windows::Forms::Keys::S));
				 this->settingsToolStripMenuItem->Size = System::Drawing::Size(214, 22);
				 this->settingsToolStripMenuItem->Text = L"Settings";
				 this->settingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::settingsToolStripMenuItem_Click);
				 // 
				 // toolsToolStripMenuItem1
				 // 
				 this->toolsToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(13) {this->reorderToolStripMenuItem, 
					 this->dimensionShiftingToolStripMenuItem, this->toolStripMenuItem6, this->ascendSortToolStripMenuItem, this->descendSortToolStripMenuItem, 
					 this->sortOriginalToolStripMenuItem, this->toolStripMenuItem2, this->hypercubeToolStripMenuItem, this->resetHypercubeToolStripMenuItem, 
					 this->toolStripMenuItem5, this->meanLevelToolStripMenuItem, this->medianLevelToolStripMenuItem, this->originalDataToolStripMenuItem});
				 this->toolsToolStripMenuItem1->Name = L"toolsToolStripMenuItem1";
				 this->toolsToolStripMenuItem1->Size = System::Drawing::Size(47, 20);
				 this->toolsToolStripMenuItem1->Text = L"Tools";
				 // 
				 // reorderToolStripMenuItem
				 // 
				 this->reorderToolStripMenuItem->Name = L"reorderToolStripMenuItem";
				 this->reorderToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
					 | System::Windows::Forms::Keys::Z));
				 this->reorderToolStripMenuItem->Size = System::Drawing::Size(225, 22);
				 this->reorderToolStripMenuItem->Text = L"Manual Sort";
				 this->reorderToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::reorderToolStripMenuItem_Click);
				 // 
				 // dimensionShiftingToolStripMenuItem
				 // 
				 this->dimensionShiftingToolStripMenuItem->Name = L"dimensionShiftingToolStripMenuItem";
				 this->dimensionShiftingToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
					 | System::Windows::Forms::Keys::X));
				 this->dimensionShiftingToolStripMenuItem->Size = System::Drawing::Size(225, 22);
				 this->dimensionShiftingToolStripMenuItem->Text = L"Manual Shift";
				 this->dimensionShiftingToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::dimensionShiftingToolStripMenuItem_Click);
				 // 
				 // toolStripMenuItem6
				 // 
				 this->toolStripMenuItem6->Name = L"toolStripMenuItem6";
				 this->toolStripMenuItem6->Size = System::Drawing::Size(222, 6);
				 // 
				 // ascendSortToolStripMenuItem
				 // 
				 this->ascendSortToolStripMenuItem->Name = L"ascendSortToolStripMenuItem";
				 this->ascendSortToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
					 | System::Windows::Forms::Keys::A));
				 this->ascendSortToolStripMenuItem->Size = System::Drawing::Size(225, 22);
				 this->ascendSortToolStripMenuItem->Text = L"Sort Ascending";
				 this->ascendSortToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::sortingToolStripMenuItem_Click);
				 // 
				 // descendSortToolStripMenuItem
				 // 
				 this->descendSortToolStripMenuItem->Name = L"descendSortToolStripMenuItem";
				 this->descendSortToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
					 | System::Windows::Forms::Keys::D));
				 this->descendSortToolStripMenuItem->Size = System::Drawing::Size(225, 22);
				 this->descendSortToolStripMenuItem->Text = L"Sort Descending";
				 this->descendSortToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::descendSortToolStripMenuItem_Click);
				 // 
				 // sortOriginalToolStripMenuItem
				 // 
				 this->sortOriginalToolStripMenuItem->Name = L"sortOriginalToolStripMenuItem";
				 this->sortOriginalToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
					 | System::Windows::Forms::Keys::R));
				 this->sortOriginalToolStripMenuItem->Size = System::Drawing::Size(225, 22);
				 this->sortOriginalToolStripMenuItem->Text = L"Reset Sort";
				 this->sortOriginalToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::sortOriginalToolStripMenuItem_Click);
				 // 
				 // toolStripMenuItem2
				 // 
				 this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
				 this->toolStripMenuItem2->Size = System::Drawing::Size(222, 6);
				 // 
				 // hypercubeToolStripMenuItem
				 // 
				 this->hypercubeToolStripMenuItem->Name = L"hypercubeToolStripMenuItem";
				 this->hypercubeToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
					 | System::Windows::Forms::Keys::H));
				 this->hypercubeToolStripMenuItem->Size = System::Drawing::Size(225, 22);
				 this->hypercubeToolStripMenuItem->Text = L"Hypercube";
				 this->hypercubeToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::hypercubeToolStripMenuItem_Click);
				 // 
				 // resetHypercubeToolStripMenuItem
				 // 
				 this->resetHypercubeToolStripMenuItem->Name = L"resetHypercubeToolStripMenuItem";
				 this->resetHypercubeToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
					 | System::Windows::Forms::Keys::C));
				 this->resetHypercubeToolStripMenuItem->Size = System::Drawing::Size(225, 22);
				 this->resetHypercubeToolStripMenuItem->Text = L"Toggle Cluster";
				 this->resetHypercubeToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::resetHypercubeToolStripMenuItem_Click);
				 // 
				 // toolStripMenuItem5
				 // 
				 this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
				 this->toolStripMenuItem5->Size = System::Drawing::Size(222, 6);
				 // 
				 // meanLevelToolStripMenuItem
				 // 
				 this->meanLevelToolStripMenuItem->Name = L"meanLevelToolStripMenuItem";
				 this->meanLevelToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
					 | System::Windows::Forms::Keys::N));
				 this->meanLevelToolStripMenuItem->Size = System::Drawing::Size(225, 22);
				 this->meanLevelToolStripMenuItem->Text = L"Mean Level";
				 this->meanLevelToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::meanLevelToolStripMenuItem_Click);
				 // 
				 // medianLevelToolStripMenuItem
				 // 
				 this->medianLevelToolStripMenuItem->Name = L"medianLevelToolStripMenuItem";
				 this->medianLevelToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
					 | System::Windows::Forms::Keys::M));
				 this->medianLevelToolStripMenuItem->Size = System::Drawing::Size(225, 22);
				 this->medianLevelToolStripMenuItem->Text = L"Median Level";
				 this->medianLevelToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::medianLevelToolStripMenuItem_Click);
				 // 
				 // originalDataToolStripMenuItem
				 // 
				 this->originalDataToolStripMenuItem->Name = L"originalDataToolStripMenuItem";
				 this->originalDataToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
					 | System::Windows::Forms::Keys::L));
				 this->originalDataToolStripMenuItem->Size = System::Drawing::Size(225, 22);
				 this->originalDataToolStripMenuItem->Text = L"Reset Level";
				 this->originalDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::originalDataToolStripMenuItem_Click);
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
				 this->helpToolStripMenuItem1->Click += gcnew System::EventHandler(this, &VisCanvas::helpToolStripMenuItem1_Click);
				 // 
				 // Tools
				 // 
				 this->Tools->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				 this->Tools->Controls->Add(this->button2);
				 this->Tools->Controls->Add(this->origData);
				 this->Tools->Controls->Add(this->nColorBoxControl1);
				 this->Tools->Controls->Add(this->sortAscend);
				 this->Tools->Controls->Add(this->hypercube);
				 this->Tools->Controls->Add(this->medianLevel);
				 this->Tools->Controls->Add(this->label4);
				 this->Tools->Controls->Add(this->manualShift);
				 this->Tools->Controls->Add(this->meanLevel);
				 this->Tools->Controls->Add(this->sortDescend);
				 this->Tools->Controls->Add(this->manualSort);
				 this->Tools->Controls->Add(this->sortOrig);
				 this->Tools->Dock = System::Windows::Forms::DockStyle::Left;
				 this->Tools->Location = System::Drawing::Point(0, 24);
				 this->Tools->Name = L"Tools";
				 this->Tools->Size = System::Drawing::Size(72, 643);
				 this->Tools->TabIndex = 2;
				 // 
				 // button2
				 // 
				 this->button2->BackColor = System::Drawing::SystemColors::ButtonFace;
				 this->button2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button2.Image")));
				 this->button2->Location = System::Drawing::Point(14, 377);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(45, 45);
				 this->button2->TabIndex = 24;
				 this->button2->UseVisualStyleBackColor = false;
				 this->button2->Click += gcnew System::EventHandler(this, &VisCanvas::button2_Click);
				 // 
				 // origData
				 // 
				 this->origData->BackColor = System::Drawing::SystemColors::ButtonFace;
				 this->origData->Font = (gcnew System::Drawing::Font(L"Eras Demi ITC", 9));
				 this->origData->Location = System::Drawing::Point(5, 540);
				 this->origData->Name = L"origData";
				 this->origData->Size = System::Drawing::Size(62, 40);
				 this->origData->TabIndex = 23;
				 this->origData->Text = L"Reset";
				 this->origData->UseVisualStyleBackColor = false;
				 this->origData->Click += gcnew System::EventHandler(this, &VisCanvas::button9_Click);
				 // 
				 // nColorBoxControl1
				 // 
				 this->nColorBoxControl1->AutoSize = false;
				 this->nColorBoxControl1->DesignTimeState = resources->GetString(L"nColorBoxControl1.DesignTimeState");
				 this->nColorBoxControl1->Location = System::Drawing::Point(5, 593);
				 this->nColorBoxControl1->Name = L"nColorBoxControl1";
				 this->nColorBoxControl1->Size = System::Drawing::Size(62, 40);
				 this->nColorBoxControl1->TabIndex = 13;
				 this->nColorBoxControl1->SelectedColorChanged += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NValueChangeEventArgs^ >(this, &VisCanvas::nColorBoxControl1_SelectedColorChanged);
				 // 
				 // sortAscend
				 // 
				 this->sortAscend->BackColor = System::Drawing::SystemColors::ButtonFace;
				 this->sortAscend->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"sortAscend.Image")));
				 this->sortAscend->Location = System::Drawing::Point(14, 150);
				 this->sortAscend->Name = L"sortAscend";
				 this->sortAscend->Size = System::Drawing::Size(45, 45);
				 this->sortAscend->TabIndex = 19;
				 this->sortAscend->UseVisualStyleBackColor = false;
				 this->sortAscend->Click += gcnew System::EventHandler(this, &VisCanvas::button3_Click);
				 // 
				 // hypercube
				 // 
				 this->hypercube->BackColor = System::Drawing::SystemColors::ButtonFace;
				 this->hypercube->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"hypercube.Image")));
				 this->hypercube->Location = System::Drawing::Point(14, 320);
				 this->hypercube->Name = L"hypercube";
				 this->hypercube->Size = System::Drawing::Size(45, 45);
				 this->hypercube->TabIndex = 20;
				 this->hypercube->UseVisualStyleBackColor = false;
				 this->hypercube->Click += gcnew System::EventHandler(this, &VisCanvas::button6_Click);
				 // 
				 // medianLevel
				 // 
				 this->medianLevel->BackColor = System::Drawing::SystemColors::ButtonFace;
				 this->medianLevel->Font = (gcnew System::Drawing::Font(L"Eras Demi ITC", 9));
				 this->medianLevel->Location = System::Drawing::Point(5, 487);
				 this->medianLevel->Name = L"medianLevel";
				 this->medianLevel->Size = System::Drawing::Size(62, 40);
				 this->medianLevel->TabIndex = 22;
				 this->medianLevel->Text = L"Median";
				 this->medianLevel->UseVisualStyleBackColor = false;
				 this->medianLevel->Click += gcnew System::EventHandler(this, &VisCanvas::button8_Click);
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
				 this->label4->Location = System::Drawing::Point(55, 2);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(14, 17);
				 this->label4->TabIndex = 7;
				 this->label4->Text = L"x";
				 this->label4->Click += gcnew System::EventHandler(this, &VisCanvas::label4_Click);
				 this->label4->MouseLeave += gcnew System::EventHandler(this, &VisCanvas::leavingToolBoxHoverColor1);
				 this->label4->MouseHover += gcnew System::EventHandler(this, &VisCanvas::toolBoxExitHoverColor1);
				 // 
				 // manualShift
				 // 
				 this->manualShift->BackColor = System::Drawing::SystemColors::ButtonFace;
				 this->manualShift->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"manualShift.Image")));
				 this->manualShift->Location = System::Drawing::Point(14, 94);
				 this->manualShift->Name = L"manualShift";
				 this->manualShift->Size = System::Drawing::Size(45, 45);
				 this->manualShift->TabIndex = 18;
				 this->manualShift->UseVisualStyleBackColor = false;
				 this->manualShift->Click += gcnew System::EventHandler(this, &VisCanvas::manualShift_Click);
				 // 
				 // meanLevel
				 // 
				 this->meanLevel->BackColor = System::Drawing::SystemColors::ButtonFace;
				 this->meanLevel->Font = (gcnew System::Drawing::Font(L"Eras Demi ITC", 9));
				 this->meanLevel->Location = System::Drawing::Point(5, 434);
				 this->meanLevel->Name = L"meanLevel";
				 this->meanLevel->Size = System::Drawing::Size(62, 40);
				 this->meanLevel->TabIndex = 21;
				 this->meanLevel->Text = L"Mean";
				 this->meanLevel->UseVisualStyleBackColor = false;
				 this->meanLevel->Click += gcnew System::EventHandler(this, &VisCanvas::button7_Click);
				 // 
				 // sortDescend
				 // 
				 this->sortDescend->BackColor = System::Drawing::SystemColors::ButtonFace;
				 this->sortDescend->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"sortDescend.Image")));
				 this->sortDescend->Location = System::Drawing::Point(14, 206);
				 this->sortDescend->Name = L"sortDescend";
				 this->sortDescend->Size = System::Drawing::Size(45, 45);
				 this->sortDescend->TabIndex = 5;
				 this->sortDescend->UseVisualStyleBackColor = false;
				 this->sortDescend->Click += gcnew System::EventHandler(this, &VisCanvas::button4_Click);
				 // 
				 // manualSort
				 // 
				 this->manualSort->BackColor = System::Drawing::SystemColors::ButtonFace;
				 this->manualSort->FlatAppearance->BorderColor = System::Drawing::Color::White;
				 this->manualSort->FlatAppearance->BorderSize = 2;
				 this->manualSort->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->manualSort->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"manualSort.Image")));
				 this->manualSort->Location = System::Drawing::Point(14, 38);
				 this->manualSort->Name = L"manualSort";
				 this->manualSort->Size = System::Drawing::Size(45, 45);
				 this->manualSort->TabIndex = 4;
				 this->manualSort->UseVisualStyleBackColor = false;
				 this->manualSort->Click += gcnew System::EventHandler(this, &VisCanvas::button1_Click);
				 // 
				 // sortOrig
				 // 
				 this->sortOrig->BackColor = System::Drawing::SystemColors::ButtonFace;
				 this->sortOrig->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"sortOrig.Image")));
				 this->sortOrig->Location = System::Drawing::Point(14, 263);
				 this->sortOrig->Name = L"sortOrig";
				 this->sortOrig->Size = System::Drawing::Size(45, 45);
				 this->sortOrig->TabIndex = 5;
				 this->sortOrig->UseVisualStyleBackColor = false;
				 this->sortOrig->Click += gcnew System::EventHandler(this, &VisCanvas::button5_Click);
				 // 
				 // Options
				 // 
				 this->Options->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				 this->Options->BackColor = System::Drawing::SystemColors::Control;
				 this->Options->Controls->Add(this->panel1);
				 this->Options->Controls->Add(this->linkLabel1);
				 this->Options->Controls->Add(this->dataGridView1);
				 this->Options->Controls->Add(this->comboBox1);
				 this->Options->Controls->Add(this->nHsbColorPickerControl1);
				 this->Options->Controls->Add(this->label5);
				 this->Options->Dock = System::Windows::Forms::DockStyle::Right;
				 this->Options->Location = System::Drawing::Point(1048, 24);
				 this->Options->Name = L"Options";
				 this->Options->Size = System::Drawing::Size(136, 643);
				 this->Options->TabIndex = 3;
				 this->Options->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &VisCanvas::Classes_Paint);
				 // 
				 // panel1
				 // 
				 this->panel1->BackColor = System::Drawing::Color::Black;
				 this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
				 this->panel1->Location = System::Drawing::Point(7, 362);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(122, 29);
				 this->panel1->TabIndex = 37;
				 // 
				 // linkLabel1
				 // 
				 this->linkLabel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
				 this->linkLabel1->AutoSize = true;
				 this->linkLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->linkLabel1->Location = System::Drawing::Point(7, 621);
				 this->linkLabel1->Name = L"linkLabel1";
				 this->linkLabel1->Size = System::Drawing::Size(121, 16);
				 this->linkLabel1->TabIndex = 21;
				 this->linkLabel1->TabStop = true;
				 this->linkLabel1->Text = L"Advanced Settings";
				 this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &VisCanvas::linkLabel1_LinkClicked);
				 // 
				 // dataGridView1
				 // 
				 this->dataGridView1->AllowUserToAddRows = false;
				 this->dataGridView1->AllowUserToDeleteRows = false;
				 this->dataGridView1->AllowUserToResizeColumns = false;
				 this->dataGridView1->AllowUserToResizeRows = false;
				 this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->Column1, 
					 this->Column2});
				 dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
				 dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
				 dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
				 dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Window;
				 dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::ControlText;
				 dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
				 this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle1;
				 this->dataGridView1->Location = System::Drawing::Point(7, 38);
				 this->dataGridView1->MultiSelect = false;
				 this->dataGridView1->Name = L"dataGridView1";
				 this->dataGridView1->ReadOnly = true;
				 dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
				 dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
				 dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
				 dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::Transparent;
				 dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
				 dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
				 this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
				 this->dataGridView1->RowHeadersVisible = false;
				 this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
				 this->dataGridView1->RowTemplate->ReadOnly = true;
				 this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
				 this->dataGridView1->ShowEditingIcon = false;
				 this->dataGridView1->Size = System::Drawing::Size(122, 150);
				 this->dataGridView1->TabIndex = 20;
				 this->dataGridView1->CellStateChanged += gcnew System::Windows::Forms::DataGridViewCellStateChangedEventHandler(this, &VisCanvas::grid_CellStateChanged);
				 // 
				 // Column1
				 // 
				 this->Column1->Frozen = true;
				 this->Column1->HeaderText = L"Class";
				 this->Column1->MinimumWidth = 45;
				 this->Column1->Name = L"Column1";
				 this->Column1->ReadOnly = true;
				 this->Column1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
				 this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
				 this->Column1->Width = 60;
				 // 
				 // Column2
				 // 
				 this->Column2->Frozen = true;
				 this->Column2->HeaderText = L"Color";
				 this->Column2->MinimumWidth = 30;
				 this->Column2->Name = L"Column2";
				 this->Column2->ReadOnly = true;
				 this->Column2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
				 this->Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
				 this->Column2->Width = 60;
				 // 
				 // comboBox1
				 // 
				 this->comboBox1->FormattingEnabled = true;
				 this->comboBox1->Location = System::Drawing::Point(7, 214);
				 this->comboBox1->Name = L"comboBox1";
				 this->comboBox1->Size = System::Drawing::Size(122, 21);
				 this->comboBox1->TabIndex = 18;
				 this->comboBox1->Text = L"select class...";
				 // 
				 // nHsbColorPickerControl1
				 // 
				 this->nHsbColorPickerControl1->AutoSize = false;
				 this->nHsbColorPickerControl1->DesignTimeState = nullptr;
				 this->nHsbColorPickerControl1->Location = System::Drawing::Point(7, 258);
				 this->nHsbColorPickerControl1->Name = L"nHsbColorPickerControl1";
				 this->nHsbColorPickerControl1->Size = System::Drawing::Size(122, 102);
				 this->nHsbColorPickerControl1->TabIndex = 17;
				 this->nHsbColorPickerControl1->SelectedColorChanged += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NValueChangeEventArgs^ >(this, &VisCanvas::nHsbColorPickerControl1_SelectedColorChanged);
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
				 this->label5->Location = System::Drawing::Point(119, 2);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(14, 17);
				 this->label5->TabIndex = 16;
				 this->label5->Text = L"x";
				 this->label5->Click += gcnew System::EventHandler(this, &VisCanvas::label5_Click);
				 this->label5->MouseLeave += gcnew System::EventHandler(this, &VisCanvas::label5_MouseLeave);
				 this->label5->MouseHover += gcnew System::EventHandler(this, &VisCanvas::label5_MouseHover);
				 // 
				 // nSliderControl1
				 // 
				 this->nSliderControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
				 this->nSliderControl1->AutoSize = false;
				 this->nSliderControl1->DesignTimeState = resources->GetString(L"nSliderControl1.DesignTimeState");
				 this->nSliderControl1->Location = System::Drawing::Point(1026, 668);
				 this->nSliderControl1->Name = L"nSliderControl1";
				 this->nSliderControl1->Size = System::Drawing::Size(146, 21);
				 this->nSliderControl1->TabIndex = 4;
				 this->nSliderControl1->ValueChanged += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NValueChangeEventArgs^ >(this, &VisCanvas::SliderValue_Changed);
				 // 
				 // label1
				 // 
				 this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
				 this->label1->AutoSize = true;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F));
				 this->label1->Location = System::Drawing::Point(990, 671);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(25, 15);
				 this->label1->TabIndex = 5;
				 this->label1->Text = L"0%";
				 // 
				 // toolStripMenuItem3
				 // 
				 this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
				 this->toolStripMenuItem3->Size = System::Drawing::Size(149, 6);
				 // 
				 // optionsToolStripMenuItem1
				 // 
				 this->optionsToolStripMenuItem1->Name = L"optionsToolStripMenuItem1";
				 this->optionsToolStripMenuItem1->Size = System::Drawing::Size(152, 22);
				 this->optionsToolStripMenuItem1->Text = L"Options";
				 this->optionsToolStripMenuItem1->Click += gcnew System::EventHandler(this, &VisCanvas::optionsToolStripMenuItem1_Click);
				 // 
				 // VisCanvas
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
				 this->BackColor = System::Drawing::SystemColors::ButtonFace;
				 this->ClientSize = System::Drawing::Size(1184, 689);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->nSliderControl1);
				 this->Controls->Add(this->Options);
				 this->Controls->Add(this->Tools);
				 this->Controls->Add(this->statusStrip1);
				 this->Controls->Add(this->menubar);
				 this->DoubleBuffered = true;
				 this->MainMenuStrip = this->menubar;
				 this->MinimumSize = System::Drawing::Size(640, 480);
				 this->Name = L"VisCanvas";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"VisCanvas";
				 this->Load += gcnew System::EventHandler(this, &VisCanvas::VisCanvas_Load);
				 this->Resize += gcnew System::EventHandler(this, &VisCanvas::ResizeMe);
				 this->menubar->ResumeLayout(false);
				 this->menubar->PerformLayout();
				 this->Tools->ResumeLayout(false);
				 this->Tools->PerformLayout();
				 this->Options->ResumeLayout(false);
				 this->Options->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion


	public: int previousClassAmount;

			/* PAINTS TO THE VIEWING WINDOW EVERY 10 SECONDS */
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);

				 if (OpenGL->appliedClassChanges() || this->previousClassAmount != 0 && OpenGL->getClassAmount() > this->previousClassAmount || OpenGL->getClassAmount() < this->previousClassAmount) {
					 this->loadClassKey();
					 this->loadClass();
					 this->comboBox1->SelectedIndex = -1;
					 this->comboBox1->Text = "select class...";
					 this->previousClassAmount = OpenGL->getClassAmount();
					 OpenGL->setAppliedClassChanges(false);
				 }

				 adjustPanels();

				 // display our OpenGL to the Parent Form
				 try {
					 OpenGL->Render();	
					 OpenGL->SwapOpenGLBuffers();	
				 } catch (...) {
					 // display an error message
					 ::DialogResult result = MessageBox::Show("WARNING: VisCanvas is unable to open the file. Click 'Retry' to try again.", "Trouble Opening File", MessageBoxButtons::RetryCancel, MessageBoxIcon::Warning);
					 if (result == ::DialogResult::Retry)
					 {
						 this->openFile(); // reopen the file dialog
					 }
					 if (result == ::DialogResult::Cancel)
					 {
						 // don't proceed to the file dialog
					 } 
				 }
			 }

			 /* THIS WILL RESIZE THE SCREEN */
	private: System::Void ResizeMe(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);

				 adjustPanels();
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

			 /* NOT USING ANYMORE */
	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
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


	private: System::Void nHsbColorPickerControl1_SelectedColorChanged(Nevron::Nov::Dom::NValueChangeEventArgs^  arg) {
				 Nevron::Nov::Graphics::NColor selectedColor = (Nevron::Nov::Graphics::NColor)arg->NewValue;
				 int r = selectedColor.R;
				 int g = selectedColor.G;
				 int b = selectedColor.B;
				 this->setColorBox(r, g, b);

				 if (this->comboBox1->SelectedIndex > -1) {
					 std::vector<double> *color = new std::vector<double>(4);
					 (*color)[0] = r / 255.0;
					 (*color)[1] = g / 255.0;
					 (*color)[2] = b / 255.0;
					 (*color)[3] = 255.0;
					 OpenGL->setClassColor(this->comboBox1->SelectedIndex, color);

					 this->dataGridView1->Rows[this->comboBox1->SelectedIndex]->Cells[1]->Style->BackColor = System::Drawing::Color::FromArgb((int)255, (int)r, (int)g, (int)b);
					 this->dataGridView1->Rows[this->comboBox1->SelectedIndex]->Cells[1]->Style->ForeColor = System::Drawing::SystemColors::Window;

					 delete color;
				 }
			 }



			 /* Exits the program */
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 this->Close();
			 }

			 /* Sort ascending (menu item) */
	private: System::Void sortingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->ascendingSort();
			 }
			 /* Sort descending (menu item) */
	private: System::Void descendSortToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->descendingSort();
			 }
			 /* Sort original (menu item) */
	private: System::Void sortOriginalToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->originalSort();
			 }
			 /* Mean level (menu item) */
	private: System::Void meanLevelToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->mean();
			 }
			 /* Median level (menu item) */
	private: System::Void medianLevelToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->median();
			 }
			 /* Original data (menu item) */
	private: System::Void originalDataToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->originalData();
			 }
			 /* Background color */
	private: System::Void nColorBoxControl1_SelectedColorChanged(Nevron::Nov::Dom::NValueChangeEventArgs^  arg) {
				 Nevron::Nov::Graphics::NColor selectedColor = (Nevron::Nov::Graphics::NColor)arg->NewValue;
				 int r = selectedColor.R;
				 int g = selectedColor.G;
				 int b = selectedColor.B;
				 OpenGL->Background(r, g, b);
			 }

			 /* Show the settings dialog */
	private: System::Void settingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 Settings^ settingsWindow = gcnew Settings(OpenGL);
				 //settingsWindow->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
				 settingsWindow->ShowDialog();
			 }

	private: System::Void hypercubeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->hypercube();
			 }

	public: bool sortToggleState; // create the toggled state
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);

				 this->sortToggle();


			 }
			 /* Sort Ascending */
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->ascendingSort();
			 }
			 /* Sort Descending */
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->descendingSort();
			 }
			 /* Sort Original */
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->originalSort();
			 }
			 /* Hypercube Analysis */
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->hypercube();
			 }
			 /* Mean Level */
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->mean();
			 }
			 /* Median Level */
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->median();
			 }
			 /* Reset to original data */
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->originalData();
			 }
			 /* Capture event when the form loads */
	private: System::Void VisCanvas_Load(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);

				 System::Windows::Forms::Cursor::Current = System::Windows::Forms::Cursors::Default;

				 System::Windows::Forms::ToolTip^ toolTip = gcnew System::Windows::Forms::ToolTip;
				 // Set up the delays for the ToolTip.
				 toolTip->AutoPopDelay = 5000;
				 toolTip->InitialDelay = 1000;
				 toolTip->ReshowDelay = 500;
				 // Force the ToolTip text to be displayed whether or not the form is active.
				 toolTip->ShowAlways = true;

				 // Set up the ToolTip text for the Button and Checkbox.
				 toolTip->SetToolTip(this->label4, "hide (ctrl+alt+t)");
				 toolTip->SetToolTip(this->label5, "hide (ctrl+alt+o)");
				 toolTip->SetToolTip(this->sortAscend, "Sort Ascending (ctrl+alt+a)");
				 toolTip->SetToolTip(this->sortDescend, "Sort Descending (ctrl+alt+d)");
				 toolTip->SetToolTip(this->sortOrig, "Reset Sorted Data (ctrl+alt+s)");
				 toolTip->SetToolTip(this->hypercube, "Hypercube Analysis (ctrl+alt+h)");
				 toolTip->SetToolTip(this->meanLevel, "Mean Level (ctrl+alt+n)");
				 toolTip->SetToolTip(this->medianLevel, "Median Level (ctrl+alt+m)");
				 toolTip->SetToolTip(this->origData, "Reset Leveled Data (ctrl+alt+l)");
				 toolTip->SetToolTip(this->manualSort, "Manually Sort Dimensions (ctrl+alt+z)");
				 toolTip->SetToolTip(this->manualShift, "Manually Shift Dimensions (ctrl+alt+x)");
				 toolTip->SetToolTip(this->button2, "Toggle Cluster (ctrl+alt+r)");

			 }

	protected:

		/* HOTKEYS: GET THE KEY COMBINATION AND THEN WE'LL SEND A MESSAGE TO THE OTHER CLASS */
		virtual bool ProcessCmdKey(Message% msg, Keys keyData) override {

			UNREFERENCED_PARAMETER(msg);

			// Open File Dialog
			if (keyData == (Keys::Control | Keys::O)) {
				this->openFile();				 
			}
			// Save File Dialog
			if (keyData == (Keys::Control | Keys::S)) {
				this->saveFile();
			}
			// Tools Panel
			if (keyData == (Keys::Control | Keys::Alt | Keys::T)) {
				this->toolPanel();				
			}
			// Options Panel
			if  (keyData == (Keys::Control | Keys::Alt | Keys::O)) {
				this->optionPanel();
			}		
			if (keyData == (Keys::W) || keyData == (Keys::Up))
			{
				OpenGL->incrementSelectedSet();
			}
			if (keyData == (Keys::S) || keyData == (Keys::Down))
			{
				OpenGL->decrementSelectedSet();
			}

			// button hotkeys
			if (keyData == (Keys::Control | Keys::Alt | Keys::H))
			{
				OpenGL->hypercube();
			}
			if (keyData == (Keys::Control | Keys::Alt | Keys::Z))
			{
				this->sortToggle();
			}
			if (keyData == (Keys::Control | Keys::Alt | Keys::X))
			{
				this->shiftToggle();
			}
			if (keyData == (Keys::Control | Keys::Alt | Keys::A))
			{
				OpenGL->ascendingSort();
			}
			if (keyData == (Keys::Control | Keys::Alt | Keys::D))
			{
				OpenGL->descendingSort();
			}
			if (keyData == (Keys::Control | Keys::Alt | Keys::R))
			{
				OpenGL->originalSort();
			}
			if (keyData == (Keys::Control | Keys::Alt | Keys::C))
			{
				OpenGL->toggleClusters();
			}
			if (keyData == (Keys::Control | Keys::Alt | Keys::N))
			{
				OpenGL->median();
			}
			if (keyData == (Keys::Control | Keys::Alt | Keys::M))
			{
				OpenGL->mean();
			}

			if (keyData == (Keys::Control | Keys::Alt | Keys::L))
			{
				OpenGL->originalData();
			}

			if (keyData == (Keys::Control | Keys::Alt | Keys::S))
			{
				Settings^ settingsWindow = gcnew Settings(OpenGL);
				//settingsWindow->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
				settingsWindow->ShowDialog();
			}

			return true;
		}

	private:

		System::Void adjustPanels(System::Void)
		{
			// adjust the canvas area according to the panels being open
			if (this->Tools->Visible && this->Options->Visible) {
				OpenGL->Resize(this->Tools->Width, 0, this->Width - this->Options->Width - this->Tools->Width - 15, this->Height - this->menubar->Height, SWP_NOZORDER | SWP_NOACTIVATE);
			} else if (this->Options->Visible && !this->Tools->Visible) {
				OpenGL->Resize(0, 0, this->Width - this->Options->Width - 15, this->Height - this->menubar->Height, SWP_NOZORDER | SWP_NOACTIVATE);
			} else if (!this->Options->Visible && this->Tools->Visible) {
				OpenGL->Resize(this->Tools->Width, 0, this->Width - (this->Tools->Width + 15), this->Height - this->menubar->Height, SWP_NOZORDER | SWP_NOACTIVATE);
			} else {
				OpenGL->Resize(0, 0, this->Width - this->Tools->Width + 56, this->Height - this->menubar->Height, SWP_NOZORDER | SWP_NOACTIVATE);
			}
		}

		/* Converts from System::String^ to std::string */
		std::string toStandardString(System::String^ str)
		{
			const char* location = (const char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi( str ).ToPointer();
			std::string temp(location);
			/* Clean up the const char* location memory */
			System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)location));
			return temp;
		}

		System::Void openFile(System::Void) {
			// TODO: last used directory method
			OpenFileDialog^ ofd = gcnew OpenFileDialog;
			ofd->InitialDirectory = ""; // NOTE "c:\\" for future reference.
			ofd->Filter = "Text Files (*.csv, *.txt, *.text)|*.csv; *.txt; *.text"; // we can add this later if needed (needs error handling if so) |All Files (*.*)|*.*";
			ofd->FilterIndex = 1;
			ofd->RestoreDirectory = true;

			if(ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				/* Convert System::String^ to a std::string */
				System::String^ path = ofd->FileName;

				std::string FILE_PATH = this->toStandardString(path); // convert to std::string

				/* Pass the FILE_PATH to OpenGL for reading the file */
				bool fileGood = OpenGL->SetFilePath(FILE_PATH);

				if (!fileGood && OpenGL->uploadedFile()) {
					this->comboBox1->Text = "select class..."; // reset the text of the combobox to its original state

					this->loadClassKey(); // load the class key info in the options panel
					this->loadClass(); // load the class info combobox in the options panel

				} else if (fileGood && !(OpenGL->uploadedFile())) {
					this->openFile();
				} else {
					// do nothing
				}


			}

		}


		System::Void saveFile(System::Void)
		{
			SaveFileDialog^ save = gcnew SaveFileDialog;

			save->InitialDirectory = ""; // NOTE "c:\\" for future reference.
			save->Filter = "Text Files (*.csv, *.txt, *.text)|*.csv; *.txt; *.text"; // we can add this later if needed (needs error handling if so) |All Files (*.*)|*.*";
			save->FilterIndex = 1;
			save->RestoreDirectory = true;

			if (save->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				/* Convert System::String^ to a std::string */
				System::String^ path = save->FileName;

				std::string FILE_PATH = this->toStandardString(path); // convert to std::string

				/* Pass the FILE_PATH to OpenGL for reading the file */
				OpenGL->save(&FILE_PATH);
			}

		}

		System::Void toolPanel(System::Void) {
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

		System::Void optionPanel(System::Void) {
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
		// This is for the color palette
		System::Void setColorBox(int r, int g, int b) {
			OpenGL->SetRGB((GLdouble)r, (GLdouble)g, (GLdouble)b);
			/* update the textbox color on RGB update */
			this->panel1->BackColor = System::Drawing::Color::FromArgb(r, g, b);
		}


		System::Void loadClass(System::Void) {
			// clear the list to prevent duplicates on update
			this->comboBox1->Items->Clear();
			this->comboBox1->Items->Clear();
			// Setup of the classes
			cli::array<System::Object^>^ item1 = gcnew cli::array<System::Object^>(OpenGL->getClassAmount());
			for (int i = 0; i < OpenGL->getClassAmount(); i++) {
				System::String^ mString = gcnew System::String((*OpenGL->getClassName(i)).c_str());
				item1[i] = (Object^)mString;
			}	
			this->comboBox1->Items->AddRange( item1 ); // set the combobox for "Class combobox" to the data in item1 
		}

		System::Void sortToggle(System::Void) {
			sortToggleState = (sortToggleState) ? false : true;
			if (!OpenGL->getManualShiftToggle() && sortToggleState) {
				this->reorderToolStripMenuItem->Checked = true;
				this->sortManual();
			} else {
				this->reorderToolStripMenuItem->Checked = false;
				this->sortManual();
			}
		}

		System::Void sortManual(System::Void) {
			if (this->reorderToolStripMenuItem->Checked) {
				this->manualSort->BackColor = System::Drawing::SystemColors::ButtonHighlight;
				OpenGL->setManualSortToggle(true);
				OpenGL->setManualShiftToggle(false);
			} else {
				this->manualSort->BackColor = System::Drawing::SystemColors::ButtonFace;
				OpenGL->setManualSortToggle(false);
				this->reorderToolStripMenuItem->Checked = false;
			}
		}


		System::Void shiftToggle(System::Void) {
			shifToggleState = (shifToggleState) ? false : true;

			if (!OpenGL->getManualSortToggle() && shifToggleState) {
				this->dimensionShiftingToolStripMenuItem->Checked = true;
				this->shiftManual();
			} else {
				this->dimensionShiftingToolStripMenuItem->Checked = false;
				this->shiftManual();
			}
		}

		System::Void shiftManual(System::Void) {
			if (this->dimensionShiftingToolStripMenuItem->Checked) {
				this->manualShift->BackColor = System::Drawing::SystemColors::ButtonHighlight;
				OpenGL->setManualShiftToggle(true);
				OpenGL->setManualSortToggle(false);
			} else {
				this->manualShift->BackColor = System::Drawing::SystemColors::ButtonFace;
				OpenGL->setManualShiftToggle(false);
				this->dimensionShiftingToolStripMenuItem->Checked = false;
			}
		}

		// This will load the class information for the class key
		System::Void loadClassKey(System::Void) {

			// clear the list so that we can add new data if updated
			this->dataGridView1->Rows->Clear();
			this->dataGridView1->Refresh();

			// set the selection color of the second column (color) to be transparent so that there is no blue highlight

			// update the cell information
			for (int i = 0; i < OpenGL->getClassAmount(); i++) {							
				System::String^ mString = gcnew System::String((*OpenGL->getClassName(i)).c_str());
				cli::array<System::String^>^ row = gcnew cli::array<System::String^> { mString };
				this->dataGridView1->Rows->Add(row);		

				// this will get the current color of the class, in this instance the set color
				std::vector<double> *color = OpenGL->getClassColor(i); // add one to skip the yellow selection line

				// get the RGBA values, we have to convert OpenGL color values to standard color values by multiplying 255
				System::Decimal r = (System::Decimal)color->at(0) * 255;
				System::Decimal g = (System::Decimal)color->at(1) * 255;
				System::Decimal b = (System::Decimal)color->at(2) * 255;
				System::Decimal a = 255; // this is set to 255 (opaque) or else the cell will be completely transparent, which we don't want

				this->dataGridView1->Rows[i]->Cells[1]->Style->BackColor = System::Drawing::Color::FromArgb((int)a, (int)r, (int)g, (int)b);
				this->dataGridView1->Rows[i]->Cells[1]->Style->ForeColor = System::Drawing::SystemColors::Window;
			}

			this->previousClassAmount = OpenGL->getClassAmount(); // this will make it so that it will refresh using the timer

		}

	public: bool shifToggleState;
	private: System::Void manualShift_Click(System::Object^  sender, System::EventArgs^  e) {

				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);

				 this->shiftToggle();


			 }

	private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
				 Settings^ settingsWindow = gcnew Settings(OpenGL);
				 //settingsWindow->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
				 settingsWindow->ShowDialog();
			 }
	private: System::Void grid_CellStateChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellStateChangedEventArgs^  e) {

				 // this will disable the cell from being selected
				 if(this->dataGridView1->Rows[e->Cell->RowIndex]->Cells[1]->Selected)
				 {
					 e->Cell->Selected = false;
				 }
			 }
	private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->saveFile();
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 OpenGL->toggleClusters();
			 }
	private: System::Void reorderToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->sortToggle();
			 }
	private: System::Void dimensionShiftingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->shiftToggle();
			 }
	private: System::Void resetHypercubeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 OpenGL->toggleClusters();
			 }
	private: int prevZoom;
	private: System::Void SliderValue_Changed(Nevron::Nov::Dom::NValueChangeEventArgs^  arg) {
				 System::String^ p = arg->NewValue->ToString();
				 std::string s = toStandardString(p);
				 int i = std::atoi(s.c_str());
				 i *= 2;
				 System::String^ percent = i.ToString();
				 this->label1->Text = percent + "%";

				 OpenGL->zoomSet(i);

			 }
	private: System::Void helpToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
				 VisCanvasHelp^ help = gcnew VisCanvasHelp();
				 //help->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
				 help->ShowDialog();
			 }
	private: System::Void optionsToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
				 AdditionalSettings^ option = gcnew AdditionalSettings(OpenGL);
				 //option->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
				 option->ShowDialog();
			 }
	};

}