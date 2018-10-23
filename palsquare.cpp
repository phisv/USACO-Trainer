/*
ID: bxu5111
TASK: palsquare
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
#include <array>
#include <bits/stdc++.h>
using namespace std;
#define LL long long

int n;
map<int,string> mp = {{0,"0"},{1,"1"},{2,"2"},{3,"3"},{4,"4"},{5,"5"},{6,"6"},{7,"7"},{8,"8"},{9,"9"},{10,"A"},{11,"B"},{12,"C"},{13,"D"},{14,"E"},{15,"F"},{16,"G"},{17,"H"},{18,"I"},{19,"J"}};
string con(int i)
{
	stack<string> q;
	string ans = "";
	while(i > 0)
	{
		q.push(mp[i%n]);
		i /= n;
	}
	while(q.size() > 0)
	{
		ans += q.top();
		q.pop();
	}
	return ans;
}
bool pal(string s)
{
	for(int i = 0; i < s.length(); i ++)
	{
		if(s[i] != s[s.length()-i-1])
		{
			return false;
		}
	}
	return true;
}

int main(void)
{
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;
	for(int i = 1; i <= 300; i++)
	{
		string a = con(i);
		string s = con(i*i);
		if(pal(s))
			cout << a << " " << s << endl;
	}
	// for(int i = 1; i < 130; i++)
	// cout << con(i) << endl;
	return 0;
}
