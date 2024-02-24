// range minimum query


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
const int lg = 20;
int ar[N];
int sparse[N][lg];
int bin_log[N];

int query(int l,int r){
	int len = (r-l) + 1;
	int pw  = 31 - __builtin_clz(len);

	return min(sparse[l][pw], sparse[r - (1<<pw)+1][pw]);
}

void solve(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>ar[i];
		sparse[i][0] = ar[i];
	}
	bin_log[1] = 0;
	for(int i =2;i<=n;i++){
		bin_log[i] = bin_log[i/2] + 1;
	}

	for(int i=1;i<lg;i++){// 1 based indexing
		for(int j = 1;(j + (1<<(i-1)))<=n;j++){
			sparse[j][i] = min(sparse[j][i-1], sparse[j+(1<<(i-1))][i-1]);
		}
	}

	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		l++,r++;
		cout<<query(l,r)<<nl;
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
