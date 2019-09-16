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

const int N=1001;	
char g[N][N];
int dp[N][N],n;

int f(int i,int j)
{
	if(i==n-1 && j==n-1)
		return 1;
	if(i<0 or i>n or j<0 or j>n or g[i][j]=='*')
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	int& ans=dp[i][j];
	ans=(f(i+1,j)%mod+f(i,j+1)%mod)%mod;
	return ans;
}

int main()
{      
  fastio();
  //input();
  int i,j;
  cin>>n;
  for(i=0;i<n;i++)
  	for(j=0;j<n;j++)
  		cin>>g[i][j];
  memset(dp,-1,sizeof dp);
  if(g[n-1][n-1]=='*')
  	cout<<0;
  else
  	cout<<f(0,0);
  return 0;
}