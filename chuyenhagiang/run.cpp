#include <bits/stdc++.h>

using namespace std;

int main(){
	system("g++ -std=c++17 -O2 Chess.cpp -o sol");
	system("g++ -std=c++17 -O2 _Chess.cpp -o brute");
	system("g++ -std=c++17 -O2 gen.cpp -o gen");	
	
	int N = 100;
	for (int i = 1; i <= N; i++){
		cerr << "TEST #" << i << ":\n";
		system("./gen");
		system("./sol");
		system("./brute");

		if (system("diff -w Chess.out Chess.ans")){
			cerr << "WA\n";
			return 0;
		}else cerr << "AC\n";
	}
	return 0;
}