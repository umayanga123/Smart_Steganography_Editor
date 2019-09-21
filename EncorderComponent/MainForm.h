#ifndef MAIN_H
#define MAIN_H

#include "ImageTest.cpp"
#include "msclr\marshal_cppstd.h"
#include "EncoderAlgo.cpp"
#include "DecoderAlgo.cpp"
#include "ImageViwer.cpp"
#include "VideoHelperTest.cpp"
#include "LSB_Vedio_Encoder.cpp"
#include "LSB_Vedio_Decoder.cpp"

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
		private: System::Windows::Forms::Button^ testBtn;
		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::Button^ button2;
		private: System::Windows::Forms::Button^ button4;
	    private: System::Windows::Forms::NumericUpDown^ numericUpDown1;

	    private: System::ComponentModel::IContainer^ components;
	
		
	
		private:void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->viewImageBtn = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->encodeBtn = (gcnew System::Windows::Forms::Button());
			this->decodeBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->testBtn = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(126, 31);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(309, 20);
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
			this->pictureBox1->Location = System::Drawing::Point(12, 67);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(333, 147);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// testBtn
			// 
			this->testBtn->Location = System::Drawing::Point(15, 356);
			this->testBtn->Name = L"testBtn";
			this->testBtn->Size = System::Drawing::Size(89, 23);
			this->testBtn->TabIndex = 8;
			this->testBtn->Text = L"Test";
			this->testBtn->UseVisualStyleBackColor = true;
			this->testBtn->Click += gcnew System::EventHandler(this, &MainForm::TestBtn_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(126, 356);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"decode_text";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::Button1_Click_1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(441, 111);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"LSB V E";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::LSB_V_E_Btn);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(441, 151);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(150, 23);
			this->button4->TabIndex = 11;
			this->button4->Text = L"LSB V D";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::LSB_V_D_Btn);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(351, 154);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(84, 20);
			this->numericUpDown1->TabIndex = 12;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MainForm::NumericUpDown1_ValueChanged);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(621, 391);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->testBtn);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


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

		private: System::Void TestBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			VideoHelper vedioHelper;
			//vedioHelper.decodeFrames();
			int i = vedioHelper.splitFrames();
			if (i == 0) {
			  MessageBox::Show("Finish Operation");
			}
		}

		private: System::Void Button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
			VideoHelper vedioHelper;
			vedioHelper.decodeFrames();

		}


	private: System::Void LSB_V_E_Btn(System::Object^ sender, System::EventArgs^ e) {
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
		LSB_Vedio_Encoder lsb_encorder;
		int i = lsb_encorder.encodeFrames(new_path ,s_text);
		if (i == 0) {
				MessageBox::Show("sucssfully LSB encorded vedio", "title", MessageBoxButtons::OK);
			}
			else {
				MessageBox::Show("error code :" + i);
			}

		}


		private: System::Void LSB_V_D_Btn(System::Object^ sender, System::EventArgs^ e) {
			LSB_Vedio_Decoder LSB_decorder;
			String^ path;

			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				if (openFileDialog->OpenFile() != nullptr) {
					path = openFileDialog->InitialDirectory + openFileDialog->FileName;
				}
			}

			if (path == nullptr) {

				return;
			}

			System::Decimal framNumber =  numericUpDown1->Value;
			std::string output_path = msclr::interop::marshal_as<std::string>(path);
			std::string msg = LSB_decorder.decodeFrames(output_path ,(int)framNumber);
			String^ str2 = gcnew String(msg.c_str());
			MessageBox::Show("Secret Message :" + str2, "title", MessageBoxButtons::OK);
		}

		
	private: System::Void NumericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {


	}
};
}


#endif