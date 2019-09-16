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
#define vi vector<ll>
#define vvi vector<vi>
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

ll INF = 1e18;

int main()
{      
  fastio();
  //input();
  ll n, m, q, u, v, w;
  cin >> n >> m >> q;
  vvi d(n, vll(n, INF));
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v >> w, u--, v--;
    if (w < d[u][v]) 
    	d[u][v] = d[v][u] = w;
  }
  for(int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
       for (int j = i + 1; j < n; j++)
         if (d[i][k] + d[k][j] < d[i][j])
           d[i][j] = d[j][i] = d[i][k] + d[k][j];
  while (q--)
  {
    cin >> u >> v, u--, v--;
    if (u == v) d[u][v] = 0;
    if (d[u][v] == INF) d[u][v] = -1;
    cout << d[u][v] << "\n";
  }
  return 0;
}