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

const int N=500005;
vi g[N],et;
ll tree[4*N],a[N];
vii inout;

int euler_tour(int u,int p)
{
	et.pb(u);
	if(g[u].size()==0)
		return u;	 
	for(int v:g[u])
	{
		if(v!=p)
		{
			int ret=euler_tour(v,u);
			et.pb(ret);
		}
	}
	return u;
}

void build(int n,int s,int e)
{
	if(s==e)
	{
		tree[n]=a[et[s]];
		return;
	}
	build(2*n,s,(s+e)/2);
	build(2*n+1,(s+e)/2+1,e);
	tree[n]=tree[2*n]+tree[2*n+1];
}

void update(int n,int s,int e,int ind,int val)
{
	if(s==e)
	{
		tree[n]=val;
		return;
	}
	else{
		int mid=(s+e)/2;
		if(s<=mid && ind<=mid)
			update(2*n,s,mid,ind,val);
		else
			update(2*n+1,mid+1,e,ind,val);
		tree[n]=tree[2*n]+tree[2*n+1];
	}
}

ll query(int n,int s,int e,int l,int r)
{
	if(l<=s && e<=r)
		return tree[n];
	if(r<s or e<l)
		return 0;
	ll left=query(2*n,s,(s+e)/2,l,r);
	ll right=query(2*n+1,(s+e)/2+1,e,l,r);
	return left+right;
}

int main()
{      
  fastio();
  //input();
  int n,q,i,j,t;
  cin>>n>>q;
  for(i=1;i<=n;i++)
  	cin>>a[i];
  
  for(i=0;i<n-1;i++)
  {
  	int x,y;
  	cin>>x>>y;
  	g[x].pb(y);
  	g[y].pb(x);
  }

  et.pb(euler_tour(1,-1));
  
  for (i=0;i<=n;i++) 
      inout.pb(mp(-1,-1));
  for(i=0;i<et.size();i++)
  {
      if(inout[et[i]].fi==-1)
          inout[et[i]].fi=i;
      else
          inout[et[i]].se=i;
  }
  build(1,0,et.size()-1);
  for(i=0;i<q;i++)
  {
  	int x;
    cin>>x;
    if(x==1)
    {
    	int y,z;
    	cin>>y>>z;
    	int e=inout[y].fi;
    	int f=inout[y].se;
    	update(1,0,et.size()-1,e,z);
    	update(1,0,et.size()-1,f,z);
    }
    else
    {
    	int z;
    	cin>>z;
    	int e=inout[z].fi;
    	int f=inout[z].se;
    	cout<<query(1,0,et.size()-1,e,f)/2<<"\n";
    }
  }
  return 0;
}