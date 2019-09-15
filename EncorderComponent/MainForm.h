#pragma once
#include "ImageTest.cpp"
#include "msclr\marshal_cppstd.h"
#include "EncoderAlgo.cpp"
#include "DecoderAlgo.cpp"
#include "ImageViwer.cpp"

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
	private: System::Windows::Forms::Button^ viewImageBtn;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ encodeBtn;
	private: System::Windows::Forms::Button^ decodeBtn;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
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
			this->viewImageBtn = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->encodeBtn = (gcnew System::Windows::Forms::Button());
			this->decodeBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(126, 31);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(279, 20);
			this->textBox1->TabIndex = 0;
			// 
			// viewImageBtn
			// 
			this->viewImageBtn->Location = System::Drawing::Point(441, 191);
			this->viewImageBtn->Name = L"viewImageBtn";
			this->viewImageBtn->Size = System::Drawing::Size(150, 23);
			this->viewImageBtn->TabIndex = 2;
			this->viewImageBtn->Text = L"View Image";
			this->viewImageBtn->UseVisualStyleBackColor = true;
			this->viewImageBtn->Click += gcnew System::EventHandler(this, &MainForm::viewImageBtn_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(516, 356);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Exit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::exitBtn_Click);
			// 
			// encodeBtn
			// 
			this->encodeBtn->Location = System::Drawing::Point(441, 31);
			this->encodeBtn->Name = L"encodeBtn";
			this->encodeBtn->Size = System::Drawing::Size(150, 23);
			this->encodeBtn->TabIndex = 4;
			this->encodeBtn->Text = L"Encode";
			this->encodeBtn->UseVisualStyleBackColor = true;
			this->encodeBtn->Click += gcnew System::EventHandler(this, &MainForm::encodeBtn_Click);
			// 
			// decodeBtn
			// 
			this->decodeBtn->Location = System::Drawing::Point(441, 67);
			this->decodeBtn->Name = L"decodeBtn";
			this->decodeBtn->Size = System::Drawing::Size(150, 23);
			this->decodeBtn->TabIndex = 5;
			this->decodeBtn->Text = L"Decode";
			this->decodeBtn->UseVisualStyleBackColor = true;
			this->decodeBtn->Click += gcnew System::EventHandler(this, &MainForm::decodeBtn_Click);
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
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(15, 67);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(390, 147);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(621, 391);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->decodeBtn);
			this->Controls->Add(this->encodeBtn);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->viewImageBtn);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MainForm";
			this->Text = L"Steganography Application";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
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
	private: System::Void viewImageBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ path;
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (openFileDialog->OpenFile() != nullptr) {
				path = openFileDialog->InitialDirectory + openFileDialog->FileName;
			}
		}

		if (path == nullptr) {
			return;
		}
		std::string new_path = msclr::interop::marshal_as<std::string>(path);

		ImageViwer imageViwer;
		imageViwer.showImage(new_path);
	}
	private: System::Void exitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		_Exit(10);
	}


	private: System::Void encodeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ path;
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (openFileDialog->OpenFile() != nullptr) {
				path = openFileDialog->InitialDirectory + openFileDialog->FileName;
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
			Bitmap^ bmp = gcnew Bitmap(path);
			pictureBox1->Image = bmp;
			pictureBox1->SizeMode = PictureBoxSizeMode::CenterImage;

		}
		else {
			MessageBox::Show("error code :" +i);
		}
	}
	private: System::Void decodeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
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
