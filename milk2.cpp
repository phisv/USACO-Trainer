/*
ID: bxu5111
TASK: milk2
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
priority_queue<int,vector<int>,greater<int>> q;
map<int,int> m;

int main(void)
{
	// freopen("milk2.in", "r", stdin);
	// freopen("milk2.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x,y;
		cin >> x >> y;
		q.push(x);
		m[x] = y;
	}
	int con = 0;
	int idl = 0;
	int t = 0;
	int mi = INT_MAX;
	while(q.size() > 0)
	{
		int a = q.top();
		q.pop();
		mi = min(a,mi);
		t = max(m[a],t);
		if(q.top() > m[a])
		{
			if(q.top() > t)
				idl = max(idl, q.top() - m[a]);
			con = max(con, t-mi);
			cout << t <<  " " << mi  << endl;
			mi = INT_MAX;
			t = 0;
		}
	}
	cout << con << " " << idl << endl;
	return 0;
}
