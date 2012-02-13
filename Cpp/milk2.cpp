/*
ID: chaoswo1
TASK: milk2
LANG: C++
*/

/**
 *  first,sort each farmer's milk time with the begin time,
 *  then determine a time interval [s,e],meaning the current time interval always has a cow,
 *  check the sorted milk time,when a new time interval came,only three situations:
 *  1.this farmer's end time still in the [s,e] interval,this doesn't make any sense.
 *  2.this farmer's end time is after e but the begin time still in the [s,e] interval,then update 
 *    the [s,e] interval to [s,current_farmer.endtime],and also update the longest milk time.
 *  3.this farmer's begin time is after e,then the current time interval should update to 
 *    [current_farmer.begintime,current_farmet.endtime],but before this we must update the longest no
 *    milk time by checking the time interval [e,current_farmer.begintime].
 *  when all the farmers time has been checked,we already had the answers.
 *  
 *  
 *  
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

typedef struct node{
	int beg;
	int end;
	node(){}
	node(int b,int e):beg(b),end(e){}
}node;

node farmers[5010];
bool cmp(node x,node y)
{
	return x.beg<y.beg;
}
int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;++i)
	{
		int b,e;
		cin>>b>>e;
		farmers[i]=node(b,e);
	}
	sort(farmers,farmers+n,cmp);

	int s=farmers[0].beg;
	int e=farmers[0].end;
	int milk=e-s;
	int nomilk=0;
	for(i=1;i<n;++i)
	{
		if(farmers[i].end<=e);
		else if(farmers[i].beg<=e && farmers[i].end>e)
		{
			e=farmers[i].end;
			if(e-s>milk) milk=e-s;
		}
		else if(farmers[i].beg>e)
		{
			if(nomilk<farmers[i].beg-e)
				nomilk=farmers[i].beg-e;
			s=farmers[i].beg;
			e=farmers[i].end;
			if(milk<e-s) milk=e-s;
		}
	}
	cout<<milk<<" "<<nomilk<<endl;
    return 0;
}


