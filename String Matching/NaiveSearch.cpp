#include<bits/stdc++.h>
using namespace std;

void NaiveSearch(string s, string pat)
{
	for(int i=0 ; i< s.size() - pat.size() ; i++)
	{
		int j;
		for(j=0 ; j<pat.size() ; j++)
		{
			if(s[i+j] != pat[j])
				break;
		}
		if(j == pat.size())
			cout<<"Pattern found at "<<i<<endl; 
	}
}

int main()
{
	string s = "aababaabaaababaaabaa", pattern = "aab";
	NaiveSearch(s,pattern);

	return 0;
}