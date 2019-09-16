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
#include <stack>
void printPrevSmaller(int arr[], int n) 
{ 
    stack<int> S; 
    for (int i=0; i<n; i++) 
    { 
        while (!S.empty() && arr[S.top()] >= arr[i]) 
            S.pop();
        if (S.empty())
            cout << "0 "; 
        else
            cout<<S.top() +1<< " "; 
        S.push(i); 
    }
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
  printPrevSmaller(a,n);
  return 0;
}