/* 
ID:chaoswor1
LANG:C++
TASK:lamps
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
int n,c;
vector<string> ret;
int lamps[10];
queue<pair<int,int> > Q;
bool vis[100][2];
bool match(int x)
{
	int i;
	int nx[10];
	memset(nx,0,sizeof(nx));
	int len=0;
	while(x)
	{
		nx[len++]=x%2;
		x>>=1;
	}
	for(i=0;i<6;++i)
		if(lamps[i]!=-1 && lamps[i]!=nx[i]) return false;
	return true;
}
void display(int x)
{
	int nx[10];
	int len=0;
	memset(nx,0,sizeof(nx));
	while(x)
	{
		nx[len++]=x%2;
		x>>=1;
	}
	int i;
	string str;
	for(i=0;i<n;++i)
	//	cout<<nx[i%6];
	//cout<<endl;
		str+=nx[i%6]+'0';
	ret.push_back(str);
}
int main(int argc, char *argv[])
{
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	memset(lamps,-1,sizeof(lamps));
	cin>>n>>c;
	int x;
	while(cin>>x,x!=-1)
	{
		x--;
		x%=6;
		if(lamps[x]==0) 
		{
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
		lamps[x]=1;
	}
	while(cin>>x,x!=-1)
	{
		x--;
		x%=6;
		if(lamps[x]==1)
		{
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
		lamps[x]=0;
	}
	Q.push(make_pair((1<<6)-1,0));
	vis[(1<<6)-1][0]=1;
	vector<int> ans;
	while(!Q.empty())
	{
		if(Q.front().second>c) break;
		int cnt=Q.front().second;
		x=Q.front().first;
	//	cout<<x<<endl;
	//	cout<<x<<":";display(x);
		Q.pop();
		if(match(x)&& (c-cnt)%2==0) ans.push_back(x);
		int y=~x;
		y&=0x0000003f;
		if(!vis[y][(cnt+1)%2])	{vis[y][(cnt+1)%2]=1;Q.push(make_pair(y,cnt+1));}

		y=x^0x15;
		y&=0x0000003f;
		if(!vis[y][(cnt+1)%2])	{vis[y][(cnt+1)%2]=1;Q.push(make_pair(y,cnt+1));}
		
		y=x^0x2a;
		y&=0x0000003f;
		if(!vis[y][(cnt+1)%2]) {vis[y][(cnt+1)%2]=1;Q.push(make_pair(y,cnt+1));}

		y=x^0x09;
		y&=0x0000003f;
		if(!vis[y][(cnt+1)%2]) {vis[y][(cnt+1)%2]=1;Q.push(make_pair(y,cnt+1));}
	}
	//cout<<ans.size()<<endl;
	int i;
	//sort(ans.begin(),ans.end());
	for(i=0;i<ans.size();++i)
		display(ans[i]);
	if(ans.size()==0) cout<<"IMPOSSIBLE"<<endl;
	else
	{
		sort(ret.begin(),ret.end());
		for(i=0;i<ret.size();++i)
			cout<<ret[i]<<endl;
	}
	return 0;
}
