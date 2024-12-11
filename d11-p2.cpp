#include <iostream>
#include <fstream>
#include <map>
#include <deque>

#define int long long

using namespace std;
 
signed main() {
    
    ifstream cin("input.in");
    ofstream cout("output.out");
    
    int a;
    map<int, int> mp, mp2;
    while (cin >> a) {
        mp[a]++;
    }
    
    
    for (int i = 1; i <= 75; i++) {
        for (auto xx : mp) {
            int x = xx.first;
            int y = xx.second;
            if (x == 0) {
                mp2[1] += y;
            }
            else {
                int xx = x;
                deque<int> d;
                while (xx) {
                    d.push_front(xx%10);
                    xx /= 10;
                }
                if (d.size() % 2 == 1) {
                    mp2[x*2024] += y;
                }
                else {
                    int aa = 0;
                    for (int ii = 0; ii < d.size() / 2; ii++) {
                        aa = aa * 10 + d[ii];
                    }
                    mp2[aa] += y;
                    aa = 0;
                    for (int ii = d.size() / 2; ii < d.size(); ii++) {
                        aa = aa * 10 + d[ii];
                    }
                    mp2[aa] += y;
                }
            }
        }
        mp = mp2;
        mp2.clear();
    }
    
    int ans = 0;
    for (auto x : mp) {
        ans += x.second;
    }
    cout << ans << '\n';
    return 0;
}
