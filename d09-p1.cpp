#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
 
int main() {
    
    ifstream cin("input.in");
    ofstream cout("output.out");
    
    string s;
    cin >> s;
    
    vector<int> xp;
    
    int cnt = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        int val = (s[i] - '0');
        if (i % 2 == 0) {
            while (val) {
                xp.push_back(cnt);
                val--;
            }
            cnt++;
        }
        else {
            while (val) {
                xp.push_back(-1);
                val--;
            }
        }
    }
    
    
    int Lpos = 0;
    while (Lpos < (int) xp.size()) {
        if (xp[Lpos] != -1) {
            Lpos++;
        }
        else {
            while (Lpos < (int) xp.size() && xp.back() == -1) {
                xp.pop_back();
            }
            if (Lpos < (int) xp.size()) {
                xp[Lpos] = xp.back();
                xp.pop_back();
                Lpos++;
            }
        }
    }
    
    long long sm = 0;
    for (int i = 0; i < (int) xp.size(); i++) {
        sm += 1LL * i * xp[i];
    }
    cout << sm << '\n';
    return 0;
}
