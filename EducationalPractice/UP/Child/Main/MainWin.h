#pragma once
#include "lib.h"
#include <fstream>
#include <string>
#include <windows.h>
#include <iostream>
#include <msclr\marshal_cppstd.h>


namespace Main {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// ������ ��� MainWin
	/// </summary>
	public ref class MainWin : public System::Windows::Forms::Form
	{
	public:
		MainWin(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MainWin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;




	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(13, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(184, 26);
			this->button1->TabIndex = 0;
			this->button1->Text = L"������� ������ �� �����";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainWin::button1_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(203, 13);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(184, 26);
			this->button3->TabIndex = 2;
			this->button3->Text = L"�������� ������� ReadOnly";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MainWin::button3_Click);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Location = System::Drawing::Point(12, 138);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(375, 292);
			this->label1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Location = System::Drawing::Point(12, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(375, 64);
			this->label2->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(15, 109);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(374, 26);
			this->button2->TabIndex = 5;
			this->button2->Text = L"��������� ���������� � ������������� ������";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainWin::button2_Click);
			// 
			// MainWin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(401, 439);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MainWin";
			this->Text = L"�������";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		ifstream fh("text.txt");
		string s;
		fh >> s;
		String^ str = gcnew String(s.c_str());
		label2->Text = str;
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	SetFileAttributes(L"text.txt", FILE_ATTRIBUTE_READONLY);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ str = label2->Text;
	string st = msclr::interop::marshal_as<std::string>(str);
	SECURITY_ATTRIBUTES sa;//�������� ������ ������
	sa.lpSecurityDescriptor = NULL; //������ �� ���������
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = true;//��������� ������������ ������������
	//����������� ������
	HANDLE child_in, parent_out, child_out, parent_in;
	//��������� ������
	SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOOPENFILEERRORBOX | SEM_NOALIGNMENTFAULTEXCEPT);
	//������� ��������� ������
	CreatePipe(&parent_out, &child_in, &sa, 0); //����� ��� stdin ��������� ��������
	CreatePipe(&child_out, &parent_in, &sa, 0); //����� ��� stdout ��������� ��������
	//startupinfo ��� ��������� ��������
	STARTUPINFO si;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;//�������� ���� ��������� ��������
	//��������� �����������
	si.hStdOutput = parent_in;
	si.hStdError = parent_in;
	si.hStdInput = parent_out;
	PROCESS_INFORMATION pi;
	CreateProcess(L"Child.exe", NULL, NULL, NULL, TRUE, ABOVE_NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi);

	DWORD num;//���������� ���������/���������� ����
	char buf[1024] = {};//����� ��� ������ ������
	char w[255];
	strcpy(w, st.c_str());//������������ ��������
	//int sz = int(sizeof(w) / sizeof(WCHAR));

	//�������� ������
	WriteFile(child_in, w, 255, &num, NULL);
	CloseHandle(child_in);//��������� ����� stdin ��������� ��������

	//������ ������
	ReadFile(child_out, buf, 1023, &num, NULL);
	CloseHandle(parent_out);//��������� ������������ ����������� ����

	//������ �� �����
	CloseHandle(parent_in);
	CloseHandle(child_out);
	//TerminateProcess(pi.hProcess, 0);//������� �������� �������
	//CloseHandle(pi.hProcess);
	//CloseHandle(pi.hThread);

	string res = string(buf);
	String^ Res = gcnew String(res.c_str());
	label1->Text = Res;

}
};
}
