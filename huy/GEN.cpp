#include <bits/stdc++.h>

using namespace std;

int main(){
	ofstream fo("GEN.int");
	fo << 200000 << endl;
	for (int i = 0; i < 200000; i++){
		fo << "1 ";
	}
	fo << endl;
	for (int i = 0; i < 200000; i++){
		fo << "1000000000 ";
	}
	return 0;
}