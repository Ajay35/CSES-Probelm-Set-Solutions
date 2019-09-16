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
void get_subset_sum(ll a[],vll& sum,int n,int offset)
{
	for(int i=0;i<(1<<n);i++)
	{
		ll s=0;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j)){
				s+=a[j+offset];
			}
		}
		sum.pb(s);
	}
}

int main()
{      
  fastio();
  //input();
  ll n,x,i,j,t;
  cin>>n>>x;
  ll a[n];
  for(i=0;i<n;i++)
  	cin>>a[i];
  vll sum1;
  vll sum2;
  get_subset_sum(a,sum1,n/2,0);
  get_subset_sum(a,sum2,n-n/2,n/2);
  int sz1=1<<(n/2);
  int sz2=1<<(n-(n/2));
  ll ans=0;
  sort(sum2.begin(),sum2.end());
  for(i=0;i<sum1.size();i++)
  {
  	ll dif=x-sum1[i];
  	int ind1=lower_bound(sum2.begin(), sum2.end(),dif)-sum2.begin();
  	int ind2=upper_bound(sum2.begin(), sum2.end(),dif)-sum2.begin();
  	ind2--;
  	ans+=(ind2-ind1+1);
  }
  cout<<ans;
  return 0;
}