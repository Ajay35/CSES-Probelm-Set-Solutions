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

bool f(int n,int m)
{
	if(n==0 && m==0)
		return 1;
	if(n<=0 or m<=0)
		return 0;
	return f(n-2,m-1) or f(n-1,m-2);
}

int main()
{      
  fastio();
  //input();
  int a,b,t;
  cin>>t;
  while(t--)
  {
	  cin>>a>>b;
	  cout << (!((a + b) % 3) && min(a, b) * 2 >= max(a, b) ? "YES\n" : "NO\n");

  }
  return 0;
}