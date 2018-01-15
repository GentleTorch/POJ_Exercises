#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<string>

using namespace std;

int main()
{
	int value[26];
	int occur[26];
	int result;
	int len;
	int i;

	int nCase;
	char originStr[10000] = { 0 };
	char expStr[10000];
	string exp;

	int factor;

	cin >> nCase;
	getchar();

	while (nCase--)
	{
		getline(cin, exp);
		memcpy(originStr, exp.c_str(), exp.length());
		len = 0;

		for (i = 0;i < exp.length();i++)
		{
			if (originStr[i] != ' ')
				expStr[len++] = originStr[i];
		}

		for (i = 0;i < 26;i++)
		{
			value[i] = i + 1;
			occur[i] = 0;
		}

		result = 0;
		i = 0;
		factor = 1;

		while (i < len)
		{
			if (expStr[i] == '+' || expStr[i] == '-')
			{
				if (expStr[i] == '+'&&expStr[i + 1] == '+')
				{
					i += 2;
					value[expStr[i] - 'a'] += 1;
				}
				else if (expStr[i] == '-'&&expStr[i + 1] == '-')
				{
					i += 2;
					value[expStr[i] - 'a'] -= 1;
				}
				else
				{
					factor = (expStr[i] == '+' ? 1 : -1);
					i++;
				}
			}
			else if (isalpha(expStr[i]))
			{
				occur[expStr[i] - 'a'] = 1;
				result += factor*value[expStr[i] - 'a'];

				if (expStr[i + 1] == '+'&&expStr[i + 2] == '+')
				{
					value[expStr[i] - 'a'] += 1;
					i += 2;
				}
				else if (expStr[i + 1] == '-'&&expStr[i + 2] == '-')
				{
					value[expStr[i] - 'a'] -= 1;
					i += 2;
				}
				else
					i++;
			}
		}

		cout << "Expression: " << exp << endl;
		cout << "value = " << result << endl;
		for (i = 0;i < 26;i++)
		{
			if (occur[i])
			{
				cout << char(i + 'a') << " = " << value[i] << endl;
			}
		}
	}

	return 0;

}
