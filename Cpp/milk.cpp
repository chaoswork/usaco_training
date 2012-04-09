/* 
ID: chaoswor1
LANG: C++
TASK: milk
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

int main(int argc, char *argv[])
{
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	int n,m;
	scanf("%d %d",&m,&n);
	vector<pair<int,int> >vp;
	int i;
	for(i=0;i<n;++i)
	{
		int p,a;
		scanf("%d %d",&p,&a);
		vp.push_back(make_pair(p,a));
	}
	sort(vp.begin(),vp.end());
	int ans=0;
	for(i=0;i<vp.size();++i)
	{
		int cnt=vp[i].second;
		if(m-cnt<=0)
		{
			ans+=vp[i].first*m;
			break;
		}
		else
		{
			ans+=vp[i].first*cnt;
			m-=cnt;
		}
	}
	printf("%d\n",ans);
	return 0;
}
