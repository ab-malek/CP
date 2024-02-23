int in[N],out[N];
int depth[N];
int timer = 0;
const int logk = 20;
int dp[N][logk];

void dfs(int v,int p){
	in[v] = ++timer;

	dp[v][0] = p;

	for(int i=1;i<logk;i++){
		dp[v][i] = dp[dp[v][i-1]][i-1];
	}

	for(auto c : g[v]){
		if(c != p){
			depth[c] += depth[v] + 1;
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
