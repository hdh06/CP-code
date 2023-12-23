#include <bits/stdc++.h>

using namespace std;

int const N = 256;

char mapp[N] = {};

int main(){
	string lay1, lay2;
	cin >> lay1 >> lay2;

	for (int i = 0; i < N; i++) mapp[i] = i;

	for (int i = 0; i < lay1.size(); i++){
		mapp[lay1[i]] = lay2[i];
		mapp[toupper(lay1[i])] = toupper(lay2[i]); 
	}

	string text;
	cin >> text;

	for (int i = 0; i < text.size(); i++){
		text[i] = mapp[text[i]];
	}

	cout << text;
	return 0;
}