/*
ID: chaoswo1
TASK: gift1
LANG: C++
*/
#define CHAOSWORK
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

class account;
vector<account> people;
map<string,int> Index;
class account{
public:
	account(){}
	account(string _name,int _num)
		:name(_name),num(_num),org(_num){}
	
	void addFriend(string);
	void giveMoney();
	void getMoney(int);
	void display()const;
	
private:
	int org;
	int num;
	string name;
	vector<string> give;
};

void account::addFriend(string str)
{
	give.push_back(str);
}
void account::giveMoney()
{
	int i;
	if(give.size()==0) return;
	int m=org/give.size();
	num-=m*give.size();
	for(i=0;i<give.size();++i)
	{
		people[Index[give[i]]].getMoney(m);
	}
}
void account::getMoney(int m)
{
	num+=m;
}
void account::display() const
{
	cout<<name<<" "<<num-org<<endl;
}


int main()
{
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
	
	int NP;
	cin>>NP;
	int i;
	string name;
	for(i=0;i<NP;++i)
	{
		cin>>name;
		Index[name]=i;
	}
	people.resize(NP);
	for(i=0;i<NP;++i)
	{
		cin>>name;
		int acc,n;
		cin>>acc>>n;
		people[Index[name]]=account(name,acc);
		int j;
		for(j=0;j<n;++j)
		{
			string fname;
			cin>>fname;
			people[Index[name]].addFriend(fname);
		}
	}
	for(i=0;i<people.size();++i)
		people[i].giveMoney();
	for(i=0;i<people.size();++i)
		people[i].display();
    return 0;
}


