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
void rotate()
{
	int N = cp.length();
	for(int k = N-1; k >= 0; k--)
	{
		for(int i = 0; i <= k; i++)
		{
			int temp = cp[i][0]; //change 0 to stuff based on which ring level
			cp[i][0] = cp[0][N-i-1];
			cp[0][N-i-1] = cp[N-i-1][N-1];
 		 	cp[N-i-1][N-1] = cp[N-1][i];
 			cp[N-1][i] = temp;
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
