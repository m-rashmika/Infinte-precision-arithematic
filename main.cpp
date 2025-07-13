#include <bits/stdc++.h>
#include "my_inf_arith.h"
using namespace std;
using namespace InfiniteArithmetic;

int main(int a, char *arguments[])
{
	string filename = arguments[0];
	string string_type = arguments[1];
	string operation = arguments[2];
	string num1 = arguments[3];
	string num2 = arguments[4];

	string ans;
	int o = 0;
	if (operation == "add")
		o = 1;
	else if (operation == "sub")
		o = 2;
	else if (operation == "mul")
		o = 3;
	else
		o = 4;

	if (string_type == "int")
	{
		integer a(num1);
		integer b(num2);
		switch (o)
		{
		case 1:
			ans = a + b;
			break;
		case 2:
			ans = a - b;
			break;
		case 3:
			ans = a * b;
			break;
		}
	}

	else if (string_type == "float")
	{
		Float a(num1);
		Float b(num2);
		switch (o)
		{
		case 1:
			ans = a + b;
			break;
		case 2:
			ans = a - b;
			break;
		case 3:
			ans = a * b;
			break;
		}
	}
	cout << ans << endl;

	return 0;
}
