/**
*	  Name: Ajay
*	  Institute: IIITH 
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <stack>
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
void input()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}
const int N=2505;
vii g[N];
bool vis[N];
ll dis[N];

void dfs(int u,int d,ll sum)
{
	if(u==d)
	{
		dis[d]=max(dis[d],sum);
		return;
	}
	vis[u]=1;
	for(ppi v:g[u])
		if(!vis[v.fi])
			dfs(v.fi,d,sum+v.se);
}

int main()
{      
  fastio();
  //input();
  int n,m,i;
  cin>>n>>m;
  for(i=1;i<=m;i++)
  {
  	ll a,b,c;
  	cin>>a>>b>>c;
  	g[a].pb(mp(b,c));
  }
  for(i=0;i<=n;i++)
  	dis[i]=-1e17;
  dfs(1,n,0);
  cout<<dis[n];
  return 0;
}