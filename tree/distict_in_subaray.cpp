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
int tree[N+15],a[N],last_vis[N],ans[N];

struct query
{
	int l,r,idx;
};
vector<query> qrs;
bool cmp(query a,query b)
{
	return a.r<b.r;
}

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


int main()
{      
  fastio();
  //input();
  int n,q,i,j,t;
  cin>>n>>q;
  for(i=0;i<n;i++)
  	cin>>a[i];
  qrs.resize(q);
  for(i=0;i<q;i++)
  {
  	int x,y;
  	cin>>x>>y;

  	qrs[i].l=x-1;
  	qrs[i].r=y-1;
  	qrs[i].idx=i;
  }
  int qc=0;
  sort(qrs.begin(),qrs.end(),cmp);
  memset(last_vis,-1,sizeof last_vis);
  for(i=0;i<n;i++)
  {
  	if(last_vis[a[i]]!=-1)
  		update(last_vis[a[i]]+1,-1);
  	last_vis[a[i]]=i;
  	update(i+1,1);
  	while(qc<q && qrs[qc].r==i) 
    { 
        ans[qrs[qc].idx]=sum(qrs[qc].r+1)-sum(qrs[qc].l); 
        qc++;
    } 
  }
  for(i=0;i<q;i++)
  	cout<<ans[i]<<" ";
  return 0;
}