#ifndef MAIN_H
#define MAIN_H

#include "msclr\marshal_cppstd.h"
#include "EncoderAlgo.cpp"
#include "DecoderAlgo.cpp"
#include "LSB_Vedio_Encoder.cpp"
#include "LSB_Vedio_Decoder.cpp"
#include "ImageHelperForm.h"
#include "VedioHelperForm.h"



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
		private: System::Windows::Forms::Button^ button3;
		private: System::Windows::Forms::Button^ encodeBtn;
		private: System::Windows::Forms::Button^ decodeBtn;
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
		private: System::Windows::Forms::PictureBox^ pictureBox1;
		private: System::Windows::Forms::Button^ button2;
		private: System::Windows::Forms::Button^ button4;
	    private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	    private: System::Windows::Forms::Button^ button5;
	    private: System::Windows::Forms::Button^ button6;
	    private: System::ComponentModel::IContainer^ components;
	    

		private:void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->encodeBtn = (gcnew System::Windows::Forms::Button());
			this->decodeBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
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
			// button3
			// 
			this->button3->Location = System::Drawing::Point(360, 331);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Exit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::exitBtn_Click);
			// 
			// encodeBtn
			// 
			this->encodeBtn->Location = System::Drawing::Point(285, 67);
			this->encodeBtn->Name = L"encodeBtn";
			this->encodeBtn->Size = System::Drawing::Size(150, 23);
			this->encodeBtn->TabIndex = 4;
			this->encodeBtn->Text = L"LSB Encode";
			this->encodeBtn->UseVisualStyleBackColor = true;
			this->encodeBtn->Click += gcnew System::EventHandler(this, &MainForm::encodeBtn_Click);
			// 
			// decodeBtn
			// 
			this->decodeBtn->Location = System::Drawing::Point(285, 106);
			this->decodeBtn->Name = L"decodeBtn";
			this->decodeBtn->Size = System::Drawing::Size(150, 23);
			this->decodeBtn->TabIndex = 5;
			this->decodeBtn->Text = L"LSB Decode";
			this->decodeBtn->UseVisualStyleBackColor = true;
			this->decodeBtn->Click += gcnew System::EventHandler(this, &MainForm::decodeBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Enter Secret Text:";
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			this->openFileDialog->Title = L"select image";
			this->openFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::OpenFileDialog_FileOk);
			// 
			// pictureBox1
			// 
		
			
			//pictureBox1->Image = bmp;
		    pictureBox1->SizeMode = PictureBoxSizeMode::CenterImage;
		    Bitmap^ bmp = gcnew Bitmap("ic_launcher.bmp");
			//resources->GetObject("ic_launcher");
			this->pictureBox1->Image = gcnew Bitmap("ic_launcher.bmp");

			this->pictureBox1->Location = System::Drawing::Point(126, 67);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(142, 139);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MainForm::PictureBox1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(285, 209);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"LSB V E";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::LSB_V_E_Btn);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(285, 238);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(150, 23);
			this->button4->TabIndex = 11;
			this->button4->Text = L"LSB V D";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::LSB_V_D_Btn);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(172, 212);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(96, 20);
			this->numericUpDown1->TabIndex = 12;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MainForm::NumericUpDown1_ValueChanged);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(110, 287);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(148, 23);
			this->button5->TabIndex = 13;
			this->button5->Text = L"Image Encode/Decode";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::Image_Form_Open_Btn_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(274, 287);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(165, 23);
			this->button6->TabIndex = 14;
			this->button6->Text = L"Vedio Encode/Decode";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MainForm::Vedio_Form_Open_Btn_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(461, 375);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->decodeBtn);
			this->Controls->Add(this->encodeBtn);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MainForm";
			this->Text = L"SVSM Encoder Application";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		/*Exit from System*/
		private: System::Void exitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			_Exit(10);
		}

        /*LSB image Encode*/
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
				//Bitmap^ bmp = gcnew Bitmap(path);
				//pictureBox1->Image = bmp;
				//pictureBox1->SizeMode = PictureBoxSizeMode::CenterImage;

			}
			else {
				MessageBox::Show("error code :" +i);
			}
		}

		/*LSB image Decode*/
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

		

        /*LSB Vedio Encode*/
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

        /*LSB vedio decoder*/
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

		private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		}

		private: System::Void OpenFileDialog_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
		}

		private: System::Void PictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		}

		//Open new Image Form
		private: System::Void Image_Form_Open_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			ImageHelperComponent::ImageHelperForm Imageform;
			Imageform.ShowDialog();
		}

	    //Open new Vedio Form
		private: System::Void Vedio_Form_Open_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			VedioHelperComponent::VedioHelperForm Vedioform;
			Vedioform.ShowDialog();
		}
	};
}


#endif