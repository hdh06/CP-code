#include <bits/stdc++.h>

using namespace std;

int const N = 1121;
int const K = 15;
int const P = 200;

int dp[P][N][K] = {};

int p, n, k;

vector<int> pl;

bool pc(int x){
	if (x < 2) return false;
	for (int i = 2; i <= sqrt(x); i++) if (x % i == 0) return false;
	return true;	
}

void prime_find(){
	pl.push_back(0);
	for (int i = 2; i < N; i++){
		if (pc(i)) pl.push_back(i);
	}
}


void init(){
	prime_find();
	p = pl.size() - 1;

	for (int i = 0; i <= p; i++){
		dp[i][0][0] = 1;
	}

	dp[0][0][0] = 1;

	// ofstream log("out.out");

	for (int t = 1; t < K; t++){
		for (int i = 1; i <= p; i++){
			for (int j = 1; j < N; j++){
				if (j - pl[i] >= 0) dp[i][j][t] = dp[i - 1][j][t] + dp[i - 1][j - pl[i]][t - 1];
				else dp[i][j][t] = dp[i - 1][j][t];
				// log << "[" << i << "][" << j << "][" << t << "] = [" << i - 1 << "][" << j << "][" << t << "] + [" <<  i - 1 << "][" << j - pl[i] << "][" << t - 1 << "]\n";
				// log << dp[i][j][t] << " " << dp[i - 1][j][t] << " " << dp[i - 1][j - pl[i]][t - 1] << "\n";			
			}
		}
	}
}

int main(){
	init();

	cin >> n >> k;
	
	while (n + k > 0){
		cout << dp[p][n][k] << "\n";
		cin >> n >> k;
	}
	return 0;
}

//vinhdinh vinhdinh vinhdinh vinhdinh vinhdinh vinhdinh vinhdinh 
//vinhdinh vinhdinh vinhdinh vinhdinh vinhdinh vinhdinh vinhdinh
//vinhdinh vinhdinh vinhdinh vinhdinh vinhdinh vinhdinh vinhdinh
//vinhdinh vinhdinh vinhdinh vinhdinh vinhdin vinhdinh vinhdinh	
