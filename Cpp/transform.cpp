/*
ID: chaoswo1
TASK: transform
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


string org[16];
string tar[16];

bool tran1(string*org,string*tar,int n)
{
	for(int oj=0,ti=0;oj<n;++oj,++ti)
		for(int oi=n-1,tj=0;oi>=0;--oi,++tj)
			if(org[oi][oj]!=tar[ti][tj]) return false;

	return true;
}
bool tr2(string*org,string*tar,int n)
{
	for(int oi=n-1,ti=0;oi>=0;oi--,ti++)
		for(int oj=n-1,tj=0;oj>=0;oj--,tj++)
			if(org[oi][oj]!=tar[ti][tj]) return false;
	return true;
}
bool tr3(string*org,string*tar,int n){
	for(int oj=0,ti=0;oj<n;oj++,ti++)
		for(int oi=n-1,tj=0;oi>=0;oi--,tj++)
			if(org[oi][oj]!=tar[ti][tj]) return false;
	return true;
}
bool tr4(string*org,string*tar,int n){
	for(int oi=0,ti=0;oi<n;oi++,ti++)
		for(int oj=n-1,tj=0;oj>=0;oj--,tj++)
			if(org[oi][oj]!=tar[ti][tj]) return false;
	return true;
}
bool tr5(string*org,string*tar,int n){

	string tmp[16];
	for(int i=0;i<n;++i)
	{
		tmp[i]=org[i];
		reverse(tmp[i].begin(),tmp[i].end());
	}

	if(tran1(tmp, tar, n)) return true;
	if(tr2(tmp, tar, n)) return true;
	if(tr3(tmp, tar, n)) return true;

	return false;
}
bool tr6(string*org,string*tar,int n){
	for(int i=0;i<n;++i)
		if(org[i]!=tar[i]) return false;
	return true;
}
int getMethods(string*org,string*tar,int n){
	if(tran1(org, tar,n)) return 1;
	if(tr2(org, tar,n)) return 2;
	if(tr3(org, tar,n)) return 3;
	if(tr4(org, tar,n)) return 4;
	if(tr5(org, tar,n)) return 5;
	if(tr6(org, tar,n)) return 6;
	return 7;
}

int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
	
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;++i)
		cin>>org[i];
	for(i=0;i<n;++i)
		cin>>tar[i];
	cout<<getMethods(org,tar,n)<<endl;

    return 0;
}


