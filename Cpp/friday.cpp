/*
ID: chaoswo1
TASK: friday
LANG: C++
*/

/*
just a sim problem,define a number for the thirteenth day of this month,
its remainder when mod 7 is the day of this week.Then add the number of this
month is the next month's thirteenth day.
Count the days of week month after month.
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

/*month to add*/
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int cnt[7];
int is_leap(int y)//leap year judge
{
	if(y%400==0 || (y%4==0&&y%100!=0)) return 1;
	return 0;
}
int main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
	
	int n;
	cin>>n;
	/*as an index,this num represents the thirteenth day 
	of each month,this num mod 7 is the day of the week,
	0 for Sunday.
	*/
	int thirteen=13;
	int i;
	for(i=1900;i<1900+n;++i)
	{
		int j;
		for(j=0;j<12;++j)
		{
			thirteen%=7;
			cnt[thirteen]++;
			if(j==1)thirteen+=is_leap(i)+month[j];
			else thirteen+=month[j];
		}
	}
	cout<<cnt[6];
	for(i=0;i<6;++i)
		cout<<" "<<cnt[i];
	cout<<endl;
    return 0;
}


