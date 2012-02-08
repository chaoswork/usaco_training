/*
ID: chaoswo1
TASK: ride
LANG: C++
*/
#define CHAOSWORK
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

int getMod(const string& str)
{
	int i;
	int res=1;
	for(i=0;i<str.size();++i)
	{
		res*=(str[i]-'A')+1;
		res%=47;
	}
	return res;
}

int main()
{
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
	string comet;
	string group;
	cin>>comet;
	cin>>group;
	if(getMod(comet)!=getMod(group))
		cout<<"STAY"<<endl;
	else cout<<"GO"<<endl;
	
    return 0;
}


