#include <bits/stdc++.h>

using namespace std;

int const N = 16;

int n;
int C[N][N];

typedef pair<int, int> ii;
#define st first
#define nd second

ii emrua(int mask){
	if (!mask) return {0, 0};
	ii ans = {INT_MIN, 0};
	for (int i = 0; i < n; i++){
		ii p = emrua(mask ^ (1 << i));
		int sum = 0;
		for (int j = 0; j < n; j++) if (p.nd & (1 << j))
			sum += C[i][j];
		
		if (p.st + sum > ans.st){
			
		}
	}
}

int main(){
	
	return 0;
}