/*
ID: bxu5111
TASK: namenum
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <climits>
#include <bits/stdc++.h>
using namespace std;
#define LL long long

// map<int,vector<char>> m = {{2,{'A','B','C'}},{3,{'D','E','F'}},{4,{'G','H','I'}},{5,{'J','K','L'}},{6,{'M','N','O'}},{7,{'P','R','S'}},{8,{'T','U','V'}},{9,{'W','X','Y'}}};

map<char,char> mp;

string con(string s)
{
	for(int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		s[i] = mp[c];
	}
	return s;
}
int main(void)
{
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	ifstream input("dict.txt");

 	string n;
	cin >> n;


	for(int i = 'A'; i < 'Z'; i++)
	{
		int j;
		if(i == 'Q')
			continue;
		if(i > 'Q')
			j = i;
		else
			j = i+1;
		mp[i] = j/3 -22+2 +'0';
	}
	string nm;
	int c = 0;
	while(input >> nm)
	{
		if(con(nm) == n)
		{
			cout << nm << endl;
			c++;
		}
	}
	if(c == 0)
		cout << "NONE" << endl;
	return 0;
}
