
/* 
ID:chaoswor1
LANG:C++
TASK:calfflac
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

const int maxn=20000+10;
char s[maxn];
char t[maxn<<1];
int idx[maxn<<1];
int R[maxn<<1];
int tlen;
void manacher()
{
	int id=0;
	int mx=0;
	int i;
	for(i=1;i<tlen;++i)
	{
		R[i]=mx>i?min(mx-i,R[id*2-i]):1;
		while(i+R[i]<tlen && i-R[i]>=0 &&
				t[i+R[i]]==t[i-R[i]]) ++R[i];
		if(mx<i+R[i])
		{
			mx=i+R[i];
			id=i;
		}
	}
}

int main(int argc, char *argv[])
{
	freopen("calfflac.in","r",stdin);
	freopen("calfflac.out","w",stdout);
	int n;
	while(gets(t))
	{
		int len=strlen(s);
		if(len)
		{
			s[len]='\n';
			s[len+1]=0;
		}
		strcat(s,t);
	}

	int i;
//	for(i=0;i<strlen(s);++i)
//		printf("%c",s[i]);
	int len=strlen(s);
	t[tlen++]='@';
	for(i=0;i<len;++i)
	{
		if(!isalpha(s[i])) continue;
		t[tlen++]='#';
		t[tlen]=tolower(s[i]);
		idx[tlen++]=i;
	}
	t[tlen++]='#';
	//printf("%s\n",t);
	manacher();
	int mxR=-1;
	int id=-1;
	for(i=1;i<tlen;++i)
		if(mxR<R[i])
		{
			mxR=R[i];
			id=i;
		}
	int beg;
	int end;


	printf("%d\n",(R[id]-1));
	beg=id-R[id]+2;
	end=id+R[id]-2;
	int cnt=0;
	for(i=idx[beg];i<=idx[end];++i)
	{
		printf("%c",s[i]);
	}
	printf("\n");
	return 0;
}
