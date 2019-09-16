
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
using namespace std;
 
char s[1000001];
int L,pref[1000000];
 
int main()
{
	fastio();
	input();
    scanf("%s",s);
    L=strlen(s);
    pref[0] = 0;
    for(int i = 1,pos = 0;i<L;++i)
    {
        pos = pref[i-1];
        
        while(pos>0 && s[pos]!=s[i]) pos = pref[pos-1];
        if(s[pos]==s[i]) ++pos;
        pref[i] = pos;
    }
    int p=L-1;
    set<int> ans;
  	 while(p>0)
  	 {
     	int s=L-pref[p];
     	ans.insert(s);
     	p=pref[p-1];
     }
    ans.insert(L);
    for(int num:ans)
    	cout<<num<<" ";
    return 0;
} 