
/* 
ID:chaoswor1
LANG:C++
TASK:numtri
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

int sum[1024][2];
int main(int argc, char *argv[])
{
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	
	int n;
	cin>>n;
	int i,j,x;
	int ans=-1;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=i;++j)
		{
			cin>>sum[j][i%2];
			sum[j][i%2]+=max(sum[j-1][(i+1)%2],sum[j][(i+1)%2]);
//			cout<<sum[j][i%2]<<" ";
			if(ans<sum[j][i%2]) ans=sum[j][i%2];
		}
//		cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
