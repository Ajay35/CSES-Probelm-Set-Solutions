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

const int INF=1e9;
const int N=55;
int n,k;
ll a[N],dp1[N][N],dp2[N][N][5005];

ll f1(int i,int k)
{
	if(k==0)
		return 0;
	if(i>=n)
		return 1e8;
	if(dp1[i][k]!=-1)
		return dp1[i][k];
	ll& ans=dp1[i][k];
	ans=1e8;
	return ans=min(a[i]+f1(i+1,k-1),f1(i+1,k));
}
ll f2(int i,int k,ll msum)
{
	if(k==0)
		return (msum==0);
	if(i>=n)
		return 0;
	if(dp2[i][k][msum]!=-1)
		return dp2[i][k][msum];
	ll& ans=dp2[i][k][msum];
	ans=0;
	return ans=f2(i+1,k-1,msum-a[i])+f2(i+1,k,msum);
}
int main()
{      
  fastio();
  input();
  int i,t;
  cin>>t;
  while(t--)
  {
  	cin>>n>>k;
  	for(i=0;i<n;i++)
  		cin>>a[i];
  	memset(dp1,-1,sizeof dp1);
  	memset(dp2,-1,sizeof dp2);
  	ll minsum=f1(0,k);
  	cout<<f2(0,k,minsum)<<"\n";
  }
  return 0;
}