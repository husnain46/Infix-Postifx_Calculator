#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace {

	struct Node {
		Char data;
		struct Node* next;
	};
	struct Node* top = nullptr;

	/// <summary>
	/// Summary for UC_convert
	/// </summary>
	public ref class UC_convert : public System::Windows::Forms::UserControl
	{
	public:
		UC_convert(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			gView->Hide();
		}


		void push(Char val)
		{
			struct Node* newnode = new Node();
			newnode->data = val;
			newnode->next = top;
			top = newnode;
		}

		void pop()
		{
			top = top->next;
		}


		bool is_Operator(Char opt)
		{
			if (opt == '+' || opt == '-' || opt == '*' || opt == '/' || opt == '^' || opt == '%')
			{
				return true;
			}
			return false;
		}

		bool is_Operand(Char opd)
		{
			if (opd >= 'A' && opd <= 'Z')
			{
				return true;
			}

			if (opd >= 'a' && opd <= 'z')
			{
				return true;
			}

			return false;
		}

		bool IsNumericDigit(Char opd)
		{
			if (opd >= '0' && opd <= '9')
				return true;
			else
				return false;
		}

		int opt_precedence(Char opt)
		{
			if (opt == '+' || opt == '-')
			{
				return 1;
			}

			if (opt == '*' || opt == '/' || opt == '%')
			{
				return 2;
			}

			if (opt == '^')
			{
				return 3;
			}

			return 0;
		}

		bool precedence_check(Char opt1, Char opt2)
		{
			int x = opt_precedence(opt1);
			int y = opt_precedence(opt2);

			if (x == y)
			{

				if (opt1 == '^')
				{
					return false;
				}
				return true;
			}

			if (x > y)
			{
				return true;
			}
			else
			{
				return false;
			}
		}


		String^ infix_postfix(String^ exp)
		{
			String^ postfix = "";
			Char c;
			String^ opt = "";
			int k = 0;

			//push(' ');

			for (int i = 0; i < exp->Length; i++)
			{
				gView->Rows->Add();
			}

			for (int j = 0; j < exp->Length; j++)
			{
				c = exp[j];

				gView->Rows[k]->Cells["stackColumn"]->Value = opt;
				gView->Rows[k]->Cells["inputColumn"]->Value = c;
				//label2->Text = c;

				if (c == ' ')
				{
					continue;
				}
				else if (c == '(')
				{
					push(c);
					opt += top->data;
					gView->Rows[k]->Cells["stackColumn"]->Value = opt;

				}
				else if (is_Operand(c))
				{
					postfix += c;

				}
				else if (IsNumericDigit(c))
				{
					int operand = 0;
					while (j < exp->Length && IsNumericDigit(exp[j]))
					{
						operand = (operand * 10) + (exp[j] - '0');
						j++;
					}

					gView->Rows[k]->Cells["inputColumn"]->Value = operand;
					postfix += " ";
					postfix += operand;
					j--;

				}
				else if (is_Operator(c))
				{
					opt += c;

					while (!top->data == '\0' && precedence_check(top->data, c))
					{
						postfix += top->data;
						String^ tk1;
						tk1 = c.ToString();
						//( + * -  
						int ind3 = opt->LastIndexOf(tk1);
						opt = opt->Remove(ind3 - 1, 1);

						pop();
					}

					push(c);

					gView->Rows[k]->Cells["stackColumn"]->Value = opt;

				}
				else if (c == ')')
				{
					while (!top->data == '\0' && top->data != '(')
					{
						postfix += top->data;
						pop();

					}
					opt += c;
					pop();

					int ind = 0, ind2 = 0;
					ind = opt->LastIndexOf("(");
					ind2 = opt->LastIndexOf(")");
					opt = opt->Remove(ind, (ind2 - ind) + 1);

					gView->Rows[k]->Cells["stackColumn"]->Value = opt;
				}

				gView->Rows[k]->Cells["outputColumn"]->Value = postfix;
				k++;
			}
			return postfix;
		}




	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UC_convert()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ gView;
	protected:



	private: System::Windows::Forms::Button^ convertBtn;
	private: System::Windows::Forms::TextBox^ inputBox;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ inputColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ stackColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ outputColumn;
private: System::Windows::Forms::Label^ label2;

























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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->gView = (gcnew System::Windows::Forms::DataGridView());
			this->inputColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->stackColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->outputColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->convertBtn = (gcnew System::Windows::Forms::Button());
			this->inputBox = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gView))->BeginInit();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// gView
			// 
			this->gView->BackgroundColor = System::Drawing::Color::White;
			this->gView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 13.25F));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->gView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->gView->ColumnHeadersHeight = 40;
			this->gView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->inputColumn, this->stackColumn,
					this->outputColumn
			});
			this->gView->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle5->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->gView->DefaultCellStyle = dataGridViewCellStyle5;
			this->gView->GridColor = System::Drawing::Color::Black;
			this->gView->Location = System::Drawing::Point(364, 191);
			this->gView->Name = L"gView";
			this->gView->ReadOnly = true;
			dataGridViewCellStyle6->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->gView->RowHeadersDefaultCellStyle = dataGridViewCellStyle6;
			this->gView->RowHeadersWidth = 51;
			this->gView->RowTemplate->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.25F));
			this->gView->RowTemplate->Height = 35;
			this->gView->RowTemplate->ReadOnly = true;
			this->gView->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->gView->Size = System::Drawing::Size(387, 404);
			this->gView->TabIndex = 24;
			// 
			// inputColumn
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->inputColumn->DefaultCellStyle = dataGridViewCellStyle2;
			this->inputColumn->HeaderText = L"Input";
			this->inputColumn->MinimumWidth = 6;
			this->inputColumn->Name = L"inputColumn";
			this->inputColumn->ReadOnly = true;
			this->inputColumn->Width = 82;
			// 
			// stackColumn
			// 
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->stackColumn->DefaultCellStyle = dataGridViewCellStyle3;
			this->stackColumn->HeaderText = L"Stack";
			this->stackColumn->MinimumWidth = 6;
			this->stackColumn->Name = L"stackColumn";
			this->stackColumn->ReadOnly = true;
			this->stackColumn->Width = 88;
			// 
			// outputColumn
			// 
			this->outputColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			this->outputColumn->DefaultCellStyle = dataGridViewCellStyle4;
			this->outputColumn->HeaderText = L"Output";
			this->outputColumn->MinimumWidth = 6;
			this->outputColumn->Name = L"outputColumn";
			this->outputColumn->ReadOnly = true;
			this->outputColumn->Width = 94;
			// 
			// convertBtn
			// 
			this->convertBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)));
			this->convertBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->convertBtn->FlatAppearance->BorderSize = 0;
			this->convertBtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->convertBtn->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12.25F));
			this->convertBtn->ForeColor = System::Drawing::Color::White;
			this->convertBtn->Location = System::Drawing::Point(655, 99);
			this->convertBtn->Name = L"convertBtn";
			this->convertBtn->Size = System::Drawing::Size(86, 31);
			this->convertBtn->TabIndex = 23;
			this->convertBtn->Text = L"Convert";
			this->convertBtn->UseVisualStyleBackColor = false;
			this->convertBtn->Click += gcnew System::EventHandler(this, &UC_convert::convertBtn_Click);
			// 
			// inputBox
			// 
			this->inputBox->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inputBox->Location = System::Drawing::Point(377, 99);
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(248, 31);
			this->inputBox->TabIndex = 22;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)));
			this->panel3->Controls->Add(this->label1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1054, 53);
			this->panel3->TabIndex = 21;
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
			this->label1->Location = System::Drawing::Point(442, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(237, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Infix-Postfix Converter";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Crimson;
			this->label2->Location = System::Drawing::Point(767, 99);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(287, 34);
			this->label2->TabIndex = 25;
			this->label2->Text = L"Note:  Enclose the expression in round brackets\r\n          e.g. (expresion)";
			// 
			// UC_convert
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->label2);
			this->Controls->Add(this->gView);
			this->Controls->Add(this->convertBtn);
			this->Controls->Add(this->inputBox);
			this->Controls->Add(this->panel3);
			this->Name = L"UC_convert";
			this->Size = System::Drawing::Size(1054, 598);
			this->Load += gcnew System::EventHandler(this, &UC_convert::UC_convert_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gView))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UC_convert_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void convertBtn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		gView->Rows->Clear();
		String^ in_exp;
		String^ post_exp;

		in_exp = inputBox->Text;
		gView->Show();
		post_exp = infix_postfix(in_exp);
	}
};
}
