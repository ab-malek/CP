Qestion link : https://cses.fi/problemset/task/1131/


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
// #define ok cout<<"ok"<<nl
#define printVec(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<nl
#define printVecPair(v) for(auto it : v){cout<<it.first<<" "<<it.second<<nl;}
const int N =2e5+10;
const int mod = 1e9+7;
vector<int> g[N];
int height[N];
int ans = 0;
void dfs(int v,int p){
	for(auto c : g[v]){
		if(c == p) continue;
		dfs(c,v);
		ans = max(ans, height[v] + height[c] + 1);
		height[v] = max(height[v], height[c] + 1);

	}
}

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1,0);
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
