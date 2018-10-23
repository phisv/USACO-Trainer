/*
ID: bxu5111
TASK: beads
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

int n;
vector<char> v;
int maxlen = 0;
int in(int x) //index mod v.size()
{
	if(x >= 0 && x < v.size())
		return x;
	while(x < 0)
		x += v.size();
	while(x >= v.size())
		x -= v.size();
	return x;
}
int main(void)
{
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		v.push_back(c);
	}
	for(int i = 0; i < n; i++) //cut index
	{
		int rlen = 0;
		int llen = 0;
		char r = v[in(i)];
		char l = v[in(i-1)];
		int rid = in(i);
		int lid = in(i-1);
		while(true)
		{
			rid++;
			rlen++;
			if(in(rid) == in(i))
				break;
			if(r == 'w' && v[in(rid)] != 'w')
				r = v[in(rid)];
			if(v[in(rid)] != r && v[in(rid)] != 'w')
				break;
		}
		while(true)
		{
			lid--;
			llen++;
			if(in(lid) == in(i))
				break;
			if(l == 'w' && v[in(lid)] != 'w')
					l = v[in(lid)];
			if(v[in(lid)] != l && v[in(lid)] != 'w')
				break;
		}
		// cout << rlen << " " << llen << endl;
		int templen = min(rlen+llen,n);
		maxlen = max(templen,maxlen);
	}
	cout << maxlen << endl;
	return 0;
}
