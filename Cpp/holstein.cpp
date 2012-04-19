/* 
ID:chaoswor1
LANG:C++
TASK:holstein
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
int V;
int v[32];
int G;
int g[32][32];
int main(int argc, char *argv[])
{
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	cin>>V;
	int i,j;
	for(i=0;i<V;++i)
		cin>>v[i];
	cin>>G;
	for(i=0;i<G;++i)
	{
		for(j=0;j<V;++j)
		{
			cin>>g[i][j];
		}
	}
	int bit;
	int best=32;
	vector<int> ans;
	for(bit=1;bit<(1<<G);++bit)
	{
		int b=bit;
		vector<int> vi(G,0);
		int len=0;
		int cur=0;
		while(b)
		{
			if(b&1) ++cur;
			vi[len++]=(b&1);
			b>>=1;
		}
		vector<int> now(V,0);
		for(i=0;i<G;++i)
			if(vi[i])
			{
				for(j=0;j<V;++j)
					now[j]+=g[i][j];
			}
		for(j=0;j<V;++j)
			if(now[j]<v[j]) break;
		if(j<V) continue;
		if(cur<best)
		{
			best=cur;
			ans.clear();
			for(i=0;i<G;++i)
				if(vi[i]) ans.push_back(i+1);
		}
		
	}
	cout<<best;
	sort(ans.begin(),ans.end());
	for(i=0;i<ans.size();++i)
		cout<<" "<<ans[i];
	cout<<endl;
	return 0;
}
