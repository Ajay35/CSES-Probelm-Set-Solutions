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

int main()
{      
  fastio();
  int n,x,i,j;
  cin>>n>>x;
  int a[n],dp[x+1];
  for(i=0;i<n;i++){
  	cin>>a[i];
  }
  for(i=0;i<=x;i++)
  	dp[i]=inf;
  dp[0]=0;
  for(i=1;i<=x;i++){
  	for(j=0;j<n;j++){
  		if(a[j]<=i){
          int sub_res=dp[i-a[j]]; 
          if (sub_res!=inf && sub_res+1<dp[i]) 
              dp[i]=sub_res+1; 
  		}
  	}
  }
  if(dp[x]!=inf)
  	cout<<dp[x];
  else
  	cout<<-1;
  return 0;
}