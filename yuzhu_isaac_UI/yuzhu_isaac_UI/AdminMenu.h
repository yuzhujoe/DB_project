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
	/// Summary for AdminMenu
	/// </summary>
	public ref class AdminMenu : public System::Windows::Forms::Form
	{
	public:
		AdminMenu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		AdminMenu(String^ userId,OracleConnection^ oraConn/*,String^ password*/)
		{
			InitializeComponent();
			adminID=userId;
			adminMenuConnection=oraConn;
		}
		String^ adminID;
		 OracleConnection^ adminMenuConnection;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  listAllCoursesToolStripMenuItem;
	private: System::Windows::Forms::CheckedListBox^  checkedListBox1;

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
			this->listAllCoursesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->listAllCoursesToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(773, 25);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// listAllCoursesToolStripMenuItem
			// 
			this->listAllCoursesToolStripMenuItem->Name = L"listAllCoursesToolStripMenuItem";
			this->listAllCoursesToolStripMenuItem->Size = System::Drawing::Size(108, 21);
			this->listAllCoursesToolStripMenuItem->Text = L"List All Courses";
			this->listAllCoursesToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminMenu::listAllCoursesToolStripMenuItem_Click);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(12, 28);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(306, 274);
			this->checkedListBox1->TabIndex = 1;
			this->checkedListBox1->Visible = false;
			// 
			// AdminMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(773, 313);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"AdminMenu";
			this->Text = L"AdminMenu";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void listAllCoursesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 this->checkedListBox1->Visible = true;
				String^ courseId;
				String^ courseTitle;
				this->checkedListBox1->Items->Clear();
				//userMenuConnection->Open();	

				OracleCommand^ MenuCommand = adminMenuConnection->CreateCommand();
				MenuCommand->CommandText = gcnew String("SELECT course_id, course_title FROM courses");
		
				
				OracleDataReader^ adminMenuReader = MenuCommand->ExecuteReader();
				
				while(adminMenuReader->Read())
				{
					courseId = adminMenuReader->GetString(0);
					courseTitle = adminMenuReader->GetString(1);
					//add to checklistBox
					checkedListBox1->Items->Add(courseId+" "+courseTitle); 
				}
			 }
	};
}
