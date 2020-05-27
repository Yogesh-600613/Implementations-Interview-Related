#include<bits/stdc++.h>
#define ll long long int
#define prime 17
using namespace std;



ll calhash(string s, int n)
{
	ll ans =0;
	for(int i=0 ; i<n ; i++)
	{
		ans += (ll)s[i] * (ll)pow(prime,i);
	}
	return ans;
}


ll recalhash(string s, int oldi, int newi, ll oldhash, int patlength)
{
	ll newhash = oldhash - s[oldi];
	newhash/= patlength;
	newhash += (ll)s[newi] * (ll)pow(prime,patlength-1);
	return newhash;
}

bool naivecompare(string s1,string s2, int start1, int end1, int start2, int end2)
{
	if(end1 - start1 != end2 - start2)
		return false;
	for(int i = start1, j=start2 ; i<=end1, j<=end2 ; i++,j++)
		if(s1[i] != s2[j])
			return false;
	return true;
}


int main()
{

	string s = "aabaaababaaabaabaaaababab";
	string pat = "aab";
	ll pathash = calhash(pat,pat.length());
	ll shash = calhash(s,pat.length());

	for(int i=0 ; i<=s.length() - pat.length() ; i++) 
	{
		cout<<"Current i is "<<i<<endl;
		cout<<"shash is "<<shash<<" pathash is "<<pathash<<endl;
		if( pathash == shash and naivecompare(s,pat,i,i+pat.length()-1, 0,pat.length()-1) )
			cout<<"Pattern Found At "<<i<<endl;
		if(i < s.length() - pat.length())
			shash = recalhash(s, i, i+pat.length(), shash, pat.length());
	}

	return 0;
}