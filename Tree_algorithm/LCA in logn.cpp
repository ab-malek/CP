// Problem link : https://cses.fi/problemset/task/1687/
int ar[N];
vector<int> g[N];
int in[N],out[N];
int timer = 0;
const int logk = 20;
int dp[N][logk];
 
void dfs(int v,int p = 1){
	in[v] = ++timer;
	for(auto c : g[v]){
		if(c == p)continue;
		dfs(c,v);
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
	dp[1][0] = 1;
 
	for(int i=1;i<logk;i++){
		for(int j=1;j<=n;j++){
			dp[j][i] = dp[dp[j][i-1]][i-1];
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
