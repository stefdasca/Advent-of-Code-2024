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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                int cntM = 0, cntS = 0;
                for (int dir = 0; dir < 8; dir++) {
                    if (abs(ox[dir]) + abs(oy[dir]) == 2) {
                        if (i + ox[dir] >= 0 && i + ox[dir] < n && j + oy[dir] >= 0 && j + oy[dir] < m) {
                            if (grid[i + ox[dir]][j + oy[dir]] == 'M') {
                                cntM++;
                            }
                            if (grid[i + ox[dir]][j + oy[dir]] == 'S') {
                                cntS++;
                            }
                        }
                    }
                }
                if (cntM == 2 && cntS == 2) {
                    if (grid[i+1][j-1] != grid[i-1][j+1]) {
                        cnt++;
                    }
                }
            }
        }
    }
    
    cout << cnt << '\n';
    return 0;
}
