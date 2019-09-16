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
#include <stack>
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
const int N=100001;
vi g[N],g1[N];
int comp[N];
bool vis[N];
stack<int> st;

void dfs(int u)
{
	vis[u]=1;
	for(int v:g[u])
	{
		if(!vis[v])
			dfs(v);
	}
	st.push(u);
}
void dfs2(int u,int c)
{
	vis[u]=1;
	comp[u]=c;
	for(int v:g1[u])
	{
		if(!vis[v])
			dfs2(v,c);
	}
}
int main()
{      
  fastio();
  //input();
  int n,m,i,j,t;
  cin>>n>>m;
  int c=0;
  for(i=0;i<m;i++)
  {
  	int a,b;
  	cin>>a>>b;
  	g[a].pb(b);
  	g1[b].pb(a);
  }
  for(i=1;i<=n;i++)
  {
  	if(!vis[i])
  		dfs(i);
  }
  memset(vis,false,sizeof vis);
  int ans=0;
  while(!st.empty())
  {
  	if(!vis[st.top()])
  	{
  		ans++;
  		dfs2(st.top(),++c);
  	}
  	st.pop();
  }
  cout<<ans<<"\n";
  for(i=1;i<=n;i++)
  	cout<<comp[i]<<" ";
  return 0;
}