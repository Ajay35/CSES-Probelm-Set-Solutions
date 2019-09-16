/**
*	  Name: Ajay
*	  Institute: IIITH 
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <ctime>
#include <string.h>
#define ll long long
#define inf 0x7fffffff
#define mod 1000000007
#define pb push_back
#define ppi pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<ppi>
#define vll vector<ll>
#define mp make_pair
#define fi first
#define se second
using namespace std;

void fastio()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void input()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}

int main()
{      
  fastio();
  //input();
  string s, r;
  cin >> s;
  vector<int> a(26);
  for (char c : s) a[c-'A']++;
  int odd = 0;
  for (int i = 0; i < 26; i++)
    odd += a[i] % 2;
  if (odd > 1) {
    cout << "NO SOLUTION\n";
    return 0;
  }
  for (int i = 0; i < 26; i++)
    if (!(a[i] % 2))
      for (int j = 0; j < a[i] / 2; j++)
        r.push_back(i + 'A');
  for (int i = 0; i < 26; i++)
    if (a[i] % 2)
      for (int j = 0; j < a[i]; j++)
        r.push_back(i + 'A');
  for (int i = 25; i >= 0; i--)
    if (!(a[i] % 2))
      for (int j = 0; j < a[i] / 2; j++)
        r.push_back(i + 'A');
  cout << r << "\n";
}