#include <bits/stdc++.h>

using namespace std;

string const BRUTE = "brute";
string const SOL = "sol";
// string const FILE_NAME = "";
string const C_VERSION = "17";
int const N = 1000;

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
		cerr << "TESTCASE #" << t << ":\n";

		clock_t s, e;
		run("gen");

		// run(BRUTE); 
		// ifstream out1("brute.out");
		// string ans1; getline(out1, ans1);

		s = clock();
		run(SOL); 
		e = clock();
		ifstream out2("sol.out");
		string ans2; getline(out2, ans2);

		// cerr << "status: " << (ans1 == ans2? "AC\n" : "WA\n");
		// cerr << "[ans1] " << ans1 << " [ans2] " << ans2 << "\n";
		cerr << "time: " << calc_t(s, e) << "s\n";

		// if (ans1 != ans2) dem++;
	}

	cerr << "===== AC:" << N - dem << " / WA:" << dem << " =====\n";
	return 0;
}