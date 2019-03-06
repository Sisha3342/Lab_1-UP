#pragma once
#include <sstream>
#include <iostream>

double calculate_string(std::string str);
double calculate_string_binary(std::string str);
bool check_for_operations(std::string str);
bool check_for_brackets(std::string str);
bool check_for_arith(std::string str);
bool check_for_binary(std::string str);
void check_brackets_balance(std::string str);
std::string count_mult_div_mult_div(std::string str);
void count_in_brackets(std::string& str);
void put_pluses(std::string& str);