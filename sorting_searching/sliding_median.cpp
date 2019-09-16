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

int main()
{      
  fastio();
  //input();
  int n,m,i,j,k;
  cin>>n>>k;
  vi nums;
  for(i=0;i<n;i++)
  {
  	int x;
  	cin>>x;
  	nums.pb(x);
  }
  vll ans;
  multiset<ll> window(nums.begin(), nums.begin() + k);
    auto mid = next(window.begin(), (k - 1) / 2);    
    for (int i = k; i <= nums.size(); ++i) 
    {
      ans.push_back(((*mid)+*next(mid, (k + 1) % 2))/2);
      if (i == nums.size()) break;
      
      window.insert(nums[i]);
      if (nums[i] < *mid) --mid; 
      if (nums[i - k] <= *mid) ++mid;
      window.erase(window.lower_bound(nums[i - k])); 
  }
  for(i=0;i<ans.size();i++)
  	cout<<ans[i]<<" ";
  return 0;
}