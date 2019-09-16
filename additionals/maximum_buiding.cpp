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
#include <stack>
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

ll get_area(vi a,int n)
{
	stack<int> st;
	int i,j;
	ll ans=0;
	i=0;
	while(i<n)
	{
		if(st.empty() or a[st.top()]<=a[i])
			st.push(i++);
		else
		{
			int tp=st.top();
			st.pop();
			ll area=a[tp]*(1ll)*(st.empty()?i:i-st.top()-1);
			ans=max(ans,area);
		}
	}
	while(!st.empty())
	{
		int tp=st.top();
		st.pop();
		ll area=a[tp]*(1ll)*(st.empty()?i:i-st.top()-1);
		ans=max(ans,area);
	}
	return ans;
}

int main()
{      
  fastio();
  //input();
  int n,m,i,j,t;
  cin>>n>>m;
  int g[n][m];
  for(i=0;i<n;i++)
  {
  	for(j=0;j<m;j++)
  	{
  		char c;
  		cin>>c;
  		if(c=='.')
  			g[i][j]=1;
  		else
  			g[i][j]=0;
  	}
  }

  
  return 0;
}