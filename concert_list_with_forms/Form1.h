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
			save_file_dialog->Filter = "Text files(*.txt)|*.txt|All files(*.*)|*.*";
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



	private: System::Windows::Forms::Button^  save_button;



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
	private: System::Windows::Forms::Button^  back_button;
	private: System::Windows::Forms::SaveFileDialog^  save_file_dialog;
	private: System::Windows::Forms::Button^  search_name_button;
	private: System::Windows::Forms::Button^  search_button;
	private: System::Windows::Forms::Button^  search_date_button;
	private: System::Windows::Forms::DateTimePicker^  date_1_pick;
	private: System::Windows::Forms::DateTimePicker^  date_2_pick;
	private: System::Windows::Forms::DataGridView^  list_show_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  capacity_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  tickets_left_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  date_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  time_column;

















	private: System::ComponentModel::IContainer^  components;





















	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// </summary>
		void InitializeComponent(void)
		{
			this->from_file_button = (gcnew System::Windows::Forms::Button());
			this->add_concert_button = (gcnew System::Windows::Forms::Button());
			this->save_button = (gcnew System::Windows::Forms::Button());
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
			this->back_button = (gcnew System::Windows::Forms::Button());
			this->save_file_dialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->search_name_button = (gcnew System::Windows::Forms::Button());
			this->search_button = (gcnew System::Windows::Forms::Button());
			this->search_date_button = (gcnew System::Windows::Forms::Button());
			this->date_1_pick = (gcnew System::Windows::Forms::DateTimePicker());
			this->date_2_pick = (gcnew System::Windows::Forms::DateTimePicker());
			this->list_show_table = (gcnew System::Windows::Forms::DataGridView());
			this->name_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->capacity_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tickets_left_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->date_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->time_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->list_show_table))->BeginInit();
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
			// save_button
			// 
			this->save_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->save_button->Location = System::Drawing::Point(32, 137);
			this->save_button->Name = L"save_button";
			this->save_button->Size = System::Drawing::Size(134, 42);
			this->save_button->TabIndex = 5;
			this->save_button->Text = L"Save the list to the file";
			this->save_button->UseVisualStyleBackColor = true;
			this->save_button->Click += gcnew System::EventHandler(this, &Form1::save_button_Click);
			// 
			// list_label
			// 
			this->list_label->AutoSize = true;
			this->list_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->list_label->Location = System::Drawing::Point(425, 58);
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
			this->concert_tickets_left_box->TabIndex = 11;
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
			this->concert_capacity_box->TabIndex = 10;
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
			this->add_button->Click += gcnew System::EventHandler(this, &Form1::add_button_Click);
			// 
			// back_button
			// 
			this->back_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->back_button->Location = System::Drawing::Point(358, 313);
			this->back_button->Name = L"back_button";
			this->back_button->Size = System::Drawing::Size(79, 33);
			this->back_button->TabIndex = 18;
			this->back_button->Text = L"Back";
			this->back_button->UseVisualStyleBackColor = true;
			this->back_button->Visible = false;
			this->back_button->Click += gcnew System::EventHandler(this, &Form1::back_button_Click);
			// 
			// search_name_button
			// 
			this->search_name_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->search_name_button->Location = System::Drawing::Point(32, 185);
			this->search_name_button->Name = L"search_name_button";
			this->search_name_button->Size = System::Drawing::Size(134, 42);
			this->search_name_button->TabIndex = 19;
			this->search_name_button->Text = L"Search by name";
			this->search_name_button->UseVisualStyleBackColor = true;
			this->search_name_button->Click += gcnew System::EventHandler(this, &Form1::search_name_button_Click);
			// 
			// search_button
			// 
			this->search_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->search_button->Location = System::Drawing::Point(358, 187);
			this->search_button->Name = L"search_button";
			this->search_button->Size = System::Drawing::Size(79, 33);
			this->search_button->TabIndex = 20;
			this->search_button->Text = L"Search";
			this->search_button->UseVisualStyleBackColor = true;
			this->search_button->Visible = false;
			this->search_button->Click += gcnew System::EventHandler(this, &Form1::search_button_Click);
			// 
			// search_date_button
			// 
			this->search_date_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->search_date_button->Location = System::Drawing::Point(32, 233);
			this->search_date_button->Name = L"search_date_button";
			this->search_date_button->Size = System::Drawing::Size(134, 42);
			this->search_date_button->TabIndex = 21;
			this->search_date_button->Text = L"Search by date";
			this->search_date_button->UseVisualStyleBackColor = true;
			this->search_date_button->Click += gcnew System::EventHandler(this, &Form1::search_date_button_Click);
			// 
			// date_1_pick
			// 
			this->date_1_pick->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->date_1_pick->CustomFormat = L"yyyy-MM-dd HH:mm";
			this->date_1_pick->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->date_1_pick->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->date_1_pick->Location = System::Drawing::Point(223, 120);
			this->date_1_pick->Name = L"date_1_pick";
			this->date_1_pick->Size = System::Drawing::Size(138, 22);
			this->date_1_pick->TabIndex = 24;
			this->date_1_pick->Visible = false;
			// 
			// date_2_pick
			// 
			this->date_2_pick->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->date_2_pick->CustomFormat = L"yyyy-MM-dd HH:mm";
			this->date_2_pick->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->date_2_pick->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->date_2_pick->Location = System::Drawing::Point(430, 120);
			this->date_2_pick->Name = L"date_2_pick";
			this->date_2_pick->Size = System::Drawing::Size(138, 22);
			this->date_2_pick->TabIndex = 25;
			this->date_2_pick->Visible = false;
			// 
			// list_show_table
			// 
			this->list_show_table->AllowUserToAddRows = false;
			this->list_show_table->AllowUserToDeleteRows = false;
			this->list_show_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->list_show_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->name_column,
					this->capacity_column, this->tickets_left_column, this->date_column, this->time_column
			});
			this->list_show_table->Location = System::Drawing::Point(208, 92);
			this->list_show_table->Name = L"list_show_table";
			this->list_show_table->ReadOnly = true;
			this->list_show_table->RowTemplate->ReadOnly = true;
			this->list_show_table->Size = System::Drawing::Size(545, 150);
			this->list_show_table->TabIndex = 26;
			// 
			// name_column
			// 
			this->name_column->HeaderText = L"Name";
			this->name_column->Name = L"name_column";
			this->name_column->ReadOnly = true;
			// 
			// capacity_column
			// 
			this->capacity_column->HeaderText = L"Capacity";
			this->capacity_column->Name = L"capacity_column";
			this->capacity_column->ReadOnly = true;
			// 
			// tickets_left_column
			// 
			this->tickets_left_column->HeaderText = L"Tickets left";
			this->tickets_left_column->Name = L"tickets_left_column";
			this->tickets_left_column->ReadOnly = true;
			// 
			// date_column
			// 
			this->date_column->HeaderText = L"Date";
			this->date_column->Name = L"date_column";
			this->date_column->ReadOnly = true;
			// 
			// time_column
			// 
			this->time_column->HeaderText = L"Time";
			this->time_column->Name = L"time_column";
			this->time_column->ReadOnly = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(753, 479);
			this->Controls->Add(this->list_show_table);
			this->Controls->Add(this->date_2_pick);
			this->Controls->Add(this->date_1_pick);
			this->Controls->Add(this->search_date_button);
			this->Controls->Add(this->search_button);
			this->Controls->Add(this->search_name_button);
			this->Controls->Add(this->back_button);
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
			this->Controls->Add(this->save_button);
			this->Controls->Add(this->add_concert_button);
			this->Controls->Add(this->from_file_button);
			this->Name = L"Form1";
			this->Text = L"Concert agency";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->list_show_table))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void display_concert_message(std::string info)
	{
		std::string subs[5];

		for (auto i = 0; i < 3; i++)
		{
			const auto pos = info.find(';');
			subs[i] = info.substr(0, pos);
			info.erase(0, pos + 1);
		}

		subs[0].insert(0, "Name: ");
		subs[1].insert(0, "Capacity: ");
		subs[2].insert(0, "Tickets left: ");

		info.erase(0, 1);
		const auto pos = info.find(' ');
		subs[3] = "Date: " + info.substr(0, pos);
		info.erase(0, pos + 1);
		subs[4] = "Time: " + info;

		String^ concert_data = msclr::interop::marshal_as<String^>(subs[0]) + Environment::NewLine
		+ msclr::interop::marshal_as<String^>(subs[1]) + Environment::NewLine
		+ msclr::interop::marshal_as<String^>(subs[2]) + Environment::NewLine
		+ msclr::interop::marshal_as<String^>(subs[3]) + Environment::NewLine
		+ msclr::interop::marshal_as<String^>(subs[4]);

		MessageBox::Show(concert_data, "Successful search");
	}


	private: System::Void redraw_list() {
	
		list_show_table->Rows->Clear();

		std::stringstream oss;
		oss << list_1;
		char my_str[128];
		while (oss.getline(my_str, 128))
		{
			concert c; c.get_info(my_str);

			std::string c_date = std::to_string(c.date.tm_year + 1900) + "-";

			if (c.date.tm_mon <= 9)
				c_date += "0";
			c_date += std::to_string(c.date.tm_mon) + "-";

			if (c.date.tm_mday <= 9)
				c_date += "0";
			c_date += std::to_string(c.date.tm_mday) + " ";

			std::string c_time;

			if (c.date.tm_hour <= 9)
				c_time += "0";
			c_time += std::to_string(c.date.tm_hour) + ":";

			if (c.date.tm_min <= 9)
				c_time += "0";
			c_time += std::to_string(c.date.tm_min);

			String^ concert_name = msclr::interop::marshal_as<String^>(c.name);
			String^ concert_capacity = msclr::interop::marshal_as<String^>(std::to_string(c.capacity));
			String^ concert_t_left = msclr::interop::marshal_as<String^>(std::to_string(c.tickets_left));
			String^ concert_date = msclr::interop::marshal_as<String^>(c_date);
			String^ concert_time = msclr::interop::marshal_as<String^>(c_time);

			list_show_table->Rows->Add(concert_name, concert_capacity, concert_t_left, 
				concert_date, concert_time);
		}
	}

	private: System::Void hide_default() {

		from_file_button->Visible = false;
		add_concert_button->Visible = false;
		save_button->Visible = false;
		list_show_table->Visible = false;
		list_label->Visible = false;
		search_name_button->Visible = false;
		search_date_button->Visible = false;
	}

	private: System::Void display_default() {

		from_file_button->Visible = true;
		add_concert_button->Visible = true;
		save_button->Visible = true;
		list_show_table->Visible = true;
		list_label->Visible = true;
		search_name_button->Visible = true;
		search_date_button->Visible = true;

		concert_name_box->Visible = false;
		concert_capacity_box->Visible = false;
		concert_date_box->Visible = false;
		concert_tickets_left_box->Visible = false;
		concert_name_label->Visible = false;
		concert_capacity_label->Visible = false;
		concert_date_label->Visible = false;
		concert_tickets_left_label->Visible = false;
		add_button->Visible = false;
		back_button->Visible = false;
		search_button->Visible = false;

		date_1_pick->Visible = false;
		date_2_pick->Visible = false;
	}

	private: System::Void display_add()
	{
		back_button->Visible = true;
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

	private: System::Void display_name_search()
	{
		concert_name_box->Visible = true;
		concert_name_label->Visible = true;
		search_button->Visible = true;
		back_button->Visible = true;
	}

	private: System::Void display_date_search()
	{
		date_1_pick->Visible = true;
		date_2_pick->Visible = true;
		search_button->Visible = true;
		back_button->Visible = true;
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

	private: System::Void add_button_Click(System::Object^  sender, System::EventArgs^  e) {

		std::string conc_name = msclr::interop::marshal_as<std::string>(concert_name_box->Text);
		std::string conc_tickets_left = msclr::interop::marshal_as<std::string>(concert_tickets_left_box->Text);
		std::string conc_capacity = msclr::interop::marshal_as<std::string>(concert_capacity_box->Text);
		std::string conc_date = msclr::interop::marshal_as<std::string>(concert_date_box->Text);

		if (conc_date == "" || conc_name == "" || conc_tickets_left == "" || conc_capacity == "")
		{
			MessageBox::Show("Fill all the fields", "Input warning");
		}
		else
		{
			std::string final_info = conc_name + ";" + conc_capacity + ";" + conc_tickets_left + ";" + conc_date;
			list_1.add_concert(final_info);

			MessageBox::Show("Concert was added to the list", "Successful addition");

			concert_name_box->Text = "";
			concert_tickets_left_box->Text = "";
			concert_capacity_box->Text = "";
			concert_date_box->Text = "";
		}
	}
	private: System::Void back_button_Click(System::Object^  sender, System::EventArgs^  e) {
		
		concert_name_box->Text = "";
		concert_tickets_left_box->Text = "";
		concert_capacity_box->Text = "";
		concert_date_box->Text = "";

		redraw_list();
		display_default();
	}

	private: System::Void save_button_Click(System::Object^  sender, System::EventArgs^  e) {

		save_file_dialog->ShowDialog();

		std::string filename = msclr::interop::marshal_as<std::string>(save_file_dialog->FileName);

		std::ofstream fout(filename);

		if (!fout.is_open() && filename != "")
		{
			MessageBox::Show("No file chosen", "File chooshing warning");
		}
		else if (filename != "")
		{
			fout << list_1;

			MessageBox::Show("The list was saved to the file", "Successful save");
		}

		fout.close();
	}

	private: System::Void search_name_button_Click(System::Object^  sender, System::EventArgs^  e) {

		display_name_search();
		hide_default();
	}

	private: System::Void search_button_Click(System::Object^  sender, System::EventArgs^  e) {

		if (concert_name_box->Visible == true)
		{
			std::string concert_name = msclr::interop::marshal_as<std::string>(concert_name_box->Text);

			if (concert_name == "")
			{
				MessageBox::Show("Fill the name field", "Name input warning");
			}
			else
			{
				if (list_1.find_first_name(concert_name) != list_1.end())
				{
					concert c = *list_1.find_first_name(concert_name);
					display_concert_message(c.take_full_string_info());

					concert_name_box->Text = "";
				}
				else
				{
					MessageBox::Show("No concerts with this name in the list", "Failed search");
				}
			}
		}
		else
		{
			std::string date_1 = msclr::interop::marshal_as<std::string>(date_1_pick->Text);
			std::string date_2 = msclr::interop::marshal_as<std::string>(date_2_pick->Text);
			std::string format = "%Y-%m-%d %H:%M";
			tm date1, date2;

			std::stringstream ss(date_1);
			ss >> std::get_time(&date1, format.c_str());
			ss.clear(); 
			ss.str(date_2);
			ss >> std::get_time(&date2, format.c_str());

			if (list_1.find_first_date_between(date1, date2) != list_1.end())
			{
				concert c = *list_1.find_first_date_between(date1, date2);
				display_concert_message(c.take_full_string_info());
			}
			else
			{
				MessageBox::Show("No concerts found between theese dates", "Failed search");
			}
		}
	}

	private: System::Void search_date_button_Click(System::Object^  sender, System::EventArgs^  e) {

		hide_default();
		display_date_search();
	}
};
}