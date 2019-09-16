/**
*      Name: Ajay
*      Institute: IIITH 
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


const int N=200005;
int a[N];

bool check(ll mid,int n,int K) 
{ 
    int count=0; 
    ll sum=0; 
    for (int i=0;i<n;i++)
    { 
        if(a[i]>mid) 
            return false; 
        sum+=a[i]; 
        if(sum>mid)
        { 
            count++; 
            sum=a[i]; 
        }
    }
    count++; 
    if(count<=K) 
        return true; 
    return false; 
} 
  
ll solve(int n,int K) 
{ 
    ll start=1; 
    ll end=0;
    for(int i=0;i<n;i++)
        end += a[i]; 
    ll answer = 0; 
    while(start<=end)
    {
        ll mid=(start+end)/2; 
        if(check(mid,n, K))
        { 
            answer=mid; 
            end=mid-1; 
        }
        else  
            start=mid+1 ;
    }
    return answer; 
} 
  
int main() 
{ 
    fastio();
    //input();
    int n,k,i;
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>a[i];
    ll num=solve(n,k);
    cout<<num; 
} 