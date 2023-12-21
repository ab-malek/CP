
/* Problem link : https://codeforces.com/contest/1092/problem/F
sum = subtree node count.
cost = sub answer for node i.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define all(a) a.begin(),a.end()
#define flush fflush(stdout) 
#define int long long
const long long INF = 1e18;
#define check cout<<"check"<<nl
#define printVec(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<nl
#define printVecPair(v) for(auto it : v){cout<<it.first<<" "<<it.second<<nl;}
const int N = 2e5+10;
int ar[N];
vector<int> g[N];
int sum[N];
int cost[N];
int ans = -3;


void dfs1(int v = 1,int p = -1){
	sum[v] = ar[v];

	for(auto c : g[v]){
		if(c == p)continue;
		dfs1(c,v);
		sum[v] += sum[c];
		cost[v] += cost[c];
		cost[v] += sum[c];
	}
}

void dfs2(int v,int p = 0){
	ans = max(ans,cost[v]);

	for(auto c : g[v]){
		if(c == p) continue;
		int newCost = cost[v] - cost[c]-sum[c];
		cost[c] += newCost + sum[v]-sum[c];

		sum[c] = sum[v];
		dfs2(c,v);
	}
}

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}

	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs1(1);
	dfs2(1);
	cout<<ans<<nl;
}



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}   
