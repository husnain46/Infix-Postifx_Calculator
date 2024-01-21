#pragma once

#include"UC_convert.h"
#include"UC_evaluate.h"

namespace ProjectDSA {

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
			//
			//TODO: Add the constructor code here
			//
			DateTime dt = DateTime::Now;
			label3->Text = dt.ToString("dd-MM-yyyy");
			UC_convert^ con = gcnew UC_convert();
			AddControlsToPanel(con);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelSide;
	protected:
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panelLeft;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panelControls;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->panelSide = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panelLeft = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panelControls = (gcnew System::Windows::Forms::Panel());
			this->panelLeft->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelSide
			// 
			this->panelSide->BackColor = System::Drawing::Color::White;
			this->panelSide->Location = System::Drawing::Point(0, 202);
			this->panelSide->Name = L"panelSide";
			this->panelSide->Size = System::Drawing::Size(10, 53);
			this->panelSide->TabIndex = 10;
			// 
			// panel2
			// 
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->ForeColor = System::Drawing::Color::Violet;
			this->panel2->Location = System::Drawing::Point(-45, 7);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(274, 124);
			this->panel2->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(4, 272);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(178, 53);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Evaluation";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(13, 202);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(166, 53);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Conversion";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// panelLeft
			// 
			this->panelLeft->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)));
			this->panelLeft->Controls->Add(this->panelSide);
			this->panelLeft->Controls->Add(this->panel2);
			this->panelLeft->Controls->Add(this->button2);
			this->panelLeft->Controls->Add(this->button1);
			this->panelLeft->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelLeft->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->panelLeft->Location = System::Drawing::Point(0, 0);
			this->panelLeft->Name = L"panelLeft";
			this->panelLeft->Size = System::Drawing::Size(186, 511);
			this->panelLeft->TabIndex = 11;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(186, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(841, 50);
			this->panel1->TabIndex = 12;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15, System::Drawing::FontStyle::Underline));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)));
			this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label3->Location = System::Drawing::Point(699, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(128, 23);
			this->label3->TabIndex = 5;
			this->label3->Text = L"dd-MM-yyyy";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)));
			this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label1->Location = System::Drawing::Point(14, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(318, 24);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Data Structures and Algorithm";
			// 
			// panelControls
			// 
			this->panelControls->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelControls->Location = System::Drawing::Point(186, 50);
			this->panelControls->Name = L"panelControls";
			this->panelControls->Size = System::Drawing::Size(841, 461);
			this->panelControls->TabIndex = 13;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1027, 511);
			this->Controls->Add(this->panelControls);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panelLeft);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Infix-Postfix App";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panelLeft->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		private: void moveSidePanel(Control^ btn)
		{
			panelSide->Top = btn->Top;
			panelSide->Height = btn->Height;
		}

		private: void AddControlsToPanel(Control^ c)
		{
			c->Dock = DockStyle::Fill;
			panelControls->Controls->Clear();
			panelControls->Controls->Add(c);
		}

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		moveSidePanel(button1);
		UC_convert^ con = gcnew UC_convert();
		AddControlsToPanel(con);
	}
	
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		moveSidePanel(button2);
		UC_evaluate^ evl = gcnew UC_evaluate();
		AddControlsToPanel(evl);
	}
};
}
