#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
 
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
        
        vector<int> ops;
        for (int i = 0; i < (values.size() - 1); i++) {
            ops.push_back(0);
        }
        
        while (ops[0] != 3) {
            long long expr = values[0];
            for (int pos = 0; pos < (values.size() - 1); pos++) {
                if (ops[pos] == 0) {
                    expr += values[pos+1];
                }
                if (ops[pos] == 1) {
                    expr *= values[pos+1];
                }
                if (ops[pos] == 2) {
                    long long cpy = values[pos+1];
                    deque<int> d;
                    if (cpy == 0) {
                        d.push_front(0);
                    }
                    while(cpy > 0) {
                        d.push_front(cpy%10);
                        cpy /= 10;
                    }
                    for (auto x : d) {
                        expr = expr * 10 + x;
                    }
                }
                if (expr > nr) {
                    break;
                }
            }
            if (expr == nr) {
                ok = 1;
                break;
            }
            ops.back()++;
            int pos = ops.size() - 1;
            while (pos > 0 && ops[pos] == 3) {
                ops[pos] = 0;
                ops[pos-1]++;
                pos--;
            }
        }
        if (ok) {
            ans += nr;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
