#include<bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
// for equal type 'less_equal'

#define ll long long
#define int long long
#define nl '\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define all(a) a.begin(),a.end()
// #define flush fflush(stdout) 
const long long INF = 1e18;
#define check cout<<"ok"<<nl
// #define mxheap priority_queue<int>
// #define mnheap priority_queue<int, vector<int>, greater<int>>
// #define mxheap2 priority_queue<pair<int,int>>
// #define mnheap2 priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>
#define printVec(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<nl
#define printVecPair(v) for(auto it : v){cout<<it.first<<" "<<it.second<<nl;}
// bool cmp(pair<int,int> &a, pair<int,int> &b){return a.second < b.second;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
#define dbg(x) cerr << #x << " " << x << "\n";
const int mod = 998244353;
const int N  = 2e5+5;

const int B = 400;
int sum = 0;
struct query {
  int l, r, idx;
  bool operator < (const query &x) const {
    if(l / B == x.l / B) return ((l / B) & 1) ? r > x.r : r < x.r;
    return l / B < x.l / B;
  }
} ar[N];

void add(int x){
    sum += x;
}
void rem(int x){
    sum -= x;
}

void solve(){
    int n,q;
    cin>>n>>q;
    int val[n];
    for(int i=0;i<n;i++){
        cin>>val[i];
    }

    // dbg(val[0]);

    for(int i=0;i<q;i++){
        cin>>ar[i].l>>ar[i].r;
        ar[i].idx = i;
    }

    sort(ar,ar+q);

    vector<int> ans(q+1,0);

    int cur_l = 0, cur_r = -1;

    for(int i=0;i<q;i++){
        int l = ar[i].l, r = ar[i].r;
        l--,r--;
        while(cur_l > l){
            cur_l--;
            add(val[cur_l]);
        }
        while(cur_r < r){
            cur_r++;
            add(val[cur_r]);
        }
        while(cur_l < l){
            rem(val[cur_l]);
            cur_l++;
        }
        while(cur_r > r){
            rem(val[cur_r]);
            cur_r--;
        }

        ans[ar[i].idx] = sum;
    }

    for(int i=0;i<q;i++){
        cout<<ans[i]<<" ";
    }
    cout<<nl;

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.in","r",stdin);
    // freopen("outpu.out","w",stdout);
    int _t = 1;
    // cin>>_t;
    for(int i = 1;i<=_t;i++){
        // cout<<"Case "<<i<<": ";
        solve();
    }
}
// static range sum problem
