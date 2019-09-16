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

int n, a, b;
vi dp1, dp2;
vvi g;

void dfs(int u, int p) {
  for (auto z:g[u]) {
    if (z == p) continue;
    dfs(z, u);
    dp2[u] += max(dp1[z], dp2[z]);
  }
  for (auto z:g[u]) {
    if (z == p) continue;
    dp1[u] = max(dp1[u], 1 + dp2[u] + dp2[z] - max(dp1[z], dp2[z]));
  }
}

int main() 
{
  fastio();
  //input();
  cin >> n;
  dp1 = vi(n);
  dp2 = vi(n);
  g = vvi(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, 0);
  cout << max(dp1[0], dp2[0]) << endl;
}
