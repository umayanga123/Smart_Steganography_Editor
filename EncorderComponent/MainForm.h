#pragma once
#include "ImageTest.cpp"
#include "msclr\marshal_cppstd.h"
#include "EncoderAlgo.cpp"
#include "DecoderAlgo.cpp"

namespace MainComponent {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(126, 31);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(210, 20);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(36, 324);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"ok";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::Button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(186, 125);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"View Image";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::Button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(261, 324);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Exit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::Button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(186, 67);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(150, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Encode";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::Button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(186, 96);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(150, 23);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Decode";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::Button5_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Enter Secrect Text:";
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			this->openFileDialog->Title = L"select image";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(364, 359);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MainForm";
			this->Text = L"Steganography Application";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ message = "Hello ";
		String^ title = "Welcome";
		Char a = '!'; //A managed character
		MessageBox::Show("message" + textBox1->Text + a, "title", MessageBoxButtons::OK);

	}
	private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Test test;
		test.A();
	}
	private: System::Void Button3_Click(System::Object^ sender, System::EventArgs^ e) {
		_Exit(10);
	}


	private: System::Void Button4_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ path;
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (openFileDialog->OpenFile() != nullptr) {
				path = openFileDialog->InitialDirectory + openFileDialog->FileName;
				//MessageBox::Show("Secret Message :" + path, "title", MessageBoxButtons::OK);
			}
		}

		if (path == nullptr) {
			return;
		}
		std::string new_path = msclr::interop::marshal_as<std::string>(path);
		System::String^ name = textBox1->Text;
		if (name->Length < 1) {
			MessageBox::Show("please enter secrect text", "title", MessageBoxButtons::OK);
			return;
		}

		std::string s_text = msclr::interop::marshal_as<std::string>(textBox1->Text);
		EncorderAlgo encorder;
		int i = encorder.LSB_encoder(s_text , new_path);
		if (i == 0) {
			MessageBox::Show("sucssfully encorded image", "title", MessageBoxButtons::OK);
		}
		else {
			MessageBox::Show("error code :" +i);
		}
	}
	private: System::Void Button5_Click(System::Object^ sender, System::EventArgs^ e) {
		DecorderAlgo decorder;
		String^ path;

		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (openFileDialog->OpenFile() != nullptr) {
				path = openFileDialog->InitialDirectory + openFileDialog->FileName;
			}
		}

		if (path == nullptr) {

			return;
		}

	
		std::string output_path = msclr::interop::marshal_as<std::string>(path);
		std::string msg = decorder.LSB_decoder(output_path);
		String^ str2 = gcnew String(msg.c_str());
		MessageBox::Show("Secret Message :" + str2, "title", MessageBoxButtons::OK);
	}
};
}
