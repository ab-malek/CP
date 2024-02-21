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
    vector<pair<int, int>> hash; // 1 - indexed
    Hashing() {}
    Hashing(const string& s) {
        n = s.size();
        hash.emplace_back(0, 0);
        for (int i = 0; i < n; i++) {
            pair<int, int> p;
            p.first = (hash[i].first + 1LL * pw[i].first * s[i] % MOD1) % MOD1;
            p.second = (hash[i].second + 1LL * pw[i].second * s[i] % MOD2) % MOD2;
            hash.push_back(p);
        }
    }
    pair<int, int> get_hash(int l, int r) { // 1 - indexed
        assert(1 <= l && l <= r && r <= n);
        pair<int, int> ans;
        ans.first = (hash[r].first - hash[l - 1].first + MOD1) * 1LL * ipw[l - 1].first % MOD1;
        ans.second = (hash[r].second - hash[l - 1].second + MOD2) * 1LL * ipw[l - 1].second % MOD2;
        return ans;
    }
    pair<int, int> get_hash() {
        return get_hash();
    }
};
//call prec() , defind Hashing name(pass string); To get hash call sh.get_hash(l,r);
