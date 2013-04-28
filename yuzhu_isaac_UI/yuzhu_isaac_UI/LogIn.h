#pragma once
#include"userMenu.h"
#include"AdminMenu.h"
namespace yuzhu_isaac_UI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LogIn
	/// </summary>
	public ref class LogIn : public System::Windows::Forms::Form
	{
	public:
		LogIn(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LogIn()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(82, 87);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Student ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(82, 202);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Password";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(220, 89);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(121, 20);
			this->textBox1->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(48, 271);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(139, 43);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Log in";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LogIn::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(259, 271);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(134, 43);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &LogIn::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(220, 201);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(121, 20);
			this->textBox2->TabIndex = 6;
			// 
			// LogIn
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(455, 371);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"LogIn";
			this->Text = L"LogIn";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 	String^ userId=this->textBox1->Text;
				String^ password=this->textBox2->Text;
				
				OracleConnection^ myConnection;	
				String^ ConnectionString;

				ConnectionString = gcnew String("Data Source=ora11g;User ID= c52639352;Password= c52639352; Unicode=True");
				myConnection = gcnew OracleConnection(ConnectionString);
				myConnection->Open();	

				OracleCommand^ MenuCommand = myConnection->CreateCommand();
				MenuCommand->CommandText = gcnew String("SELECT id, permission FROM users WHERE id=:userID AND password=:userPassword");
		
				MenuCommand->Parameters->Add(":userID", OracleType::Number);
				MenuCommand->Parameters->default[0]->Value = userId;
				
				MenuCommand->Parameters->Add(":userPassword", OracleType::VarChar);
				MenuCommand->Parameters->default[1]->Value = password;
				
				OracleDataReader^ myFirstReader = MenuCommand->ExecuteReader();

				// Set parameter
				int permission;
				String^ sid;

				if ( myFirstReader->Read() )	
				{
					permission = myFirstReader->GetInt32(1);
					sid = myFirstReader->GetString(0);
				}
				else
				{
					permission=-1;
				}

				if(permission == 1)// 11111111  pas 0001
				{
					userMenu^ um=gcnew userMenu(sid, myConnection);
					um->Owner=this;
					um->Show();
					this->Hide();
				}
				if(permission == 0)// 52639352 pas0000
				{
					AdminMenu^ am=gcnew AdminMenu(sid,myConnection);
					am->Owner=this;
					am->Show();
					this->Hide();
				}
				if(permission == -1)
				{
					MessageBox::Show("Log in fail!");
				}

		 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 	this->Hide();
					this->Owner->Show();
					this->Close();
			 }

};
}
