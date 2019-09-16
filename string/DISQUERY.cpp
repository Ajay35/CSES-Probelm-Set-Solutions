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

const int N=1e5+5;
vii g[N];
bool vis[N];
ll ancestor[N][20],minp[N][20],maxp[N][20],h[N];
ll min_ans,max_ans;

void dfs(int u,int p,int lvl,int dis)
{
	h[u]=lvl;
	ancestor[u][0]=p;
	maxp[u][0]=dis;
	minp[u][0]=dis;
	vis[u]=1;
	for(ppi v:g[u])
	{
		if(!vis[v.fi])
			dfs(v.fi,u,lvl+1,v.se);
	}
}

void preprocess(int n)
{

	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;(1<<j)<n;j++)
		{
			ancestor[i][j]=-1;
			maxp[i][j]=-N;
			minp[i][j]=N;
			vis[i]=0;
		}
	}
	
	dfs(0,-1,0,0);
	
	for(j=0;(1<<j)<n;j++)
	{
		for(i=0;i<n;i++)
		{
			ancestor[i][j]=ancestor[ancestor[i][j-1]][j-1];
			maxp[i][j]=max(maxp[i][j-1],maxp[maxp[i][j-1]][j-1]);
			minp[i][j]=max(minp[i][j-1],minp[minp[i][j-1]][j-1]);
		}
	}
}

void lca(int a,int b)
{
	if(h[a]<h[b])
		swap(a,b);
	int log=1;
	while((1<<log)<=h[a])
		log++;
	log--;
	for(int i=log;i>=0;i--)
	{
		if(h[a]-(1<<i)>=h[b])
		{
			min_ans=min(min_ans,minp[a][i]);
			max_ans=max(max_ans,maxp[a][i]);
			a=ancestor[a][i];
		}
	}

	if(a==b)
		return;

	for(int i=log;i>=0;i--)
	{
		if(ancestor[a][i]!=-1 && ancestor[a][i]!=ancestor[b][i])
		{
			min_ans=min(min_ans,min(minp[a][i],minp[b][i]));
			max_ans=max(max_ans,max(maxp[a][i],maxp[b][i]));
			a=ancestor[a][i];
			b=ancestor[b][i];
		}
	}
	min_ans=min(min_ans,min(minp[a][0],minp[b][0]));
	max_ans=max(max_ans,max(maxp[a][0],maxp[b][0]));
}


int main()
{
  fastio();
  input();
  int n,m,i,j,t;
  cin>>n;
  for(i=0;i<n-1;i++)
  {
  	int a,b,c;
  	cin>>a>>b>>c;
  	a--;
  	b--;
  	g[a].pb(mp(b,c));
  	g[b].pb(mp(a,c));
  }
  preprocess(n);
  cin>>t;
  while(t--)
  {
  	int u,v;
  	cin>>u,v;
  	lca(u,v);
  	cout<<min_ans<<" "<<max_ans<<"\n";
  }
  
  return 0;
}