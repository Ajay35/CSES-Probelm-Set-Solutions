#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
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


const int maxn = 100005;
typedef long long ll ;
typedef pair < ll , ll > pll ;
pll res ;
ll maxnl[maxn][20] , minl[maxn][20] , Level[maxn] , parnt[maxn][20];
vector < pll > Adj[maxn];
bool vis[maxn];
ll maxAns , minAns ;
void Dfs(int to , int from , int lvl , ll dist)
{
    Level[to] = lvl ;
    parnt[to][0] = from ;
   // cout << dist << " print " << endl ;
    maxnl[to][0] = dist ;
    minl[to][0] = dist ;
    int i , sz = Adj[to].size();
    int  u ;
    vis[to] = 1;
    for ( i = 0 ; i < sz ; i++ )
    {
        u = Adj[to][i].first;
        if( vis[u]) continue;
        Dfs(u , to , lvl + 1 , Adj[to][i].second);
    }
}
void Preprocess(int n)
{
    int i , j ;
    for ( i = 0 ; i < n ; i++ )
    {
        for ( j = 0 ; ( 1 << j ) < n ; j++ )
        {
            parnt[i][j] = -1 ;
            maxnl[i][j] = -maxn ;
            minl[i][j] = maxn ;// 1e5 highest limit so it will work fine
            vis[i] = 0 ;
        }
    }
    Dfs(0,-1,0,0);
    for ( j = 1 ; ( 1 << j ) < n ; j++ )
    {
        for ( i = 0 ; i < n ; i++ )
        {
            if ( parnt[i][j-1] != -1 )
            {
                parnt[i][j] = parnt[parnt[i][j-1]][j-1];
                maxnl[i][j] = max ( maxnl[i][j-1] , maxnl[parnt[i][j-1]][j-1]);
                minl[i][j] = min(minl[i][j-1] , minl[parnt[i][j-1]][j-1]);
            }
        }
    }

}
void LCA(int a , int b , int n)
{
    if( Level[a] < Level[b] ) swap(a,b) ;
    int logn = 1 ;
    for (  ; (1 << logn) <= Level[a] ; logn++ ) ;
    logn--;
    int i , j ;
    maxAns = -( 1e16 ) , minAns = ( 1e16) ;
    for ( i = logn ; i >= 0 ; i-- )
    {
        if ( Level[a] - ( 1 << i ) >= Level[b] )
        {

            minAns = min(minAns, minl[a][i]);
            maxAns = max(maxAns , maxnl[a][i]);
            a = parnt[a][i] ;
        }
    }
    if( a == b ) return ;
    for ( i = logn ; i >= 0 ; i-- )
    {
        if (parnt[a][i] != -1 && parnt[a][i] != parnt[b][i] )
        {

            minAns = min( minAns , min(minl[b][i],minl[a][i]));
            maxAns = max( maxAns , max(maxnl[b][i],maxnl[a][i]));
            a = parnt[a][i] ;
            b = parnt[b][i];
        }
    }
     minAns = min(minAns , min(minl[b][0],minl[a][0]));
     maxAns = max(maxAns , max(maxnl[b][0],maxnl[a][0]));

}
int main()
{
	fastio();
	input();
     int n ;
     cin>>n;
     int q , u , v , w , i;
     for ( i = 0 ; i < n - 1 ; i++ )
     {
         cin>>u>>v>>w;
         u-- , v-- ;
         Adj[u].pb(mp(v,w));
         Adj[v].pb(mp(u,w));
     }
     Preprocess(n);
     cin>>q;

     for ( i = 0 ; i < q ; i++ )
     {
         cin>>u>>w;
         u-- , w-- ;
         LCA(u,w,n);
         cout<<minAns<<" "<<maxAns<<"\n";
     }
         

   return 0;
}