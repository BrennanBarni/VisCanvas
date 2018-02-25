#pragma once

namespace VisCanvas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for VisCanvasHelp
	/// </summary>
	public ref class VisCanvasHelp : public System::Windows::Forms::Form
	{
	public:
		VisCanvasHelp(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VisCanvasHelp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::HelpProvider^  helpProvider1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: Nevron::Nov::WinFormControls::NButtonControl^  nButtonControl1;

	protected: 

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VisCanvasHelp::typeid));
			this->helpProvider1 = (gcnew System::Windows::Forms::HelpProvider());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->nButtonControl1 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(5, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(594, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"For help or instruction on how to use VisCanvas please refer to the user manual.\r" 
				L"\n";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel1->Location = System::Drawing::Point(262, 62);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(78, 17);
			this->linkLabel1->TabIndex = 1;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Download";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &VisCanvasHelp::linkLabel1_LinkClicked);
			// 
			// nButtonControl1
			// 
			this->nButtonControl1->AutoSize = false;
			this->nButtonControl1->DesignTimeState = resources->GetString(L"nButtonControl1.DesignTimeState");
			this->nButtonControl1->Location = System::Drawing::Point(521, 123);
			this->nButtonControl1->Name = L"nButtonControl1";
			this->nButtonControl1->Size = System::Drawing::Size(68, 23);
			this->nButtonControl1->TabIndex = 2;
			this->nButtonControl1->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &VisCanvasHelp::nButtonControl1_Click);
			// 
			// VisCanvasHelp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(600, 153);
			this->Controls->Add(this->nButtonControl1);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(616, 192);
			this->MinimizeBox = false;
			this->Name = L"VisCanvasHelp";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Help";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void nButtonControl1_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 this->Close();
			 }
	private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {

				 try {
					 System::Diagnostics::Process::Start("https://github.com/BrennanBarni/VisCanvas");
				 } catch (...) {
					 // display an error message
					 System::Windows::Forms::DialogResult result = MessageBox::Show("WARNING: VisCanvas is unable to open the user manual. Either it does not exist or it has gone missing.", "Trouble Opening User Manual", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
					 if (result == System::Windows::Forms::DialogResult::OK)
					 {
						 System::Diagnostics::Process::Start("https://github.com/BrennanBarni/VisCanvas");
					 }
				 }
			 }
	};
}
