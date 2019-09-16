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
const int N=200005;
vi g[N];
bool vis[N];
int cnt[N];

int dfs(int u)
{
	if(vis[u])
		return 0;
	vis[u]=1;
	int ans=0;
	for(int v:g[u])
		ans+=1+dfs(v);
	cnt[u]=ans;
	return ans;
}

int main()
{      
  fastio();
  //input();
  int n,m,i,j,t;
  cin>>n;
  map<ppi,int> edges;
  for(i=2;i<=n;i++)
  {
  	int x;
  	cin>>x;
  	if(edges[mp(x,i)]==0)
  	{
  		edges[mp(x,i)]=1;
  		g[x].pb(i);
  	}
  }
  for(i=2;i<=n;i++)
  {
  	if(edges[mp(1,i)]==0)
  	{
  		edges[mp(1,i)]=1;
  		g[1].pb(i);
  	}	
  }
  memset(vis,false,sizeof vis);
  cnt[1]=n-1;
  for(i=2;i<=n;i++)
  {
  	if(!vis[i])
  		dfs(i);
  }
  for(i=1;i<=n;i++)
  	cout<<cnt[i]<<" ";
  return 0;
}