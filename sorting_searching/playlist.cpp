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

int sizeOfLongestDistinctSubArrayO1(int arr[],int n) {
    int max = 0;
    map<int,int> counts;
    int cur = 0;
    int prev = 0;
    for(int i=0,len=n;i<len;i++)
    {
        if(counts.find(arr[i])!=counts.end()) {
            int j=counts[arr[i]];
            max=std::max(max,cur);
            prev=std::max(j,prev);
            cur=i-prev;
            counts[arr[i]]=i;
        } 
        else 
        {
            cur++;
            counts[arr[i]]=i;
        }
    }
    return std::max(max, cur);
}

int main()
{      
  fastio();
  //input();
  int n,m,i,j,t;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++)
  	cin>>a[i];  
  cout<<sizeOfLongestDistinctSubArrayO1(a,n);
  return 0;
}