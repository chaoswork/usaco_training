/* 
ID:chaoswor1
LANG:C++
TASK:dualpal
*/
#include<iostream>
#include<sstream>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<numeric>
#include<algorithm>
#include<limits>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

typedef long long LL;

const int maxn=1024;
char *s="0123456789";
char* swapB(int x,int B)
{
	char* digit=new char[maxn];
	int len=0;
	while(x)
	{
		digit[len++]=s[x%B];
		x/=B;
	}
	digit[len]=0;
	return digit;
}
bool ispal(char *s)
{
	int i;
	int len=strlen(s);
	for(i=0;i+i<len;++i)
		if(s[i]!=s[len-i-1]) break;
	if(i+i<len) return false;
	return true;
}
bool solve(int s)
{
	int b;
	int cnt=0;
	for(b=2;b<11;++b)
	{
		char *num=swapB(s,b);
		if(ispal(num)) ++cnt;
		delete []num;
	}
	return cnt>=2;
}
int main(int argc, char *argv[])
{
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	int n,s;
	scanf("%d %d",&n,&s);
	while(n)
	{
		if(solve(++s)) 
		{
			printf("%d\n",s);
			--n;
		}
	}

	return 0;
}
