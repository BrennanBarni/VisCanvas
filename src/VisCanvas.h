#pragma once

namespace VisCanvas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for VisCanvas
	/// </summary>
	public ref class VisCanvas : public System::Windows::Forms::Form
	{
	public:
		VisCanvas(void)
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
		~VisCanvas()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  undoAllToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  undoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  redoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  classMenuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::Panel^  toolsPanel;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  classPanel;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  colorblindfilterToolStripMenuItem;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ToolStripMenuItem^  preferencesToolStripMenuItem1;



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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->undoAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->undoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->classMenuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorblindfilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsPanel = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->classPanel = (gcnew System::Windows::Forms::Panel());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->preferencesToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->toolsPanel->SuspendLayout();
			this->classPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->fileToolStripMenuItem, 
				this->editToolStripMenuItem, this->viewToolStripMenuItem, this->helpToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(946, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menustrip";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &VisCanvas::menuStrip1_ItemClicked);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->newToolStripMenuItem, 
				this->openToolStripMenuItem, this->saveToolStripMenuItem, this->saveAsToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::fileToolStripMenuItem_Click);
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->newToolStripMenuItem->Text = L"New";
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
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->saveAsToolStripMenuItem->Text = L"Save As";
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->undoAllToolStripMenuItem, 
				this->undoToolStripMenuItem, this->redoToolStripMenuItem});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// undoAllToolStripMenuItem
			// 
			this->undoAllToolStripMenuItem->Name = L"undoAllToolStripMenuItem";
			this->undoAllToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->undoAllToolStripMenuItem->Text = L"Undo All";
			// 
			// undoToolStripMenuItem
			// 
			this->undoToolStripMenuItem->Name = L"undoToolStripMenuItem";
			this->undoToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->undoToolStripMenuItem->Text = L"Undo";
			// 
			// redoToolStripMenuItem
			// 
			this->redoToolStripMenuItem->Name = L"redoToolStripMenuItem";
			this->redoToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->redoToolStripMenuItem->Text = L"Redo";
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolsToolStripMenuItem, 
				this->classMenuToolStripMenuItem, this->colorblindfilterToolStripMenuItem, this->preferencesToolStripMenuItem1});
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->Checked = true;
			this->toolsToolStripMenuItem->CheckOnClick = true;
			this->toolsToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(159, 22);
			this->toolsToolStripMenuItem->Text = L"Tools";
			this->toolsToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::toolsToolStripMenuItem_Click);
			// 
			// classMenuToolStripMenuItem
			// 
			this->classMenuToolStripMenuItem->Checked = true;
			this->classMenuToolStripMenuItem->CheckOnClick = true;
			this->classMenuToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->classMenuToolStripMenuItem->Name = L"classMenuToolStripMenuItem";
			this->classMenuToolStripMenuItem->Size = System::Drawing::Size(159, 22);
			this->classMenuToolStripMenuItem->Text = L"Class Menu";
			this->classMenuToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::classMenuToolStripMenuItem_Click);
			// 
			// colorblindfilterToolStripMenuItem
			// 
			this->colorblindfilterToolStripMenuItem->Name = L"colorblindfilterToolStripMenuItem";
			this->colorblindfilterToolStripMenuItem->Size = System::Drawing::Size(159, 22);
			this->colorblindfilterToolStripMenuItem->Text = L"Colorblind Filter";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::helpToolStripMenuItem_Click);
			// 
			// toolsPanel
			// 
			this->toolsPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->toolsPanel->Controls->Add(this->button4);
			this->toolsPanel->Controls->Add(this->button3);
			this->toolsPanel->Controls->Add(this->button2);
			this->toolsPanel->Controls->Add(this->button1);
			this->toolsPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->toolsPanel->Location = System::Drawing::Point(0, 24);
			this->toolsPanel->Name = L"toolsPanel";
			this->toolsPanel->Size = System::Drawing::Size(200, 515);
			this->toolsPanel->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(108, 32);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(68, 27);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Level";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &VisCanvas::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(18, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(68, 27);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Drag/Drop";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &VisCanvas::button1_Click);
			// 
			// classPanel
			// 
			this->classPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->classPanel->Controls->Add(this->checkBox5);
			this->classPanel->Controls->Add(this->checkBox4);
			this->classPanel->Controls->Add(this->checkBox3);
			this->classPanel->Controls->Add(this->checkBox2);
			this->classPanel->Controls->Add(this->checkBox1);
			this->classPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->classPanel->Location = System::Drawing::Point(746, 24);
			this->classPanel->Name = L"classPanel";
			this->classPanel->Size = System::Drawing::Size(200, 515);
			this->classPanel->TabIndex = 2;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(64, 124);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(60, 17);
			this->checkBox5->TabIndex = 4;
			this->checkBox5->Text = L"Class 5";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(64, 101);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(60, 17);
			this->checkBox4->TabIndex = 3;
			this->checkBox4->Text = L"Class 4";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(64, 78);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(60, 17);
			this->checkBox3->TabIndex = 2;
			this->checkBox3->Text = L"Class 3";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(64, 55);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(60, 17);
			this->checkBox2->TabIndex = 1;
			this->checkBox2->Text = L"Class 2";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(64, 32);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(60, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Class 1";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &VisCanvas::checkBox1_CheckedChanged);
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->textBox1->Location = System::Drawing::Point(200, 396);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(546, 143);
			this->textBox1->TabIndex = 3;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(18, 95);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(68, 27);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Sort Asc";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(108, 95);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(68, 27);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Sort Desc";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// preferencesToolStripMenuItem1
			// 
			this->preferencesToolStripMenuItem1->Name = L"preferencesToolStripMenuItem1";
			this->preferencesToolStripMenuItem1->Size = System::Drawing::Size(159, 22);
			this->preferencesToolStripMenuItem1->Text = L"Preferences";
			// 
			// VisCanvas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(946, 539);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->classPanel);
			this->Controls->Add(this->toolsPanel);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"VisCanvas";
			this->Text = L"VisCanvas";
			this->Load += gcnew System::EventHandler(this, &VisCanvas::VisCanvas_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolsPanel->ResumeLayout(false);
			this->classPanel->ResumeLayout(false);
			this->classPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void VisCanvas_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void toolsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

				 if (this->toolsToolStripMenuItem->Checked == false) {
					 this->toolsToolStripMenuItem->Checked = false;
				 } else {
					 this->toolsToolStripMenuItem->Checked == true;
				 }
				 this->toolsPanel->Visible = this->toolsToolStripMenuItem->Checked;


			 }
	private: System::Void fileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 // TODO: last used directory method
				 OpenFileDialog^ ofd = gcnew OpenFileDialog;
				 ofd->InitialDirectory=""; // NOTE "c:\\" for future reference.
				 ofd->Filter="Text Files (*.csv, *.txt, *text)|*.csv, *txt, *text|All Files (*.*)|*.*";
				 ofd->FilterIndex=1;
				 ofd->RestoreDirectory=true;

				 if(ofd->ShowDialog()==System::Windows::Forms::DialogResult::OK)
				 {
					 MessageBox::Show(ofd->FileName,"Path:");
				 }

			 }
	private: System::Void classMenuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

				 if (this->classMenuToolStripMenuItem->Checked == false) {
					 this->classMenuToolStripMenuItem->Checked = false;
				 } else {
					 this->classMenuToolStripMenuItem->Checked == true;
				 }
				 this->classPanel->Visible = this->classMenuToolStripMenuItem->Checked;

			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
