#include <bits/stdc++.h>

using namespace std;

int main(){
	int k = (1<<30) - 1;
	for (int l = 0; l < 30; l++) if (k & (1 << l)) cout << l << " ";	
	return 0;
}