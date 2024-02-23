#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
// for equal type 'less_equal'

#define ll long long
#define int long long
#define nl '\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define all(a) a.begin(),a.end()
#define flush fflush(stdout) 
const long long INF = 1e18;
#define check cout<<"ok"<<nl
#define printVec(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<nl
#define printVecPair(v) for(auto it : v){cout<<it.first<<" "<<it.second<<nl;}
// bool cmp(pair<int,int> &a, pair<int,int> &b){return a.second < b.second;}
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
// const int mod = 998244353;
const int N  = 3e5+5;
vector<int> g[N];
int in[N],out[N];
int timer = 0;
const int logk = 20;
int dp[N][logk];

void dfs(int v,int p){
	in[v] = ++timer;

	for(auto c : g[v]){
		if(c != p){
			dfs(c,v);
		}
	}

	out[v] = ++timer;
}

bool is_ancestor(int a,int b){// return true if a is boss of b.
	 return in[a] <= in[b] && out[a] >= out[b];
}

int lca(int a,int b){
	if(is_ancestor(a,b)) return a;
	if(is_ancestor(b,a)) return b;

	for(int i=logk-1;i>=0;i--){
		if(!is_ancestor(dp[a][i], b)){
			a = dp[a][i];
		}
	}

	return dp[a][0];
}
void solve(){
	int n,q;
	cin>>n>>q; 
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		g[x].push_back(i);
		g[i].push_back(x);
		dp[i][0] = x;
	}
	dfs(1,0);
	dp[1][0] = 1;//boss of 1 is one;
	for(int i = 1;i<logk;i++){
		for(int j = 1;j<=n;j++){
			dp[j][i] = dp[ dp[j][i-1] ][i-1];
		}
	}

	while(q--){
		int a,b;
		cin>>a>>b;

		cout<<lca(a,b)<<nl;
	}
}	

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int _t = 1;
    // cin>>_t;
    for(int i = 1;i<=_t;i++){
    	// cout<<"Case "<<i<<": ";
    	solve();
    }
}