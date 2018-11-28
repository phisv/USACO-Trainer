/*
ID: bxu5111
LANG: C++
TASK: transform
*/#include <cstdio>
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
	for(int k = N; k > 0; k--)  //ring size
	{
		for(int i = 0; i < k-1; i++)
		{
			int temp = cp[i][N-k]; //0 is N-k
			cp[i][N-k] = cp[N-k][N-i-1];
			cp[N-k][N-i-1] = cp[N-i-1][N-1];
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
int check()
{
	if(comp()) //no change needed
		return 6;
	rotate(); //rotated once 90
	if(comp())
		return 1;
	rotate(); //rotated total 180
	if(comp())
		return 2;
	rotate(); //rotated total 270
	if(comp())
		return 3;
	rotate(); //back to orig
	reflect(); //horizontal reflection
	if(comp())
		return 4;
	rotate(); //rotated once 90 combo with reflect
	if(comp())
		return 5;
	rotate(); //rotated total 180 combo with reflect
	if(comp())
		return 5;
	rotate(); //rotated total 270 combo with reflect
	if(comp())
		return 5;
	return 7; //invalid
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
	cout << check() << endl;

	return 0;
}
