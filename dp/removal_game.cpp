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

const int N=5001;
ll a[N],dp[N][N];

ll rec(int i, int j, ll sum) 
{ 
    if (j==i+1)
        return max(a[i],a[j]);
    if(dp[i][j]!=-1)
    	return dp[i][j];
    ll& ans=dp[i][j];
    ans=-inf; 
    return ans=max((sum-rec(i+1,j,sum-a[i])),(sum-rec(i,j-1,sum-a[j]))); 
} 
ll f(int n) 
{ 
    ll sum=0; 
    for(int i=0;i<n;i++)
    	sum+=a[i];
    return rec(0,n-1,sum); 
} 
int main() 
{ 
	fastio();
	//input();
	int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    	cin>>a[i];
    memset(dp,-1,sizeof dp);
   	cout<<f(n);   
    return 0; 
}