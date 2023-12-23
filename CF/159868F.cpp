#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#endif

using namespace std;

int const N = 5001;

int n;
int a[N];

bool sang[N];
vector<int> pl;
void init(){
	for (int i = 2; i < N; i++) if (!sang[i]){
		for (int j = i * i; j < N; j += i) sang[j] = 1;
		pl.push_back(i);
	}
	debug(pl.size(), pl);
}

int main(){
	init();
	return 0;
}