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
#include <limits.h>
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
#define INF INT_MAX
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
const int N=101;

ll adj[N][N];

ll matrix_power(int n,ll k)
{
	int i,j,p;
	ll res[N][N];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				res[i][j]=1;
			else
				res[i][j]=0;
		}
	}
	while(k>0)
	{
		if(k&1)
		{
			ll temp[N][N];
			memset(temp,0,sizeof temp);
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					for(p=0;p<n;p++)
						temp[i][j]+=res[i][p]*adj[p][j],temp[i][j]=temp[i][j]%mod;
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					res[i][j]=temp[i][j]%mod;
		}
		
		ll temp[N][N];
		memset(temp,0,sizeof temp);
		
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(p=0;p<n;p++)
					temp[i][j]+=adj[i][p]*adj[p][j],temp[i][j]=temp[i][j]%mod;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				adj[i][j]=temp[i][j]%mod;
		k=k>>1;
	}
	return res[0][n-1];
}


int main()
{      
  fastio();
  input();
  int n,m,i,j,k;
  memset(adj,0,sizeof adj);
  cin>>n>>m>>k;
  for(i=1;i<=m;i++)
  {
  	int a,b;
  	cin>>a>>b;
  	adj[a-1][b-1]=1;
  }
  cout<<matrix_power(n,k);
  return 0;
}