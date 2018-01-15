#include<iostream>
#include<cstring>
#include<string>

using namespace std;

const int MAXN = 65;

int main()
{
	int num;
	string name[MAXN];
	cin >> num;
	int i;
	int pos[MAXN];

	for (i = 0;i < num;i++)
	{
		cin >> name[i];
		pos[i] = i;
	}


	int w, s;
	char c;
	cin >> w >> c >> s;

	w = (w + num - 1) % num;
	do
	{
		if (num == 0)break;
		w = (w + s - 1) % num;
		cout << name[pos[w]] << endl;

		for (i = w;i < num;i++)
		{
			pos[i] = pos[i + 1];
		}

	} while (num--);



	
	return 0;

}