
/* 
ID:chaoswor1
LANG:C++
TASK:milk3
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
const int maxn=32;
bool vis[maxn][maxn][maxn];
set<int> ans;
int A,B,C;
void dfs(int a,int b,int c)
{
	if(a==0)
	{
		ans.insert(c);
	}
	if(vis[a][b][c]) return;
	vis[a][b][c]=true;

	//a->c
	if(c!=C) dfs(a-min(a,C-c),b,c+min(a,C-c));
	//a->b
	if(b!=B) dfs(a-min(a,B-b),b+min(a,B-b),c);
	//b->a
	if(a!=A) dfs(a+min(A-a,b),b-min(A-a,b),c);
	//b->c
	if(c!=C) dfs(a,b-min(b,C-c),c+min(b,C-c));
	//c->a
	if(a!=A) dfs(a+min(c,A-a),b,c-min(c,A-a));
	//c->b
	if(b!=B) dfs(a,b+min(B-b,c),c-min(B-b,c));


}
int main(int argc, char *argv[])
{
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	int a,b,c;
	scanf("%d %d %d",&A,&B,&C);
	dfs(0,0,C);
	
	vector<int> res(ans.begin(),ans.end());
	for(int i=0;i<res.size();++i)
	{
		if(i) printf(" ");
		printf("%d",res[i]);
	}
	printf("\n");
	return 0;
}
