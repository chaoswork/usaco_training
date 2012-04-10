/* 
ID:chaoswor1
LANG:C++
TASK:clocks
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

int clocks[9];
int tmp[9];
int num[9];
char seq[9][9]={
	"ABDE\0",
	"ABC\0",
	"BCEF\0",
	"ADG\0",
	"BDEFH\0",
	"CFI\0",
	"DEGH\0",
	"GHI\0",
	"EFHI\0"
};
int best;
vector<int> ans;
int main(int argc, char *argv[])
{
	freopen("clocks.in","r",stdin);
	freopen("clocks.out","w",stdout);
	best=1<<20;
	int i,j;
	for(i=0;i<9;++i)
	{
		scanf("%d",clocks+i);
		clocks[i]/=3;
		if(clocks[i]==4) clocks[i]=0;
	}
	int end=pow(4,9);
	for(i=0;i<end;++i)
	{
		int I=i;
		int cnt=0;
		bool noway=false;
		memcpy(tmp,clocks,sizeof(clocks));
		for(j=0;j<9;++j)
		{
			num[j]=I%4;
			cnt+=num[j];
			int k;
			for(k=0;k<strlen(seq[j]);++k)
				tmp[seq[j][k]-'A']+=num[j];
			I/=4;
		}
		for(j=0;j<9;++j) if(tmp[j]%4!=0) break;
		if(j<9) continue;
		if(best>cnt)
		{
			best=cnt;
			ans.clear();
			for(j=0;j<9;++j)
				while(num[j]--) ans.push_back(j+1); 
		}

		
	}
	for(i=0;i<ans.size();++i)
	{
		if(i)printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}
