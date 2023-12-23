#include <bits/stdc++.h>

using namespace std;

string const BRUTE = "";
string const SOL = "";
string const FILE_NAME = "";
string const C_VERSION = "17";
int const N = 10;

void compile(string file){
	const string com = "g++ -std=c++" + C_VERSION + " " + file + ".cpp -o " + file; 
	system(com.c_str()); 
}

void run(string file){
	const string com = "./" + file;
	system(com.c_str()); 
}

double calc_t(clock_t s, clock_t e){
	return (((double) e - s) / CLOCKS_PER_SEC);
}

int main(){
	compile(BRUTE);
	compile(SOL);
	compile("gen");

	cout << fixed << setprecision(8);

	int dem = 0;
	for (int t = 1; t <= N; t++){
		clock_t s1, e1, s2, e2;
		cout << "TESTCASE #" << t << ":\n";

		run("gen");

		s1 = clock();
		run(BRUTE); 
		e1 = clock();
		ifstream out1(FILE_NAME + ".out");
		string ans1; getline(out1, ans1);

		s2 = clock();
		run(SOL); 
		e2 = clock();
		ifstream out2(FILE_NAME + ".out");
		string ans2; getline(out2, ans2);

		cout << "status: " << (ans1 == ans2? "AC\n" : "WA\n");
		cout << "[ans1] " << ans1 << " [ans2] " << ans2 << "\n";
		cout << BRUTE << " run in " << calc_t(s1, e1) << "s\n";
		cout << SOL << " run in " << calc_t(s2, e2) << "s\n";

		if (ans1 != ans2) dem++;
	}

	cout << "===== AC:" << N - dem << " / WA:" << dem << " =====\n";
	return 0;
}