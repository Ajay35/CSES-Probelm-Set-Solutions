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

const int N=1000001;
ll dp[N];
vector<string> dict;

ll wordBreak(string str)
{
	if (str.size() == 0)
		return 1;
	/*if(dp[i]!=-1)
		return dp[i];*/
	//ll& ans=dp[i];
	ll ans=0;
	for (int i=1;i<=str.size();i++) 
	{
		string prefix=str.substr(0, i);
		if (find(dict.begin(), dict.end(), prefix) != dict.end())
		{
			ans+=wordBreak(str.substr(i));
			ans=ans%mod;
		}
	}
	return ans;
}



int main()
{      
  fastio();
  input();
  int n,m,i,j,t;
  string s;
  cin>>s;
  cin>>n;
  memset(dp,-1,sizeof dp);
  for(i=0;i<n;i++)
  {
  	string x;
  	cin>>x;
  	dict.pb(x);
  }
  cout<<wordBreak(s);
  return 0;
}