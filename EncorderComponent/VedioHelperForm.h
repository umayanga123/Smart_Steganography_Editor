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
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ button8;
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
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(294, 226);
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
			this->button4->Location = System::Drawing::Point(251, 29);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(118, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Encode Stream";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &VedioHelperForm::encode_stream_btn_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(251, 171);
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
			this->button6->Location = System::Drawing::Point(74, 110);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(128, 23);
			this->button6->TabIndex = 7;
			this->button6->Text = L"split/save";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &VedioHelperForm::split_and_save_btn_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(251, 110);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(118, 23);
			this->button7->TabIndex = 8;
			this->button7->Text = L"vedio info";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &VedioHelperForm::video_information_btn_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(74, 174);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(128, 20);
			this->numericUpDown1->TabIndex = 13;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(251, 68);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(89, 17);
			this->checkBox1->TabIndex = 14;
			this->checkBox1->Text = L"Hard Encode";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(251, 139);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(118, 23);
			this->button8->TabIndex = 15;
			this->button8->Text = L"play vedio";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &VedioHelperForm::Button8_Click);
			// 
			// VedioHelperForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(391, 261);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->numericUpDown1);
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
			this->Text = L"Vedio Menu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
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

			System::Boolean^ isChecked = checkBox1->Checked;
			int code = vedio_hepler.encodeQRCodeWithInVedio(qr_path, im_path, (bool)isChecked);

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

			System::Decimal framNumber = numericUpDown1->Value;
			std::string output_path = msclr::interop::marshal_as<std::string>(ev_path);
			
			std::string msg = vedio_hepler.decodeQCodeFromVedio(output_path, (int)framNumber);
			String^ str2 = gcnew String(msg.c_str());
			MessageBox::Show("End Process", "title", MessageBoxButtons::OK);
		}

		/*Split vedio stream to frames set and save*/
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
	private: System::Void Button8_Click(System::Object^ sender, System::EventArgs^ e) {
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
		vedio_hepler.playVedio(e_path);
	}
};
}

#endif
