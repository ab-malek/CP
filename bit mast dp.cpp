// how many permutation of n are divisible by x;

int dp[(1<<10)+2][1005];

int helper(int mask,int md){
	int pos = __builtin_popcount(mask);
	if(pos == s.size()) return md == 0;

	if(dp[mask][md] != -1) return dp[mask][md];

	int res = 0;

	for(int i=0;i<size();i++){
		if((mask&(1<<i))) continue;

		res += helper(mask|(1<<i), md*10 + s[i] - '0');
	}

	return dp[mask][md] = res;
}
