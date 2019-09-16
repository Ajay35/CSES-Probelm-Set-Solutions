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

int n,x;
ll dp[1000001];
int coins[101];

ll f(int i,int p){
	if(i==0)
		return 1;
	if(dp[i]!=-1)
		return dp[i];
	ll& ans=dp[i];
	ans=0;
	for(int j=i;j<n;j++){
		if(i>=coins[j])
			ans+=f(i-coins[j],j)%mod;
	}
	return ans%mod;
}
int main()
{      
  fastio();
  input();
  int i,j;
  cin>>n>>x;
  for(i=0;i<n;i++)
  	cin>>coins[i];
  memset(dp,-1,sizeof dp);
  cout<<f(x,0);
  return 0;
}