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
 
 
class order
{
public:
	int start;
	int duration;
	int price;
	bool operator<(const order& a) const
	{
		if(start+duration < a.start+a.duration)
		{
			return true;
		}
		else return false;
	}
	void print()
	{
		cout<<start<<" "<<duration<<" "<<price<<" "<<start+duration<<endl;
	}
};
order orders[10001];
ll dp[10001],n;
 
int search(int val,int start,int end)
{
	if(start == end) return start;
	int mid = ceil((start+end)/2.0);
	struct order& temp = orders[mid];
	if(temp.start+temp.duration <= val) return search(val, mid, end);
	else return search(val, start, mid-1);
}
 typedef tuple<ll, ll, ll> iii;
typedef vector<iii> viii;
int main()
{      
  fastio();
  //input();
  	ll n, x, y, z;
	cin >> n;
	viii a(n);
	vll c(n);
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		a[i] = {y, x, z};
	}
	sort(a.begin(), a.end());
	c[0] = get<2>(a[0]);
	for (int i = 1; i < n; i++)
	{
		tie(y, x, z) = a[i];
		int k = lower_bound(a.begin(), a.end(), make_tuple(x, 0, 0)) - a.begin() - 1;
		ll m = c[i - 1];
		if (k >= 0) m = max(m, c[k] + z);
		else m = max(m, z);
		c[i] = m;
	}
	cout << c[n - 1] << endl;
 
  return 0;
} 