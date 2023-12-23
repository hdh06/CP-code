#include <bits/stdc++.h>

using namespace std;

int main(){
	system("g++ -std=c++17 gen.cpp -o gen");
	system("g++ -std=c++17 Sub5.cpp -o Sub5");
	for (int t = 100; t <= 900; t++){
		cerr << "TESTCASE #" << t << " :\n";

		system("./gen");
		system("./Sub5");

		ifstream gen("gen.out");
		string inp; getline(gen, inp);
		cerr << "input: " << inp << "\n";

		ifstream ans("ans.out");
		string out; getline(ans, out);
		cerr << "output: " << out << "\n";

		string file_test = "test";
		file_test += (char) (t / 100 + '0');
		file_test += (char) ((t % 100) / 10 + '0');
		file_test += (char) (t % 10 + '0');
		file_test += ".inp";

		ofstream test(file_test);
		test << inp;
	}
	return 0;
}