#include "calculator.h"

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

void check_brackets_balance(std::string str)
{
	int left_count = 0, right_count = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
			left_count++;
		if (str[i] == ')')
			right_count++;

		if (right_count > left_count)
			throw 1;
	}

	if (left_count != right_count)
		throw 2;
}

void put_pluses(std::string& str)
{
	for (int i = 0; i < str.size(); i++)
		if (str[i] == '-' && i != 0)
		{
			if (str[i - 1] != '*' && str[i - 1] != '/')
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
	char operations[] = "|^&<>";
	for (int i = 0; operations[i] != '\0'; i++)
		if (str.find(operations[i]) != std::string::npos)
			return true;
	return false;
}

std::string count_mult_div(std::string str)
{
	std::string sub_str; int index = 0;
	char operation;

	while (str[index] != '*' && str[index] != '/' && index < str.size())
	{
		sub_str.push_back(str[index]);
		index++;
	}

	double value = std::stod(sub_str);
	sub_str.clear();
	operation = str[index];
	index++;

	while (index < str.size())
	{
		while (str[index] != '*' && str[index] != '/' && index < str.size())
		{
			sub_str.push_back(str[index]);
			index++;
		}

		double value1 = std::stod(sub_str);

		if (operation == '*')
			value *= value1;
		else
		{
			if (value1 == 0)
				throw 3;

			value /= value1;
		}
		operation = str[index];
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
	if (value < 0 && start_index != 0)
		if (str[start_index - 1] == '+')
			start_index--;
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
	if (str.size() == 0)
		return 0;

	char oper_list[] = "*/+-.|&^<>";

	if (strchr(oper_list, str[str.size() - 1]))
		throw 4;

	check_brackets_balance(str);
	count_in_brackets(str);

	if (!check_for_binary(str))
		return calculate_string(str);

	char operation = '0';
	int value = 0;
	std::string sub_str;
	char binary_list[] = "|&^<>";

	for (int i = 0; i < str.size(); i++)
	{

		while (!strchr(binary_list, str[i]) && i < str.size())
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
			throw -1;

		if (operation == '0')
			value = std::stoi(sub_str);
		else if (operation == '^')
			value ^= std::stoi(sub_str);
		else if (operation == '|')
			value |= std::stoi(sub_str);
		else if (operation == '<')
			value <<= std::stoi(sub_str);
		else if (operation == '>')
			value >>= std::stoi(sub_str);
		else
			value &= std::stoi(sub_str);

		operation = str[i];

		if (operation == '<' || operation == '>')
			i++;

		sub_str.clear();
	}

	return value;
}