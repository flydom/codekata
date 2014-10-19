#include <assert.h>
#include <string>
using namespace std;

extern string Add(const string &str1, const string &str2);

void main()
{
	assert(Add("1","2") == "3");

	assert(Add("1","9") == "10");
	assert(Add("2","9") == "11");

	assert(Add("1","99") == "100");
	assert(Add("1","999") == "1000");
	assert(Add("1","9999") == "10000");

	assert(Add("2","99") == "101");
	assert(Add("12345","99") == "12444");
	assert(Add("123456789123456789123456789", "222") == "123456789123456789123457011");

	getchar();
}