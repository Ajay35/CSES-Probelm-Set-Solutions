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
ll a[N];
ll lazy[4*N],tree[4*N];

void build(int n,int s,int e)
{
	if(s==e)
	{
		tree[n]=a[s];
		return;
	}
	build(2*n,s,(s+e)/2);
	build(2*n+1,(s+e)/2+1,e);
	tree[n]=tree[2*n]+tree[2*n+1];
}

void updateRange(int node, int start, int end, int l, int r, int val)
{
    if(lazy[node] != 0)
    { 
        tree[node] +=lazy[node];    
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  
            lazy[node*2+1] += lazy[node];                
        }
        lazy[node] = 0;                               
    }
    if(start > end or start > r or end < l)
        return;
    if(start >= l and end <= r)
    {
        tree[node] += val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2,start, mid, l, r, val); 
    updateRange(node*2+1,mid+1,end,l,r,val); 
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    ll p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}

int main()
{      
  fastio();
  //input();
  int n,q,i,j,t;
  cin>>n>>q;
  for(i=0;i<n;i++)
  	cin>>a[i];
  build(1,0,n-1);
  for(i=0;i<q;i++)
  {
  	int x;
  	cin>>x;
  	if(x==2)
  	{
  		int k;
  		cin>>k;
  		cout<<queryRange(1,0,n-1,k-1,k-1)<<"\n";
  	}
  	else
  	{
  		int y,z,u;
  		cin>>y>>z>>u;
  		updateRange(1,0,n-1,y-1,z-1,u);
  	}
  }
  return 0;
}