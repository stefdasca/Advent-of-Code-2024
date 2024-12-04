#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> ox = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> oy = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    
    ifstream cin("input.in");
    ofstream cout("output.out");
    
    vector<string> v;
    string s;
    while (cin >> s) {
        v.push_back(s);
    }
    
    vector<vector<char>> grid(v.size(), vector<char> (s.size()));
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            grid[i][j] = v[i][j];
        }
    }
    
    int n = v.size();
    int m = s.size();
    
    string sir = "XMAS";
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            for (int dir = 0; dir < 8; dir++) {
                bool ok = 1;
                for (int stp = 0; stp < 4; stp++) {
                    if (i + stp * ox[dir] >= 0 && i + stp * ox[dir] < n && j + stp * oy[dir] >= 0 && j + stp * oy[dir] < m) {
                        if (grid[i + stp * ox[dir]][j + stp * oy[dir]] != sir[stp]) {
                            ok = 0;
                        }
                    }
                    else {
                        ok = 0;
                    }
                }
                if (ok) {
                    cnt++;
                }
                
                ok = 1;
                for (int stp = 0; stp < 4; stp++) {
                    if (i + stp * ox[dir] >= 0 && i + stp * ox[dir] < n && j + stp * oy[dir] >= 0 && j + stp * oy[dir] < m) {
                        if (grid[i + stp * ox[dir]][j + stp * oy[dir]] != sir[3 - stp]) {
                            ok = 0;
                        }
                    }
                    else {
                        ok = 0;
                    }
                }
                if (ok) {
                    cnt++;
                }
            }
        }
    }
    
    cout << cnt/2 << '\n';
    return 0;
}
