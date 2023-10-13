#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define nl '\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define all(a) a.begin(),a.end()
#define flush fflush(stdout) 
#define int long long
const long long INF = 1e18;
#define check cout<<"ok"<<nl
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;// find_by_order, order_of_key
#define printVec(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<nl
#define printVecPair(v) for(auto it : v){cout<<it.first<<" "<<it.second<<nl;}
const int N = 1e9 + 7;
const int inf = 1e9;



///////   nCr   inverse mod    //////
 

int fact[N];
int inverFact[N];
 
int binEx(int a,int b){
	if(b == 0) return 1;
	int res = binEx(a,b/2);
	if(b&1){
		return (((res*res)%mod)*a)%mod;
	}
	else{
		return (res*res)%mod;
	}
}
 
int nCr(int n,int r){
	if(r>n) return 0;
 
	return ((fact[n]*inverFact[r])%mod*inverFact[n-r])%mod;
}


 /////    Prime factorization
	// order of square root





 void primeFactor(int n){
	vector<int> prime_factor;
	while(n%2 == 0){
		prime_factor.push_back(2);
		n/=2;
	}

	for(int i=3;i*i<=n;i+=2){
		while(n%i == 0){
		prime_factor.push_back(i);
			n/=i;
		}
	}
	if(n > 2){
		prime_factor.push_back(n);
	}

	for(auto it : prime_factor){
		cout<<it<<" ";
	}
	cout<<nl;
}


/////// prime generate + smallest prime factor    /////


const int NN = 1e7+5;
int spf[NN];
vector<int> primes;

void sieve(){
	for(int i=0;i<NN;i++){
		spf[i] = i;
	}
	bool mark[NN];
	memset(mark,1,sizeof(mark));
	mark[2] = 1;
	for(int i=2;i<=NN;i+=2){
		spf[i] = 2;
	}

	for(int i=3;i*i<=NN;i+=2){
		if(spf[i] == i){
			for(int j = i+i;j<=NN;j+=i){
				// mark[j] = 0;
				if(spf[j] == j)
					spf[j] = i;
			}
		}
	}
	primes.push_back(2);
	for(int i=3;i<NN;i+=2){
		if(mark[i] == 1){
			primes.push_back(i);
		}
	}
	printVec(primes);
}



vector<int> primes2;
void segsieve(ll l,ll r){
	bool marked[r-l+1];
	for(ll i=0;i<r-l+1;i++){
		marked[i] = true;
	}

	for(ll i=0;primes[i]*primes[i]<=NN;i++){
		ll curPrime = primes[i];
		ll base = (l/curPrime)*curPrime;
		if(base<l) base += curPrime;
		for(ll j = base;j<=r;j+=curPrime){
			marked[j-l] = false;
		}
		if(base == curPrime) marked[base-l] = true;
	}
	for(ll i=0;i<r-l+1;i++){
		if(marked[i] == 1){
			primes2.push_back(i+l);
		}
	}
}




//////// Binary Exponentiation ///////////

int binEx(int a,int b){
	if(b == 0) return 1;
	int res =  binex(a,b/2);
	if(b&1){
		return res*res*a;
	}
	else {
		return res*res;
	}
}



vector<int> NGE(vector<int> v){
	vector<int> nge(v.size());

	stack<int> st;

	for(int i = 0;i<v.size();i++){

		while(!st.empty() && v[i]>v[st.top()]){
			nge[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}

	while(!st.empty()){
		nge[st.top()] = -1;
		st.pop();
	}

	return nge;
}



/////    FIND CATALAN   ///////


int catalan(int n){
	int dp[n+1];

	dp[0] = dp[1] = 1;

	for(int i=2;i<=n;i++){
		dp[i] = 0;
		for(int j = 0;j<i;j++){
			dp[i] += dp[j]*dp[i-j-1];
		} 
	}

	return dp[n];
}


int ncr(int n,int c){
	int res = 1;

	for(int i=0;i<c;i++){
		res *= (n-i);
		res /= (i+1);
	}

	return res;
}


/////////////// ALL SUBSETS ///////////


vector<vector<int> > allSubsets;
void getSubsets(vector<int> nums){
	int size = nums.size();
	int numOfSubsets = (1<<size);

	for(int subsetMask=0;subsetMask<numOfSubsets;subsetMask++){
		vector<int> subset;
		for(int j=0;j<size;j++){
			if((subsetMask&(1<<j)) != 0){
				subset.push_back(nums[j]);
			}
		}
		allSubsets.push_back(subset);
	}
}


/////////  STRING HAHSING  //////////

int power(int a,int b,int mod){
    int ans = 1%mod;;
    a %= mod;
    if(a<0) a+= mod;
    while(b>0){
        if(b&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return ans;
}

const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
    pw[0] =  {1, 1};
    for (int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
    }
    ip1 = power(p1, MOD1 - 2, MOD1);
    ip2 = power(p2, MOD2 - 2, MOD2);
    ipw[0] =  {1, 1};
    for (int i = 1; i < N; i++) {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
    }

}
struct Hashing {
    int n;
    vector<pair<int, int>> hs; // 1 - indexed
    Hashing() {}
    Hashing(const string& s) {
        n = s.size();
        hs.emplace_back(0, 0);
        for (int i = 0; i < n; i++) {
            pair<int, int> p;
            p.first = (hs[i].first + 1LL * pw[i].first * s[i] % MOD1) % MOD1;
            p.second = (hs[i].second + 1LL * pw[i].second * s[i] % MOD2) % MOD2;
            hs.push_back(p);
        }
    }
    pair<int, int> get_hash(int l, int r) { // 1 - indexed
        assert(1 <= l && l <= r && r <= n);
        pair<int, int> ans;
        ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL * ipw[l - 1].first % MOD1;
        ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL * ipw[l - 1].second % MOD2;
        return ans;
    }
    pair<int, int> get_hash() {
        return get_hash(1, n);
    }
};



///////////  RANGE UPDATE QUERY ///////////

void built_seg(int ind,int lo,int hi){

	if(lo == hi){
		seg[ind] = v[lo];
		return;
	}
	int mid = (lo+hi)/2;
	built_seg(ind*2+1,lo,mid);
	built_seg(ind*2+2,mid+1,hi);
	seg[ind] = seg[ind*2+1]+seg[ind*2+2];
}

int query(int ind,int lo,int hi,int l,int r){
	if(lo>=l && hi<=r){
		return seg[ind];
	}
	if(lo>r || hi<l) return 0;
	int mid = (lo+hi)/2;
	int left = query(ind*2+1,lo,mid,l,r);
	int right = query(ind*2+2,mid+1,hi,l,r);
	return left+right;
}

void pointUpdate(int ind,int lo,int hi,int node,int val){
	if(lo == hi){
		seg[ind] += val;
		return ;
	}
	else{
		int mid = (lo+hi) >> 1;
		if(node<=mid && node>=lo){
			pointUpdate(ind*2+1,lo,mid,node,val);
		}
		else{
			pointUpdate(ind*2+2,mid+1,hi,node,val);
		}
		seg[ind] = seg[ind*2+1]+seg[ind*2+2];
	}
}

void rangUpdate(int ind,int lo,int hi,int l,int r,int val){
	if(lazy[ind] != 0){
		seg[ind] += ((hi-lo)+1)*lazy[ind];
		if(hi != lo){
			lazy[ind*2+1] += lazy[ind];
			lazy[ind*2+2] += lazy[ind];
		}
		lazy[ind] = 0;
	}

	if(l>hi || r<lo || lo>hi) return;

	if(l<=lo && r>=hi){
		seg[ind] += (hi-lo+1)*val;
		if(lo != hi){
			lazy[ind*2+1] = val;
			lazy[ind*2+2] = val;
		}
		return;
	}

	int mid = (hi+lo) >> 1;
    rangUpdate(ind*2+1,lo,mid,l,r,val);
    rangUpdate(ind*2+2,mid+1,hi,l,r,val);
    seg[ind] = seg[ind*2+1]+seg[ind*2+2];

}

int lazySum(int ind,int lo,int hi,int l,int r){
	if(lazy[ind] != 0){
		seg[ind] += (hi-lo+1)*lazy[ind];
		if(hi != lo){
			lazy[ind*2+1] = lazy[ind];
			lazy[ind+2+2] = lazy[ind];
		}
	}
	if(l>hi || r< lo) return 0;

	if(l>=lo && r<=hi){
		return seg[ind];
	}
	int mid = (lo+hi)/2;

	return lazySum(ind*2+1,lo,mid,l,r)+lazySum(ind*2+2,mid+1,hi,l,r);
}



int nextPower(int n){

	if(n && !(n&(n-1))){
		return n;
	}

	int ct = 0;
	while(n>0){
		ct++;
		n >>= 1;
	}

	return pow(2,ct);
}


/////////START HERE ///////////



void solve(){
    
	return ;
}

int main() {
	// int t;
	// cin>>t;
	// while(t--){
	// 	solve();
	// }
}
