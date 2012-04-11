
/* 
ID:chaoswor1
LANG:C++
TASK:sprime
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

int N;
const int maxn=1000000;
int sprime[maxn]={2,3,5,7};
bool isPrime(int x)
{
	if(x==2) return true;
	if(x%2==0) return false;
	int i;
	for(i=3;i*i<=x;i+=2)
		if(x%i==0) return false;
	return true;
}
int main(int argc, char *argv[])
{
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	scanf("%d",&N);
	int beg=0;
	int end=4;
	while(--N)
	{
		int oldend=end;
		while(beg<oldend)
		{
			int x=sprime[beg%maxn];
			beg++;
			int k;
			for(k=1;k<10;k+=2)
			{
				int np=x*10+k;
				if(isPrime(np)) 
				{
					//printf("%d\n",np);
					sprime[end%maxn]=np;
					end++;
				}
			}
		}
	}
	for(;beg<end;++beg)
	{
		printf("%d\n",sprime[beg%maxn]);
	}


	return 0;
}
