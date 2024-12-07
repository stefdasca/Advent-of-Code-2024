#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    
    ifstream cin("input.in");
    ofstream cout("output.out");
    
    vector<string> tests;
    string s;
    while (getline(cin, s)) {
        tests.push_back(s);
    }
    
    long long ans = 0;
    
    for (auto s : tests) {
        long long nr = -1;
        long long target = 0;
        vector<long long> values;
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                target = target * 10 + (s[i] - '0');
            }
            else {
                if (nr == -1) {
                    nr = target;
                }
                else {
                    if (target != 0) {
                        values.push_back(target);
                    }
                }
                target = 0;
            }
        }
        
        values.push_back(target);
        bool ok = 0;
        
        for (int i = 0; i < (1<<(values.size() - 1)); i++) {
            long long expr = values[0];
            for (int pos = 0; pos < (values.size() - 1); pos++) {
                if (i & (1<<pos)) {
                    expr += values[pos+1];
                }
                else {
                    expr *= values[pos+1];
                }
                if (expr > nr) {
                    break;
                }
            }
            if (expr == nr) {
                ok = 1;
            }
        }
        if (ok) {
            ans += nr;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
