/* 
ID:chaoswor1
LANG:C++
TASK:palsquare
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
char *s="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int* swapB(int x,int B,int &len)
{
	int *num=new int[maxn];
	len=0;
	while(x)
	{
		num[len++]=x%B;
		x/=B;
	}
	reverse(num,num+len);
	//fputs(num,stderr);
	return num;
}
void printI(int i,int B)
{
	int len;
	int *digit=swapB(i*i,B,len);
	
	int j;
	for(j=0;j+j<len;++j)
		if(digit[j]!=digit[len-j-1]) break;
	if(j+j<len) return;
	int leni;
	int* I=swapB(i,B,leni);
	for(j=0;j<leni;++j)
		printf("%c",s[I[j]]);
	printf(" ");
	for(j=0;j<len;++j)
		printf("%c",s[digit[j]]);
	printf("\n");
	delete []digit;
	delete []I;
}
int main(int argc, char *argv[])
{
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	int B;
	scanf("%d",&B);

	int i;
	for(i=1;i<=300;++i)
	{
		printI(i,B);
	}

	return 0;
}
