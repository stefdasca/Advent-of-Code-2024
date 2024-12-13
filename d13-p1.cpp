#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;

int dir = 0;

int main() {
    
    ifstream cin("input.in");
    ofstream cout("output.out");
    
    vector<string> grid;
    string s;
    
    int ans = 0;
    while (getline(cin, s)) {
        if (s.size() == 0) {
            continue;
        }
        grid.push_back(s);
        if (grid.size() == 3) {
            int xA = 0, yA = 0;
            int cf = 0;
            for (int i = 0; i < grid[0].size(); i++) {
                if (grid[0][i] >= '0' && grid[0][i] <= '9') {
                    if (cf == 0) {
                        xA = xA * 10 + (grid[0][i] - '0');
                    }
                    else {
                        yA = yA * 10 + (grid[0][i] - '0');
                    }
                }
                else {
                    if (cf == 0 && xA > 0) {
                        cf = 1;
                    }
                }
            }
            
            
            int xB = 0, yB = 0;
            int cf2 = 0;
            for (int i = 0; i < grid[1].size(); i++) {
                if (grid[1][i] >= '0' && grid[1][i] <= '9') {
                    if (cf2 == 0) {
                        xB = xB * 10 + (grid[1][i] - '0');
                    }
                    else {
                        yB = yB * 10 + (grid[1][i] - '0');
                    }
                }
                else {
                    if (cf2 == 0 && xB > 0) {
                        cf2 = 1;
                    }
                }
            }
            
            
            int xT = 0, yT = 0;
            int cf3 = 0;
            for (int i = 0; i < grid[2].size(); i++) {
                if (grid[2][i] >= '0' && grid[2][i] <= '9') {
                    if (cf3 == 0) {
                        xT = xT * 10 + (grid[2][i] - '0');
                    }
                    else {
                        yT = yT * 10 + (grid[2][i] - '0');
                    }
                }
                else {
                    if (cf3 == 0 && xT > 0) {
                        cf3 = 1;
                    }
                }
            }
            
            int mincost = (1<<30);
            for (int i = 0; i <= 100; i++) {
                for (int j = 0; j <= 100; j++) {
                    if (i * xA + j * xB == xT && i * yA + j * yB == yT) {
                        mincost = min(mincost, i * 3 + j);
                    }
                }
            }
            
            if (mincost != (1<<30)) {
                ans += mincost;
            }
            grid.clear();
        }
    }
    
    cout << ans << '\n';
    return 0;
}
