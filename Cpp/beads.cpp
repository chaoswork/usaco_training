/*
ID: chaoswo1
TASK: beads
LANG: C++
*/

/*
you can append the given string,so it looks like a longer necklace.
then find the point from left to right,determine the best point to 
get the longest substring as the problem said.
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
string necklace;
int best;
void find_largest(int p)
{
	int maxlen=0;
	int i;
	for(i=p;i>=0;--i)//from p to i,all is red
		if(necklace[i]=='b') break;
	maxlen+=p-i;
	for(i=p+1;i<necklace.size();++i)// from p+1 to i,all is blue
		if(necklace[i]=='r') break;
	maxlen+=i-p-1;
	if(best<maxlen) best=maxlen;

	maxlen=0;

	for(i=p;i>=0;--i)//from p to i ,all is blue
		if(necklace[i]=='r') break;
	maxlen+=p-i;
	for(i=p+1;i<necklace.size();++i)//from p+1 to i,all is red
		if(necklace[i]=='b') break;
	maxlen+=i-p-1;
	if(best<maxlen) best=maxlen;
}
int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
	int n;
	
	cin>>n;
	cin>>necklace;
	necklace+=necklace;
	int i;
	for(i=0;i<necklace.size();++i)
		find_largest(i);
	if(best>n) best=n;
	cout<<best<<endl;
    return 0;
}


