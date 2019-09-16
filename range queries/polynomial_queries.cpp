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

struct node
{
	int sum;
	int lci1,rci1;
	int lci2,rci2;
};


const int N=1e5+5;
node tree[4*N];
int a[N],lazy[2*N];

void build(int n,int s,int e)
{
	if(s==e)
	{
		tree[n].sum=a[s];
		tree[n].lci1=s;
		tree[n].rci1=s;
		tree[n].lci2=s;
		tree[n].rci2=s;
		return;
	}
	build(2*n,s,(s+e)/2);
	build(2*n+1,(s+e)/2+1,e);
	tree[n].sum=tree[2*n].sum+tree[2*n+1].sum;
	tree[n].lci1=tree[2*n].lci1;
	tree[n].rci1=tree[2*n].rci1;
	tree[n].lci2=tree[2*n+1].lci2;
	tree[n].rci2=tree[2*n+1].rci2;
}

void update(int n,int s,int e,int l,int r)
{
	if(lazy[n]!= 0)
    { 
        tree[n].sum+=lazy[n];    
        if(s!=e)
        {
        	int left_sum=(tree[n].rci1-tree[n].lci1+1);
        	int right_sum=(tree[n].rci2-tree[n].lci2+1);
            lazy[n*2]+=(left_sum*(left_sum+1))/2;
            lazy[n*2+1]+=(right_sum*(right_sum+1))/2;
        }
        lazy[n]=0;                               
    }
	if(e<l or r<s)
		return;
	if(s>=l and e<=r)
    {
    	int x=(e-s+1);
        tree[n].sum+=(x*(x+1))/2;
        if(s!=e)
        {
        	int left_sum=(tree[n].rci1-tree[n].lci1+1);
        	int right_sum=(tree[n].rci2-tree[n].lci2+1);
            lazy[n*2]+=(left_sum*(left_sum+1))/2;
            lazy[n*2+1]+=(right_sum*(right_sum+1))/2;
        }
        return;
    }
}

ll queryRange(int n,int s,int e,int l,int r)
{
	if(s>e or s>r or e<l)
        return 0;
    if(lazy[n]!=0)
    {
        tree[n].sum+=lazy[n];
        if(s!=e)
        {
            int left_sum=(tree[n].rci1-tree[n].lci1+1);
        	int right_sum=(tree[n].rci2-tree[n].lci2+1);
            lazy[n*2]+=(left_sum*(left_sum+1))/2;
            lazy[n*2+1]+=(right_sum*(right_sum+1))/2;
        }
        lazy[n]=0;
    }
    if(s>=l and e<=r)             
        return tree[n].sum;
    int mid=(s+e)/2;
    ll p1=queryRange(n*2,s,mid,l,r);
    ll p2=queryRange(n*2+1,mid+1,e,l,r);
    return (p1+p2);
}


int main()
{      
  fastio();
  //input();
  int n,m,i,j,t;
  cin>>n>>m;
  for(i=0;i<n;i++)
  	cin>>a[i];
  build(1,0,n-1);
  while(m--)
  {
  	int x,y,z;
  	cin>>x>>y>>z;
  	if(x==2)
  		cout<<queryRange(1,0,n-1,y-1,z-1)<<"\n";
  	else
  		update(1,0,n-1,y-1,z-1);
  }
  return 0;
}