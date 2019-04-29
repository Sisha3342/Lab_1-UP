// stdafx.h: Includedatei für Standardsystem-Includedateien
// oder häufig verwendete projektspezifische Includedateien,
// die nur in unregelmäßigen Abständen geändert werden.
//

#pragma once
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <boost/algorithm/string.hpp>

struct concert
{
	std::string name;
	int tickets_left{};
	int capacity{};
	tm date{};

	void get_info(std::string info);
	void reserve();
	friend std::ostream& operator<< (std::ostream& out, concert const& conc);
	std::string take_full_string_info();
};

class concert_list
{
	std::vector<concert> list_;
public:

	concert_list() = default;
	concert_list(concert_list const&) = delete;
	concert_list(concert_list&&) = delete;

	void add_concert(std::string info);
	int get_concerts_count() const;
	concert& operator[](int index);
	void reserve_ticket(int conc_index);
	void sort_by_name();
	void sort_by_date();
	void clear_list();
	std::vector<concert>::iterator begin();
	std::vector<concert>::iterator end();
	std::vector<concert> find_first_name(std::string const&);
	std::vector<concert> find_first_date_between(tm const& date1, tm const& date2);

	friend std::ostream& operator<< (std::ostream& out, concert_list const& list1);
	friend std::istream& operator>> (std::istream& in, concert_list& list1);
};

