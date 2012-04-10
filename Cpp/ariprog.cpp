
/* 
ID:chaoswor1
LANG:C++
TASK:ariprog
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
const int maxn=250*250*2+10;
bool ok[maxn];
int main(int argc, char *argv[])
{
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	
	int n,m;
	int i,j;
	scanf("%d %d",&n,&m);
	int maxm=m*m*2;
	for(i=0;i<=m;++i)
		for(j=0;j<=m;++j)
			ok[i*i+j*j]=true;
	vector<int> vi;
	for(i=0;i<=maxm;++i)
		if(ok[i]) vi.push_back(i);
	vector<pair<int,int> > vp;
	for(i=0;i<vi.size();++i)
	{
		for(j=i+1;j<vi.size();++j)
		{
			int k;
			int d=vi[j]-vi[i];
			int a=vi[i];
			if(a+(n-1)*d>maxm) break;
			for(k=0;k<n;++k)
			{
				if(!ok[a]) break;
				a+=d;
			}
			if(k<n) continue;
			vp.push_back(make_pair(d,vi[i]));
		}
	}
	if(vp.size()==0)
	{
		printf("NONE\n");
		return 0;
	}
	sort(vp.begin(),vp.end());
	for(i=0;i<vp.size();++i)
		printf("%d %d\n",vp[i].second,vp[i].first);
	return 0;
}
