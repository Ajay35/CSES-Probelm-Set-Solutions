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

const int N=100005;
vi g[N];
int side[N];
bool vis[N];

bool bipartite(int v)
{
	int s=1;
	bool is_bipartite=true;
	queue<int> que;
	for(int i=1;i<=v-1;i++)
	{
		if(side[i]==-1)
		{
			que.push(i);
			side[i]=0;
			while(!que.empty())
			{
				int v=que.front();
				que.pop();
				for(int u:g[v])
				{
					if(side[u]==-1)
					{
						side[u]=side[v]^1;
						que.push(u);
					}
					else
					{
						is_bipartite&=side[u]!=side[v];
					}
				}
			}
		}
	}
	return is_bipartite;	
}

int main()
{      
  fastio();
  //input();
  int n,m,i,j,t;
  cin>>n>>m;
  for(i=1;i<=m;i++)
  {
  	int a,b;
  	cin>>a>>b;
  	g[a].pb(b);
  	g[b].pb(a);
  }
  memset(side,-1,sizeof side);
  bool bipart=bipartite(n);
  if(!bipart)
  	cout<<"IMPOSSIBLE";
  else
  {
  	for(i=1;i<=n;i++)
  		cout<<side[i]+1<<" ";
  }
  return 0;
}