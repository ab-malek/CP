// how many numbers upto n whose digit sum equal to x.
int x;
int dp[11][2][92];
int helper(int pos,int isSmall, int sum){
	if(pos == 10) return sum == x;
	if(dp[pos][isSmall][sum] != -1) return dp[pos][isSmall][sum];

	int lo = 0, hi = s[pos] - '0';
	int res = 0;
	if(isSmall) hi = 9;

	for(int i=lo;i<=hi;i++){
		int newIsSmall = isSmall | (i<hi);

		res += helper(pos+1,newIsSmall,sum + i);
	}

	return dp[pos][isSmall][sum] = res;
}
