#include <bits/stdc++.h>
#define MAX 100000
typedef unsigned long long ull;

using namespace std;

int main() {
    ull n,arr[MAX];
    cin >> n;
    for (ull i = 0; i < n; i++) cin >> arr[i];
    sort(arr,arr+n);
    ull tong = 0;
    for (ull i = 0; i < n; i += 2) tong += (arr[i+1] - arr[i]);
    cout << tong;
    return 0;
}
    