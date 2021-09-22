#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	int i, j, k, l = 0, p = 0, total = 0, ll, lr, intv = 0, q = 0;
	string org, words, ans, str1, str2;
	cin >> org;
	cin >> words;
	cin >> ans;
	ofstream out(ans);
	ifstream in1(org);
	if (!in1)
		out << "org open error!" << endl;
	while (getline(in1, str1))
	{
		l++;
		ifstream in2(words);
		if (!in2)
			out << "words open error!" << endl;
		while (getline(in2, str2))
		{
			if (str2[0] > 0)
			{
				for (i = 0;i < str1.size();i++)
				{
					if (str2[0] == str1[i] || str2[0] + 32 == str1[i] || str2[0] - 32 == str1[i])
					{
						ll = i;
						q = 0;
						intv = 0;
						for (j = i;j < str1.size();j++)
						{
							intv++;
							if (intv > 20)
							{
								p = 0;
								break;
							}
							if (str2[q] == str1[j] || str2[q] + 32 == str1[j] || str2[q] - 32 == str1[j])
							{
								q++;
								intv = 0;
								if (q == str2.size())
								{
									p = 1;
									lr = j;
									break;
								}
							}
						}
					}
					if (p)
					{
						total++;
						out << "Line" << l << ":<" << str2 << '>';
						for (k = ll;k <= lr;k++)
							out << str1[k];
						out << endl;
						p = 0;
					}
				}
			}
			else
				for (i = 0;i < str1.size();i++)
				{
					if (str2[0] == str1[i] && str2[1] == str1[i + 1] && str2[2] == str1[i + 2])
					{
						ll = i;
						q = 0;
						intv = 0;
						for (j = i;j < str1.size();j++)
						{
							intv++;
							if (intv > 23)
							{
								p = 0;
								break;
							}
							if (str2[q] == str1[j] && str2[q + 1] == str1[j + 1] && str2[q + 2] == str1[j + 2])
							{
								q = q + 3;
								intv = 0;
								if (q == str2.size())
								{
									p = 1;
									lr = j + 2;
									break;
								}
							}
						}
					}
					if (p)
					{
						total++;
						out << "Line" << l << ":<" << str2 << '>';
						for (k = ll;k <= lr;k++)
							out << str1[k];
						out << endl;
						p = 0;
					}
				}
		}
		in2.close();
	}
	out << "Total:" << total;
	out.close();
	return 0;
}

