#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    long long m;
    int c;
    cin >> m >> c;
    if (m == 0){
        cout << "0 0";
        return 0;
    }
    if (m % 1000 != 0){
        cout << 0;
        return 0;
    }
    m /= 1000;
    int const ways[10] = {1,1,1,1,2,1,2,1,1,3};
    int const num[10]  = {0,1,1,1,2,1,2,2,2,3};
    int wayCount = 1, minCount = 0;
    while (c-- && m > 0){
        minCount += num[m % 10];
        wayCount *= ways[m % 10];
        m /= 10;
    }
    if (m <= 9){
        minCount += num[m];
        wayCount *= ways[m];
    }
    else if (m % 5 == 4){
        minCount += (m / 5) + num[m % 5];
        wayCount *= ways[9];
    }
    else if (m % 5 == 1){
        minCount += (m / 5) + num[m % 5];
        wayCount *= ways[6];
    }
    else{
        minCount += (m / 5) + num[m % 5];
        wayCount *= ways[m % 5];
    }
    cout << minCount << " " << wayCount;
    return 0;
}
    
