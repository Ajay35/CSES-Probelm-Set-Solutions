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
ll tree[4*N];

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

void update(int n,int s,int e,int ind,int val)
{
	if(s==e)
	{
		tree[n]=val;
		return;
	}
	int mid=(s+e)/2;
	if(ind<=mid)
		update(2*n,s,mid,ind,val);
	else
		update(2*n+1,mid+1,e,ind,val);
	tree[n]=tree[2*n]+tree[2*n+1];
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
  	int x,y,z;
  	cin>>x>>y>>z;
  	if(x==2)
  		cout<<query(1,0,n-1,y-1,z-1)<<"\n";
  	else
  		update(1,0,n-1,y-1,z);
  }
  return 0;
}