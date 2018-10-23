/*
ID: bxu5111
TASK: gift1
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
using namespace std;
#define LL long long

int main(void)
{
  // ifstream in("in.txt");
  // streambuf *cinbuf = std::cin.rdbuf(); //save old buf
  // cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
  //
  // ofstream out("out.txt");
  // streambuf *coutbuf = std::cout.rdbuf(); //save old buf
  // cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
  freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	int k;
	cin >> k;
  cin.ignore();
  map<string,int> m;
  vector<string> v;
	for(int i = 0; i < k; i++)
	{
    string n;
    cin >> n;
    m[n] = 0;
    v.push_back(n);
	}
  string n;
  while(cin >> n)
  {
    int x,y;
    cin >> x >> y;
    cin.ignore();
    if(y == 0)
      continue;
    m[n] = m[n] + x%y - x;
    int re = x/y;
    for(int i = 0; i < y; i++)
    {
      string r;
      cin >> r;
      // cout << n << " add " << re << " to " << r << endl;
      m[r] += re;
    }
  }
  for(auto x: v)
  {
    cout << x << " " << m[x] << endl;
  }
	return 0;
}
