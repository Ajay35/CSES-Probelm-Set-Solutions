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

ll subCount(ll arr[], ll n) 
{ 
    ll mod[n]; 
    memset(mod, 0, sizeof(mod)); 
    ll cumSum = 0; 
    for (int i = 0; i < n; i++) { 
        cumSum += arr[i]; 
        mod[((cumSum % n) + n) % n]++; 
    } 
  
    ll result=0;
    for (int i = 0; i < n; i++)
        if (mod[i] > 1) 
            result += (mod[i] * (mod[i] - 1)) / 2; 
    result += mod[0]; 
    return result; 
} 


int main()
{      
  fastio();
  //input();
  ll n,m,i,j,t;
  cin>>n;
  ll a[n];
  for(i=0;i<n;i++)
  	cin>>a[i];
  cout<<subCount(a,n);
  return 0;
}