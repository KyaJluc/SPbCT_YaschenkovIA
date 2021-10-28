#pragma once
#include "table.h"
#include <ctime>
#include <iostream>
#include "stroka.h"
#include "autotable.h"
#include "sorttable.h"

namespace lab14 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:

	protected:

	protected:
	private: System::Windows::Forms::TextBox^ N;
	private: System::Windows::Forms::TextBox^ M;
	private: System::Windows::Forms::DataGridView^ Table;
	private: System::Windows::Forms::TextBox^ Stroka;
	private: System::Windows::Forms::TextBox^ Sto;
	private: System::Windows::Forms::DataGridView^ Table1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DataGridView^ Table2;
	private: System::Windows::Forms::Label^ label7;







	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->N = (gcnew System::Windows::Forms::TextBox());
			this->M = (gcnew System::Windows::Forms::TextBox());
			this->Table = (gcnew System::Windows::Forms::DataGridView());
			this->Stroka = (gcnew System::Windows::Forms::TextBox());
			this->Sto = (gcnew System::Windows::Forms::TextBox());
			this->Table1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->Table2 = (gcnew System::Windows::Forms::DataGridView());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(285, 295);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Выполнить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// N
			// 
			this->N->Location = System::Drawing::Point(113, 235);
			this->N->Name = L"N";
			this->N->Size = System::Drawing::Size(100, 20);
			this->N->TabIndex = 1;
			this->N->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::N_KeyPress);
			// 
			// M
			// 
			this->M->Location = System::Drawing::Point(133, 267);
			this->M->Name = L"M";
			this->M->Size = System::Drawing::Size(100, 20);
			this->M->TabIndex = 2;
			this->M->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::M_KeyPress);
			// 
			// Table
			// 
			this->Table->AllowUserToDeleteRows = false;
			this->Table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table->ColumnHeadersVisible = false;
			this->Table->Location = System::Drawing::Point(12, 31);
			this->Table->Name = L"Table";
			this->Table->ReadOnly = true;
			this->Table->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Table->RowHeadersVisible = false;
			this->Table->Size = System::Drawing::Size(305, 198);
			this->Table->TabIndex = 3;
			// 
			// Stroka
			// 
			this->Stroka->Location = System::Drawing::Point(296, 258);
			this->Stroka->Name = L"Stroka";
			this->Stroka->ReadOnly = true;
			this->Stroka->Size = System::Drawing::Size(199, 20);
			this->Stroka->TabIndex = 4;
			// 
			// Sto
			// 
			this->Sto->Location = System::Drawing::Point(167, 297);
			this->Sto->Name = L"Sto";
			this->Sto->Size = System::Drawing::Size(100, 20);
			this->Sto->TabIndex = 5;
			this->Sto->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::Sto_KeyPress);
			// 
			// Table1
			// 
			this->Table1->AllowUserToDeleteRows = false;
			this->Table1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table1->ColumnHeadersVisible = false;
			this->Table1->Location = System::Drawing::Point(328, 31);
			this->Table1->Name = L"Table1";
			this->Table1->ReadOnly = true;
			this->Table1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Table1->RowHeadersVisible = false;
			this->Table1->Size = System::Drawing::Size(305, 198);
			this->Table1->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(9, 236);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 17);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Кол-во строк:\r\n";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(5, 270);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(122, 17);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Кол-во столбцов:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(5, 298);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(156, 17);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Номер нужной строки:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(337, 238);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(116, 17);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Строка таблицы\r\n";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(12, 11);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(65, 17);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Таблица";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(325, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(205, 17);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Таблица с автосумированием\r\n";
			// 
			// Table2
			// 
			this->Table2->AllowUserToDeleteRows = false;
			this->Table2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table2->ColumnHeadersVisible = false;
			this->Table2->Location = System::Drawing::Point(639, 31);
			this->Table2->Name = L"Table2";
			this->Table2->ReadOnly = true;
			this->Table2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Table2->RowHeadersVisible = false;
			this->Table2->Size = System::Drawing::Size(305, 198);
			this->Table2->TabIndex = 13;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(636, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(164, 17);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Таблица с сортировкой\r\n";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(950, 336);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->Table2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Table1);
			this->Controls->Add(this->Sto);
			this->Controls->Add(this->Stroka);
			this->Controls->Add(this->Table);
			this->Controls->Add(this->M);
			this->Controls->Add(this->N);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Stroka->Text = " ";
		try {
			srand(time(NULL));
			int n, m, sto;

			n = Convert::ToInt32(N->Text);
			m = Convert::ToInt32(M->Text);
			//////////////////////////
			int** tab = new int* [n];
			for (int i = 0; i < n; i++)
				tab[i] = new int[m];
			table t1(tab, n, m);
			tab[n - 1][m] = t1.filltable(&tab[0]);
			Table->ColumnCount = m;
			Table->RowCount = n;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					this->Table->Rows[i]->Cells[j]->Value = Convert::ToString(tab[i][j]);
			//////////////////////////
			sto = Convert::ToInt32(Sto->Text);
			int* s = new int[m];
			stroka s1(tab, n, m, sto, s);
			s[m] = s1.fillstroka(&s[0]);
			for (int i = 0; i < m; i++)
				Stroka->Text += " " + s[i];
			//////////////////////////
			m = m + 1;
			int** tab1 = new int* [n];
			for (int i = 0; i < n; i++)
				tab1[i] = new int[m];
			autotable t2(tab, n, m, tab1);
			tab1[n - 1][m] = t2.fillautotable(&tab1[0]);
			Table1->ColumnCount = m;
			Table1->RowCount = n;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					this->Table1->Rows[i]->Cells[j]->Value = Convert::ToString(tab1[i][j]);
			//////////////////////////
			m = m - 1;
			int** tab2 = new int* [n];
			for (int i = 0; i < n; i++)
				tab2[i] = new int[m];
			sorttable t3(tab, n, m, tab2);
			tab2[n - 1][m] = t3.fillsorttable(&tab2[0]);
			Table2->ColumnCount = m;
			Table2->RowCount = n;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					this->Table2->Rows[i]->Cells[j]->Value = Convert::ToString(tab2[i][j]);
		}
		catch (System::FormatException^ ex) {
			MessageBox::Show("Заполните все поля.", "Ошибка!",
				MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation);
		}
	}

	private: System::Void M_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar >= '0' && e->KeyChar <= '9') return;
		if (Char::IsControl(e->KeyChar)) {
			if (e->KeyChar == (Char)Keys::Enter)
				button1->Focus();
			return;
		}
		e->Handled = true;
	}

	private: System::Void N_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar >= '0' && e->KeyChar <= '9') return;
		if (Char::IsControl(e->KeyChar)) {
			if (e->KeyChar == (Char)Keys::Enter)
				button1->Focus();
			return;
		}
		e->Handled = true;
	}

	private: System::Void Sto_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar >= '0' && e->KeyChar <= '9') return;
		if (Char::IsControl(e->KeyChar)) {
			if (e->KeyChar == (Char)Keys::Enter)
				button1->Focus();
			return;
		}
		e->Handled = true;
	}
	};
}
