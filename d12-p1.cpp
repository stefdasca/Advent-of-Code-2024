#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
 
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
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = 1;
                
                int ar = 1, perim = 0;
                while(!q.empty()){
                    int val1 = q.front().first, val2 = q.front().second;
                    q.pop();
             
                    for(int dir = 0; dir < 4; dir++){
                        int newX = val1 + ox[dir]; // New coords
                        int newY = val2 + oy[dir];
                        
                        if(newX < 0 || newX >= n || newY < 0 || newY >= m){ // If it's not in the matrix
                            perim++;
                            continue;
                        }
                        if(grid[newX][newY] != grid[i][j]){ // If it's a '.' (empty space) update the temporary perimeter
                            perim++;
                            continue;
                        }
                        if(visited[newX][newY]){ // If it was already visited
                            continue;
                        }
                        if(grid[newX][newY] == grid[i][j]){ // If it's a cell of ice cream, update area.
                            ar++;
                        }
             
                        visited[newX][newY] = 1; // Mark as visited
                        q.push({newX, newY}); // Push new values
                    }
                }
                
                ans += ar * perim;
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}
