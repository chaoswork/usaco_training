
/* 
ID:chaoswor1
LANG:C++
TASK:pprime
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
int A,B;
vector<int> ans;

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
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	scanf("%d %d",&A,&B);

	int i;
	for(i=1;i<10000;++i)
	{
		char tmp[16];
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"%d",i);
		int len=strlen(tmp);
		char tmp2[16];
		strcpy(tmp2,tmp);
		reverse(tmp2,tmp2+len);
		char num[16];
		strcpy(num,tmp);
		strncat(num,tmp2+1,len-1);

		if((num[0]-'0')&1)
		{
			int p=atoi(num);
			if(p>=A && p<=B && isPrime(p)) ans.push_back(p);
		}
		//printf("%s\n",num);
		num[len]=0;
		strcat(num,tmp2);
		if((num[0]-'0')&1)
		{
			int p=atoi(num);
			if(p>=A && p<=B && isPrime(p)) ans.push_back(p);
		}
	//	printf("%s\n",num);		
	}
	sort(ans.begin(),ans.end());
	for(i=0;i<ans.size();++i)
		printf("%d\n",ans[i]);
	return 0;
}
