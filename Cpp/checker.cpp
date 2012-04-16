/* 
ID:chaoswor1
LANG:C++
TASK:checker
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
int n;
int now;
int ans[16];
bool visv[16];
bool visa[32];
bool visb[32];
int cnt;
void solve(int cur)
{
	if(cur==n)
	{
		++cnt;
		if(now<3)
		{
			++now;
			int i;
			for(i=0;i<n;++i)
			{
				if(i) cout<<" ";
				cout<<ans[i]+1;
			}
			cout<<endl;
		}
		return ;
	}
	int i;
	for(i=0;i<n;++i)
	{
		if(!visv[i] && !visa[i+cur] && !visb[i-cur+16])
		{
			ans[cur]=i;
			visv[i]=true;
			visa[i+cur]=true;
			visb[i-cur+16]=true;
			solve(cur+1);
			visv[i]=false;
			visa[i+cur]=false;
			visb[i-cur+16]=false;
		}
	}
}

int main(int argc, char *argv[])
{
	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);
	cin>>n;
	solve(0);
	cout<<cnt<<endl;
	return 0;
}
