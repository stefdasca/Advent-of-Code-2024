#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
 
int main() {
    
    ifstream cin("input.in");
    ofstream cout("output.out");
    
    int a, b;
    
    vector<int> va;
    
    map<int, int> mp;
    while (cin >> a >> b) {
        va.push_back(a);
        mp[b]++;
    }
    
    long long ans = 0;
    for (int i = 0; i < (int) va.size(); i++) {
        ans += 1LL * va[i] * mp[va[i]];
    }
    
    cout << ans << '\n';
    return 0;
}
