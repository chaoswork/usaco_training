/* 
ID:chaoswor1
LANG:C++
TASK:runround
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

bool isrd(LL m)
{
	char num[1024];
	bool vis[1024];
	memset(vis,0,sizeof(vis));

	sprintf(num,"%lld",m);
	int i;
	int len=strlen(num);
	bool unq[10];
	memset(unq,0,sizeof(unq));
	for(i=0;i<len;++i)
	{
		if(num[i]-'0'==0) return false;
		if(unq[num[i]-'0']) return false;
		unq[num[i]-'0']=true;
	}
	
	i=0;
	while(!vis[i])
	{
		vis[i]=true;
		i=(i+num[i]-'0')%len;
	}
	if(i!=0) return false;
	for(i=0;i<len;++i) if(!vis[i]) break;
	return i==len;
}
int main(int argc, char *argv[])
{
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	LL M;
	cin>>M;
	while(true)
	{
		M++;
		if(isrd(M)) 
		{
			cout<<M<<endl;
			break;
		}
	}

	return 0;
}
