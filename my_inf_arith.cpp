#include <bits/stdc++.h>
#include "my_inf_arith.h"
using namespace std;
using namespace InfiniteArithmetic;

integer::integer()
{
    int_num = '0';
}
integer::integer(string s)
{
    int_num = s;
}
integer::integer(const integer &copy)
{
    int_num = copy.int_num;
}
integer::~integer()
{
    int_num = "";
}
void integer::parse(const string &s)
{
    int_num = s;
}

string removeextrazeroes(const string &s)
{
	size_t n = s.find_first_not_of('0');
	if(n == string::npos)
	{
		return "0";
	}
	return s.substr(n);
}

string remove_end_zeros(const string &str)
{
	string ans = str;

	size_t decimal_place = ans.find('.');
	if (decimal_place == string::npos)
	{
		return ans;
	}

	size_t  lastint = ans.find_last_not_of('0');

	if (lastint != string::npos && lastint > decimal_place)
	{
		ans.erase(lastint + 1);
	}
	else if (lastint == decimal_place)
	{
		ans.erase(decimal_place, string::npos);
	}
	if (decimal_place == ans.size() - 1)
	{
		ans.erase(decimal_place, 1);
	}
	if (ans[0] == '.')
	{
		ans = "0" + ans;
	}
	if (ans[0] == '-' && ans[1] == '.')
	{
		ans.insert(1, "0");
	}
	return ans;
}

void bal_len(string &num1 , string &num2)
{
    int maximum = max(num1.size(),num2.size());
    if(num1.size() < maximum)
    {
        for(int i = 0;i<(maximum - num1.size());i++)
        {
            num1 = "0" + num1;
        }
    }
    if(num2.size() < maximum)
    {
        for(int i = 0;i<(maximum - num2.size());i++)
        {
            num2 = "0" + num2;
        }
    }
}

string integer::operator+(const integer &s) const
{
	string number1 = int_num;
	string n2 = s.int_num;
	bool neg1 = (number1[0] == '-');
	bool neg2 = (n2[0] == '-');

	string num1 = neg1 ? number1.substr(1) : number1;
	string num2 = neg2 ? n2.substr(1) : n2;
	int lenumber1 = num1.length();
	int len2 = num2.length();
	if(neg1 == neg2)
	{
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
	}

	string result;
	int carry = 0;
	int sum = 0;
	for (size_t i = 0; i < max(lenumber1,len2); i++) 
	{
		sum = carry + (i < lenumber1 ? num1[i] - '0' : 0) + (i < len2 ? num2[i] - '0' : 0);
		result.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	if (carry) 
	{
		result.push_back(carry + '0');
	}
	if(neg1 != neg2)
	{
		integer a(num1);
	       	integer	b(num2);
		string subtract = a - b;
		if(neg1)
			subtract = "-" + subtract;
		reverse(subtract.begin(),subtract.end());
		result = subtract;
	}

	bool resultneg = false;

	if (neg1 && neg2) 
	{
		resultneg = true;
	} 
	reverse(result.begin(), result.end());
	result = removeextrazeroes(result);
	if(resultneg)
		result = "-" + result;
	if(result[0] == '-' && result[1] == '-')
		result = result.substr(2);
	return result;
}

string integer::operator-(const integer &s) const
{
	string num1 = int_num;
	string num2 = s.int_num;
	bool neg1 = (num1[0] == '-');
	bool neg2 = (num2[0] == '-');
	if (neg1)
	{
		num1 = num1.substr(1);
	}
	if (neg2)
	{
		num2 = num2.substr(1);
	}
	bal_len(num1 , num2);
	bool swapped = false;
	if (num1<num2)
	{
		string a;
		a = num1;
		num1 = num2;
		num2 = a;
		swapped = true;
	}
	string ans = "";
	if(neg1 == neg2)
	{
		reverse(num1.begin(),num1.end());
		reverse(num2.begin(),num2.end());

	}
	int borrow = 0;
	for(int i=0 ; i < num1.size() ; i++)
	{
		int sub = (num1[i] - '0') - (num2[i] - '0') - borrow;
		if(sub < 0)
		{
			sub += 10;
			borrow = 1;
		}
		else
		{
			borrow = 0;
		}
		ans.push_back(sub + '0');
	}
	if (neg1 && !neg2)
	{
		integer a(num1);
		integer b(num2);
		string mini_ans = a + b;
		mini_ans = "-" + mini_ans;
		reverse(mini_ans.begin(),mini_ans.end());
		ans = mini_ans;
	}if (!neg1 && neg2)
	{
		integer a(num1);
		integer b(num2);
		string mini_ans = a + b;
		reverse(mini_ans.begin(),mini_ans.end());
		ans = mini_ans;
	}
	reverse(ans.begin(),ans.end());
	ans = removeextrazeroes(ans);
	if(swapped)
	{
		ans = '-'+ ans;
	}
	if((neg1)&&(neg2))
	{
		ans = '-'+ ans ;
	}
	if((ans[0] =='-')&&(ans[1] =='-'))
	{
		ans = ans.substr(2);
	}

	return ans;   
}

string integer::operator*(const integer &s) const
{
	string num1 = int_num;
	string num2 = s.int_num;
	bool neg1 = (num1[0] == '-');
	bool neg2 = (num2[0] == '-');
	if (neg1)
	{
		num1 = num1.substr(1);
	}
	if (neg2)
	{
		num2 = num2.substr(1);
	}
	reverse(num1.begin(),num1.end());
	reverse(num2.begin(),num2.end());
	string ans , add = "0";
	for(int i=0 ; i < num2.size() ; i++)
	{
		ans = "";
		int carry = 0;
		for(int j=0 ; j < num1.size() ; j++)
		{
			int digi = ((num1[j] - '0') * (num2[i] - '0')) + carry;
			carry = digi/10;
			if (digi >= 10)
			{
				digi = digi%10;
			}
			ans.push_back(digi + '0');
		}
		reverse(ans.begin(),ans.end());
		for(int z =0 ; z < i  ; z++)
		{
			ans.push_back('0');
		}
		integer res(add);
		integer addon(ans);
		add = res + addon;
	}
	add = removeextrazeroes(add);
	if (neg1 != neg2)
	{
		add = '-' + add;
	}
	return add;
}
Float::Float()
{
	float_num="0";
}
Float::Float(string s)
{
	float_num = s;
}
Float::Float(const Float &copy)
{
	float_num = copy.float_num;
}
Float::~Float()
{
        float_num = "";
}
void Float::parse(const string &s)
{
	float_num = s;
}
void bal_size(string &num1, string &num2, int &n) 
{
	int a = num1.find('.');
	int b = num2.find('.');

	int c;
       	if(a == string::npos)
	{
		c = 0;
	}
	else
	{
		c = num1.size() - (a + 1);
	}
	int d;
	if(b == string::npos)
	{	
		d = 0;
	}
	else
	{
		d = num2.size() - (b + 1);
	}
	n = max(c, d);

	if (a == string::npos) 
	{}
	else 
	{
		num1 = num1 + string(n - c, '0');
		num1.erase(a, 1);
	}

	if (b == string::npos) 
	{
	}
	else 
	{
		num2 = num2 + string(n - d, '0');
		num2.erase(b, 1);
	}
}
string Float::operator+(const Float &s) const
{
	string num1 = float_num;
	string num2 = s.float_num;
	bool neg1 = (num1[0] == '-');
	bool neg2 = (num2[0] == '-');
	if (neg1)
	{
		num1 = num1.substr(1);
	}
	if (neg2)
	{
		num2 = num2.substr(1);
	}
	int c;
	bal_size(num1, num2, c);
	integer n1(num1);
	integer n2(num2);
	string ans;
	if (neg1 == neg2)
	{
		ans = (n1 + n2);
	}
	else
	{
		ans = (n1 - n2);
	}
	if(neg1)
	{
		ans = "-" + ans;
	}
	int len = ans.size() - c;
	ans.insert(len, ".");
	if(ans[0] == '-' && ans[1] == '-')
	{
		ans = ans.substr(2);
	}
	ans = remove_end_zeros(ans);

	return ans;
}
string Float::operator-(const Float &s) const
{
	string num1 = float_num;
	string num2 = s.float_num;
	bool neg1 = (num1[0] == '-');
	bool neg2 = (num2[0] == '-');

	if (neg1)
	{
		num1 = num1.substr(1);
	}
	if (neg2)
	{
		num2 = num2.substr(1);
	}
	int c;
	bal_size(num1, num2, c);
	integer n1(num1);
	integer n2(num2);

	string ans;
	if (neg1 != neg2)
	{
		ans = (n1 + n2);
	}
	else
	{
		ans = (n1 - n2);
	}
	if (neg1 != neg2 && ans[0] != '-')
	{
		ans = "-" + ans;
	}
	else if (neg1 && neg2 && ans[0] == '-')
	{
		ans = ans.substr(1);
	}
	int len = ans.size() - c;
	ans.insert(len, ".");
	if(ans[0] == '-' && ans[1] == '-')
	{
		ans = ans.substr(2);
	}
	ans = remove_end_zeros(ans);
	
	return ans;
}
string Float::operator*(const Float &s) const
{
	string num1 = float_num;
	string num2 = s.float_num;
	bool neg1 = (num1[0] == '-');
	bool neg2 = (num2[0] == '-');
	if (neg1 == true)
	{
		num1 = num1.substr(1);
	}
	if (neg2 == true)
	{
		num2 = num2.substr(1);
	}
	int a,b;
	for(int i = 0 ; i < num1.size() ; i++)
	{
		if (num1[i]=='.')
		{
			a = i;
			break;
		}
	}
	for(int i =0 ; i < num2.size() ; i++)
	{
		if (num2[i]=='.')
		{
			b = i;
			break;
		}
	}
	num1.erase(num1.begin()+a);
	num2.erase(num2.begin()+b);
	integer n1(num1);
	integer n2(num2);
	string sol;
	sol = n1 * n2;
	sol.insert(sol.end() - ((num1.size() - a) + (num2.size() - b)),'.');
	sol = remove_end_zeros(sol);
	return sol;
}

