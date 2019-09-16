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
#define ppi pair<ll,ll>
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

const ll INF=1e12;
const int N=100001;
vii g[N];
bool vis[N];
ll dis[N];

void dijkstra(int s,int m)
{
	priority_queue<ppi,vii,greater<ppi>> pq;
	pq.push(mp(0,s));
	for(int i=0;i<=100000;i++)
		dis[i]=( 1000000000LL * m + 1LL);
	dis[s]=0;
	while(!pq.empty())
	{
		ppi cur=pq.top();
		pq.pop();
		int u=cur.se;
		if(vis[u]) 
			continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].fi;
			ll w=g[u][i].se;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				pq.push(mp(dis[v],v));
			}
		}
	}
}

int main()
{      
  fastio();
  //input();
  ll n,m,i,j,t;
  cin>>n>>m;
  for(i=1;i<=m;i++)
  {
  	int a,b,c;
  	cin>>a>>b>>c;
  	g[a].pb(mp(b,c));
  }
  dijkstra(1,m);
  for(i=1;i<=n;i++)
  	cout<<dis[i]<<" ";
  return 0;
}