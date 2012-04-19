/* 
ID:chaoswor1
LANG:C++
TASK:subset
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
LL dp[64][1600];

LL getRes(LL n,LL m)
{
	LL &ret=dp[n][m];
	if(ret>=0) return ret;
	if(m==n*(n+1)/2) return ret=1;
	if(m>n*(n+1)/2) return ret=0;
	if(m==0) return ret=1;
	ret=0;
	if(m-n>=0)ret=getRes(n-1,m-n);
	ret+=getRes(n-1,m);
	return ret;
}
int main(int argc, char *argv[])
{
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	int m=n*(n+1)/2;
	if(m&1) cout<<0<<endl;
	else cout<<getRes(n,m/2)/2<<endl;

	return 0;
}
