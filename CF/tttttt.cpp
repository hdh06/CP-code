int calc(int i, int j){
	if (i == n + 1 || j == 0) return 0;
	
	return dp[i][j] = calc(i + 1, j - 1) + 1;
}

-> 


for i: n -> 1
	for j: 1 -> n
			// if (i == n + 1 || j == 0) dp[i][j] = 0;
			
			dp[i][j] = dp[i + 1][j - 1] + 1;
			

i, mask

mask; 2 ^ n  - 1 -> 0	