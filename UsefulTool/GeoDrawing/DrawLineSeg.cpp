#include <bits/stdc++.h>
#include <geodeb.h>

using namespace std;

int main(){
	GD_INIT("line.html");
	long long x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	GD_POINT(x1, y1, "#000000") << x1 << " " << y1;
	GD_POINT(x2, y2, "#000000") << x2 << " " << y2;
	GD_POINT(x3, y3, "#000000") << x3 << " " << y3;
	GD_POINT(x4, y4, "#000000") << x4 << " " << y4;

	GD_SEGMENT(x1, y1, x2, y2, "#B22222 bold");
	// GD_PAUSE();
	GD_SEGMENT(x3, y3, x4, y4, "#0000FF");
	return 0;
}