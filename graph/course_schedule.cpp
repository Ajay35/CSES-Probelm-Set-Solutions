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
#include <stack>
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
bool vis[N];
stack<int> st;
bool recStack[N];

bool cyclic(int v) 
{ 
    if(vis[v]==false) 
    { 
        vis[v] = true; 
        recStack[v] = true; 
        for(int i:g[v]) 
        { 
            if ( !vis[i] && cyclic(i) ) 
                return true;
            else if (recStack[i]) 
                return true; 
        }
    }
    recStack[v] = false;
    return false; 
} 



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
  }
  for(i=1;i<=n;i++)
  {
  	if(!vis[i])
  		dfs(i);	
  }
  
  memset(vis,false,sizeof vis);
  bool pos=cyclic(1);
  if(!pos)
  {
	  while(!st.empty())
	  {
	  	cout<<st.top()<<" ";
	  	st.pop();
	  }
  }
  else
  	cout<<"IMPOSSIBLE";

  return 0;
}