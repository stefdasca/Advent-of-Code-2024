#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;

void solve() {
    
}
 
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
    
    int X = 0, Y = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '^') {
                X = i;
                Y = j;
                break;
            }
        }
    }
    
    while (X >= 0 && X < n && Y >= 0 && Y < m) {
        visited[X][Y] = 1;
        if (X + ox[dir] >= 0 && X + ox[dir] < n && Y + oy[dir] >= 0 && Y + oy[dir] < m) {
            if (grid[X + ox[dir]][Y + oy[dir]] == '#') {
                dir = (dir + 1) % 4;
            }
            else {
                X += ox[dir];
                Y += oy[dir];
            }
        }
        else {
            break;
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
