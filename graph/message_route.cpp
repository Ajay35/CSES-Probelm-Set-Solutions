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

const int N=100001;
vi g[N];
int p[N];
bool vis[N];
int bfs(int s,int d)
{
	queue<ppi> que;
	que.push(mp(s,0));
	vis[s]=1;
	while(!que.empty())
	{
		ppi c=que.front();
		que.pop();
		int u=c.fi;
		if(u==d)
			return c.se;
		for(int v:g[u])
		{
			if(!vis[v])
			{
				vis[v]=1;
				p[v]=u;
				que.push(mp(v,c.se+1));
			}
		}
	}
	return -1;
}
int main()
{      
  fastio();
  //input();
  int n,m,i;
  cin>>n>>m;
  for(i=1;i<=m;i++)
  {
  	int a,b;
  	cin>>a>>b;
  	g[a].pb(b);
  	g[b].pb(a);
  }
  memset(p,-1,sizeof p);
  int ans=bfs(1,n);
  if(ans==-1)
  	cout<<"IMPOSSIBLE";
  else
  {
  	cout<<ans+1<<"\n";
  	vi ans;
  	int x=n;
  	while(p[x]!=-1)
  	{
  		ans.pb(x);
  		x=p[x];
  		if(ans.size()>100010) break;
  	}
  	cout<<1<<" ";
  	for(i=ans.size()-1;i>=0;i--)
  		cout<<ans[i]<<" ";
  }
  return 0;
}