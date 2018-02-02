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
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected: 
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: Nevron::Nov::WinFormControls::NHsbColorPickerControl^  nHsbColorPickerControl1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;



	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl2;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl4;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl5;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl6;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl7;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl8;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl9;
			 OpenGLForm::COpenGL ^ OpenGL;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Settings::typeid));
				 this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
				 this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->textBox5 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox4 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox3 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox2 = (gcnew System::Windows::Forms::TextBox());
				 this->nButtonControl3 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
				 this->nButtonControl2 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->nButtonControl1 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				 this->nHsbColorPickerControl1 = (gcnew Nevron::Nov::WinFormControls::NHsbColorPickerControl());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
				 this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
				 this->nButtonControl4 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->nButtonControl5 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->nButtonControl6 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
				 this->nButtonControl7 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->nButtonControl8 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->nButtonControl9 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
				 this->tabControl1->SuspendLayout();
				 this->tabPage2->SuspendLayout();
				 this->tabPage1->SuspendLayout();
				 this->tabPage3->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // tabControl1
				 // 
				 this->tabControl1->Controls->Add(this->tabPage2);
				 this->tabControl1->Controls->Add(this->tabPage1);
				 this->tabControl1->Controls->Add(this->tabPage3);
				 this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tabControl1->Location = System::Drawing::Point(0, 0);
				 this->tabControl1->Name = L"tabControl1";
				 this->tabControl1->SelectedIndex = 0;
				 this->tabControl1->Size = System::Drawing::Size(414, 411);
				 this->tabControl1->TabIndex = 0;
				 // 
				 // tabPage2
				 // 
				 this->tabPage2->BackColor = System::Drawing::Color::LightGray;
				 this->tabPage2->Controls->Add(this->label6);
				 this->tabPage2->Controls->Add(this->textBox5);
				 this->tabPage2->Controls->Add(this->textBox4);
				 this->tabPage2->Controls->Add(this->textBox3);
				 this->tabPage2->Controls->Add(this->textBox2);
				 this->tabPage2->Controls->Add(this->nButtonControl3);
				 this->tabPage2->Controls->Add(this->checkBox1);
				 this->tabPage2->Controls->Add(this->nButtonControl2);
				 this->tabPage2->Controls->Add(this->nButtonControl1);
				 this->tabPage2->Controls->Add(this->label5);
				 this->tabPage2->Controls->Add(this->label4);
				 this->tabPage2->Controls->Add(this->label3);
				 this->tabPage2->Controls->Add(this->textBox1);
				 this->tabPage2->Controls->Add(this->nHsbColorPickerControl1);
				 this->tabPage2->Controls->Add(this->label2);
				 this->tabPage2->Controls->Add(this->label1);
				 this->tabPage2->Controls->Add(this->comboBox1);
				 this->tabPage2->Location = System::Drawing::Point(4, 22);
				 this->tabPage2->Name = L"tabPage2";
				 this->tabPage2->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage2->Size = System::Drawing::Size(406, 385);
				 this->tabPage2->TabIndex = 1;
				 this->tabPage2->Text = L"Class";
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Font = (gcnew System::Drawing::Font(L"MS Office Symbol Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label6->Location = System::Drawing::Point(22, 60);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(57, 32);
				 this->label6->TabIndex = 28;
				 this->label6->Text = L"Change\r\nName:";
				 this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 // 
				 // textBox5
				 // 
				 this->textBox5->Location = System::Drawing::Point(92, 70);
				 this->textBox5->Name = L"textBox5";
				 this->textBox5->Size = System::Drawing::Size(202, 20);
				 this->textBox5->TabIndex = 27;
				 // 
				 // textBox4
				 // 
				 this->textBox4->Enabled = false;
				 this->textBox4->Location = System::Drawing::Point(338, 234);
				 this->textBox4->MaxLength = 3;
				 this->textBox4->Name = L"textBox4";
				 this->textBox4->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
				 this->textBox4->Size = System::Drawing::Size(38, 20);
				 this->textBox4->TabIndex = 26;
				 this->textBox4->Text = L"0";
				 // 
				 // textBox3
				 // 
				 this->textBox3->Enabled = false;
				 this->textBox3->Location = System::Drawing::Point(338, 192);
				 this->textBox3->MaxLength = 3;
				 this->textBox3->Name = L"textBox3";
				 this->textBox3->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
				 this->textBox3->Size = System::Drawing::Size(38, 20);
				 this->textBox3->TabIndex = 25;
				 this->textBox3->Text = L"0";
				 // 
				 // textBox2
				 // 
				 this->textBox2->Enabled = false;
				 this->textBox2->Location = System::Drawing::Point(338, 149);
				 this->textBox2->MaxLength = 3;
				 this->textBox2->Name = L"textBox2";
				 this->textBox2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
				 this->textBox2->Size = System::Drawing::Size(38, 20);
				 this->textBox2->TabIndex = 24;
				 this->textBox2->Text = L"0";
				 this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Settings::redBox);
				 // 
				 // nButtonControl3
				 // 
				 this->nButtonControl3->AutoSize = false;
				 this->nButtonControl3->DesignTimeState = resources->GetString(L"nButtonControl3.DesignTimeState");
				 this->nButtonControl3->Location = System::Drawing::Point(341, 354);
				 this->nButtonControl3->Name = L"nButtonControl3";
				 this->nButtonControl3->Size = System::Drawing::Size(56, 23);
				 this->nButtonControl3->TabIndex = 23;
				 // 
				 // checkBox1
				 // 
				 this->checkBox1->AutoSize = true;
				 this->checkBox1->Enabled = false;
				 this->checkBox1->Font = (gcnew System::Drawing::Font(L"MS Office Symbol Bold", 12));
				 this->checkBox1->Location = System::Drawing::Point(315, 72);
				 this->checkBox1->Name = L"checkBox1";
				 this->checkBox1->Size = System::Drawing::Size(61, 20);
				 this->checkBox1->TabIndex = 22;
				 this->checkBox1->Text = L"visible";
				 this->checkBox1->UseVisualStyleBackColor = true;
				 // 
				 // nButtonControl2
				 // 
				 this->nButtonControl2->AutoSize = false;
				 this->nButtonControl2->DesignTimeState = resources->GetString(L"nButtonControl2.DesignTimeState");
				 this->nButtonControl2->Location = System::Drawing::Point(286, 354);
				 this->nButtonControl2->Name = L"nButtonControl2";
				 this->nButtonControl2->Size = System::Drawing::Size(49, 23);
				 this->nButtonControl2->TabIndex = 21;
				 this->nButtonControl2->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl2_Click);
				 // 
				 // nButtonControl1
				 // 
				 this->nButtonControl1->AutoSize = false;
				 this->nButtonControl1->DesignTimeState = resources->GetString(L"nButtonControl1.DesignTimeState");
				 this->nButtonControl1->Location = System::Drawing::Point(233, 354);
				 this->nButtonControl1->Name = L"nButtonControl1";
				 this->nButtonControl1->Size = System::Drawing::Size(45, 23);
				 this->nButtonControl1->TabIndex = 20;
				 this->nButtonControl1->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl1_Click);
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Font = (gcnew System::Drawing::Font(L"MS Office Symbol Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label5->Location = System::Drawing::Point(312, 233);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(19, 16);
				 this->label5->TabIndex = 16;
				 this->label5->Text = L"B:";
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Font = (gcnew System::Drawing::Font(L"MS Office Symbol Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label4->Location = System::Drawing::Point(312, 190);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(20, 16);
				 this->label4->TabIndex = 15;
				 this->label4->Text = L"G:";
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Font = (gcnew System::Drawing::Font(L"MS Office Symbol Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label3->Location = System::Drawing::Point(312, 148);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(20, 16);
				 this->label3->TabIndex = 14;
				 this->label3->Text = L"R:";
				 // 
				 // textBox1
				 // 
				 this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(0)));
				 this->textBox1->Enabled = false;
				 this->textBox1->Location = System::Drawing::Point(91, 284);
				 this->textBox1->Multiline = true;
				 this->textBox1->Name = L"textBox1";
				 this->textBox1->Size = System::Drawing::Size(202, 35);
				 this->textBox1->TabIndex = 13;
				 this->textBox1->TextChanged += gcnew System::EventHandler(this, &Settings::textBox1_TextChanged);
				 // 
				 // nHsbColorPickerControl1
				 // 
				 this->nHsbColorPickerControl1->AutoSize = false;
				 this->nHsbColorPickerControl1->DesignTimeState = nullptr;
				 this->nHsbColorPickerControl1->Location = System::Drawing::Point(92, 111);
				 this->nHsbColorPickerControl1->Name = L"nHsbColorPickerControl1";
				 this->nHsbColorPickerControl1->Size = System::Drawing::Size(202, 168);
				 this->nHsbColorPickerControl1->TabIndex = 3;
				 this->nHsbColorPickerControl1->SelectedColorChanged += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NValueChangeEventArgs^ >(this, &Settings::nHsbColorPickerControl1_SelectedColorChanged);
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Font = (gcnew System::Drawing::Font(L"MS Office Symbol Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label2->Location = System::Drawing::Point(33, 111);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(46, 16);
				 this->label2->TabIndex = 2;
				 this->label2->Text = L"Color:";
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Font = (gcnew System::Drawing::Font(L"MS Office Symbol Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label1->Location = System::Drawing::Point(25, 29);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(54, 16);
				 this->label1->TabIndex = 1;
				 this->label1->Text = L"Name :";
				 // 
				 // comboBox1
				 // 
				 this->comboBox1->FormattingEnabled = true;
				 this->comboBox1->ItemHeight = 13;
				 this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Class 1", L"Class 2", L"Class 3", L"Class 4", 
					 L"Class 5"});
				 this->comboBox1->Location = System::Drawing::Point(92, 27);
				 this->comboBox1->Name = L"comboBox1";
				 this->comboBox1->Size = System::Drawing::Size(202, 21);
				 this->comboBox1->TabIndex = 0;
				 // 
				 // tabPage1
				 // 
				 this->tabPage1->BackColor = System::Drawing::Color::LightGray;
				 this->tabPage1->Controls->Add(this->nButtonControl4);
				 this->tabPage1->Controls->Add(this->nButtonControl5);
				 this->tabPage1->Controls->Add(this->nButtonControl6);
				 this->tabPage1->Location = System::Drawing::Point(4, 22);
				 this->tabPage1->Name = L"tabPage1";
				 this->tabPage1->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage1->Size = System::Drawing::Size(406, 385);
				 this->tabPage1->TabIndex = 2;
				 this->tabPage1->Text = L"Set";
				 // 
				 // nButtonControl4
				 // 
				 this->nButtonControl4->AutoSize = false;
				 this->nButtonControl4->DesignTimeState = resources->GetString(L"nButtonControl4.DesignTimeState");
				 this->nButtonControl4->Location = System::Drawing::Point(341, 354);
				 this->nButtonControl4->Name = L"nButtonControl4";
				 this->nButtonControl4->Size = System::Drawing::Size(56, 23);
				 this->nButtonControl4->TabIndex = 26;
				 // 
				 // nButtonControl5
				 // 
				 this->nButtonControl5->AutoSize = false;
				 this->nButtonControl5->DesignTimeState = resources->GetString(L"nButtonControl5.DesignTimeState");
				 this->nButtonControl5->Location = System::Drawing::Point(286, 354);
				 this->nButtonControl5->Name = L"nButtonControl5";
				 this->nButtonControl5->Size = System::Drawing::Size(49, 23);
				 this->nButtonControl5->TabIndex = 25;
				 this->nButtonControl5->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl5_Click);
				 // 
				 // nButtonControl6
				 // 
				 this->nButtonControl6->AutoSize = false;
				 this->nButtonControl6->DesignTimeState = resources->GetString(L"nButtonControl6.DesignTimeState");
				 this->nButtonControl6->Location = System::Drawing::Point(233, 354);
				 this->nButtonControl6->Name = L"nButtonControl6";
				 this->nButtonControl6->Size = System::Drawing::Size(45, 23);
				 this->nButtonControl6->TabIndex = 24;
				 // 
				 // tabPage3
				 // 
				 this->tabPage3->BackColor = System::Drawing::Color::LightGray;
				 this->tabPage3->Controls->Add(this->nButtonControl7);
				 this->tabPage3->Controls->Add(this->nButtonControl8);
				 this->tabPage3->Controls->Add(this->nButtonControl9);
				 this->tabPage3->Location = System::Drawing::Point(4, 22);
				 this->tabPage3->Name = L"tabPage3";
				 this->tabPage3->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage3->Size = System::Drawing::Size(406, 385);
				 this->tabPage3->TabIndex = 3;
				 this->tabPage3->Text = L"Dimension";
				 // 
				 // nButtonControl7
				 // 
				 this->nButtonControl7->AutoSize = false;
				 this->nButtonControl7->DesignTimeState = resources->GetString(L"nButtonControl7.DesignTimeState");
				 this->nButtonControl7->Location = System::Drawing::Point(341, 354);
				 this->nButtonControl7->Name = L"nButtonControl7";
				 this->nButtonControl7->Size = System::Drawing::Size(56, 23);
				 this->nButtonControl7->TabIndex = 26;
				 // 
				 // nButtonControl8
				 // 
				 this->nButtonControl8->AutoSize = false;
				 this->nButtonControl8->DesignTimeState = resources->GetString(L"nButtonControl8.DesignTimeState");
				 this->nButtonControl8->Location = System::Drawing::Point(286, 354);
				 this->nButtonControl8->Name = L"nButtonControl8";
				 this->nButtonControl8->Size = System::Drawing::Size(49, 23);
				 this->nButtonControl8->TabIndex = 25;
				 this->nButtonControl8->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &Settings::nButtonControl8_Click);
				 // 
				 // nButtonControl9
				 // 
				 this->nButtonControl9->AutoSize = false;
				 this->nButtonControl9->DesignTimeState = resources->GetString(L"nButtonControl9.DesignTimeState");
				 this->nButtonControl9->Location = System::Drawing::Point(233, 354);
				 this->nButtonControl9->Name = L"nButtonControl9";
				 this->nButtonControl9->Size = System::Drawing::Size(45, 23);
				 this->nButtonControl9->TabIndex = 24;
				 // 
				 // Settings
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(414, 411);
				 this->Controls->Add(this->tabControl1);
				 this->MaximizeBox = false;
				 this->MinimizeBox = false;
				 this->MinimumSize = System::Drawing::Size(430, 450);
				 this->Name = L"Settings";
				 this->ShowIcon = false;
				 this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
				 this->Text = L"Settings";
				 this->tabControl1->ResumeLayout(false);
				 this->tabPage2->ResumeLayout(false);
				 this->tabPage2->PerformLayout();
				 this->tabPage1->ResumeLayout(false);
				 this->tabPage3->ResumeLayout(false);
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
				 System::String^ hex = selectedColor.GetHEX();
				 std::string s = toStandardString(hex); // convert HEX to std::string
				 s = s.substr(1, s.length()); // remove the "#" from the front of the string
				 char* str = (char*)s.c_str(); // convert back to a dynamic char array
				 int R, G, B;
				 sscanf_s(str, "%02x%02x%02x", &R, &G, &B); // convert HEX to RGB	

				 this->textBox1->BackColor = System::Drawing::Color::FromArgb(R, G, B);
				 OpenGL->SetRGB((GLdouble)R, (GLdouble)G, (GLdouble)B);

				 // update the RGB values in the textbox
				 this->textBox2->Text = ""+R;
				 this->textBox3->Text = ""+G;
				 this->textBox4->Text = ""+B;
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
	};
}
