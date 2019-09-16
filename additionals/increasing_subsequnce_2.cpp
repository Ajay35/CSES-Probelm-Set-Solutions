#include <bits/stdc++.h>
#define MOD 1000000007
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


int tree[200050];
int a[200050];
int n;
int cnt;


int update(int i, int val)
{

	while(i <= cnt) {
		tree[i] = (tree[i] + val) % MOD;
        i += ( (i) & (-i) );
        	}

}

int query(int i)
{
	int result;
	result = 0;
	while(i > 0)
	{
		result =  (result + tree[i]) % MOD;
        i -= ( (i) & (-i) )	
    }
	return result;
}
int main()
{
	fastio();
	//input();
	int t;
	int result;
	int ans;
	scanf("%d", &n);
	cnt = 0;
	ans = 0;
	memset(a, 0, sizeof a);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);

	vector <int> b(a, a+n);

	memset(tree, 0, sizeof tree);

	map <int, int> m;

	sort(b.begin(), b.end());

	for (int i = 0; i < n; i++) {
		if(m.count(b[i]) == 0) {
			m[b[i]] = ++cnt;
		}
	}

	for (int i = 0; i < n; i++)
	{
		result = query(m[a[i]] - 1) + 1;
		ans = (result  + ans) % MOD;
		update(m[a[i]], result);
	}
	printf("%d",ans);
	return 0;

}