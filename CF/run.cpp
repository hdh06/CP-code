#include <bits/stdc++.h>

using namespace std;

int main(){
	int N = 100;
	system("g++ -std=c++17 -O2 gen.cpp -o gen");
	system("g++ -std=c++17 -O2 sol.cpp -o sol");
	system("g++ -std=c++17 -O2 1695C.cpp -o brute");
	for (int t = 1; t <= 100; t++){
		cerr << "TESTCASE #" << t << ":\n";
		system("./gen"); system("./sol"); system("./brute");

		ifstream o1("sol.out");
		string z1; o1 >> z1;
		ifstream o2("brute.out");
		string z2; o2 >> z2;

		if (z1 == z2){
			cerr << "AC\n";
			// cerr << z1 << " " << z2 << "\n";
		}
		else{
			cerr << "WA\n";
			break;
		}
	}	
	return 0;
}