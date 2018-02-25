#pragma once

#include "OpenGL.h"
#include <cctype>
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
	/// Summary for Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{
	public:
		Settings(COpenGL^ openGL)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			OpenGL = openGL;

			this->SetStyle(::ControlStyles::SupportsTransparentBackColor | ::ControlStyles::UserPaint | ::ControlStyles::AllPaintingInWmPaint | 
				::ControlStyles::OptimizedDoubleBuffer, 
				true);

			this->changedColor = false;
			this->changedClusterColor = false;
			this->classSetSelectedIndexChanged = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected: 

	protected: 




















	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::DataGridView^  dataGridView2;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl7;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl8;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl9;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl4;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl5;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl6;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox5;




	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl3;

	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl2;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: Nevron::Nov::WinFormControls::NHsbColorPickerControl^  nHsbColorPickerControl1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  classComboBox;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage4;






	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl10;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl11;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl12;







	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown5;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown6;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown7;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown8;


	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: Nevron::Nov::WinFormControls::NHsbColorPickerControl^  nHsbColorPickerControl2;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Timer^  timer2;

	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::TabPage^  tabPage5;

	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::ComboBox^  comboBox5;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl13;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl14;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl15;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::TextBox^  textBox3;

	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::CheckedListBox^  checkedListBox1;

			 OpenGLForm::COpenGL ^ OpenGL;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Settings::typeid));
				 this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
				 this->label18 = (gcnew System::Windows::Forms::Label());
				 this->label17 = (gcnew System::Windows::Forms::Label());
				 this->textBox2 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				 this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
				 this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
				 this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->label9 = (gcnew System::Windows::Forms::Label());
				 this->textBox7 = (gcnew System::Windows::Forms::TextBox());
				 this->label10 = (gcnew System::Windows::Forms::Label());
				 this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
				 this->nButtonControl7 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->nButtonControl8 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->nButtonControl9 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
				 this->label11 = (gcnew System::Windows::Forms::Label());
				 this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 this->textBox6 = (gcnew System::Windows::Forms::TextBox());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
				 this->nButtonControl4 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->nButtonControl5 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->nButtonControl6 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
				 this->panel1 = (gcnew System::Windows::Forms::Panel());
				 this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
				 this->label14 = (gcnew System::Windows::Forms::Label());
				 this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
				 this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
				 this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
				 this->label13 = (gcnew System::Windows::Forms::Label());
				 this->label12 = (gcnew System::Windows::Forms::Label());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->textBox5 = (gcnew System::Windows::Forms::TextBox());
				 this->nButtonControl3 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->nButtonControl2 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->nButtonControl1 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->nHsbColorPickerControl1 = (gcnew Nevron::Nov::WinFormControls::NHsbColorPickerControl());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->classComboBox = (gcnew System::Windows::Forms::ComboBox());
				 this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
				 this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
				 this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
				 this->label26 = (gcnew System::Windows::Forms::Label());
				 this->label25 = (gcnew System::Windows::Forms::Label());
				 this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
				 this->nButtonControl13 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->nButtonControl14 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->nButtonControl15 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
				 this->label24 = (gcnew System::Windows::Forms::Label());
				 this->textBox3 = (gcnew System::Windows::Forms::TextBox());
				 this->label16 = (gcnew System::Windows::Forms::Label());
				 this->panel2 = (gcnew System::Windows::Forms::Panel());
				 this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
				 this->label15 = (gcnew System::Windows::Forms::Label());
				 this->numericUpDown6 = (gcnew System::Windows::Forms::NumericUpDown());
				 this->numericUpDown7 = (gcnew System::Windows::Forms::NumericUpDown());
				 this->numericUpDown8 = (gcnew System::Windows::Forms::NumericUpDown());
				 this->label19 = (gcnew System::Windows::Forms::Label());
				 this->label20 = (gcnew System::Windows::Forms::Label());
				 this->label21 = (gcnew System::Windows::Forms::Label());
				 this->nHsbColorPickerControl2 = (gcnew Nevron::Nov::WinFormControls::NHsbColorPickerControl());
				 this->label22 = (gcnew System::Windows::Forms::Label());
				 this->label23 = (gcnew System::Windows::Forms::Label());
				 this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
				 this->nButtonControl10 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->nButtonControl11 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->nButtonControl12 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->tabPage3->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->BeginInit();
				 this->tabPage1->SuspendLayout();
				 this->tabPage2->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
				 this->tabControl1->SuspendLayout();
				 this->tabPage5->SuspendLayout();
				 this->tabPage4->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown5))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown6))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown7))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown8))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // tabPage3
				 // 
				 this->tabPage3->BackColor = System::Drawing::Color::LightGray;
				 this->tabPage3->Controls->Add(this->label18);
				 this->tabPage3->Controls->Add(this->label17);
				 this->tabPage3->Controls->Add(this->textBox2);
				 this->tabPage3->Controls->Add(this->textBox1);
				 this->tabPage3->Controls->Add(this->checkBox1);
				 this->tabPage3->Controls->Add(this->dataGridView2);
				 this->tabPage3->Controls->Add(this->label9);
				 this->tabPage3->Controls->Add(this->textBox7);
				 this->tabPage3->Controls->Add(this->label10);
				 this->tabPage3->Controls->Add(this->comboBox3);
				 this->tabPage3->Controls->Add(this->nButtonControl7);
				 this->tabPage3->Controls->Add(this->nButtonControl8);
				 this->tabPage3->Controls->Add(this->nButtonControl9);
				 this->tabPage3->Location = System::Drawing::Point(4, 22);
				 this->tabPage3->Name = L"tabPage3";
				 this->tabPage3->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage3->Size = System::Drawing::Size(326, 385);
				 this->tabPage3->TabIndex = 3;
				 this->tabPage3->Text = L"Dimension";
				 this->tabPage3->Click += gcnew System::EventHandler(this, &Settings::tabPage3_Click);
				 // 
				 // label18
				 // 
				 this->label18->AutoSize = true;
				 this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label18->Location = System::Drawing::Point(188, 127);
				 this->label18->Name = L"label18";
				 this->label18->Size = System::Drawing::Size(38, 15);
				 this->label18->TabIndex = 44;
				 this->label18->Text = L"Max:";
				 this->label18->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 // 
				 // label17
				 // 
				 this->label17->AutoSize = true;
				 this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label17->Location = System::Drawing::Point(85, 127);
				 this->label17->Name = L"label17";
				 this->label17->Size = System::Drawing::Size(35, 15);
				 this->label17->TabIndex = 43;
				 this->label17->Text = L"Min:";
				 this->label17->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 // 
				 // textBox2
				 // 
				 this->textBox2->Enabled = false;
				 this->textBox2->Location = System::Drawing::Point(191, 145);
				 this->textBox2->Name = L"textBox2";
				 this->textBox2->Size = System::Drawing::Size(74, 20);
				 this->textBox2->TabIndex = 42;
				 this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Settings::textBox2_KeyPress_State);
				 // 
				 // textBox1
				 // 
				 this->textBox1->Enabled = false;
				 this->textBox1->Location = System::Drawing::Point(88, 145);
				 this->textBox1->Name = L"textBox1";
				 this->textBox1->Size = System::Drawing::Size(74, 20);
				 this->textBox1->TabIndex = 41;
				 this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Settings::textBox1_KeyPress_State);
				 // 
				 // checkBox1
				 // 
				 this->checkBox1->AutoSize = true;
				 this->checkBox1->Location = System::Drawing::Point(64, 145);
				 this->checkBox1->Name = L"checkBox1";
				 this->checkBox1->Size = System::Drawing::Size(15, 14);
				 this->checkBox1->TabIndex = 40;
				 this->checkBox1->UseVisualStyleBackColor = true;
				 this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Settings::checkedDimension_State);
				 // 
				 // dataGridView2
				 // 
				 this->dataGridView2->AllowUserToAddRows = false;
				 this->dataGridView2->AllowUserToDeleteRows = false;
				 this->dataGridView2->AllowUserToResizeColumns = false;
				 this->dataGridView2->AllowUserToResizeRows = false;
				 this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) {this->dataGridViewTextBoxColumn1});
				 this->dataGridView2->Location = System::Drawing::Point(64, 181);
				 this->dataGridView2->MultiSelect = false;
				 this->dataGridView2->Name = L"dataGridView2";
				 this->dataGridView2->RowHeadersVisible = false;
				 this->dataGridView2->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
				 this->dataGridView2->Size = System::Drawing::Size(201, 154);
				 this->dataGridView2->TabIndex = 39;
				 this->dataGridView2->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Settings::dataGridView2_CellValueChanged);
				 this->dataGridView2->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &Settings::dataGridView1_EditingControl);
				 this->dataGridView2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Settings::dataGridView2_KeyPressed_State);
				 // 
				 // dataGridViewTextBoxColumn1
				 // 
				 this->dataGridViewTextBoxColumn1->FillWeight = 200;
				 this->dataGridViewTextBoxColumn1->HeaderText = L"Set Data";
				 this->dataGridViewTextBoxColumn1->MinimumWidth = 198;
				 this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
				 this->dataGridViewTextBoxColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
				 this->dataGridViewTextBoxColumn1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
				 this->dataGridViewTextBoxColumn1->Width = 198;
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label9->Location = System::Drawing::Point(60, 77);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(102, 15);
				 this->label9->TabIndex = 38;
				 this->label9->Text = L"Change Name:";
				 this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 // 
				 // textBox7
				 // 
				 this->textBox7->Location = System::Drawing::Point(63, 95);
				 this->textBox7->Name = L"textBox7";
				 this->textBox7->Size = System::Drawing::Size(202, 20);
				 this->textBox7->TabIndex = 37;
				 // 
				 // label10
				 // 
				 this->label10->AutoSize = true;
				 this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label10->Location = System::Drawing::Point(60, 21);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(49, 15);
				 this->label10->TabIndex = 36;
				 this->label10->Text = L"Name:";
				 // 
				 // comboBox3
				 // 
				 this->comboBox3->FormattingEnabled = true;
				 this->comboBox3->ItemHeight = 13;
				 this->comboBox3->Location = System::Drawing::Point(63, 39);
				 this->comboBox3->Name = L"comboBox3";
				 this->comboBox3->Size = System::Drawing::Size(202, 21);
				 this->comboBox3->TabIndex = 35;
				 this->comboBox3->Text = L"select...";
				 this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Settings::comboBox3_SelectedIndexChanged);
				 // 
				 // nButtonControl7
				 // 
				 this->nButtonControl7->AutoSize = false;
				 this->nButtonControl7->DesignTimeState = resources->GetString(L"nButtonControl7.DesignTimeState");
				 this->nButtonControl7->Location = System::Drawing::Point(262, 354);
				 this->nButtonControl7->Name = L"nButtonControl7";
				 this->nButtonControl7->Size = System::Drawing::Size(56, 23);
				 this->nButtonControl7->TabIndex = 26;
				 this->nButtonControl7->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl7_Click);
				 // 
				 // nButtonControl8
				 // 
				 this->nButtonControl8->AutoSize = false;
				 this->nButtonControl8->DesignTimeState = resources->GetString(L"nButtonControl8.DesignTimeState");
				 this->nButtonControl8->Location = System::Drawing::Point(207, 354);
				 this->nButtonControl8->Name = L"nButtonControl8";
				 this->nButtonControl8->Size = System::Drawing::Size(49, 23);
				 this->nButtonControl8->TabIndex = 25;
				 this->nButtonControl8->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl8_Click);
				 // 
				 // nButtonControl9
				 // 
				 this->nButtonControl9->AutoSize = false;
				 this->nButtonControl9->DesignTimeState = resources->GetString(L"nButtonControl9.DesignTimeState");
				 this->nButtonControl9->Location = System::Drawing::Point(154, 354);
				 this->nButtonControl9->Name = L"nButtonControl9";
				 this->nButtonControl9->Size = System::Drawing::Size(45, 23);
				 this->nButtonControl9->TabIndex = 24;
				 this->nButtonControl9->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl9_Click);
				 // 
				 // tabPage1
				 // 
				 this->tabPage1->BackColor = System::Drawing::Color::LightGray;
				 this->tabPage1->Controls->Add(this->label11);
				 this->tabPage1->Controls->Add(this->comboBox1);
				 this->tabPage1->Controls->Add(this->label7);
				 this->tabPage1->Controls->Add(this->textBox6);
				 this->tabPage1->Controls->Add(this->label8);
				 this->tabPage1->Controls->Add(this->comboBox2);
				 this->tabPage1->Controls->Add(this->nButtonControl4);
				 this->tabPage1->Controls->Add(this->nButtonControl5);
				 this->tabPage1->Controls->Add(this->nButtonControl6);
				 this->tabPage1->Location = System::Drawing::Point(4, 22);
				 this->tabPage1->Name = L"tabPage1";
				 this->tabPage1->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage1->Size = System::Drawing::Size(326, 385);
				 this->tabPage1->TabIndex = 2;
				 this->tabPage1->Text = L"Set";
				 // 
				 // label11
				 // 
				 this->label11->AutoSize = true;
				 this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label11->Location = System::Drawing::Point(58, 193);
				 this->label11->Name = L"label11";
				 this->label11->Size = System::Drawing::Size(124, 15);
				 this->label11->TabIndex = 35;
				 this->label11->Text = L"Class Assignment:";
				 this->label11->TextAlign = System::Drawing::ContentAlignment::TopRight;
				 // 
				 // comboBox1
				 // 
				 this->comboBox1->FormattingEnabled = true;
				 this->comboBox1->ItemHeight = 13;
				 this->comboBox1->Location = System::Drawing::Point(61, 211);
				 this->comboBox1->Name = L"comboBox1";
				 this->comboBox1->Size = System::Drawing::Size(202, 21);
				 this->comboBox1->TabIndex = 34;
				 this->comboBox1->Text = L"select...";
				 this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Settings::setClass_SelectedIndex_Change);
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label7->Location = System::Drawing::Point(58, 138);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(102, 15);
				 this->label7->TabIndex = 33;
				 this->label7->Text = L"Change Name:";
				 this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 // 
				 // textBox6
				 // 
				 this->textBox6->Location = System::Drawing::Point(61, 156);
				 this->textBox6->Name = L"textBox6";
				 this->textBox6->Size = System::Drawing::Size(202, 20);
				 this->textBox6->TabIndex = 32;
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label8->Location = System::Drawing::Point(58, 80);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(49, 15);
				 this->label8->TabIndex = 30;
				 this->label8->Text = L"Name:";
				 // 
				 // comboBox2
				 // 
				 this->comboBox2->FormattingEnabled = true;
				 this->comboBox2->ItemHeight = 13;
				 this->comboBox2->Location = System::Drawing::Point(61, 98);
				 this->comboBox2->Name = L"comboBox2";
				 this->comboBox2->Size = System::Drawing::Size(202, 21);
				 this->comboBox2->TabIndex = 29;
				 this->comboBox2->Text = L"select...";
				 this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Settings::setSetIndexChanged_ChangeEvent);
				 // 
				 // nButtonControl4
				 // 
				 this->nButtonControl4->AutoSize = false;
				 this->nButtonControl4->DesignTimeState = resources->GetString(L"nButtonControl4.DesignTimeState");
				 this->nButtonControl4->Location = System::Drawing::Point(262, 354);
				 this->nButtonControl4->Name = L"nButtonControl4";
				 this->nButtonControl4->Size = System::Drawing::Size(56, 23);
				 this->nButtonControl4->TabIndex = 26;
				 this->nButtonControl4->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl4_Click);
				 // 
				 // nButtonControl5
				 // 
				 this->nButtonControl5->AutoSize = false;
				 this->nButtonControl5->DesignTimeState = resources->GetString(L"nButtonControl5.DesignTimeState");
				 this->nButtonControl5->Location = System::Drawing::Point(207, 354);
				 this->nButtonControl5->Name = L"nButtonControl5";
				 this->nButtonControl5->Size = System::Drawing::Size(49, 23);
				 this->nButtonControl5->TabIndex = 25;
				 this->nButtonControl5->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl5_Click);
				 // 
				 // nButtonControl6
				 // 
				 this->nButtonControl6->AutoSize = false;
				 this->nButtonControl6->DesignTimeState = resources->GetString(L"nButtonControl6.DesignTimeState");
				 this->nButtonControl6->Location = System::Drawing::Point(154, 354);
				 this->nButtonControl6->Name = L"nButtonControl6";
				 this->nButtonControl6->Size = System::Drawing::Size(45, 23);
				 this->nButtonControl6->TabIndex = 24;
				 this->nButtonControl6->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl6_Click);
				 // 
				 // tabPage2
				 // 
				 this->tabPage2->BackColor = System::Drawing::Color::LightGray;
				 this->tabPage2->Controls->Add(this->panel1);
				 this->tabPage2->Controls->Add(this->numericUpDown4);
				 this->tabPage2->Controls->Add(this->label14);
				 this->tabPage2->Controls->Add(this->numericUpDown3);
				 this->tabPage2->Controls->Add(this->numericUpDown2);
				 this->tabPage2->Controls->Add(this->numericUpDown1);
				 this->tabPage2->Controls->Add(this->label13);
				 this->tabPage2->Controls->Add(this->label12);
				 this->tabPage2->Controls->Add(this->label6);
				 this->tabPage2->Controls->Add(this->textBox5);
				 this->tabPage2->Controls->Add(this->nButtonControl3);
				 this->tabPage2->Controls->Add(this->nButtonControl2);
				 this->tabPage2->Controls->Add(this->nButtonControl1);
				 this->tabPage2->Controls->Add(this->label5);
				 this->tabPage2->Controls->Add(this->label4);
				 this->tabPage2->Controls->Add(this->label3);
				 this->tabPage2->Controls->Add(this->nHsbColorPickerControl1);
				 this->tabPage2->Controls->Add(this->label2);
				 this->tabPage2->Controls->Add(this->label1);
				 this->tabPage2->Controls->Add(this->classComboBox);
				 this->tabPage2->Location = System::Drawing::Point(4, 22);
				 this->tabPage2->Name = L"tabPage2";
				 this->tabPage2->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage2->Size = System::Drawing::Size(326, 385);
				 this->tabPage2->TabIndex = 1;
				 this->tabPage2->Text = L"Class";
				 // 
				 // panel1
				 // 
				 this->panel1->BackColor = System::Drawing::Color::Black;
				 this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
				 this->panel1->Location = System::Drawing::Point(37, 297);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(187, 29);
				 this->panel1->TabIndex = 36;
				 this->panel1->BackColorChanged += gcnew System::EventHandler(this, &Settings::changePanelColor);
				 // 
				 // numericUpDown4
				 // 
				 this->numericUpDown4->Location = System::Drawing::Point(267, 275);
				 this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
				 this->numericUpDown4->Name = L"numericUpDown4";
				 this->numericUpDown4->Size = System::Drawing::Size(47, 20);
				 this->numericUpDown4->TabIndex = 35;
				 this->numericUpDown4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
				 this->numericUpDown4->ValueChanged += gcnew System::EventHandler(this, &Settings::numericUpDown4_ValueChanged);
				 // 
				 // label14
				 // 
				 this->label14->AutoSize = true;
				 this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
				 this->label14->Location = System::Drawing::Point(242, 276);
				 this->label14->Name = L"label14";
				 this->label14->Size = System::Drawing::Size(17, 15);
				 this->label14->TabIndex = 34;
				 this->label14->Text = L"A:";
				 // 
				 // numericUpDown3
				 // 
				 this->numericUpDown3->Location = System::Drawing::Point(267, 232);
				 this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
				 this->numericUpDown3->Name = L"numericUpDown3";
				 this->numericUpDown3->Size = System::Drawing::Size(47, 20);
				 this->numericUpDown3->TabIndex = 33;
				 this->numericUpDown3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->numericUpDown3->ValueChanged += gcnew System::EventHandler(this, &Settings::numericUpDown3_ValueChanged);
				 // 
				 // numericUpDown2
				 // 
				 this->numericUpDown2->Location = System::Drawing::Point(267, 190);
				 this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
				 this->numericUpDown2->Name = L"numericUpDown2";
				 this->numericUpDown2->Size = System::Drawing::Size(47, 20);
				 this->numericUpDown2->TabIndex = 32;
				 this->numericUpDown2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &Settings::numericUpDown2_ValueChanged);
				 // 
				 // numericUpDown1
				 // 
				 this->numericUpDown1->Location = System::Drawing::Point(267, 148);
				 this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
				 this->numericUpDown1->Name = L"numericUpDown1";
				 this->numericUpDown1->Size = System::Drawing::Size(47, 20);
				 this->numericUpDown1->TabIndex = 31;
				 this->numericUpDown1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &Settings::numericUpDown1_ValueChanged);
				 // 
				 // label13
				 // 
				 this->label13->AutoSize = true;
				 this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.5F, System::Drawing::FontStyle::Bold));
				 this->label13->Location = System::Drawing::Point(248, 39);
				 this->label13->Name = L"label13";
				 this->label13->Size = System::Drawing::Size(20, 20);
				 this->label13->TabIndex = 30;
				 this->label13->Text = L"+";
				 this->label13->Click += gcnew System::EventHandler(this, &Settings::label13_Click);
				 this->label13->MouseLeave += gcnew System::EventHandler(this, &Settings::classAddLeave);
				 this->label13->MouseHover += gcnew System::EventHandler(this, &Settings::classAddHover);
				 // 
				 // label12
				 // 
				 this->label12->AutoSize = true;
				 this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Bold));
				 this->label12->Location = System::Drawing::Point(272, 42);
				 this->label12->Name = L"label12";
				 this->label12->Size = System::Drawing::Size(12, 12);
				 this->label12->TabIndex = 29;
				 this->label12->Text = L"X";
				 this->label12->Click += gcnew System::EventHandler(this, &Settings::label12_Click);
				 this->label12->MouseLeave += gcnew System::EventHandler(this, &Settings::classRemoveLeave);
				 this->label12->MouseHover += gcnew System::EventHandler(this, &Settings::classRemoveHover);
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label6->Location = System::Drawing::Point(34, 76);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(102, 15);
				 this->label6->TabIndex = 28;
				 this->label6->Text = L"Change Name:";
				 this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 // 
				 // textBox5
				 // 
				 this->textBox5->Location = System::Drawing::Point(37, 96);
				 this->textBox5->Name = L"textBox5";
				 this->textBox5->Size = System::Drawing::Size(202, 20);
				 this->textBox5->TabIndex = 27;
				 this->textBox5->TextChanged += gcnew System::EventHandler(this, &Settings::textBox5_TextChanged);
				 // 
				 // nButtonControl3
				 // 
				 this->nButtonControl3->AutoSize = false;
				 this->nButtonControl3->DesignTimeState = resources->GetString(L"nButtonControl3.DesignTimeState");
				 this->nButtonControl3->Location = System::Drawing::Point(262, 354);
				 this->nButtonControl3->Name = L"nButtonControl3";
				 this->nButtonControl3->Size = System::Drawing::Size(56, 23);
				 this->nButtonControl3->TabIndex = 23;
				 this->nButtonControl3->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl3_Click);
				 // 
				 // nButtonControl2
				 // 
				 this->nButtonControl2->AutoSize = false;
				 this->nButtonControl2->DesignTimeState = resources->GetString(L"nButtonControl2.DesignTimeState");
				 this->nButtonControl2->Location = System::Drawing::Point(207, 354);
				 this->nButtonControl2->Name = L"nButtonControl2";
				 this->nButtonControl2->Size = System::Drawing::Size(49, 23);
				 this->nButtonControl2->TabIndex = 21;
				 this->nButtonControl2->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl2_Click);
				 // 
				 // nButtonControl1
				 // 
				 this->nButtonControl1->AutoSize = false;
				 this->nButtonControl1->DesignTimeState = resources->GetString(L"nButtonControl1.DesignTimeState");
				 this->nButtonControl1->Location = System::Drawing::Point(154, 354);
				 this->nButtonControl1->Name = L"nButtonControl1";
				 this->nButtonControl1->Size = System::Drawing::Size(45, 23);
				 this->nButtonControl1->TabIndex = 20;
				 this->nButtonControl1->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl1_Click);
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
				 this->label5->Location = System::Drawing::Point(242, 232);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(18, 15);
				 this->label5->TabIndex = 16;
				 this->label5->Text = L"B:";
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
				 this->label4->Location = System::Drawing::Point(242, 190);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(19, 15);
				 this->label4->TabIndex = 15;
				 this->label4->Text = L"G:";
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
				 this->label3->Location = System::Drawing::Point(242, 149);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(19, 15);
				 this->label3->TabIndex = 14;
				 this->label3->Text = L"R:";
				 // 
				 // nHsbColorPickerControl1
				 // 
				 this->nHsbColorPickerControl1->AutoSize = false;
				 this->nHsbColorPickerControl1->DesignTimeState = nullptr;
				 this->nHsbColorPickerControl1->Location = System::Drawing::Point(37, 148);
				 this->nHsbColorPickerControl1->Name = L"nHsbColorPickerControl1";
				 this->nHsbColorPickerControl1->Size = System::Drawing::Size(187, 147);
				 this->nHsbColorPickerControl1->TabIndex = 3;
				 this->nHsbColorPickerControl1->SelectedColorChanged += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NValueChangeEventArgs^ >(this, &Settings::nHsbColorPickerControl1_SelectedColorChanged);
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label2->Location = System::Drawing::Point(34, 130);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(45, 15);
				 this->label2->TabIndex = 2;
				 this->label2->Text = L"Color:";
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label1->Location = System::Drawing::Point(34, 20);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(49, 15);
				 this->label1->TabIndex = 1;
				 this->label1->Text = L"Name:";
				 // 
				 // classComboBox
				 // 
				 this->classComboBox->FormattingEnabled = true;
				 this->classComboBox->ItemHeight = 13;
				 this->classComboBox->Location = System::Drawing::Point(37, 38);
				 this->classComboBox->Name = L"classComboBox";
				 this->classComboBox->Size = System::Drawing::Size(202, 21);
				 this->classComboBox->TabIndex = 0;
				 this->classComboBox->Text = L"select...";
				 this->classComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Settings::classComboBox_SelectedIndexChanged);
				 // 
				 // tabControl1
				 // 
				 this->tabControl1->Controls->Add(this->tabPage2);
				 this->tabControl1->Controls->Add(this->tabPage5);
				 this->tabControl1->Controls->Add(this->tabPage1);
				 this->tabControl1->Controls->Add(this->tabPage3);
				 this->tabControl1->Controls->Add(this->tabPage4);
				 this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tabControl1->Location = System::Drawing::Point(0, 0);
				 this->tabControl1->Name = L"tabControl1";
				 this->tabControl1->SelectedIndex = 0;
				 this->tabControl1->Size = System::Drawing::Size(334, 411);
				 this->tabControl1->TabIndex = 0;
				 // 
				 // tabPage5
				 // 
				 this->tabPage5->BackColor = System::Drawing::Color::LightGray;
				 this->tabPage5->Controls->Add(this->checkedListBox1);
				 this->tabPage5->Controls->Add(this->label26);
				 this->tabPage5->Controls->Add(this->label25);
				 this->tabPage5->Controls->Add(this->comboBox5);
				 this->tabPage5->Controls->Add(this->nButtonControl13);
				 this->tabPage5->Controls->Add(this->nButtonControl14);
				 this->tabPage5->Controls->Add(this->nButtonControl15);
				 this->tabPage5->Location = System::Drawing::Point(4, 22);
				 this->tabPage5->Name = L"tabPage5";
				 this->tabPage5->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage5->Size = System::Drawing::Size(326, 385);
				 this->tabPage5->TabIndex = 5;
				 this->tabPage5->Text = L"Class Set";
				 // 
				 // checkedListBox1
				 // 
				 this->checkedListBox1->FormattingEnabled = true;
				 this->checkedListBox1->Location = System::Drawing::Point(62, 98);
				 this->checkedListBox1->Name = L"checkedListBox1";
				 this->checkedListBox1->Size = System::Drawing::Size(202, 229);
				 this->checkedListBox1->TabIndex = 50;
				 // 
				 // label26
				 // 
				 this->label26->AutoSize = true;
				 this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label26->Location = System::Drawing::Point(59, 79);
				 this->label26->Name = L"label26";
				 this->label26->Size = System::Drawing::Size(79, 15);
				 this->label26->TabIndex = 48;
				 this->label26->Text = L"Visible Set:";
				 // 
				 // label25
				 // 
				 this->label25->AutoSize = true;
				 this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label25->Location = System::Drawing::Point(59, 20);
				 this->label25->Name = L"label25";
				 this->label25->Size = System::Drawing::Size(49, 15);
				 this->label25->TabIndex = 46;
				 this->label25->Text = L"Name:";
				 // 
				 // comboBox5
				 // 
				 this->comboBox5->FormattingEnabled = true;
				 this->comboBox5->ItemHeight = 13;
				 this->comboBox5->Location = System::Drawing::Point(62, 38);
				 this->comboBox5->Name = L"comboBox5";
				 this->comboBox5->Size = System::Drawing::Size(202, 21);
				 this->comboBox5->TabIndex = 45;
				 this->comboBox5->Text = L"select...";
				 this->comboBox5->SelectedIndexChanged += gcnew System::EventHandler(this, &Settings::classSetSelectedIndex_Changed);
				 // 
				 // nButtonControl13
				 // 
				 this->nButtonControl13->AutoSize = false;
				 this->nButtonControl13->DesignTimeState = resources->GetString(L"nButtonControl13.DesignTimeState");
				 this->nButtonControl13->Location = System::Drawing::Point(262, 354);
				 this->nButtonControl13->Name = L"nButtonControl13";
				 this->nButtonControl13->Size = System::Drawing::Size(56, 23);
				 this->nButtonControl13->TabIndex = 44;
				 this->nButtonControl13->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl13_Click);
				 // 
				 // nButtonControl14
				 // 
				 this->nButtonControl14->AutoSize = false;
				 this->nButtonControl14->DesignTimeState = resources->GetString(L"nButtonControl14.DesignTimeState");
				 this->nButtonControl14->Location = System::Drawing::Point(207, 354);
				 this->nButtonControl14->Name = L"nButtonControl14";
				 this->nButtonControl14->Size = System::Drawing::Size(49, 23);
				 this->nButtonControl14->TabIndex = 43;
				 this->nButtonControl14->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl14_Click);
				 // 
				 // nButtonControl15
				 // 
				 this->nButtonControl15->AutoSize = false;
				 this->nButtonControl15->DesignTimeState = resources->GetString(L"nButtonControl15.DesignTimeState");
				 this->nButtonControl15->Location = System::Drawing::Point(154, 354);
				 this->nButtonControl15->Name = L"nButtonControl15";
				 this->nButtonControl15->Size = System::Drawing::Size(45, 23);
				 this->nButtonControl15->TabIndex = 42;
				 this->nButtonControl15->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl15_Click);
				 // 
				 // tabPage4
				 // 
				 this->tabPage4->BackColor = System::Drawing::Color::LightGray;
				 this->tabPage4->Controls->Add(this->label24);
				 this->tabPage4->Controls->Add(this->textBox3);
				 this->tabPage4->Controls->Add(this->label16);
				 this->tabPage4->Controls->Add(this->panel2);
				 this->tabPage4->Controls->Add(this->numericUpDown5);
				 this->tabPage4->Controls->Add(this->label15);
				 this->tabPage4->Controls->Add(this->numericUpDown6);
				 this->tabPage4->Controls->Add(this->numericUpDown7);
				 this->tabPage4->Controls->Add(this->numericUpDown8);
				 this->tabPage4->Controls->Add(this->label19);
				 this->tabPage4->Controls->Add(this->label20);
				 this->tabPage4->Controls->Add(this->label21);
				 this->tabPage4->Controls->Add(this->nHsbColorPickerControl2);
				 this->tabPage4->Controls->Add(this->label22);
				 this->tabPage4->Controls->Add(this->label23);
				 this->tabPage4->Controls->Add(this->comboBox4);
				 this->tabPage4->Controls->Add(this->nButtonControl10);
				 this->tabPage4->Controls->Add(this->nButtonControl11);
				 this->tabPage4->Controls->Add(this->nButtonControl12);
				 this->tabPage4->Location = System::Drawing::Point(4, 22);
				 this->tabPage4->Name = L"tabPage4";
				 this->tabPage4->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage4->Size = System::Drawing::Size(326, 385);
				 this->tabPage4->TabIndex = 4;
				 this->tabPage4->Text = L"Cluster";
				 this->tabPage4->Click += gcnew System::EventHandler(this, &Settings::tabPage4_Click);
				 // 
				 // label24
				 // 
				 this->label24->AutoSize = true;
				 this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label24->Location = System::Drawing::Point(34, 76);
				 this->label24->Name = L"label24";
				 this->label24->Size = System::Drawing::Size(102, 15);
				 this->label24->TabIndex = 61;
				 this->label24->Text = L"Change Name:";
				 this->label24->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 // 
				 // textBox3
				 // 
				 this->textBox3->Location = System::Drawing::Point(37, 96);
				 this->textBox3->Name = L"textBox3";
				 this->textBox3->Size = System::Drawing::Size(202, 20);
				 this->textBox3->TabIndex = 60;
				 // 
				 // label16
				 // 
				 this->label16->AutoSize = true;
				 this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Bold));
				 this->label16->Location = System::Drawing::Point(253, 43);
				 this->label16->Name = L"label16";
				 this->label16->Size = System::Drawing::Size(12, 12);
				 this->label16->TabIndex = 59;
				 this->label16->Text = L"X";
				 this->label16->Click += gcnew System::EventHandler(this, &Settings::label16_Click);
				 this->label16->MouseLeave += gcnew System::EventHandler(this, &Settings::removeCluster_Leave);
				 this->label16->MouseHover += gcnew System::EventHandler(this, &Settings::removeCluster_Hover);
				 // 
				 // panel2
				 // 
				 this->panel2->BackColor = System::Drawing::Color::Black;
				 this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
				 this->panel2->Location = System::Drawing::Point(37, 297);
				 this->panel2->Name = L"panel2";
				 this->panel2->Size = System::Drawing::Size(187, 29);
				 this->panel2->TabIndex = 58;
				 // 
				 // numericUpDown5
				 // 
				 this->numericUpDown5->Location = System::Drawing::Point(267, 275);
				 this->numericUpDown5->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
				 this->numericUpDown5->Name = L"numericUpDown5";
				 this->numericUpDown5->Size = System::Drawing::Size(47, 20);
				 this->numericUpDown5->TabIndex = 57;
				 this->numericUpDown5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->numericUpDown5->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
				 this->numericUpDown5->ValueChanged += gcnew System::EventHandler(this, &Settings::numericUpDown5_ValueChanged);
				 // 
				 // label15
				 // 
				 this->label15->AutoSize = true;
				 this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
				 this->label15->Location = System::Drawing::Point(242, 276);
				 this->label15->Name = L"label15";
				 this->label15->Size = System::Drawing::Size(17, 15);
				 this->label15->TabIndex = 56;
				 this->label15->Text = L"A:";
				 // 
				 // numericUpDown6
				 // 
				 this->numericUpDown6->Location = System::Drawing::Point(267, 232);
				 this->numericUpDown6->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
				 this->numericUpDown6->Name = L"numericUpDown6";
				 this->numericUpDown6->Size = System::Drawing::Size(47, 20);
				 this->numericUpDown6->TabIndex = 55;
				 this->numericUpDown6->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->numericUpDown6->ValueChanged += gcnew System::EventHandler(this, &Settings::numericUpDown6_ValueChanged);
				 // 
				 // numericUpDown7
				 // 
				 this->numericUpDown7->Location = System::Drawing::Point(267, 190);
				 this->numericUpDown7->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
				 this->numericUpDown7->Name = L"numericUpDown7";
				 this->numericUpDown7->Size = System::Drawing::Size(47, 20);
				 this->numericUpDown7->TabIndex = 54;
				 this->numericUpDown7->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->numericUpDown7->ValueChanged += gcnew System::EventHandler(this, &Settings::numericUpDown7_ValueChanged);
				 // 
				 // numericUpDown8
				 // 
				 this->numericUpDown8->Location = System::Drawing::Point(267, 148);
				 this->numericUpDown8->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
				 this->numericUpDown8->Name = L"numericUpDown8";
				 this->numericUpDown8->Size = System::Drawing::Size(47, 20);
				 this->numericUpDown8->TabIndex = 53;
				 this->numericUpDown8->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->numericUpDown8->ValueChanged += gcnew System::EventHandler(this, &Settings::numericUpDown8_ValueChanged);
				 // 
				 // label19
				 // 
				 this->label19->AutoSize = true;
				 this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
				 this->label19->Location = System::Drawing::Point(242, 232);
				 this->label19->Name = L"label19";
				 this->label19->Size = System::Drawing::Size(18, 15);
				 this->label19->TabIndex = 48;
				 this->label19->Text = L"B:";
				 // 
				 // label20
				 // 
				 this->label20->AutoSize = true;
				 this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
				 this->label20->Location = System::Drawing::Point(242, 190);
				 this->label20->Name = L"label20";
				 this->label20->Size = System::Drawing::Size(19, 15);
				 this->label20->TabIndex = 47;
				 this->label20->Text = L"G:";
				 // 
				 // label21
				 // 
				 this->label21->AutoSize = true;
				 this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
				 this->label21->Location = System::Drawing::Point(242, 149);
				 this->label21->Name = L"label21";
				 this->label21->Size = System::Drawing::Size(19, 15);
				 this->label21->TabIndex = 46;
				 this->label21->Text = L"R:";
				 // 
				 // nHsbColorPickerControl2
				 // 
				 this->nHsbColorPickerControl2->AutoSize = false;
				 this->nHsbColorPickerControl2->DesignTimeState = nullptr;
				 this->nHsbColorPickerControl2->Location = System::Drawing::Point(37, 148);
				 this->nHsbColorPickerControl2->Name = L"nHsbColorPickerControl2";
				 this->nHsbColorPickerControl2->Size = System::Drawing::Size(187, 147);
				 this->nHsbColorPickerControl2->TabIndex = 45;
				 this->nHsbColorPickerControl2->SelectedColorChanged += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NValueChangeEventArgs^ >(this, &Settings::nHsbColorPickerControl2_SelectedColorChanged);
				 // 
				 // label22
				 // 
				 this->label22->AutoSize = true;
				 this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label22->Location = System::Drawing::Point(34, 130);
				 this->label22->Name = L"label22";
				 this->label22->Size = System::Drawing::Size(45, 15);
				 this->label22->TabIndex = 44;
				 this->label22->Text = L"Color:";
				 // 
				 // label23
				 // 
				 this->label23->AutoSize = true;
				 this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label23->Location = System::Drawing::Point(34, 20);
				 this->label23->Name = L"label23";
				 this->label23->Size = System::Drawing::Size(49, 15);
				 this->label23->TabIndex = 43;
				 this->label23->Text = L"Name:";
				 // 
				 // comboBox4
				 // 
				 this->comboBox4->FormattingEnabled = true;
				 this->comboBox4->ItemHeight = 13;
				 this->comboBox4->Location = System::Drawing::Point(37, 38);
				 this->comboBox4->Name = L"comboBox4";
				 this->comboBox4->Size = System::Drawing::Size(202, 21);
				 this->comboBox4->TabIndex = 42;
				 this->comboBox4->Text = L"select...";
				 // 
				 // nButtonControl10
				 // 
				 this->nButtonControl10->AutoSize = false;
				 this->nButtonControl10->DesignTimeState = resources->GetString(L"nButtonControl10.DesignTimeState");
				 this->nButtonControl10->Location = System::Drawing::Point(262, 354);
				 this->nButtonControl10->Name = L"nButtonControl10";
				 this->nButtonControl10->Size = System::Drawing::Size(56, 23);
				 this->nButtonControl10->TabIndex = 41;
				 this->nButtonControl10->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl10_Click);
				 // 
				 // nButtonControl11
				 // 
				 this->nButtonControl11->AutoSize = false;
				 this->nButtonControl11->DesignTimeState = resources->GetString(L"nButtonControl11.DesignTimeState");
				 this->nButtonControl11->Location = System::Drawing::Point(207, 354);
				 this->nButtonControl11->Name = L"nButtonControl11";
				 this->nButtonControl11->Size = System::Drawing::Size(49, 23);
				 this->nButtonControl11->TabIndex = 40;
				 this->nButtonControl11->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl11_Click);
				 // 
				 // nButtonControl12
				 // 
				 this->nButtonControl12->AutoSize = false;
				 this->nButtonControl12->DesignTimeState = resources->GetString(L"nButtonControl12.DesignTimeState");
				 this->nButtonControl12->Location = System::Drawing::Point(154, 354);
				 this->nButtonControl12->Name = L"nButtonControl12";
				 this->nButtonControl12->Size = System::Drawing::Size(45, 23);
				 this->nButtonControl12->TabIndex = 39;
				 this->nButtonControl12->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl12_Click);
				 // 
				 // timer1
				 // 
				 this->timer1->Enabled = true;
				 this->timer1->Interval = 20;
				 this->timer1->Tick += gcnew System::EventHandler(this, &Settings::timer1_Tick);
				 // 
				 // timer2
				 // 
				 this->timer2->Enabled = true;
				 this->timer2->Interval = 20;
				 this->timer2->Tick += gcnew System::EventHandler(this, &Settings::timer2_Tick);
				 // 
				 // Settings
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(334, 411);
				 this->Controls->Add(this->tabControl1);
				 this->DoubleBuffered = true;
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
				 this->MaximizeBox = false;
				 this->MinimizeBox = false;
				 this->MinimumSize = System::Drawing::Size(350, 450);
				 this->Name = L"Settings";
				 this->ShowIcon = false;
				 this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
				 this->Text = L"Settings";
				 this->Load += gcnew System::EventHandler(this, &Settings::Settings_Load);
				 this->tabPage3->ResumeLayout(false);
				 this->tabPage3->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->EndInit();
				 this->tabPage1->ResumeLayout(false);
				 this->tabPage1->PerformLayout();
				 this->tabPage2->ResumeLayout(false);
				 this->tabPage2->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
				 this->tabControl1->ResumeLayout(false);
				 this->tabPage5->ResumeLayout(false);
				 this->tabPage5->PerformLayout();
				 this->tabPage4->ResumeLayout(false);
				 this->tabPage4->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown5))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown6))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown7))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown8))->EndInit();
				 this->ResumeLayout(false);

			 }
#pragma endregion
	private: System::Void nButtonControl2_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 // UNREFERENCED_PARAMETER(arg);
				 this->Close();
			 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }

			 // Class tab OK button
	private: System::Void nButtonControl1_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 this->applyClass();
				 this->Close();
			 }

	private: System::Void redBox(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

				 if (!std::iscntrl(e->KeyChar) && !std::isdigit(e->KeyChar))
				 {
					 e->Handled = true;
				 }

			 }

	private: System::Void nButtonControl5_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 this->Close();
			 }

	private: System::Void nButtonControl8_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 this->Close();
			 }


	private: System::Void nHsbColorPickerControl1_SelectedColorChanged(Nevron::Nov::Dom::NValueChangeEventArgs^  arg) {
				 Nevron::Nov::Graphics::NColor selectedColor = (Nevron::Nov::Graphics::NColor)arg->NewValue;

				 // get the values of the color from the palette
				 int r = selectedColor.R; // red
				 int g = selectedColor.G; // green
				 int b = selectedColor.B; // blue

				 // update the RGB values in the textbox
				 this->numericUpDown1->Value = r;
				 this->numericUpDown2->Value = g;
				 this->numericUpDown3->Value = b;	

				 this->changedColor = true;

			 }

	private:

		/* Converts from System::String^ to std::string */
		std::string *toStandardString(System::String^ str)
		{
			const char* location = (const char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi( str ).ToPointer();
			std::string *temp = new std::string(location);
			/* Clean up the const char* location memory */
			System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)location));
			return temp;
		}	

	private: System::Void comboBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (OpenGL->uploadedFile()) {
					 int currentIndex = this->comboBox3->SelectedIndex;
					 System::String^ temp = gcnew System::String((*OpenGL->getDimensionName(currentIndex)).c_str());
					 this->textBox7->Text = temp;

					 // get the min-max
					 double temp1 = OpenGL->getArtificialMinimum(currentIndex);
					 double temp2 = OpenGL->getArtificialMaximum(currentIndex);

					 if (OpenGL->isArtificiallyCalibrated(currentIndex)) {
						 this->textBox1->Enabled = true;
						 this->textBox2->Enabled = true;
						 this->checkBox1->Checked = true;
					 } else {
						 this->textBox1->Enabled = false;
						 this->textBox2->Enabled = false;	
						 this->checkBox1->Checked = false;
					 }

					 // convert to system var
					 System::Double^ tmp1 = gcnew System::Double( temp1 );
					 System::Double^ tmp2 = gcnew System::Double( temp2 );

					 // convert to system var
					 System::String^ str1 =  System::String::Format("{0}", tmp1);
					 System::String^ str2 =  System::String::Format("{0}", tmp2);

					 // applys to textbox
					 this->textBox1->Text = str1;
					 this->textBox2->Text = str2;

					 this->loadSetData(currentIndex);

				 }

			 }
	private: System::Void classComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (OpenGL->uploadedFile()) {
					 System::String^ temp = gcnew System::String((*OpenGL->getClassName(this->classComboBox->SelectedIndex)).c_str());
					 this->textBox5->Text = temp;
				 }
			 }
	private: System::Void Settings_Load(System::Object^  sender, System::EventArgs^  e) {

				 System::Windows::Forms::ToolTip^ toolTip = gcnew System::Windows::Forms::ToolTip;
				 // Set up the delays for the ToolTip.
				 toolTip->AutoPopDelay = 5000;
				 toolTip->InitialDelay = 1000;
				 toolTip->ReshowDelay = 500;
				 // Force the ToolTip text to be displayed whether or not the form is active.
				 toolTip->ShowAlways = true;

				 // Set up the ToolTip text for the Button and Checkbox.
				 toolTip->SetToolTip(this->label12, "Remove");
				 toolTip->SetToolTip(this->label13, "Add");
				 // class tab
				 toolTip->SetToolTip(this->label3, "Red");
				 toolTip->SetToolTip(this->label4, "Green");
				 toolTip->SetToolTip(this->label5, "Blue");
				 toolTip->SetToolTip(this->label14, "Alpha");
				 // cluster tab
				 toolTip->SetToolTip(this->label21, "Red");
				 toolTip->SetToolTip(this->label20, "Green");
				 toolTip->SetToolTip(this->label19, "Blue");
				 toolTip->SetToolTip(this->label15, "Alpha");
				 // tooltip for cluster tab
				 toolTip->SetToolTip(this->label16, "Remove");
				 // tooltips for dimension tab
				 toolTip->SetToolTip(this->label17, "Minimum");
				 toolTip->SetToolTip(this->label18, "Maximum");

				 if (OpenGL->uploadedFile()) { 

					 // initially loads the data for the classes
					 this->loadClass();
					 this->loadSet();
					 this->loadDimensions();
					 this->loadClusters();

					 // show default the first element in each combobox
					 this->classComboBox->SelectedIndex = 0; 

					 if(this->comboBox2->Items->Count > 0) {
						 this->comboBox2->SelectedIndex = 0; 
						 if (this->comboBox1->Items->Count > 0) {
							 this->comboBox1->SelectedIndex = OpenGL->getClassOfSet(this->comboBox2->SelectedIndex);
						 }
					 }
					 if (this->comboBox3->Items->Count > 0) {
						 this->comboBox3->SelectedIndex = 0;
					 }
					 if (this->comboBox4->Items->Count > 0) {
						 this->comboBox4->SelectedIndex = 0;
					 }					 
					 if (this->comboBox5->Items->Count > 0) {
						 this->comboBox5->SelectedIndex = 0;
					 }
				 }
			 }


	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			 }
	private: System::Void tabPage3_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 System::Decimal r = this->numericUpDown1->Value;
				 System::Decimal g = this->numericUpDown2->Value;
				 System::Decimal b = this->numericUpDown3->Value;
				 System::Decimal a = this->numericUpDown4->Value;

				 this->changedColor = true;
			 }
	private: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 System::Decimal r = this->numericUpDown1->Value;
				 System::Decimal g = this->numericUpDown2->Value;
				 System::Decimal b = this->numericUpDown3->Value;
				 System::Decimal a = this->numericUpDown4->Value;

				 this->changedColor = true;
			 }
	private: System::Void numericUpDown3_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 System::Decimal r = this->numericUpDown1->Value;
				 System::Decimal g = this->numericUpDown2->Value;
				 System::Decimal b = this->numericUpDown3->Value;
				 System::Decimal a = this->numericUpDown4->Value;

				 this->changedColor = true;
			 }
	private: System::Void numericUpDown4_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 System::Decimal r = this->numericUpDown1->Value;
				 System::Decimal g = this->numericUpDown2->Value;
				 System::Decimal b = this->numericUpDown3->Value;
				 System::Decimal a = this->numericUpDown4->Value;	

				 this->changedColor = true;
			 }

	private: System::Void changePanelColor(System::Object^  sender, System::EventArgs^  e) {
				 /* System::Decimal r = this->numericUpDown1->Value;
				 System::Decimal g = this->numericUpDown2->Value;
				 System::Decimal b = this->numericUpDown3->Value;
				 System::Decimal a = this->numericUpDown4->Value;
				 this->panel1->BackColor = System::Drawing::Color::FromArgb((int)a, (int)r, (int)g, (int)b); */

			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 System::Decimal r = this->numericUpDown1->Value;
				 System::Decimal g = this->numericUpDown2->Value;
				 System::Decimal b = this->numericUpDown3->Value;
				 System::Decimal a = this->numericUpDown4->Value;
				 this->panel1->BackColor = System::Drawing::Color::FromArgb((int)a, (int)r, (int)g, (int)b);

			 }

	private: System::Void label13_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (OpenGL->uploadedFile()) {
					 OpenGL->addClass();
					 this->loadClass();
					 this->classComboBox->SelectedIndex = this->classComboBox->Items->Count - 1; // set it to the last index and shows it
					 System::String^ temp = gcnew System::String((*OpenGL->getClassName(this->classComboBox->Items->Count - 1)).c_str());
					 this->textBox5->Text = temp;
				 }
			 }
	private: System::Void classAddHover(System::Object^  sender, System::EventArgs^  e) {
				 this->label13->ForeColor = System::Drawing::Color::FromArgb((int)45, (int)200, (int)0); // somewhat dark green
			 }

	private: System::Void classAddLeave(System::Object^  sender, System::EventArgs^  e) {
				 this->label13->ForeColor = System::Drawing::Color::Black;
			 }
	private: System::Void classRemoveHover(System::Object^  sender, System::EventArgs^  e) {
				 this->label12->ForeColor = System::Drawing::Color::FromArgb((int)200, (int)0, (int)0); // somewhat dark green

			 }

	private: System::Void classRemoveLeave(System::Object^  sender, System::EventArgs^  e) {
				 this->label12->ForeColor = System::Drawing::Color::Black;
			 }


	protected:
		bool changedColor;
		System::Void applyClass(System::Void) {

			if (OpenGL->uploadedFile()) {
				std::string *className = this->toStandardString(this->textBox5->Text);

				int currentIndex = this->classComboBox->SelectedIndex;

				if (!className->empty()) {
					// set the new name
					OpenGL->setClassName(currentIndex, className);
					// reload the class
					this->loadClass();
					// reset the selected index
					this->classComboBox->SelectedIndex = currentIndex;
				} else {
					this->textBox5->Text = gcnew System::String((*OpenGL->getClassName(currentIndex)).c_str());
				}

				double r = System::Decimal::ToDouble(this->numericUpDown1->Value);
				double g = System::Decimal::ToDouble(this->numericUpDown2->Value);
				double b = System::Decimal::ToDouble(this->numericUpDown3->Value);
				double a = System::Decimal::ToDouble(this->numericUpDown4->Value);

				if (this->changedColor) {
					std::vector<double> *color = new std::vector<double>(4);
					(*color)[0] = r / 255.0;
					(*color)[1] = g / 255.0;
					(*color)[2] = b / 255.0;
					(*color)[3] = a / 255.0;
					OpenGL->setClassColor(currentIndex, color);
					this->changedColor = false;
					delete color;
				}

				OpenGL->setAppliedClassChanges(true);
				delete className;
			}
		}

		bool classSetSelectedIndexChanged;
		System::Void applySet(System::Void)
		{
			if (OpenGL->uploadedFile()) {
				std::string *setName = this->toStandardString(this->textBox6->Text);
				int currentIndex = this->comboBox2->SelectedIndex;
				int currentSetIndex = this->comboBox1->SelectedIndex;
				if (currentSetIndex == -1) {
					currentSetIndex++;
				}
				if (!setName->empty()) {
					OpenGL->setSetName(currentIndex, *setName);
					this->loadSet();
					this->comboBox2->SelectedIndex = currentIndex;		
				} else {
					this->textBox6->Text = gcnew System::String((*OpenGL->getSetName(currentIndex)).c_str());
				}

				if (this->classSetSelectedIndexChanged){
					OpenGL->setSetClass(currentIndex, currentSetIndex);
					this->comboBox1->SelectedIndex = currentSetIndex;
					this->classSetSelectedIndexChanged = false;
				}

				delete setName;

			}
		}

		System::Void applyDimension(System::Void) {
			if (OpenGL->uploadedFile()) {
				std::string *dimensionName = this->toStandardString(this->textBox7->Text);
				int currentIndex = this->comboBox3->SelectedIndex;

				// may need to be improved because it updates every time accept or is clicked,
				// but this is an easy way to do it
				for (int i = 0; i < this->dataGridView2->Rows->Count; i++) {
					std::string *str = toStandardString(this->dataGridView2->Rows[i]->Cells[0]->Value->ToString());
					if (!str->empty()) {
						double newVal = std::stod(*str);
						OpenGL->setData(i, currentIndex, newVal);
					}
					delete str;
				}


				if (!dimensionName->empty()) {
					OpenGL->setDimensionName(currentIndex, dimensionName);
					this->loadDimensions();
				} else {
					this->textBox7->Text = gcnew System::String((*OpenGL->getDimensionName(currentIndex)).c_str());
				}

				if (this->checkBox1->Checked) {
					// create temporary string variable that way we can manage them when out of scope
					std::string *minStr = this->toStandardString(this->textBox1->Text);
					std::string *maxStr = this->toStandardString(this->textBox2->Text);

					// get the previous min-max
					double prevMin = OpenGL->getArtificialMinimum(currentIndex);
					double prevMax = OpenGL->getArtificialMaximum(currentIndex);

					// turn the strings into doubles
					double min = 0.0;
					double max = 0.0;

					// set the min-max
					if (minStr->empty() && maxStr->empty()) {
						min = prevMin;
						max = prevMax;
					} else if (minStr->empty() && !maxStr->empty()) {
						min = prevMin;
						max = std::stod(*maxStr);
					} else if (!minStr->empty() && maxStr->empty()) {
						min = std::stod(*minStr);
						max = prevMax;
					} else { 
						min = std::stod(*minStr);
						max = std::stod(*maxStr);
					}

					OpenGL->setCalibrationBounds(currentIndex, max, min);

					// delete the dynamic memory locations
					delete minStr;
					delete maxStr;

				} else {
					OpenGL->clearArtificialCalibration(currentIndex);
				}

				// reset the selectecd index back to what it was
				delete dimensionName;
				this->comboBox3->SelectedIndex = currentIndex;
			}
		}
		bool changedClusterColor;
		System::Void applyCluster(System::Void) {
			if (OpenGL->uploadedFile()) {

				double r = System::Decimal::ToDouble(this->numericUpDown8->Value);
				double g = System::Decimal::ToDouble(this->numericUpDown7->Value);
				double b = System::Decimal::ToDouble(this->numericUpDown6->Value);
				double a = System::Decimal::ToDouble(this->numericUpDown5->Value);

				if (this->changedClusterColor) {
					std::vector<double> *color = new std::vector<double>(4);
					(*color)[0] = r / 255.0;
					(*color)[1] = g / 255.0;
					(*color)[2] = b / 255.0;
					(*color)[3] = a / 255.0;
					OpenGL->setClusterColor(this->comboBox4->SelectedIndex, color);
					this->changedClusterColor = false;
					delete color;
				}
			}
		}

		System::Void loadClass(System::Void) {
			// clear the list to prevent duplicates on update
			this->classComboBox->Items->Clear();
			this->comboBox1->Items->Clear();
			this->comboBox5->Items->Clear();
			// Setup of the classes
			cli::array<System::Object^>^ item1 = gcnew cli::array<System::Object^>(OpenGL->getClassAmount());
			for (int i = 0; i < OpenGL->getClassAmount(); i++) {
				System::String^ mString = gcnew System::String((*OpenGL->getClassName(i)).c_str());
				item1[i] = (Object^)mString;
			}	
			this->classComboBox->Items->AddRange( item1 ); // set the combobox for "Class tab" to the data in item1 
			this->comboBox1->Items->AddRange( item1 ); // set the combobox for class assignment in "Set tab" to the data in item1
			this->comboBox5->Items->AddRange( item1 ); // set the combobox for class assignment in "Set tab" to the data in item1

		}

		System::Void loadSet(System::Void)
		{
			// clear the list to prevent duplicates
			this->comboBox2->Items->Clear();

			// Setup of the sets
			cli::array<System::Object^>^ item2 = gcnew cli::array<System::Object^>(OpenGL->getSetAmount());
			for (int i = 0; i < OpenGL->getSetAmount(); i++) {
				System::String^ mString = gcnew System::String((*OpenGL->getSetName(i)).c_str());
				item2[i] = (Object^)mString;
			}				
			this->comboBox2->Items->AddRange( item2 ); // set the combobox to the data in items2
		}

		System::Void loadSetData(int currentDimensionIndex)
		{
			this->dataGridView2->Rows->Clear();
			this->dataGridView2->Refresh();
			for (int i = 0; i < OpenGL->getSetAmount(); i++) {	
				double setData = OpenGL->getOriginalData(i, currentDimensionIndex);
				cli::array<System::Double^>^ row = gcnew cli::array<System::Double^> { setData };
				this->dataGridView2->Rows->Add( row );	
			}
		}

		System::Void loadDimensions(System::Void)
		{
			// clear the list to prevent duplicates
			this->comboBox3->Items->Clear();

			// Setup of the dimensions
			cli::array<System::Object^>^ item3 = gcnew cli::array<System::Object^>(OpenGL->getDimensionAmount());
			for (int i = 0; i < OpenGL->getDimensionAmount(); i++) {
				System::String^ mString = gcnew System::String((*OpenGL->getDimensionName(i)).c_str());
				item3[i] = (Object^)mString;
			}				
			this->comboBox3->Items->AddRange( item3 ); // set the combobox to the data in items3
		}

		System::Void loadClusters(System::Void)
		{
			// clear the list to prevent errors
			this->comboBox4->Items->Clear();

			// Setup of the dimensions
			cli::array<System::Object^>^ item4 = gcnew cli::array<System::Object^>(OpenGL->getClusterAmount());
			for (int i = 0; i < OpenGL->getClusterAmount(); i++) {
				System::String^ mString = gcnew System::String("" + i);
				item4[i] = (Object^)mString;
			}				
			this->comboBox4->Items->AddRange( item4 ); // set the combobox to the data in items3
		}





	private: System::Void tabPage4_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label12_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (OpenGL->uploadedFile()) {
					 int currentIndex = this->classComboBox->SelectedIndex;
					 if (currentIndex > 0) {
						 OpenGL->removeClass(this->classComboBox->SelectedIndex);
						 this->loadClass();
						 if (currentIndex < OpenGL->getClassAmount()) {
							 this->classComboBox->SelectedIndex = currentIndex; // set it to the last index and shows it
							 System::String^ temp = gcnew System::String((*OpenGL->getClassName(currentIndex)).c_str());
							 this->textBox5->Text = temp;
						 } else if (currentIndex == OpenGL->getClassAmount()) {
							 this->classComboBox->SelectedIndex = currentIndex - 1; // set it to the last index and shows it
							 System::String^ temp = gcnew System::String((*OpenGL->getClassName(currentIndex - 1)).c_str());
							 this->textBox5->Text = temp;
						 } else {
							 // do nothing
						 }
					 }
				 }
			 }
	private: System::Void nButtonControl3_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 this->applyClass();
			 }
	private: System::Void label16_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (OpenGL->uploadedFile()) {
					 if (this->comboBox4->Items->Count > 0) {
						 int currentIndex = this->comboBox4->SelectedIndex;
						 OpenGL->deleteCluster(currentIndex);
						 this->loadClusters();
						 if (currentIndex < this->comboBox4->Items->Count) {
							 if (currentIndex == 0) {
								 if (this->comboBox4->Items->Count == 0) {
									 this->comboBox4->Text = "select..."; // if there's only one element left then show select...
								 } else {
									 this->comboBox4->SelectedIndex = currentIndex; // set it to the last index and shows it
								 }
							 } else {
								 this->comboBox4->SelectedIndex = currentIndex; // set it to the next index and shows it
							 }
						 } else if (currentIndex == this->comboBox4->Items->Count) {
							 if (this->comboBox4->Items->Count == 0) {
								 this->comboBox4->Text = "select..."; // if there's only one element left then show select... 
							 } else {
								 this->comboBox4->SelectedIndex = currentIndex - 1; // set it to the last index and shows it
							 }
						 } else {
							 // do nothing
						 }

					 } 
				 }
			 }
	private: System::Void numericUpDown8_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

				 System::Decimal r = this->numericUpDown8->Value;
				 System::Decimal g = this->numericUpDown7->Value;
				 System::Decimal b = this->numericUpDown6->Value;
				 System::Decimal a = this->numericUpDown5->Value;	

				 this->changedClusterColor = true;

			 }
	private: System::Void numericUpDown7_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

				 System::Decimal r = this->numericUpDown8->Value;
				 System::Decimal g = this->numericUpDown7->Value;
				 System::Decimal b = this->numericUpDown6->Value;
				 System::Decimal a = this->numericUpDown5->Value;	

				 this->changedClusterColor = true;
			 }
	private: System::Void numericUpDown6_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

				 System::Decimal r = this->numericUpDown8->Value;
				 System::Decimal g = this->numericUpDown7->Value;
				 System::Decimal b = this->numericUpDown6->Value;
				 System::Decimal a = this->numericUpDown5->Value;

				 this->changedClusterColor = true;
			 }
	private: System::Void numericUpDown5_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

				 System::Decimal r = this->numericUpDown8->Value;
				 System::Decimal g = this->numericUpDown7->Value;
				 System::Decimal b = this->numericUpDown6->Value;
				 System::Decimal a = this->numericUpDown5->Value;	

				 this->changedClusterColor = true;
			 }

			 // Cluster tab color picker
	private: System::Void nHsbColorPickerControl2_SelectedColorChanged(Nevron::Nov::Dom::NValueChangeEventArgs^  arg) {
				 Nevron::Nov::Graphics::NColor selectedColor = (Nevron::Nov::Graphics::NColor)arg->NewValue;

				 // get the values of the color from the palette
				 int r = selectedColor.R; // red
				 int g = selectedColor.G; // green
				 int b = selectedColor.B; // blue

				 // update the RGB values in the textbox
				 this->numericUpDown8->Value = r;
				 this->numericUpDown7->Value = g;
				 this->numericUpDown6->Value = b;	

				 this->changedClusterColor = true;

			 }
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
				 System::Decimal r = this->numericUpDown8->Value;
				 System::Decimal g = this->numericUpDown7->Value;
				 System::Decimal b = this->numericUpDown6->Value;
				 System::Decimal a = this->numericUpDown5->Value;
				 this->panel2->BackColor = System::Drawing::Color::FromArgb((int)a, (int)r, (int)g, (int)b);

			 }
	private: System::Void setSetIndexChanged_ChangeEvent(System::Object^  sender, System::EventArgs^  e) {
				 System::String^ temp = gcnew System::String((*OpenGL->getSetName(this->comboBox2->SelectedIndex)).c_str());
				 this->textBox6->Text = temp;
				 if (this->comboBox1->Items->Count > 0) {
					 this->comboBox1->SelectedIndex = OpenGL->getClassOfSet(this->comboBox2->SelectedIndex);
				 }
			 }
	private: System::Void nButtonControl11_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 this->Close();
			 }
	private: System::Void nButtonControl10_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 this->applyCluster();
			 }
	private: System::Void nButtonControl12_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 this->applyCluster();
				 this->Close();
			 }
	private: System::Void nButtonControl7_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 this->applyDimension();
			 }
	private: System::Void nButtonControl9_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 this->applyDimension();
				 this->Close();
			 }
	private: System::Void nButtonControl4_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 this->applySet();
			 }
	private: System::Void nButtonControl6_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 this->applySet();
				 this->Close();
			 }
	private: System::Void removeCluster_Hover(System::Object^  sender, System::EventArgs^  e) {
				 this->label16->ForeColor = System::Drawing::Color::FromArgb((int)200, (int)0, (int)0); // somewhat dark green, like lawn green
			 }
	private: System::Void removeCluster_Leave(System::Object^  sender, System::EventArgs^  e) {
				 this->label16->ForeColor = System::Drawing::Color::Black; // black
			 }
	private: System::Void setClass_SelectedIndex_Change(System::Object^  sender, System::EventArgs^  e) {
				 this->classSetSelectedIndexChanged = true;
			 }
	private: System::Void checkedDimension_State(System::Object^  sender, System::EventArgs^  e) {
				 if (this->checkBox1->Checked) {
					 this->textBox1->Enabled = true;
					 this->textBox2->Enabled = true;
				 } else {
					 this->textBox1->Enabled = false;
					 this->textBox2->Enabled = false;					 
				 }
			 }


	private: System::Void textBox1_KeyPress_State(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
				 if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) && (e->KeyChar != '.') && (e->KeyChar != '-')) {
					 e->Handled = true;
				 }

				 // only allow one decimal point
				 if ((e->KeyChar == '.') && safe_cast<TextBox^>(sender)->Text->IndexOf('.') > -1) {
					 e->Handled = true;
				 }

				 // only allow for one negative sign and only at the front of the numer
				 if ((e->KeyChar == '-') && safe_cast<TextBox^>(sender)->SelectionStart != 0) {
					 e->Handled = true;
				 } 

				 if ((e->KeyChar == '-') && safe_cast<TextBox^>(sender)->SelectionStart == 0 && safe_cast<TextBox^>(sender)->Text->IndexOf('-') == 0) {
					 e->Handled = true;
				 }


				 if (( (Char::IsDigit(e->KeyChar)) || (e->KeyChar == '.') )  && safe_cast<TextBox^>(sender)->SelectionStart == 0 && safe_cast<TextBox^>(sender)->Text->IndexOf('-') == 0) {
					 e->Handled = true;
				 }



			 }
	private: System::Void textBox2_KeyPress_State(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
				 if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) && (e->KeyChar != '.') && (e->KeyChar != '-')) {
					 e->Handled = true;
				 }

				 // only allow one decimal point
				 if ((e->KeyChar == '.') && safe_cast<TextBox^>(sender)->Text->IndexOf('.') > -1) {
					 e->Handled = true;
				 }

				 // only allow for one negative sign and only at the front of the numer
				 if ((e->KeyChar == '-') && safe_cast<TextBox^>(sender)->SelectionStart != 0) {
					 e->Handled = true;
				 } 

				 if ((e->KeyChar == '-') && safe_cast<TextBox^>(sender)->SelectionStart == 0 && safe_cast<TextBox^>(sender)->Text->IndexOf('-') == 0) {
					 e->Handled = true;
				 }

				 if (( (Char::IsDigit(e->KeyChar)) || (e->KeyChar == '.') )  && safe_cast<TextBox^>(sender)->SelectionStart == 0 && safe_cast<TextBox^>(sender)->Text->IndexOf('-') == 0) {
					 e->Handled = true;
				 }


			 }
	private: System::Void dataGridView2_KeyPressed_State(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

				 if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) && (e->KeyChar != '.') && (e->KeyChar != '-')) {
					 e->Handled = true;
				 }

				 // only allow one decimal point
				 if ((e->KeyChar == '.') && safe_cast<TextBox^>(sender)->Text->IndexOf('.') > -1) {
					 e->Handled = true;
				 }

				 // only allow for one negative sign and only at the front of the numer
				 if ((e->KeyChar == '-') && safe_cast<TextBox^>(sender)->SelectionStart != 0) {
					 e->Handled = true;
				 } 

				 if ((e->KeyChar == '-') && safe_cast<TextBox^>(sender)->SelectionStart == 0 && safe_cast<TextBox^>(sender)->Text->IndexOf('-') == 0) {
					 e->Handled = true;
				 }

				 if (( (Char::IsDigit(e->KeyChar)) || (e->KeyChar == '.') )  && safe_cast<TextBox^>(sender)->SelectionStart == 0 && safe_cast<TextBox^>(sender)->Text->IndexOf('-') == 0) {
					 e->Handled = true;
				 }

			 }
	private: System::Void dataGridView1_EditingControl(System::Object^  sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^  e) {
				 e->Control->KeyPress -= gcnew KeyPressEventHandler(this, &Settings::dataGridView2_KeyPressed_State);
				 TextBox^ tb = safe_cast<TextBox^>(e->Control);
				 if (tb != nullptr)
				 {
					 tb->KeyPress += gcnew KeyPressEventHandler(this, &Settings::dataGridView2_KeyPressed_State);
				 }
			 }
	private: System::Void dataGridView2_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 }
	private: System::Void classSetSelectedIndex_Changed(System::Object^  sender, System::EventArgs^  e) {
				 if (OpenGL->uploadedFile()) {
					 this->checkedListBox1->Items->Clear();
					 for (int i = 0; i < OpenGL->getSetAmount(); i++) {
						 if (!(*OpenGL->getSetOfClass(this->comboBox5->SelectedIndex, i)).empty()) 
						 {
							 System::String^ temp = gcnew System::String((*OpenGL->getSetOfClass(this->comboBox5->SelectedIndex, i)).c_str());
							 this->checkedListBox1->Items->Add(temp, true);
						 }
					 }
				 }
			 }
	private: System::Void nButtonControl14_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 this->Close();
			 }
	private: System::Void nButtonControl15_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 // this->applyClassSet();
				 this->Close();
			 }
	private: System::Void nButtonControl13_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 // this->applyClassSet();
			 }
	private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}