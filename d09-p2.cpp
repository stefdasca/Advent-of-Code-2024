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
    
    for (int i = (int) xp.size() - 1; i > 0; i--) {
        if (xp[i] != -1 && xp[i-1] != xp[i]) {
            int len = 0;
            while (i + len < (int) xp.size() && xp[i+len] == xp[i]) {
                len++;
            }
            
            int spaces = 0;
            while (spaces < i) {
                if (xp[spaces] != -1) {
                    spaces++;
                }
                else {
                    if (spaces + len - 1 < i) {
                        bool bad = 0;
                        for (int j = spaces; j < spaces+len; j++) {
                            if (xp[j] != -1) {
                                bad = 1;
                                break;
                            }
                        }
                        if (bad == 0) {
                            for (int j = spaces; j < spaces+len; j++) {
                                xp[j] = xp[i];
                            }
                            for (int j = i; j < i+len; j++) {
                                xp[j] = -1;
                            }
                            break;
                        }
                    }
                    spaces++;
                }
            }
        }
    }
    
    long long sm = 0;
    for (int i = 0; i < (int) xp.size(); i++) {
        if (xp[i] != -1) {
            sm += 1LL * i * xp[i];
        }
    }
    cout << sm << '\n';
    return 0;
}
