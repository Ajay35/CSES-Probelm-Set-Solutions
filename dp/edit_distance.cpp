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
string s1,s2;
int n,m;
int dp[5001][5001];

int f(int i,int j){
	if(i==0)
		return j;
	if(j==0)
		return i;
	if(dp[i][j]!=-1)
		return dp[i][j];
	int& ans=dp[i][j];
	if(s1[i-1]==s2[j-1])
		return ans=f(i-1,j-1); 
	return ans=1+min(f(i-1,j),min(f(i,j-1),f(i-1,j-1)));
}

int main()
{      
  fastio();
  //input();
  int i,j;
  cin>>s1>>s2;
  n=s1.size();
  m=s2.size();
  memset(dp,-1,sizeof dp);
  cout<<f(n,m);
  return 0;
}