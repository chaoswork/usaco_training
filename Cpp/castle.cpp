/* 
ID:chaoswor1
LANG:C++
TASK:castle
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
int M,N;
const int maxn=64;
int castle[maxn][maxn];
int color[maxn][maxn];
int sz[maxn*maxn];
int cnt;
void FloodFill(int x,int y,int c)
{
	if(x<0 || x>=N) return ;
	if(y<0 || y>=M) return ;
	if(color[x][y]) return;

	color[x][y]=c;
	++sz[c];
	if(!(castle[x][y]&1)) FloodFill(x,y-1,c);
	if(!(castle[x][y]&2)) FloodFill(x-1,y,c);
	if(!(castle[x][y]&4)) FloodFill(x,y+1,c);
	if(!(castle[x][y]&8)) FloodFill(x+1,y,c);
}
int main(int argc, char *argv[])
{
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	cin>>M>>N;
	int i,j;
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			cin>>castle[i][j];
	cnt=1;
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			if(color[i][j]==0)
				FloodFill(i,j,cnt++);
	cout<<--cnt<<endl;
//	for(i=1;i<=cnt;++i) cout<<sz[i]<<endl;
//	for(i=0;i<N;++i)
//	{
//		for(j=0;j<M;++j)
//			cout<<color[i][j]<<" ";
//		cout<<endl;
//	}	
	int maxsz=-1;
	for(i=1;i<=cnt;++i)
		if(maxsz<sz[i]) maxsz=sz[i];
	cout<<maxsz<<endl;
	int best=0;
	int x=-1;
	int y=-1;
	char d=-1;
	for(j=0;j<M;++j)
		for(i=N-1;i>=0;--i)
		{
			if(i-1>=0 && castle[i][j]&2 && color[i][j]!=color[i-1][j] && 
					sz[color[i][j]]+sz[color[i-1][j]]>best)
			{
				best=sz[color[i][j]]+sz[color[i-1][j]];
				x=i;
				y=j;
				d='N';
			}
			if(j<M-1 && castle[i][j]&4 && color[i][j]!=color[i][j+1] && 
					sz[color[i][j]]+sz[color[i][j+1]]>best)
			{
				best=sz[color[i][j]]+sz[color[i][j+1]];
				x=i;
				y=j;
				d='E';
			}
		}
	cout<<best<<endl;
	cout<<x+1<<" "<<y+1<<" "<<d<<endl;
	return 0;
}
