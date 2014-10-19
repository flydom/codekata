#include <iostream>
#include <string>
using namespace std;

typedef unsigned int uint;

void AddInit(const string &str1, const string &str2, string &temp_str, string &result)
{
	if (str1.size() >= str2.size())
	{
		temp_str = str2;
		temp_str.insert(temp_str.begin(), str1.size() - str2.size(), '0');

		result = str1;
	}
	else
	{
		temp_str = str1;
		temp_str.insert(temp_str.begin(), str2.size() - str1.size(), '0');

		result = str2;
	}
}

string Add(const string &str1, const string &str2)
{
	uint carry_bit = 0;
	uint temp_value = 0;
	string result, temp_str;
	
	AddInit(str1, str2, temp_str, result);

	uint index = result.size() - 1;
	for (uint i = 0; i < result.size(); i++)
	{
		temp_value = (result[index - i] - '0') + (temp_str[index - i] - '0') + carry_bit;

		carry_bit = temp_value / 10;

		temp_value = temp_value % 10;
		result[index - i] = temp_value + '0';
	}

	if (carry_bit > 0)
	{
		result.insert(result.begin(), carry_bit + '0');
	}

	cout << ">:" <<  result << "\n";

	return result;
}