#pragma once

namespace CppCLR_WinformsProjekt {
	concert_list list_1;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();

			open_file_dialog->Filter = "Text files(*.txt)|*.txt|All files(*.*)|*.*";
		}

	protected:
		/// <summary>
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  from_file_button;
	private: System::Windows::Forms::Button^  add_concert_button;
	private: System::Windows::Forms::Button^  sort_name_button;
	private: System::Windows::Forms::Button^  sort_date_button;

	private: System::Windows::Forms::Button^  save_button;
	private: System::Windows::Forms::TextBox^  list_show_box;


	private: System::Windows::Forms::OpenFileDialog^  open_file_dialog;
	private: System::Windows::Forms::Label^  list_label;
	private: System::Windows::Forms::TextBox^  concert_name_box;
	private: System::Windows::Forms::TextBox^  concert_tickets_left_box;
	private: System::Windows::Forms::TextBox^  concert_capacity_box;
	private: System::Windows::Forms::TextBox^  concert_date_box;
	private: System::Windows::Forms::Label^  concert_name_label;
	private: System::Windows::Forms::Label^  concert_tickets_left_label;
	private: System::Windows::Forms::Label^  concert_capacity_label;
	private: System::Windows::Forms::Label^  concert_date_label;
	private: System::Windows::Forms::Button^  add_button;





















	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// </summary>
		void InitializeComponent(void)
		{
			this->from_file_button = (gcnew System::Windows::Forms::Button());
			this->add_concert_button = (gcnew System::Windows::Forms::Button());
			this->sort_name_button = (gcnew System::Windows::Forms::Button());
			this->sort_date_button = (gcnew System::Windows::Forms::Button());
			this->save_button = (gcnew System::Windows::Forms::Button());
			this->list_show_box = (gcnew System::Windows::Forms::TextBox());
			this->open_file_dialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->list_label = (gcnew System::Windows::Forms::Label());
			this->concert_name_box = (gcnew System::Windows::Forms::TextBox());
			this->concert_tickets_left_box = (gcnew System::Windows::Forms::TextBox());
			this->concert_capacity_box = (gcnew System::Windows::Forms::TextBox());
			this->concert_date_box = (gcnew System::Windows::Forms::TextBox());
			this->concert_name_label = (gcnew System::Windows::Forms::Label());
			this->concert_tickets_left_label = (gcnew System::Windows::Forms::Label());
			this->concert_capacity_label = (gcnew System::Windows::Forms::Label());
			this->concert_date_label = (gcnew System::Windows::Forms::Label());
			this->add_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// from_file_button
			// 
			this->from_file_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->from_file_button->Location = System::Drawing::Point(32, 41);
			this->from_file_button->Name = L"from_file_button";
			this->from_file_button->Size = System::Drawing::Size(134, 42);
			this->from_file_button->TabIndex = 0;
			this->from_file_button->Text = L"Upload list from the file";
			this->from_file_button->UseVisualStyleBackColor = true;
			this->from_file_button->Click += gcnew System::EventHandler(this, &Form1::from_file_button_Click);
			// 
			// add_concert_button
			// 
			this->add_concert_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->add_concert_button->Location = System::Drawing::Point(32, 89);
			this->add_concert_button->Name = L"add_concert_button";
			this->add_concert_button->Size = System::Drawing::Size(134, 42);
			this->add_concert_button->TabIndex = 1;
			this->add_concert_button->Text = L"Add a concert to the list";
			this->add_concert_button->UseVisualStyleBackColor = true;
			this->add_concert_button->Click += gcnew System::EventHandler(this, &Form1::add_concert_button_Click);
			// 
			// sort_name_button
			// 
			this->sort_name_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sort_name_button->Location = System::Drawing::Point(32, 138);
			this->sort_name_button->Name = L"sort_name_button";
			this->sort_name_button->Size = System::Drawing::Size(134, 42);
			this->sort_name_button->TabIndex = 2;
			this->sort_name_button->Text = L"Sort concerts by name";
			this->sort_name_button->UseVisualStyleBackColor = true;
			// 
			// sort_date_button
			// 
			this->sort_date_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sort_date_button->Location = System::Drawing::Point(32, 187);
			this->sort_date_button->Name = L"sort_date_button";
			this->sort_date_button->Size = System::Drawing::Size(134, 42);
			this->sort_date_button->TabIndex = 3;
			this->sort_date_button->Text = L"Sort concerts by date";
			this->sort_date_button->UseVisualStyleBackColor = true;
			// 
			// save_button
			// 
			this->save_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->save_button->Location = System::Drawing::Point(32, 236);
			this->save_button->Name = L"save_button";
			this->save_button->Size = System::Drawing::Size(134, 42);
			this->save_button->TabIndex = 5;
			this->save_button->Text = L"Save the list to the file";
			this->save_button->UseVisualStyleBackColor = true;
			// 
			// list_show_box
			// 
			this->list_show_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->list_show_box->Location = System::Drawing::Point(404, 89);
			this->list_show_box->Multiline = true;
			this->list_show_box->Name = L"list_show_box";
			this->list_show_box->ReadOnly = true;
			this->list_show_box->Size = System::Drawing::Size(297, 189);
			this->list_show_box->TabIndex = 7;
			this->list_show_box->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// list_label
			// 
			this->list_label->AutoSize = true;
			this->list_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->list_label->Location = System::Drawing::Point(504, 58);
			this->list_label->Name = L"list_label";
			this->list_label->Size = System::Drawing::Size(107, 25);
			this->list_label->TabIndex = 8;
			this->list_label->Text = L"Your list:";
			// 
			// concert_name_box
			// 
			this->concert_name_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->concert_name_box->Location = System::Drawing::Point(299, 58);
			this->concert_name_box->Name = L"concert_name_box";
			this->concert_name_box->Size = System::Drawing::Size(187, 22);
			this->concert_name_box->TabIndex = 9;
			this->concert_name_box->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->concert_name_box->Visible = false;
			// 
			// concert_tickets_left_box
			// 
			this->concert_tickets_left_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->concert_tickets_left_box->Location = System::Drawing::Point(299, 120);
			this->concert_tickets_left_box->Name = L"concert_tickets_left_box";
			this->concert_tickets_left_box->Size = System::Drawing::Size(187, 22);
			this->concert_tickets_left_box->TabIndex = 10;
			this->concert_tickets_left_box->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->concert_tickets_left_box->Visible = false;
			// 
			// concert_capacity_box
			// 
			this->concert_capacity_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->concert_capacity_box->Location = System::Drawing::Point(299, 89);
			this->concert_capacity_box->Name = L"concert_capacity_box";
			this->concert_capacity_box->Size = System::Drawing::Size(187, 22);
			this->concert_capacity_box->TabIndex = 11;
			this->concert_capacity_box->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->concert_capacity_box->Visible = false;
			// 
			// concert_date_box
			// 
			this->concert_date_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->concert_date_box->Location = System::Drawing::Point(299, 151);
			this->concert_date_box->Name = L"concert_date_box";
			this->concert_date_box->Size = System::Drawing::Size(187, 22);
			this->concert_date_box->TabIndex = 12;
			this->concert_date_box->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->concert_date_box->Visible = false;
			// 
			// concert_name_label
			// 
			this->concert_name_label->AutoSize = true;
			this->concert_name_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->concert_name_label->Location = System::Drawing::Point(240, 59);
			this->concert_name_label->Name = L"concert_name_label";
			this->concert_name_label->Size = System::Drawing::Size(53, 16);
			this->concert_name_label->TabIndex = 13;
			this->concert_name_label->Text = L"Name:";
			this->concert_name_label->Visible = false;
			// 
			// concert_tickets_left_label
			// 
			this->concert_tickets_left_label->AutoSize = true;
			this->concert_tickets_left_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->concert_tickets_left_label->Location = System::Drawing::Point(205, 123);
			this->concert_tickets_left_label->Name = L"concert_tickets_left_label";
			this->concert_tickets_left_label->Size = System::Drawing::Size(88, 16);
			this->concert_tickets_left_label->TabIndex = 14;
			this->concert_tickets_left_label->Text = L"Tickets left:";
			this->concert_tickets_left_label->Visible = false;
			// 
			// concert_capacity_label
			// 
			this->concert_capacity_label->AutoSize = true;
			this->concert_capacity_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->concert_capacity_label->Location = System::Drawing::Point(220, 92);
			this->concert_capacity_label->Name = L"concert_capacity_label";
			this->concert_capacity_label->Size = System::Drawing::Size(73, 16);
			this->concert_capacity_label->TabIndex = 15;
			this->concert_capacity_label->Text = L"Capacity:";
			this->concert_capacity_label->Visible = false;
			// 
			// concert_date_label
			// 
			this->concert_date_label->AutoSize = true;
			this->concert_date_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->concert_date_label->Location = System::Drawing::Point(248, 152);
			this->concert_date_label->Name = L"concert_date_label";
			this->concert_date_label->Size = System::Drawing::Size(45, 16);
			this->concert_date_label->TabIndex = 16;
			this->concert_date_label->Text = L"Date:";
			this->concert_date_label->Visible = false;
			// 
			// add_button
			// 
			this->add_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->add_button->Location = System::Drawing::Point(358, 187);
			this->add_button->Name = L"add_button";
			this->add_button->Size = System::Drawing::Size(79, 33);
			this->add_button->TabIndex = 17;
			this->add_button->Text = L"Add";
			this->add_button->UseVisualStyleBackColor = true;
			this->add_button->Visible = false;
			this->add_button->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(753, 479);
			this->Controls->Add(this->add_button);
			this->Controls->Add(this->concert_date_label);
			this->Controls->Add(this->concert_capacity_label);
			this->Controls->Add(this->concert_tickets_left_label);
			this->Controls->Add(this->concert_name_label);
			this->Controls->Add(this->concert_date_box);
			this->Controls->Add(this->concert_capacity_box);
			this->Controls->Add(this->concert_tickets_left_box);
			this->Controls->Add(this->concert_name_box);
			this->Controls->Add(this->list_label);
			this->Controls->Add(this->list_show_box);
			this->Controls->Add(this->save_button);
			this->Controls->Add(this->sort_date_button);
			this->Controls->Add(this->sort_name_button);
			this->Controls->Add(this->add_concert_button);
			this->Controls->Add(this->from_file_button);
			this->Name = L"Form1";
			this->Text = L"Concert agency";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void redraw_list() {
	
		list_show_box->Text = "";

		std::stringstream oss;
		oss << list_1;
		char my_str[128];
		while (oss.getline(my_str, 128))
		{
			String^ temp = msclr::interop::marshal_as<String^>(my_str);

			list_show_box->Text += temp;
			list_show_box->Text += Environment::NewLine;
		}
	}

	private: System::Void hide_default() {

		from_file_button->Visible = false;
		add_concert_button->Visible = false;
		sort_date_button->Visible = false;
		sort_name_button->Visible = false;
		save_button->Visible = false;
		list_show_box->Visible = false;
		list_label->Visible = false;
	}

	private: System::Void display_default() {

		from_file_button->Visible = true;
		add_concert_button->Visible = true;
		sort_date_button->Visible = true;
		sort_name_button->Visible = true;
		save_button->Visible = true;
		list_show_box->Visible = true;
		list_label->Visible = true;

		concert_name_box->Visible = false;
		concert_capacity_box->Visible = false;
		concert_date_box->Visible = false;
		concert_tickets_left_box->Visible = false;
		concert_name_label->Visible = false;
		concert_capacity_label->Visible = false;
		concert_date_label->Visible = false;
		concert_tickets_left_label->Visible = false;
		add_button->Visible = false;
	}

	private: System::Void display_add()
	{
		add_button->Visible = true;
		concert_name_box->Visible = true;
		concert_capacity_box->Visible = true;
		concert_date_box->Visible = true;
		concert_tickets_left_box->Visible = true;
		concert_name_label->Visible = true;
		concert_capacity_label->Visible = true;
		concert_date_label->Visible = true;
		concert_tickets_left_label->Visible = true;
	}

	private: System::Void from_file_button_Click(System::Object^  sender, System::EventArgs^  e) {

		open_file_dialog->ShowDialog();

		std::string filename = msclr::interop::marshal_as<std::string>(open_file_dialog->FileName);

		std::ifstream fin(filename);

		if (!fin.is_open() && filename != "")
		{
			MessageBox::Show("No file chosen", "File chooshing warning");
		}
		else if (filename != "")
		{
			list_1.clear_list();

			while(!fin.eof())
			{
				fin >> list_1;
			}
		}

		fin.close();

		redraw_list();

	}

	private: System::Void add_concert_button_Click(System::Object^  sender, System::EventArgs^  e) {

		display_add();
		hide_default();
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		std::string conc_name = msclr::interop::marshal_as<std::string>(concert_name_box->Text);
		std::string conc_tickets_left = msclr::interop::marshal_as<std::string>(concert_tickets_left_box->Text);
		std::string conc_capacity = msclr::interop::marshal_as<std::string>(concert_capacity_box->Text);
		std::string conc_date = msclr::interop::marshal_as<std::string>(concert_date_box->Text);

		std::string final_info = conc_name + ";" + conc_capacity + ";" + conc_tickets_left + ";" + conc_date;
		list_1.add_concert(final_info);

		redraw_list();
		display_default();
	}
};
}