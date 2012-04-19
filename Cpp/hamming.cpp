/* 
ID:chaoswor1
LANG:C++
TASK:hamming
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

int N,B,D;
int main(int argc, char *argv[])
{
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	
	cin>>N>>B>>D;
	vector<int>ans;
	ans.push_back(0);
	int bit=1;
	while(true)
	{
		int i;
		for(i=0;i<ans.size();++i)
		{
			int x=bit^ans[i];
			int cnt=0;
			while(x)
			{
				cnt+=x&1;
				x>>=1;
			}
			if(cnt<D) break;
		}
		if(i==ans.size()) ans.push_back(bit);
		bit++;
		if(ans.size()>=N) break;
	}
	for(bit=0;bit<ans.size();++bit)
	{
		if(bit && bit%10==0) cout<<endl;
		if(bit%10) cout<<" ";
		cout<<ans[bit];
	}
	cout<<endl;
	return 0;
}
