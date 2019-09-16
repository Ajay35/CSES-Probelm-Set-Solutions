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
int p[N],sz[N],comp,mx=1;

int findSet(int i)
{
  return p[i] == i?i:p[i] = findSet(p[i]);
}

bool isSameSet(int i, int j) 
{
  return findSet(i) == findSet(j);
}

void unionSet(int i, int j) 
{
  
  i=findSet(i);
  j=findSet(j);
  if(i==j)
  	return;
  else if(sz[i]>sz[j])
  {
  	comp--;
  	p[j]=i;
  	sz[i]+=sz[j];
  	mx=max(mx,sz[i]);
  }
  else
  {
  	comp--;
  	p[i]=j;
  	sz[j]+=sz[i];
  	mx=max(mx,sz[j]);
  }
}

int main()
{      
  fastio();
  //input();
  int n,m,i,j,t;
  cin>>n>>m;
  comp=n;
  for(i=1;i<=n;i++)
  {
  	p[i]=i;
  	sz[i]=1;
  }
  for(i=1;i<=m;i++)
  {
  	int a,b;
  	cin>>a>>b;
  	if(findSet(a)!=findSet(b))
  		unionSet(a,b);
  	cout<<comp<<" "<<mx<<"\n";
  }
  return 0;
}