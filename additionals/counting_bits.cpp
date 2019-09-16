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
ll dp[55][55][2];
string s;
long long getDigits(long long x, vector <int> &digit) 
{ 
    while (x) 
    { 
        digit.push_back(x%2); 
        x /= 2; 
    } 
} 
long long digitSum(int idx, int sum, int tight,vector <int> &digit) 
{ 
    if(idx==-1) 
       return sum; 
  
    if(dp[idx][sum][tight]!=-1 and tight!=1) 
        return dp[idx][sum][tight]; 
  
    ll ret=0; 
  
    int k=(tight)?digit[idx]:1; 
  
    for (int i=0;i<=k;i++) 
    { 
        int newTight=(digit[idx]==i)?tight:0;   
        int new_sum=(i==1)?sum+1:sum;
        ret += digitSum(idx-1,new_sum,newTight,digit); 
    } 
  
    if (!tight) 
      dp[idx][sum][tight]=ret;
    return ret; 
} 

int main()
{      
  fastio();
  //input();
  ll n,m,i,j,t;
  cin>>n;

  vi digits;
  getDigits(n,digits);
  memset(dp,-1,sizeof dp);
  cout<< digitSum(digits.size()-1,0,1,digits) ;
  return 0;
}