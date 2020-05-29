#include<bits/stdc++.h>
using namespace std;
#define max_n 100005



int reset[max_n];

void kmpPre(string pat)
{
	int i = 0 , j = -1;
	while(i < pat.length())
	{
		while(j>=0 && pat[i] != pat[j])
			j = reset[j];

		i++;
		j++;
		reset[i] = j;
	}
}

vector<int> kmp(string s, string pat)
{
	vector<int> ans;
	kmpPre(pat);
	int i = 0, j = 0;

	while(i< s.length())
	{
		while(j>=0 && s[i] != pat[j])
			j = reset[j];

		i++;
		j++;
		if(j == pat.length())
		{
			ans.push_back(i-j);
			j = reset[j];
		}
	}
	return ans;
}

int main()
{
	for(int i=0;i<max_n;i++)
		reset[i] = -1;

	string s = "aabaaababaaabaabaaaababab";
	string pat = "aab";
	vector<int> ans = kmp(s,pat);

	for(int i : ans)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}