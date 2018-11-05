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
char mat[11][11];
char cp[11][11];
char nw[11][11];

void reflect()
{
	for(int r = 0; r < cp.length/2; r++)
	{
		for(int c = 0; c < cp.length; c++)
		{
			int temp = cp[r][c];
			cp[r][c] = cp[cp.length-r-1][c];
			cp[cp.length-r-1][c] = temp;
		}
	}
}

bool comp()
{
	for(int i = 0; i < mat.length; i++)
	{
		for(int j = 0; j < mat.length; j++)
			if(cp[i][j] != nw[i][j])
				return false;
	}
	return true;
}

int main(void)
{
	//freopen("abc.in", "r", stdin);
	//freopen("abc.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			mat[i][j] = c;
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			nw[i][j] = c;
		}
	}


	memcpy(mat,cp,sizeof(mat));


	return 0;
}
