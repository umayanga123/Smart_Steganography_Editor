#ifndef VEDIO_H
#define VEDIO_H

#include "VedioHelper.cpp"
#include "msclr\marshal_cppstd.h"


namespace VedioHelperComponent {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// Summary for VedioHelperForm
	public ref class VedioHelperForm : public System::Windows::Forms::Form
	{
	public:
		VedioHelperForm(void)
		{
			InitializeComponent();	
			//TODO: Add the constructor code her		
		}

	protected:
		
		/// Clean up any resources being used.
		~VedioHelperForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	protected:
	public: String^ vedio_path;
	public: String^ qr_path;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	public:

	private:

		/// Required designer variable.
		System::ComponentModel::Container ^components;


	
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(270, 226);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &VedioHelperForm::back_Btn_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(21, 30);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Vedio File";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &VedioHelperForm::open_vedio_btn_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(127, 30);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"QR Code";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &VedioHelperForm::open_qr_code_btn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(102, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(13, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"+";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(219, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"=";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(238, 29);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(118, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Encode Stream";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &VedioHelperForm::encode_stream_btn_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(238, 136);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(118, 23);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Decode Stream";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &VedioHelperForm::decode_stream_btn_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(21, 91);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(128, 23);
			this->button6->TabIndex = 7;
			this->button6->Text = L"split/save";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &VedioHelperForm::split_and_save_btn_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(21, 136);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(128, 23);
			this->button7->TabIndex = 8;
			this->button7->Text = L"vedio info";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &VedioHelperForm::video_information_btn_Click);
			// 
			// VedioHelperForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(372, 261);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"VedioHelperForm";
			this->Text = L"VedioHelperForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

        /*close window*/
		private: System::Void back_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
			this->~VedioHelperForm();
		}

	    /*Open Vedio file*/
	    private: System::Void open_vedio_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				if (openFileDialog1->OpenFile() != nullptr) {
					vedio_path = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
				}
			}
			if (vedio_path == nullptr) {
				return;
			}
		}

		/*Open QR code*/
        private: System::Void open_qr_code_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				if (openFileDialog1->OpenFile() != nullptr) {
					qr_path = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
				}
			}
			if (qr_path == nullptr) {
				return;
			}
		}

		/*encode Vedio Stream*/
		private: System::Void encode_stream_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			VedioHelper vedio_hepler;
			System::String^ q_path = qr_path;
			std::string qr_path = msclr::interop::marshal_as<std::string>(q_path);

			System::String^ v_path = vedio_path;
			std::string im_path = msclr::interop::marshal_as<std::string>(v_path);

			int code = vedio_hepler.encodeQRCodeWithInVedio(qr_path, im_path);

			if (code == 0) {
				MessageBox::Show("Vedio Encode Complete", "Encode Complete", MessageBoxButtons::OK);
			}
			else {
				MessageBox::Show("error code :" + code);
			}

		}

        /*Decode Vedio Stream*/
		private: System::Void decode_stream_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			VedioHelper vedio_hepler;
			System::String^ ev_path;

			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				if (openFileDialog1->OpenFile() != nullptr) {
					ev_path = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
				}
			}
			if (ev_path == nullptr) {
				return;
			}


			std::string e_path = msclr::interop::marshal_as<std::string>(ev_path);
			String^ code = vedio_hepler.decodeQCodeFromVedio(e_path);
			//String^ msg = gcnew String(code.c_str());

			if (code == "ERROR") {
				MessageBox::Show("ERROR");
			}
			else {
				MessageBox::Show("Message :" + code);
			}


		}

		/*Split vedio stream to frams set and save*/
		private: System::Void split_and_save_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			VedioHelper vedio_hepler;
			System::String^ v_path;

			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				if (openFileDialog1->OpenFile() != nullptr) {
					v_path = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
				}
			}
			if (v_path == nullptr) {
				return;
			}


			std::string e_path = msclr::interop::marshal_as<std::string>(v_path);
			int code = vedio_hepler.extract_frames(e_path);
		
			if (code == 0) {
				MessageBox::Show("Process Complete", "Process Complete", MessageBoxButtons::OK);
			}
			else {
				MessageBox::Show("ERROR :" + code);
			}
		}

	    /*vedio infromation*/
		private: System::Void video_information_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			VedioHelper vedio_hepler;
			System::String^ i_path;

			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				if (openFileDialog1->OpenFile() != nullptr) {
					i_path = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
				}
			}
			if (i_path == nullptr) {
				return;
			}


			std::string e_path = msclr::interop::marshal_as<std::string>(i_path);
			std::string code = vedio_hepler.informationOfVedio(e_path);
			String^ msg = gcnew String(code.c_str());

			if (msg == "ERROR") {
				MessageBox::Show("ERROR");
			}
			else {
				MessageBox::Show("Informations :" + msg);
			}
		}
	};
}

#endif
