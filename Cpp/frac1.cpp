/* 
ID:chaoswor1
LANG:C++
TASK:frac1
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

int N;
void printFrac(int u1,int d1,int u2,int d2)
{
	if(d1+d2>N) return;
	printFrac(u1,d1,u1+u2,d1+d2);
	cout<<u1+u2<<"/"<<d1+d2<<endl;
	printFrac(u1+u2,d1+d2,u2,d2);
}
int main(int argc, char *argv[])
{
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	cin>>N;
	cout<<0<<"/"<<1<<endl;
	printFrac(0,1,1,1);
	cout<<1<<"/"<<1<<endl;

	return 0;
}
