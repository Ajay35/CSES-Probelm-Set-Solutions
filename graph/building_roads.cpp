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


const int N=100001;
vi g[N];
bool vis[N];

void dfs(int u,int p)
{
	if(vis[u])
		return;
	vis[u]=1;
	for(int v:g[u])
	{
		if(v!=p)
			dfs(v,u);
	}
}

int main()
{      
  fastio();
  int n,m,i;
  cin>>n>>m;
  for(i=1;i<=m;i++)
  {
  	int a,b;
  	cin>>a>>b;
  	g[a].pb(b);
  	g[b].pb(a);
  }
  vi ans;
  for(i=1;i<=n;i++)
  {
  	if(!vis[i])
  	{
  		ans.pb(i);
  		dfs(i,-1);
  	}
  }
  cout<<ans.size()-1<<"\n";
  if(ans.size()>1)
  {
	  for(i=0;i+1<(int)ans.size();i++)
	  	cout<<ans[i]<<" "<<ans[i+1]<<"\n";
  }
  return 0;
}