#include <iostream>
#include <sstream>

double calculate_string(std::string str);
bool check_for_operations_mult_div(std::string str);
bool check_for_brackets(std::string str);
bool check_for_arith(std::string str);
bool check_for_binary(std::string str);
std::string count_mult_div(std::string str);
void count_in_brackets(std::string& str);
void put_pluses(std::string& str);
double calculate_string_binary(std::string str);

template <typename T>
bool is_double(T value)
{
	std::string help_str;
	std::stringstream oss;
	oss << value;
	oss >> help_str;
	if (help_str.find('.') == std::string::npos)
		return false;
	return true;
}


int main()
{
	std::string calc_str;
	std::getline(std::cin, calc_str);

	double result = calculate_string_binary(calc_str);

	std::cout << result;

	return 0;
}

void put_pluses(std::string& str)
{
	for (int i = 0; i < str.size(); i++)
		if (str[i] == '-' && i != 0)
		{
			if (str[i-1] != '*' && str[i-1] != '/')
			{
				str.insert(i, "+");
				i++;
			}
		}
}

bool check_for_operations_mult_div(std::string str)
{
	char operations[] = "*/";
	for (int i = 0; operations[i] != '\0'; i++)
		if (str.find(operations[i]) != std::string::npos)
			return true;
	return false;
}

bool check_for_brackets(std::string str)
{
	char brackets[] = "(";
	for (int i = 0; i < brackets[i] != '\0'; i++)
		if (str.find(brackets[i]) != std::string::npos)
			return true;
	return false;
}

bool check_for_arith(std::string str)
{
	char operations[] = "+-*/";
	for (int i = 0; operations[i] != '\0'; i++)
		if (str.find(operations[i]) != std::string::npos)
			return true;
	return false;
}

bool check_for_binary(std::string str)
{
	char operations[] = "|^&";
	for (int i = 0; operations[i] != '\0'; i++)
		if (str.find(operations[i]) != std::string::npos)
			return true;
	return false;
}

std::string count_mult_div(std::string str)
{
	std::string sub_str; int index = 0;
	char operation;
	
	while(str[index] != '*' && str[index] != '/' && index < str.size())
	{
		sub_str.push_back(str[index]);
		index++;
	}

	double value = std::stod(sub_str);
	sub_str.clear();
	operation = str[index];
	index++;

	while(index < str.size())
	{
		while (str[index] != '*' && str[index] != '/' && index < str.size())
		{
			sub_str.push_back(str[index]);
			index++;
		}

		if (operation == '*')
			value *= std::stod(sub_str);
		else
			value /= std::stod(sub_str);

		operation == str[index];
		index++;
		sub_str.clear();
	}

	sub_str.clear();
	std::stringstream oss;
	oss << value;
	oss >> sub_str;

	return sub_str;
}

void count_in_brackets(std::string& str)
{
	std::string sub_str; int start_index = 0;

	if (!check_for_brackets(str))
		return;

	for (int i = 0; i < str.size() && str[i] != '('; i++, start_index++);

	int left_count = 1, i = start_index + 1;

	for (; left_count; i++)
	{
		if (str[i] == '(')
		{
			left_count++;
		}
		if (str[i] == ')')
		{
			left_count--;
			if (!left_count)
				break;
		}

		sub_str.push_back(str[i]);
	}

	double value = calculate_string_binary(sub_str);

	std::stringstream oss;
	oss << value;
	oss >> sub_str;
	str.replace(start_index, i - start_index, sub_str);
	count_in_brackets(str);
}

double calculate_string(std::string str)
{
	double value = 0; std::string sub_str;

	put_pluses(str);

	for (int i = 0; i < str.size(); i++)
	{
		while (str[i] != '+' && i < str.size())
		{
			sub_str.push_back(str[i]);
			i++;
		}

		if (check_for_operations_mult_div(sub_str))
			sub_str = count_mult_div(sub_str);
	
		value += std::stod(sub_str);
		
		sub_str.clear();
	}


	return value;
}

double calculate_string_binary(std::string str)
{
	count_in_brackets(str);

	if (!check_for_binary(str))
		return calculate_string(str);

	char operation = '0';
	int value = 0;
	std::string sub_str;

	for (int i = 0; i < str.size(); i++)
	{

		while (str[i] != '|' && str[i] != '&' && str[i] != '^' && i < str.size())
		{
			sub_str.push_back(str[i]);
			i++;
		}

		if (check_for_arith(sub_str))
		{
			std::stringstream oss;
			oss << calculate_string(sub_str);
			oss >> sub_str;
		}

		if (is_double(sub_str))
			throw - 1;

		if (operation == '0')
			value = std::stoi(sub_str);
		else if (operation == '^')
			value ^= std::stoi(sub_str);
		else if (operation == '|')
			value |= std::stoi(sub_str);
		else
			value &= std::stoi(sub_str);

		operation = str[i];

		sub_str.clear();
	}

	return value;
}