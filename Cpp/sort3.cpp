/* 
ID:chaoswor1
LANG:C++
TASK:sort3
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
const int maxn=1024;
int a[maxn];

int main(int argc, char *argv[])
{
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	cin>>N;
	int i;
	int cnt1=0;
	int cnt2=0;
	int cnt3=0;
	for(i=0;i<N;++i)
	{
		cin>>a[i];
		if(a[i]==1) ++cnt1;
		else if(a[i]==2) ++cnt2;
		else ++cnt3;
	}
	int cnt12=0;
	int cnt13=0;
	int cnt21=0;
	int cnt23=0;
	int cnt31=0;
	int cnt32=0;
	int org=0;
	for(i=0;i<N;++i)
	{
		if(i<cnt1)
		{
			if(a[i]==2) ++cnt12;
			else if(a[i]==3) ++cnt13;
			else ++org;
		}
		else if(i<cnt1+cnt2)
		{
			if(a[i]==1) ++cnt21;
			else if(a[i]==3) ++cnt23;
			else ++org;
		}
		else
		{
			if(a[i]==1) ++cnt31;
			else if(a[i]==2) ++cnt32;
			else ++org;
		}
	}
	int ans=0;
	ans+=min(cnt12,cnt21);
	ans+=min(cnt13,cnt31);
	ans+=min(cnt23,cnt32);

	ans+=(N-2*ans-org)*2/3;
	cout<<ans<<endl;
	return 0;
}
