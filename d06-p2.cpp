#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> ox = {-1, 0, 1, 0};
vector<int> oy = {0, 1, 0, -1};

int dir = 0;

int solve(int X, int Y, int n, int m, vector<string> &grid) {
    int moves = 0;
    dir = 0;
    while (X >= 0 && X < n && Y >= 0 && Y < m) {
        moves++;
        if (moves >= 100000) {
            return 1;
        }
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
    return 0;
}
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
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '^' && grid[i][j] != '#') {
                grid[i][j] = '#';
                ans += solve(X, Y, n, m, grid);
                grid[i][j] = '.';
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}
