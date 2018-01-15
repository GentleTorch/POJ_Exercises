#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string expression;
	int nCase;

	int result, value[26] = { 0 };
	bool occur[26] = { 0 };
	int i, j;
	char varChar;

	while (cin >> nCase)
	{
		while (nCase--)
		{
			getline(cin, expression);





			cout << "Expression: " << expression << endl;
			cout << "value: " << result << endl;
			for (i = 0;i < 26;i++)
			{
				if (occur[i])
				{
					varChar = 'a' + i;
					cout << varChar << " = " << value[i] << endl;
				}

			}
		}
	}


}