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

int main()
{      
  fastio();
  //input();
  int n,m,i,j,t;
  ll ans=0;
  cin>>n;
  ll a[n];
  for(i=0;i<n;i++)
  	cin>>a[i];
  stack<ll> st;
  i=0;
  while(i<n)
  {
  	if(st.empty() or a[st.top()]<=a[i])
  		st.push(i++);
  	else
  	{
  		ll tp=st.top();
  		st.pop();
  		ll area= a[tp]*(st.empty()?i:(i-st.top()-1));
  		ans=max(ans,area);
  	}
  }
  while (st.empty() == false) 
  { 
    ll	 tp = st.top(); 
    st.pop(); 
    ll area= a[tp] *(1ll)* (st.empty()?i:i - st.top() - 1); 
  
        if (ans < area) 
            ans = area; 
    } 
  
  cout<<ans;
  return 0;
}