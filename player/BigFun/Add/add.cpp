#include <iostream>
#include <string>
using namespace std;

typedef unsigned int uint;

uint GetNum(const string &str, uint index)
{
	uint temp_value = 0;

	if (index < str.length())
	{
		temp_value = str[str.length() - 1 - index] - '0';
	}
	return temp_value;
}

string Add(const string &left, const string &right)
{
	uint carry_bit = 0;
	string result = left.size() >= right.size() ? left : right;

	for (uint i = 0; i < left.size() || i < right.size(); i++)
	{
		uint temp_value = GetNum(left, i) + GetNum(right, i) + carry_bit;

		carry_bit = temp_value / 10;

		temp_value = temp_value % 10;
		result[result.length() - 1 - i] = temp_value + '0';
	}

	if (carry_bit > 0)
	{
		result.insert(result.begin(), carry_bit + '0');
	}

	cout << ">:" <<  result << "\n";

	return result;
}