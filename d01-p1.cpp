#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main() {
    
    ifstream cin("input.in");
    ofstream cout("output.out");
    
    int a, b;
    
    vector<int> va, vb;
    while (cin >> a >> b) {
        va.push_back(a);
        vb.push_back(b);
    }
    
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    
    long long ans = 0;
    for (int i = 0; i < (int) va.size(); i++) {
        ans += abs(va[i] - vb[i]);
    }
    
    cout << ans << '\n';
    return 0;
}
