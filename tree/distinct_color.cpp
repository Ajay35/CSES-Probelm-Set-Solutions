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

struct query
{
	int l,r,idx;
};

bool cmp(query a,query b)
{
	return a.r<b.r;
}

const int N=500001;
int ans[N],a[N],tree[N+10];
vi g[N],et,flat;
vii inout;
map<int,vi> table;
map<int,int> traverser;

void update(int idx,int val)
{
	for(;idx<=N;idx+=idx&-idx)
		tree[idx]+=val;
}

int sum(int idx)
{
	int s=0;
	for(;idx>0;idx-=idx&-idx)
		s+=tree[idx];
	return s;
}


int euler_tour(int u,int p)
{	
	et.pb(u);
	flat.pb(a[u]);
	if(g[u].size()==0)
		return u;
	for(int v:g[u])
	{
		if(v!=p)
		{
			int temp=euler_tour(v,u);
			et.pb(temp);
			flat.pb(a[temp]);
		}
	}
	return u;
}

void hashMarkFirstOccurences(int n) 
{ 
    for (int i=1;i<=2*n;i++) 
    {
        table[flat[i]].pb(i);
        if(table[flat[i]].size()==1) 
        { 
        	update(i, 1);
        	traverser[flat[i]]++; 
        }
    }
}

void processQueries(vector<query> qrs)
{
	int j=1;
	for(int i=0;i<qrs.size();i++)
	{
		for ( ; j < qrs[i].l ; j++ ) 
        { 
            int elem = flat[j]; 
  
            //update(i, -1) removes an element at ith index 
            //in the BIT 
            int temp=traverser[elem]-1;
            update( table[elem][temp],-1); 
  
            //if there is another occurrence of the same element 
            if ( traverser[elem] < table[elem].size() ) 
            { 
                //add the occurrence to the BIT and 
                //increment traverser 
                update(table[elem][ traverser[elem] ], 1); 
                traverser[elem]++; 
            }
        }
        ans[qrs[i].idx]=sum(qrs[i].r);
	}
}

int main()
{      
  fastio();
  //input();
  int n,i,j,t;
  cin>>n;
  for(i=1;i<=n;i++)
  	cin>>a[i];
  for(i=0;i<n-1;i++)
  {
  	int x,y;
  	cin>>x>>y;
  	g[x].pb(y);
  	g[y].pb(x);
  }
  int temp=euler_tour(1,0);
  et.pb(temp);

  for(i=0;i<=n;i++)
  {
  	inout.pb(mp(-1,-1));
  }
  for(i=0;i<et.size();i++)
  {
  	if(inout[et[i]].fi==-1)
  		inout[et[i]].fi=i;
  	else
  		inout[et[i]].se=i;
  }
  vector<query> qrs(n);
  for(i=0;i<n;i++)
  {
  	int e,f;
  	e=inout[i+1].fi;
  	f=inout[i+1].se;
  	qrs[i].l=e;
  	qrs[i].r=f;
  	qrs[i].idx=i;
  }
  sort(qrs.begin(),qrs.end(),cmp);
  hashMarkFirstOccurences(n); 
  processQueries(qrs);
  for(i=0;i<n;i++)
  	cout<<ans[i]<<" ";
  return 0;
}