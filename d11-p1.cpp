#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

#define int long long

using namespace std;
 
signed main() {
    
    ifstream cin("input.in");
    ofstream cout("output.out");
    
    int a;
    vector<int> va, vb;
    while (cin >> a) {
        va.push_back(a);
    }
    
    
    for (int i = 1; i <= 25; i++) {
        for (auto x : va) {
            if (x == 0) {
                vb.push_back(1);
            }
            else {
                int xx = x;
                deque<int> d;
                while (xx) {
                    d.push_front(xx%10);
                    xx /= 10;
                }
                if (d.size() % 2 == 1) {
                    vb.push_back(x * 2024);
                }
                else {
                    int aa = 0;
                    for (int ii = 0; ii < d.size() / 2; ii++) {
                        aa = aa * 10 + d[ii];
                    }
                    vb.push_back(aa);
                    aa = 0;
                    for (int ii = d.size() / 2; ii < d.size(); ii++) {
                        aa = aa * 10 + d[ii];
                    }
                    vb.push_back(aa);
                }
            }
        }
        va = vb;
        vb.clear();
    }
    
    cout << va.size() << '\n';
    return 0;
}
