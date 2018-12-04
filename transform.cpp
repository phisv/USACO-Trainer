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
	for(int r = 0; r < n; r++)
	{
		for(int c = 0; c < n/2; c++)
		{
			int temp = cp[r][c];
			cp[r][c] = cp[r][n-c-1];
			cp[r][n-c-1] = temp;
		}
	}
}
void reflect1()
{
	for(int r = 0; r < n/2; r++)
	{
		for(int c = 0; c < n; c++)
		{
			int temp = cp[r][c];
			cp[r][c] = cp[n-r-1][c];
			cp[n-r-1][c] = temp;
		}
	}
}
void reflectdiag()
{
	for(int r = 0; r < n; r++)
	{
		for(int c = 0; c < n-r; c++)
		{
			int temp = cp[r][c];
			cp[r][c] = cp[n-c-1][n-r-1];
			cp[n-c-1][n-r-1] = temp;
		}
	}
}
void rotate()
{
	reflectdiag();
	reflect1();
}

bool comp()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			if(cp[i][j] != nw[i][j])
				return false;
	}
	return true;
}
int check()
{
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
	rotate();
	reflect();
	if(comp()) //no change needed
		return 6;
	return 7; //invalid
}


int main(void)
{
	//freopen("transform.in", "r", stdin);
	//freopen("transform.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;
	//cout << n << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			mat[i][j] = c;
			cp[i][j] = c;
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
	/*rotate();
	cout << "copy matrix" << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << cp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "new matrix" << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << nw[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << check() << endl;

	return 0;
}
