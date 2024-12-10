#include <fstream>
#include <vector>
#include <queue>
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
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '0') {
                queue<pair<int, int>> q;
                q.push({i, j});
                
                vector<vector<int>> visited(n, vector<int> (m));
                while (!q.empty()) {
                    pair<int, int> node = q.front();
                    q.pop();
                    
                    if (grid[node.first][node.second] == '9') {
                        if (visited[node.first][node.second] == 0) {
                            ans++;
                        }
                        visited[node.first][node.second] = 1;
                    }
                    
                    for (int x = 0; x < 4; x++) {
                        int nxt_x = node.first + ox[x];
                        int nxt_y = node.second + oy[x];
                        
                        if (nxt_x >= 0 && nxt_x < n && nxt_y >= 0 && nxt_y < m) {
                            if (grid[nxt_x][nxt_y] == grid[node.first][node.second] + 1) {
                                q.push({nxt_x, nxt_y});
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}
