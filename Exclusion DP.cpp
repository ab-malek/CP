  // g[i] = count of unordered pair whose gcd is i;

  // Related problem : https://cses.fi/problemset/task/2417/
	vector<int> g(N,0);
	for(int i=N;i>0;i--){
		int count = 0;
		int over_gcd = 0;
		for(int j=i;j<=N;j += i){
			count += ct[j];
			over_gcd += g[j];
		}

		g[i] = (count*(count-1))/2;
		g[i] -= over_gcd;
	}
