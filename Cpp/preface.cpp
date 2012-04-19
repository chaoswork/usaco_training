/* 
ID:chaoswor1
LANG:C++
TASK:preface
 */
#include<iostream>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

using namespace std;

typedef long long LL;

string RM="IVXLCDM===";
int idx[4]={8,6,4,2};
int ret[16];
string getD(int x,int b)
{
	string ans;
	int i;
	if(x==9) 
	{
		ans+=RM[b-2];
		ans+=RM[b];
	}
	else if(x<9 && x>=5)
	{
		ans+=RM[b-1];
		for(i=0;i<x-5;++i)
			ans+=RM[b-2];
	}
	else if(x==4)
	{
		ans+=RM[b-2];
		ans+=RM[b-1];
	}
	else if(x<4 && x>0)
	{
		for(i=0;i<x;++i)
			ans+=RM[b-2];
	}
	return ans;
}
string toRaman(int n)
{
	string ans;
	int base=1000;
	int i=0;
	while(n)
	{
		ans+=getD(n/base,idx[i++]);
		n%=base;
		base/=10;
	}
	return ans;
}
int main(int argc, char *argv[])
{
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	int n;
	cin>>n;

	int i;
	map<char,int> mp;
	for(i=0;i<RM.size();++i)
		mp.insert(make_pair(RM[i],i));
	for(i=1;i<=n;++i)
	{
		string s=toRaman(i);
		int j;
		for(j=0;j<s.size();++j)
			ret[mp[s[j]]]++;
	}
	for(i=0;i<16;++i)
	{
		if(ret[i]) cout<<RM[i]<<" "<<ret[i]<<endl;
	}
	return 0;
}
