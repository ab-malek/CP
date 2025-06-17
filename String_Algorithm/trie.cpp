Question link  : https://codeforces.com/contest/271/problem/D

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
//for unique type 'less'

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
const int mod = 998244353;
const int N  = 2e5+5;

struct node{
	node *next[26];
	node(){
		for(int i=0;i<26;i++){
			next[i] = NULL;
		}
	}
};

void solve(){
	string s,mark;
	cin>>s>>mark;
	int k;
	cin>>k;
	int n = s.size();
	node *root = new node();
	int res = 0;
	for(int i=0;i<n;i++){
		node *cur = root;
		int bad = 0;
		for(int j = i;j<n;j++){

			bad += (mark[s[j] - 'a'] == '0');
			if(bad > k) break;
			int id = s[j] - 'a';
			if(cur->next[id] == NULL){
				res++;
				cur->next[id] = new node();
			}
			cur = cur->next[id];
		}
	}

	cout<<res<<nl;
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
