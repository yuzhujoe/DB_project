#pragma once

namespace yuzhu_isaac_UI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OracleClient;

	/// <summary>
	/// Summary for userMenu
	/// </summary>
	public ref class userMenu : public System::Windows::Forms::Form
	{
	public:
		userMenu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		userMenu(String^ sid,OracleConnection^ oraConn)
		{
			InitializeComponent();
			studentID=sid;
			userMenuConnection=oraConn;
		}

		 String^ studentID;
		 OracleConnection^ userMenuConnection;
		 int CourseNum;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	public: 
	private: System::Windows::Forms::ToolStripMenuItem^  listAllCourseToolStripMenuItem;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::CheckedListBox^  checkedListBox1;
		


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~userMenu()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->listAllCourseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->listAllCourseToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(794, 25);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// listAllCourseToolStripMenuItem
			// 
			this->listAllCourseToolStripMenuItem->Name = L"listAllCourseToolStripMenuItem";
			this->listAllCourseToolStripMenuItem->Size = System::Drawing::Size(100, 21);
			this->listAllCourseToolStripMenuItem->Text = L"List All course";
			this->listAllCourseToolStripMenuItem->Click += gcnew System::EventHandler(this, &userMenu::listAllCourseToolStripMenuItem_Click);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(12, 27);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(302, 289);
			this->checkedListBox1->TabIndex = 1;
			this->checkedListBox1->Visible = false;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(331, 45);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 57);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Course Detail";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &userMenu::button1_Click);
			// 
			// userMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(794, 335);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"userMenu";
			this->Text = L"userMenu";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void listAllCourseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 this->checkedListBox1->Visible = true;
				String^ courseId;
				String^ courseTitle;
				String^ StaffName;
				String^ section;
				int credit;
				int capacity;

				
				//userMenuConnection->Open();	
				this->checkedListBox1->Items->Clear();

				OracleCommand^ MenuCommand = userMenuConnection->CreateCommand();
				MenuCommand->CommandText = gcnew String("SELECT *FROM courses");
		
				
				OracleDataReader^ userMenuReader = MenuCommand->ExecuteReader();
				
				while(userMenuReader->Read())
				{
					courseId = userMenuReader->GetString(0);
					courseTitle = userMenuReader->GetString(1);
					StaffName = userMenuReader->GetString(2);
					section = userMenuReader->GetString(3);
					credit = userMenuReader->GetInt32(4);
					capacity = userMenuReader->GetInt32(5);

					//store into globe 

					//add to checklistBox
					checkedListBox1->Items->Add(courseId+" "+courseTitle); 
				}
				courseNum=checkedListBox1->Items->Count;
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {

			 }
};
}
