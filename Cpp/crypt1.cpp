
/* 
ID:chaoswor1
LANG:C++
TASK:crypt1
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

int num[10];
bool vis[10];
bool check(int x,int len)
{
	char tmp[10];
	sprintf(tmp,"%d",x);
	if(len!=strlen(tmp)) return false;
	int i;
	for(i=0;i<len;++i)
		if(!vis[tmp[i]-'0']) return false;
	return true;

}
int main(int argc, char *argv[])
{
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;++i)
	{
		cin>>num[i];
		vis[num[i]]=true;
	}
	int A,B,C,D,E;
	int cnt=0;
	for(A=0;A<n;++A)
		for(B=0;B<n;++B)
			for(C=0;C<n;++C)
			{
				int x=num[A]*100+num[B]*10+num[C];
				bool ck1=false;
				for(D=0;D<n;++D)
				{
					ck1=check(x*num[D],3);
					for(E=0;E<n;++E)
					{
						bool ck2=check(x*num[E],3);
						bool ck3=check(x*num[D]+x*num[E]*10,4);
						if(ck1 && ck2 && ck3) cnt++;
					}
				}

			}
	cout<<cnt<<endl;
	return 0;
}
