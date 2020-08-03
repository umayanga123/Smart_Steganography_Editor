#ifndef IMAGE_H
#define IMAGE_H

#include "msclr\marshal_cppstd.h"
#include "ImageHelper.cpp"
#include "ImageViwer.cpp"

namespace ImageHelperComponent {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	// Summary for ImageHelperForm
	public ref class ImageHelperForm : public System::Windows::Forms::Form
	{
	public:
		ImageHelperForm(void)
		{
			InitializeComponent();
			//TODO: Add the constructor code here
		}

	protected:
		/// Clean up any resources being used.
		~ImageHelperForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ button2;
	
	
	public: String^ image_path;
	public: String^ qr_path;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ button9;

	private:

		/// Required designer variable.
		System::ComponentModel::Container ^components;


		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(281, 250);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ImageHelperForm::back_Btn_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(64, 38);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"QR code";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ImageHelperForm::open_Qr_Code_Btn_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(164, 38);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Image";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &ImageHelperForm::open_Image_Btn_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &ImageHelperForm::OpenFileDialog1_FileOk);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(281, 38);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Encode";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ImageHelperForm::encode_Btn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(262, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(13, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"=";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(145, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"+";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(64, 100);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(166, 23);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Image Info";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &ImageHelperForm::image_Info_Btn_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(64, 129);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(166, 23);
			this->button6->TabIndex = 8;
			this->button6->Text = L"Image To Channel";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &ImageHelperForm::convert_Image_Channel_Btn_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(64, 159);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(166, 23);
			this->button7->TabIndex = 9;
			this->button7->Text = L"Image To BW";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &ImageHelperForm::convert_Image_To_Bw_Btn_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(281, 221);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 10;
			this->button8->Text = L"Decode";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &ImageHelperForm::decode_Image_Btn_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(263, 77);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(89, 17);
			this->checkBox1->TabIndex = 11;
			this->checkBox1->Text = L"Hard Encode";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(64, 188);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(166, 23);
			this->button9->TabIndex = 12;
			this->button9->Text = L"color Hist";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &ImageHelperForm::Button9_Click);
			// 
			// ImageHelperForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(375, 285);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Name = L"ImageHelperForm";
			this->Text = L"Image Menu";
			this->Load += gcnew System::EventHandler(this, &ImageHelperForm::ImageHelperForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: 
		System::Void back_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
			this->~ImageHelperForm();
		}

	private: 
		System::Void open_Qr_Code_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
	  
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				if (openFileDialog1->OpenFile() != nullptr) {
					qr_path = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
				}
			}
			if (qr_path == nullptr) {
				return;
			}
		}

	private: 
		System::Void open_Image_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				if (openFileDialog1->OpenFile() != nullptr) {
					image_path = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
				}
			}
			if (image_path == nullptr) {
				return;
			}

		}

	private: System::Void OpenFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {

	}

    /*encode QR code incide blue channel*/
	private: 
		System::Void encode_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			ImageHelper image_hepler;
			ImageViwer imageViwer , imageViwer1;
			System::String^ q_path = qr_path;
			std::string qr_path = msclr::interop::marshal_as<std::string>(q_path);
		
			System::String^ i_path = image_path;
			std::string im_path = msclr::interop::marshal_as<std::string>(i_path);
			System::Boolean^ isChecked = checkBox1->Checked;
			int code= image_hepler.encodeQRCodeWithInImage(qr_path, im_path,(bool)isChecked);

			if (code == 0) {
				//imageViwer.showImage(qr_path);
				//imageViwer1.showImage(im_path);
				MessageBox::Show("Image Encode Complete", "Encode Complete", MessageBoxButtons::OK);
			}
			else {
				MessageBox::Show("error code :" + code);
			}
	
		}

	/*Decode given image and take QR code*/
	private: 
		System::Void decode_Image_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			ImageHelper image_hepler;
			System::String^ cam_imagr_path;
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				if (openFileDialog1->OpenFile() != nullptr) {
					cam_imagr_path = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
				}
			}
			if (cam_imagr_path == nullptr) {
				return;
			}

			//System::Boolean^ isChecked = checkBox1->Checked;
			std::string cam_image = msclr::interop::marshal_as<std::string>(cam_imagr_path);
			std::string code = image_hepler.decodeQRCodeFromImage(cam_image);

			String^ msg = gcnew String(code.c_str());
			MessageBox::Show("Decode Stego image is completed :" + msg, "Decode Stego Image", MessageBoxButtons::OK);
		}

	
	private: 
		System::Void ImageHelperForm_Load(System::Object^ sender, System::EventArgs^ e) {
		}

    /*Print image information to file*/
	private: 
		System::Void image_Info_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
		ImageHelper image_hepler;
		System::String^ info_path;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (openFileDialog1->OpenFile() != nullptr) {
				info_path = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
			}
		}
		if (info_path == nullptr) {
			return;
		}

		std::string image_info = msclr::interop::marshal_as<std::string>(info_path);
		int code =image_hepler.readImagePixel(image_info);

		if (code == 0) {
			MessageBox::Show("Create a Image Info file", "Image Information", MessageBoxButtons::OK);
		}
		else {
			MessageBox::Show("error code :" + code);
		}
	}

	/*Devide Image Into multiple channels*/
	private: 
		System::Void convert_Image_Channel_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			ImageHelper image_hepler;
			System::String^ channel_path;
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				if (openFileDialog1->OpenFile() != nullptr) {
					channel_path = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
				}
			}
			if (channel_path == nullptr) {
				return;
			}

			std::string image_channel = msclr::interop::marshal_as<std::string>(channel_path);
			int code = image_hepler.convertImageToChannel(image_channel);

			if (code == 0) {
				MessageBox::Show("Operation Complete", "Image Channels", MessageBoxButtons::OK);
			}
			else {
				MessageBox::Show("error code :" + code);
			}
		}

	private: 
		System::Void convert_Image_To_Bw_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			ImageHelper image_hepler;
			System::String^ rbg_path;
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				if (openFileDialog1->OpenFile() != nullptr) {
					rbg_path = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
				}
			}
			if (rbg_path == nullptr) {
				return;
			}

			std::string image_color = msclr::interop::marshal_as<std::string>(rbg_path);
			int code = image_hepler.convertImageToBW(image_color);

			if (code == 0) {
				MessageBox::Show("Operation Complete", "Covert Image To BW", MessageBoxButtons::OK);
			}
			else {
				MessageBox::Show("error code :" + code);
			}
		} 
	private: System::Void Button9_Click(System::Object^ sender, System::EventArgs^ e) {
		ImageHelper image_hepler;
		System::String^ rbg_path;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (openFileDialog1->OpenFile() != nullptr) {
				rbg_path = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
			}
		}
		if (rbg_path == nullptr) {
			return;
		}

		std::string image_color = msclr::interop::marshal_as<std::string>(rbg_path);
		int code = image_hepler.getHistograme(image_color);

		if (code == 0) {
			MessageBox::Show("Operation Complete", "Show histograme", MessageBoxButtons::OK);
		}
		else {
			MessageBox::Show("error code :" + code);
		}




	}
};

}


#endif
