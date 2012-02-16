/*
ID: chaoswo1
TASK: namenum
LANG: C++
*/
/**
 * As we already know,the words in 'dict.txt' is sorted by alphabetical,so
 * we just pick one and check whether it fixes to the number.If matched,
 * print it out by one single line.If none of them fixed,then print out 
 * the word "NONE".
 */
#define CHAOSWORK
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
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


string getNum(const string& name)
{
	string num="";
	for(int i=0;i<name.size();++i){
		switch (name[i]) {
		case 'A':case 'B':case 'C':num+='2';break;
		case 'D':case 'E':case 'F':num+='3';break;
		case 'G':case 'H':case 'I':num+='4';break;
		case 'J':case 'K':case 'L':num+='5';break;
		case 'M':case 'N':case 'O':num+='6';break;
		case 'P':case 'R':case 'S':num+='7';break;
		case 'T':case 'U':case 'V':num+='8';break;
		case 'W':case 'X':case 'Y':num+='9';break;

		default:
			break;
		}
	}
	return num;
}
int main()
{
    //freopen("namenum.in","r",stdin);
    //freopen("namenum.out","w",stdout);
	ifstream fin("namenum.in");
	ifstream din("dict.txt");
	ofstream fout("namenum.out");
	string num;
	fin>>num;
	
	string name;
	bool none=true;
	while(din>>name)
	{
		if(num==getNum(name))
		{
			fout<<name<<endl;
			none=false;
		}
	}
	if(none)fout<<"NONE"<<endl;

    return 0;
}


