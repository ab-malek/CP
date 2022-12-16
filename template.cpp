#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define all(a) a.begin(),a.end()
#define forz(i,n) for(int i=0;i<n;i++)
#define foro(i,n) for(int i=1;i<=n;i++)


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