#include <bits/stdc++.h>
#include <debug.h>

using namespace std;

int main(){
	int n, m; cin >> n >> m;
	for (int i = 0; i <= m; i++)
		debug(i, n ^ i);
	return 0;
}
// 100 -> 110 111 101

//[n, m]: 
// 1100

//000...000...00
//001...000...00


//1001
//1010