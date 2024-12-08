#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> ox = {-1, 0, 1, 0};
vector<int> oy = {0, 1, 0, -1};

int dir = 0;

int main() {
    
    ifstream cin("input.in");
    ofstream cout("output.out");
    
    vector<string> grid;
    string s;
    while (getline(cin, s)) {
        grid.push_back(s);
    }
    
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> visited(n, vector<int> (m, 0));
    
    for (int xa = 0; xa < n; xa++) {
        for (int ya = 0; ya < m; ya++) {
            for (int xb = xa; xb < n; xb++) {
                for (int yb = 0; yb < m; yb++) {
                    if (xa == xb && ya == yb) {
                        continue;
                    }
                    if (grid[xa][ya] == '.') {
                        continue;
                    }
                    if (grid[xa][ya] == grid[xb][yb]) {
                        if (ya <= yb) {
                            int dx = xb-xa;
                            int dy = yb-ya;
                            if (xa - dx >= 0 && xa - dx < n && ya - dy >= 0 && ya - dy < m) {
                                visited[xa-dx][ya-dy] = 1;
                            }
                            if (xb+dx >= 0 && xb+dx < n && yb+dy >= 0 && yb+dy < m) {
                                visited[xb+dx][yb+dy] = 1;
                            }
                        }
                        else {
                            int dx = xb-xa;
                            int dy = ya-yb;
                            if (xa-dx >= 0 && xa-dx < n && ya+dy >= 0 && ya+dy < m) {
                                visited[xa-dx][ya+dy] = 1;
                            }
                            if (xb+dx >= 0 && xb+dx < n && yb-dy >= 0 && yb-dy < m) {
                                visited[xb+dx][yb-dy] = 1;
                            }
                        }
                        
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += visited[i][j];
        }
    }
    
    cout << ans << '\n';
    return 0;
}
