/* 
ID:chaoswor1
LANG:C++
TASK:prefix
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
vector<string> vs;
string S;
bool ok[200000+100];
int main(int argc, char *argv[])
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	string str;
	S="#";
	ok[0]=1;
	while(cin>>str,str!=".")
		vs.push_back(str);
	while(cin>>str)
		S+=str;
	int i,j;
	for(i=1;i<=S.size();++i)
	{
		for(j=0;j<vs.size();++j)
		{
			int k;
			if(i-vs[j].size()<0) continue;
			for(k=0;k<vs[j].size();++k)
				if(S[i-k]!=vs[j][vs[j].size()-1-k]) break;
			if(k==vs[j].size()&&ok[i-k])
			{
				ok[i]=true;
				break;
			}
		}
	}
	for(i=S.size();i>0;--i) if(ok[i]==1) break;
	cout<<i<<endl;
	return 0;
}
