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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
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
	private: System::Windows::Forms::CheckBox^  checkBox1;
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
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::TextBox^  textBox1;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label21;
private: Nevron::Nov::WinFormControls::NHsbColorPickerControl^  nHsbColorPickerControl2;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::ComboBox^  comboBox4;
































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
				 this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
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
				 this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
				 this->panel2 = (gcnew System::Windows::Forms::Panel());
				 this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
				 this->label15 = (gcnew System::Windows::Forms::Label());
				 this->numericUpDown6 = (gcnew System::Windows::Forms::NumericUpDown());
				 this->numericUpDown7 = (gcnew System::Windows::Forms::NumericUpDown());
				 this->numericUpDown8 = (gcnew System::Windows::Forms::NumericUpDown());
				 this->label18 = (gcnew System::Windows::Forms::Label());
				 this->textBox1 = (gcnew System::Windows::Forms::TextBox());
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
				 this->tabPage3->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->BeginInit();
				 this->tabPage1->SuspendLayout();
				 this->tabPage2->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
				 this->tabControl1->SuspendLayout();
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
				 // dataGridView2
				 // 
				 this->dataGridView2->AllowUserToAddRows = false;
				 this->dataGridView2->AllowUserToDeleteRows = false;
				 this->dataGridView2->AllowUserToResizeColumns = false;
				 this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) {this->dataGridViewTextBoxColumn1});
				 this->dataGridView2->Location = System::Drawing::Point(105, 147);
				 this->dataGridView2->Name = L"dataGridView2";
				 this->dataGridView2->RowHeadersVisible = false;
				 this->dataGridView2->Size = System::Drawing::Size(116, 179);
				 this->dataGridView2->TabIndex = 39;
				 // 
				 // dataGridViewTextBoxColumn1
				 // 
				 this->dataGridViewTextBoxColumn1->FillWeight = 200;
				 this->dataGridViewTextBoxColumn1->HeaderText = L"Data";
				 this->dataGridViewTextBoxColumn1->MinimumWidth = 113;
				 this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
				 this->dataGridViewTextBoxColumn1->Width = 113;
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label9->Location = System::Drawing::Point(60, 82);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(102, 15);
				 this->label9->TabIndex = 38;
				 this->label9->Text = L"Change Name:";
				 this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 // 
				 // textBox7
				 // 
				 this->textBox7->Location = System::Drawing::Point(63, 100);
				 this->textBox7->Name = L"textBox7";
				 this->textBox7->Size = System::Drawing::Size(202, 20);
				 this->textBox7->TabIndex = 37;
				 // 
				 // label10
				 // 
				 this->label10->AutoSize = true;
				 this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label10->Location = System::Drawing::Point(60, 26);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(49, 15);
				 this->label10->TabIndex = 36;
				 this->label10->Text = L"Name:";
				 // 
				 // comboBox3
				 // 
				 this->comboBox3->FormattingEnabled = true;
				 this->comboBox3->ItemHeight = 13;
				 this->comboBox3->Location = System::Drawing::Point(63, 44);
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
				 // 
				 // nButtonControl4
				 // 
				 this->nButtonControl4->AutoSize = false;
				 this->nButtonControl4->DesignTimeState = resources->GetString(L"nButtonControl4.DesignTimeState");
				 this->nButtonControl4->Location = System::Drawing::Point(262, 354);
				 this->nButtonControl4->Name = L"nButtonControl4";
				 this->nButtonControl4->Size = System::Drawing::Size(56, 23);
				 this->nButtonControl4->TabIndex = 26;
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
				 this->tabPage2->Controls->Add(this->checkBox1);
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
				 this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
				 this->label13->Location = System::Drawing::Point(248, 38);
				 this->label13->Name = L"label13";
				 this->label13->Size = System::Drawing::Size(19, 20);
				 this->label13->TabIndex = 30;
				 this->label13->Text = L"+";
				 this->label13->Click += gcnew System::EventHandler(this, &Settings::label13_Click);
				 this->label13->MouseLeave += gcnew System::EventHandler(this, &Settings::classAddLeave);
				 this->label13->MouseHover += gcnew System::EventHandler(this, &Settings::classAddHover);
				 // 
				 // label12
				 // 
				 this->label12->AutoSize = true;
				 this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.5F, System::Drawing::FontStyle::Bold));
				 this->label12->Location = System::Drawing::Point(273, 42);
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
				 // 
				 // nButtonControl3
				 // 
				 this->nButtonControl3->AutoSize = false;
				 this->nButtonControl3->DesignTimeState = resources->GetString(L"nButtonControl3.DesignTimeState");
				 this->nButtonControl3->Location = System::Drawing::Point(262, 354);
				 this->nButtonControl3->Name = L"nButtonControl3";
				 this->nButtonControl3->Size = System::Drawing::Size(56, 23);
				 this->nButtonControl3->TabIndex = 23;
				 // 
				 // checkBox1
				 // 
				 this->checkBox1->AutoSize = true;
				 this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->checkBox1->Location = System::Drawing::Point(18, 42);
				 this->checkBox1->Name = L"checkBox1";
				 this->checkBox1->Size = System::Drawing::Size(15, 14);
				 this->checkBox1->TabIndex = 22;
				 this->checkBox1->UseVisualStyleBackColor = true;
				 this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Settings::checkBox1_CheckedChanged);
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
				 // tabPage4
				 // 
				 this->tabPage4->BackColor = System::Drawing::Color::LightGray;
				 this->tabPage4->Controls->Add(this->panel2);
				 this->tabPage4->Controls->Add(this->numericUpDown5);
				 this->tabPage4->Controls->Add(this->label15);
				 this->tabPage4->Controls->Add(this->numericUpDown6);
				 this->tabPage4->Controls->Add(this->numericUpDown7);
				 this->tabPage4->Controls->Add(this->numericUpDown8);
				 this->tabPage4->Controls->Add(this->label18);
				 this->tabPage4->Controls->Add(this->textBox1);
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
				 // 
				 // numericUpDown7
				 // 
				 this->numericUpDown7->Location = System::Drawing::Point(267, 190);
				 this->numericUpDown7->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
				 this->numericUpDown7->Name = L"numericUpDown7";
				 this->numericUpDown7->Size = System::Drawing::Size(47, 20);
				 this->numericUpDown7->TabIndex = 54;
				 this->numericUpDown7->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 // 
				 // numericUpDown8
				 // 
				 this->numericUpDown8->Location = System::Drawing::Point(267, 148);
				 this->numericUpDown8->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
				 this->numericUpDown8->Name = L"numericUpDown8";
				 this->numericUpDown8->Size = System::Drawing::Size(47, 20);
				 this->numericUpDown8->TabIndex = 53;
				 this->numericUpDown8->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 // 
				 // label18
				 // 
				 this->label18->AutoSize = true;
				 this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
				 this->label18->Location = System::Drawing::Point(34, 76);
				 this->label18->Name = L"label18";
				 this->label18->Size = System::Drawing::Size(102, 15);
				 this->label18->TabIndex = 50;
				 this->label18->Text = L"Change Name:";
				 this->label18->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 // 
				 // textBox1
				 // 
				 this->textBox1->Location = System::Drawing::Point(37, 96);
				 this->textBox1->Name = L"textBox1";
				 this->textBox1->Size = System::Drawing::Size(202, 20);
				 this->textBox1->TabIndex = 49;
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
				 // 
				 // nButtonControl11
				 // 
				 this->nButtonControl11->AutoSize = false;
				 this->nButtonControl11->DesignTimeState = resources->GetString(L"nButtonControl11.DesignTimeState");
				 this->nButtonControl11->Location = System::Drawing::Point(207, 354);
				 this->nButtonControl11->Name = L"nButtonControl11";
				 this->nButtonControl11->Size = System::Drawing::Size(49, 23);
				 this->nButtonControl11->TabIndex = 40;
				 // 
				 // nButtonControl12
				 // 
				 this->nButtonControl12->AutoSize = false;
				 this->nButtonControl12->DesignTimeState = resources->GetString(L"nButtonControl12.DesignTimeState");
				 this->nButtonControl12->Location = System::Drawing::Point(154, 354);
				 this->nButtonControl12->Name = L"nButtonControl12";
				 this->nButtonControl12->Size = System::Drawing::Size(45, 23);
				 this->nButtonControl12->TabIndex = 39;
				 // 
				 // timer1
				 // 
				 this->timer1->Enabled = true;
				 this->timer1->Interval = 20;
				 this->timer1->Tick += gcnew System::EventHandler(this, &Settings::timer1_Tick);
				 // 
				 // Settings
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(334, 411);
				 this->Controls->Add(this->tabControl1);
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

	private: System::Void nButtonControl1_Click(Nevron::Nov::Dom::NEventArgs^  arg) {

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

			 }

	private:

		/* Converts from System::String^ to std::string */
		std::string toStandardString(System::String^ str)
		{
			const char* location = (const char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi( str ).ToPointer();
			std::string temp(location);
			/* Clean up the const char* location memory */
			System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)location));
			return temp;
		}	
	private: System::Void comboBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				/*cli::array<System::Object^>^ item = gcnew cli::array<System::Object^>(OpenGL->getDimensionAmount());
				for (int i = 0; i < OpenGL->getDimensionAmount(); i++) {
					System::String^ mString = gcnew System::String(OpenGL->getDimensionName(i));
					item[i] = (Object^)mString;
				}
				this->comboBox3->Items->AddRange( item );*/
			 }
private: System::Void classComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 
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
				 toolTip->SetToolTip(this->label3, "Red");
				 toolTip->SetToolTip(this->label4, "Green");
				 toolTip->SetToolTip(this->label5, "Blue");
				 toolTip->SetToolTip(this->label14, "Alpha");
				 toolTip->SetToolTip(this->checkBox1, "Visible");
				 
				loadClass();

				// Setup of the sets
				cli::array<System::Object^>^ item2 = gcnew cli::array<System::Object^>(OpenGL->getSetAmount());
				for (int i = 0; i < OpenGL->getSetAmount(); i++) {
					System::String^ mString = gcnew System::String((*OpenGL->getSetName(i)).c_str());
					item2[i] = (Object^)mString;
				}				
				this->comboBox2->Items->AddRange( item2 ); // set the combobox to the data in items2

				// Setup of the dimensions
				cli::array<System::Object^>^ item3 = gcnew cli::array<System::Object^>(OpenGL->getDimensionAmount());
				for (int i = 0; i < OpenGL->getDimensionAmount(); i++) {
					System::String^ mString = gcnew System::String((*OpenGL->getDimensionName(i)).c_str());
					item3[i] = (Object^)mString;
				}				
				this->comboBox3->Items->AddRange( item3 ); // set the combobox to the data in items3

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
			 
			 // set the textbox back color
			// this->panel1->BackColor = System::Drawing::Color::FromArgb((int)a, (int)r, (int)g, (int)b);
			 OpenGL->SetRGB((GLdouble)r, (GLdouble)g, (GLdouble)b);
		 }
private: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 System::Decimal r = this->numericUpDown1->Value;
			 System::Decimal g = this->numericUpDown2->Value;
			 System::Decimal b = this->numericUpDown3->Value;
			 System::Decimal a = this->numericUpDown4->Value;

		 }
private: System::Void numericUpDown3_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 System::Decimal r = this->numericUpDown1->Value;
			 System::Decimal g = this->numericUpDown2->Value;
			 System::Decimal b = this->numericUpDown3->Value;
			 System::Decimal a = this->numericUpDown4->Value;	 
		}
private: System::Void numericUpDown4_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 System::Decimal r = this->numericUpDown1->Value;
			 System::Decimal g = this->numericUpDown2->Value;
			 System::Decimal b = this->numericUpDown3->Value;
			 System::Decimal a = this->numericUpDown4->Value;	
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

			 OpenGL->addClass();
			 this->loadClass();

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
		
		System::Void applyClass(System::Void) {
						
			loadClass();	

			 System::Decimal r = this->numericUpDown1->Value;
			 System::Decimal g = this->numericUpDown2->Value;
			 System::Decimal b = this->numericUpDown3->Value;
			 System::Decimal a = this->numericUpDown4->Value;
			 OpenGL->SetRGB((GLdouble)r, (GLdouble)g, (GLdouble)b);

		}


		System::Void loadClass(System::Void) {
			// clear the list to prevent duplicates on update
			this->classComboBox->Items->Clear();
			this->comboBox1->Items->Clear();
			// Setup of the classes
				cli::array<System::Object^>^ item1 = gcnew cli::array<System::Object^>(OpenGL->getClassAmount());
				for (int i = 0; i < OpenGL->getClassAmount(); i++) {
					System::String^ mString = gcnew System::String((*OpenGL->getClassName(i)).c_str());
					item1[i] = (Object^)mString;
				}	
				this->classComboBox->Items->AddRange( item1 ); // set the combobox for "Class tab" to the data in item1 
				this->comboBox1->Items->AddRange( item1 ); // set the combobox for class assignment in "Set tab" to the data in item1
		}


		
private: System::Void tabPage4_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label12_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenGL->removeClass(this->classComboBox->SelectedIndex);
			 this->loadClass();
		 }
};
}
