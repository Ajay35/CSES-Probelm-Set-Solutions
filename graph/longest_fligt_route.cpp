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

const int INF=1e9 * -1;
const int N=1e5+5;
vi g[N];
bool vis[N];
int dis[N],p[N];
stack<int> st;

void dfs(int u)
{
	vis[u]=1;
	for(int v:g[u])
		if(!vis[v])
			dfs(v);
	st.push(u);
}

int main()
{      
  fastio();
  //input();
  int n,m,i,s,t;
  cin>>n>>m;
  for(i=1;i<=m;i++)
  {
  	int a,b;
  	cin>>a>>b;
  	g[a].pb(b);
  }
  
  for(i=1;i<=n;i++)
  {
  	if(!vis[i])
  		dfs(i);
  }
  for(i=0;i<=n;i++)
  	dis[i]=INF;
  memset(p,-1,sizeof p);
  s=1,t=n;
  dis[s]=0;

  while(!st.empty())
  {
  	int u=st.top();
  	st.pop();
  	if(dis[u]!=INF)
  	{
  		for(int v:g[u])
  		{
  			if(dis[v]<dis[u]+1)
  			{
  				dis[v]=dis[u]+1;
  				p[v]=u;
  			}
  		}

  	}
  }
  if(dis[n]==INF)
  	cout<<"IMPOSSIBLE";
  else
  {
  	vi ans;
  	int cur=p[n];
  	ans.pb(n);
  	while(cur!=-1)
  	{
  		ans.pb(cur);
  		cur=p[cur];
  		if(ans.size()>N) break;
  	}
  	cout<<ans.size()<<"\n";
  	for(i=ans.size()-1;i>=0;i--)
  		cout<<ans[i]<<" ";
  }
  return 0;
}