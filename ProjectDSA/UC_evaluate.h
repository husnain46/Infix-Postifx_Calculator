#pragma once
#include<cmath>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace {

	struct Node2 {
		int data;
		struct Node2* next;
	};
	struct Node2* top2 = nullptr;



	/// <summary>
	/// Summary for UC_evaluate
	/// </summary>
	public ref class UC_evaluate : public System::Windows::Forms::UserControl
	{
	public:
		UC_evaluate(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			errorLabel->Hide();
			gridView2->Hide();
			panelResult->Hide();
		}


		int top2_()
		{
			int val = top2->data;
			return val;
		}

		void push(Char val)
		{
			struct Node2* newNode = new Node2();
			newNode->data = val;
			newNode->next = top2;
			top2 = newNode;
		}

		void pop()
		{
			top2 = top2->next;
		}


		bool IsNumericDigit(Char C)
		{
			if (C >= '0' && C <= '9') 
				return true;
			else
				return false;
		}

		bool IsOperator(Char C)
		{
			if (C == '+' || C == '-' || C == '*' || C == '/' || C == '^' || C == '%')
				return true;
			else
				return false;
		}

		int PerformOperation(Char opt, int op1, int op2)
		{
			if (opt == '+')
			{
				return op1 + op2;
			}
			else if (opt == '-')
			{
				return op1 - op2;
			}
			else if (opt == '*')
			{
				return op1 * op2;
			}
			else if (opt == '/')
			{
				return op1 / op2;
			}
			else if (opt == '^')
			{
				return pow(op1,op2);
			}
			else if (opt == '%')
			{
				return op1 % op2;
			}
			else
			{
				errorLabel->Show();
				errorLabel->Text = "Unexpected Error! Please Enter the expression in proper format.";
			}
			return -1;
		}

		int EvaluatePostfix(String^ exp)
		{
			String^ stk = "";
			String^ st;
 			int j = 0;

			for (int k = 0; k < exp->Length / 2; k++)
			{
				gridView2->Rows->Add();
			}

			for (int i = 0; i < exp->Length; i++)
			{
				if (exp[i] == ' ' || exp[i] == ',') 
					continue;

				if (IsOperator(exp[i]))
				{

					gridView2->Rows[j]->Cells["inputColumn"]->Value = exp[i];

					int opd2 = top2_();
					pop();
					gridView2->Rows[j]->Cells["op2Column"]->Value = opd2;

					int opd1 = top2_();
					pop();
					gridView2->Rows[j]->Cells["op1Column"]->Value = opd1;

					int result = PerformOperation(exp[i], opd1, opd2);
					gridView2->Rows[j]->Cells["resultColumn"]->Value = result;

					push(result);

					st = opd1.ToString();
					int ind = stk->IndexOf(st);
					stk = stk->Remove(ind);

					stk += top2->data;
					gridView2->Rows[j]->Cells["stackColumn"]->Value = stk;
					j++;
				}
				else if (IsNumericDigit(exp[i]))
				{
					int operand = 0;
					while (i < exp->Length && IsNumericDigit(exp[i]))
					{
						operand = (operand * 10) + (exp[i] - '0');
						i++;
					}
					gridView2->Rows[j]->Cells["inputColumn"]->Value = operand;
					push(operand);
					stk += ",";
					stk += top2->data;
					
					if (j==0)
					{
						stk = stk->Replace(",", " ");
						stk = stk->Trim();
					}

					gridView2->Rows[j]->Cells["stackColumn"]->Value = stk;
					i--;
					j++;
				}
			}
			return top2_();
		}




	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UC_evaluate()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel2;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ evaluateBtn;
	private: System::Windows::Forms::TextBox^ inBox;





	private: System::Windows::Forms::Label^ errorLabel;
private: System::Windows::Forms::DataGridView^ gridView2;





private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Panel^ panelResult;





private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ inputColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ op1Column;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ op2Column;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ resultColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ stackColumn;












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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->evaluateBtn = (gcnew System::Windows::Forms::Button());
			this->inBox = (gcnew System::Windows::Forms::TextBox());
			this->errorLabel = (gcnew System::Windows::Forms::Label());
			this->gridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->inputColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->op1Column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->op2Column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->resultColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->stackColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panelResult = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridView2))->BeginInit();
			this->panelResult->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)));
			this->panel2->Controls->Add(this->label1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1054, 53);
			this->panel2->TabIndex = 30;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(454, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(191, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Postfix Evaluation";
			// 
			// evaluateBtn
			// 
			this->evaluateBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)));
			this->evaluateBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->evaluateBtn->FlatAppearance->BorderSize = 0;
			this->evaluateBtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->evaluateBtn->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->evaluateBtn->ForeColor = System::Drawing::Color::Cornsilk;
			this->evaluateBtn->Location = System::Drawing::Point(635, 87);
			this->evaluateBtn->Name = L"evaluateBtn";
			this->evaluateBtn->Size = System::Drawing::Size(88, 29);
			this->evaluateBtn->TabIndex = 28;
			this->evaluateBtn->Text = L"Evaluate";
			this->evaluateBtn->UseVisualStyleBackColor = false;
			this->evaluateBtn->Click += gcnew System::EventHandler(this, &UC_evaluate::evaluateBtn_Click);
			// 
			// inBox
			// 
			this->inBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.25F));
			this->inBox->Location = System::Drawing::Point(357, 88);
			this->inBox->Name = L"inBox";
			this->inBox->Size = System::Drawing::Size(242, 28);
			this->inBox->TabIndex = 27;
			// 
			// errorLabel
			// 
			this->errorLabel->AutoSize = true;
			this->errorLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->errorLabel->ForeColor = System::Drawing::Color::Red;
			this->errorLabel->Location = System::Drawing::Point(353, 145);
			this->errorLabel->Name = L"errorLabel";
			this->errorLabel->Size = System::Drawing::Size(230, 23);
			this->errorLabel->TabIndex = 31;
			this->errorLabel->Text = L"If Error! will be shown here.";
			// 
			// gridView2
			// 
			this->gridView2->BackgroundColor = System::Drawing::Color::White;
			this->gridView2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->gridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->gridView2->ColumnHeadersHeight = 40;
			this->gridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->gridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->inputColumn,
					this->op1Column, this->op2Column, this->resultColumn, this->stackColumn
			});
			this->gridView2->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle7->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.25F));
			dataGridViewCellStyle7->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle7->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle7->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle7->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->gridView2->DefaultCellStyle = dataGridViewCellStyle7;
			this->gridView2->GridColor = System::Drawing::Color::Black;
			this->gridView2->Location = System::Drawing::Point(257, 210);
			this->gridView2->Name = L"gridView2";
			dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle8->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"Arial", 14));
			dataGridViewCellStyle8->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle8->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle8->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle8->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->gridView2->RowHeadersDefaultCellStyle = dataGridViewCellStyle8;
			this->gridView2->RowHeadersWidth = 51;
			this->gridView2->RowTemplate->Height = 35;
			this->gridView2->RowTemplate->ReadOnly = true;
			this->gridView2->Size = System::Drawing::Size(612, 430);
			this->gridView2->TabIndex = 29;
			this->gridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UC_evaluate::gridView2_CellContentClick);
			// 
			// inputColumn
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->inputColumn->DefaultCellStyle = dataGridViewCellStyle2;
			this->inputColumn->HeaderText = L"Input";
			this->inputColumn->MinimumWidth = 6;
			this->inputColumn->Name = L"inputColumn";
			this->inputColumn->ReadOnly = true;
			this->inputColumn->Width = 90;
			// 
			// op1Column
			// 
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->op1Column->DefaultCellStyle = dataGridViewCellStyle3;
			this->op1Column->HeaderText = L"OP1";
			this->op1Column->MinimumWidth = 6;
			this->op1Column->Name = L"op1Column";
			this->op1Column->ReadOnly = true;
			this->op1Column->Width = 90;
			// 
			// op2Column
			// 
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->op2Column->DefaultCellStyle = dataGridViewCellStyle4;
			this->op2Column->HeaderText = L"OP2";
			this->op2Column->MinimumWidth = 6;
			this->op2Column->Name = L"op2Column";
			this->op2Column->ReadOnly = true;
			this->op2Column->Width = 90;
			// 
			// resultColumn
			// 
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->resultColumn->DefaultCellStyle = dataGridViewCellStyle5;
			this->resultColumn->HeaderText = L"Result";
			this->resultColumn->MinimumWidth = 6;
			this->resultColumn->Name = L"resultColumn";
			this->resultColumn->ReadOnly = true;
			this->resultColumn->Width = 90;
			// 
			// stackColumn
			// 
			this->stackColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			this->stackColumn->DefaultCellStyle = dataGridViewCellStyle6;
			this->stackColumn->HeaderText = L"Stack";
			this->stackColumn->MinimumWidth = 6;
			this->stackColumn->Name = L"stackColumn";
			this->stackColumn->ReadOnly = true;
			this->stackColumn->Width = 80;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::MediumBlue;
			this->label2->Location = System::Drawing::Point(5, 3);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 24);
			this->label2->TabIndex = 31;
			this->label2->Text = L"Answer:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.25F));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(91, 3);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 23);
			this->label3->TabIndex = 31;
			this->label3->Text = L"_____";
			// 
			// panelResult
			// 
			this->panelResult->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panelResult->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelResult->Controls->Add(this->label3);
			this->panelResult->Controls->Add(this->label2);
			this->panelResult->Location = System::Drawing::Point(357, 142);
			this->panelResult->Name = L"panelResult";
			this->panelResult->Size = System::Drawing::Size(187, 32);
			this->panelResult->TabIndex = 32;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Crimson;
			this->label4->Location = System::Drawing::Point(749, 87);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(282, 68);
			this->label4->TabIndex = 33;
			this->label4->Text = L"Note:  Add white space or comma after every \r\n          operand and operator.\r\n  "
				L"        e.g.   3,5,+\r\n                   3 5 +";
			// 
			// UC_evaluate
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->label4);
			this->Controls->Add(this->panelResult);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->evaluateBtn);
			this->Controls->Add(this->inBox);
			this->Controls->Add(this->errorLabel);
			this->Controls->Add(this->gridView2);
			this->Name = L"UC_evaluate";
			this->Size = System::Drawing::Size(1054, 646);
			this->Load += gcnew System::EventHandler(this, &UC_evaluate::UC_evaluate_Load);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridView2))->EndInit();
			this->panelResult->ResumeLayout(false);
			this->panelResult->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UC_evaluate_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void evaluateBtn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		gridView2->Rows->Clear();
		String^ in_exp;
		int result = 0;
		panelResult->Show();
		in_exp = inBox->Text;
		gridView2->Show();
		result = EvaluatePostfix(in_exp);
		String^ a;
		a = result.ToString();
		label3->Text = a;
	}
private: System::Void gridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
