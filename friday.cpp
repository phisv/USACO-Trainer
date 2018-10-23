/*
ID: bxu5111
TASK: friday
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

int num;
map<int,int> m;
int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool leap(int y)
{
	if(y%100 == 0)
		return y%400 == 0;
	return y%4 == 0;
}
int main(void)
{
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	LL n;
	cin >> n;
	num = 13;
	for(int i = 1900; i < 1900+n; i++)
	{
		for(int j = 1; j <= 12; j++)
		{
			m[num%7]++;
			// cout << j << " " << num%7 << " " << num <<endl;
			num += days[j-1];
			if(j == 2 && leap(i))
			{
				num++;
		//		cout << i << "is leap" << endl;
			}
		}
	}
	cout << m[6];
	for(int a = 0; a <= 5; a++)
		cout << " " << m[a];
	cout << endl;
//	for(auto &a: days)
	//	cout << a.first << " " << a.second << endl;
	return 0;
}
