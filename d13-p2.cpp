#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
 
#define int long long

using namespace std;

int dir = 0;

int solveLinearSystem(int a, int b, int n, int a2, int b2, int n2) {
    int det = a * b2 - a2 * b;

    if (det == 0) {
        cout << "what?" << '\n';
    }

    int numeratorX = n * b2 - n2 * b;
    int numeratorY = a * n2 - a2 * n;
        
    if (numeratorX % det != 0 || numeratorY % det != 0) {
        return -1;
    }

    int x = numeratorX / det;
    int y = numeratorY / det;
    
    if (x < 0 || y < 0) {
        return -1;
    }
    
    return 3 * x + y;
}

signed main() {
    
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
            
            xT += 1LL * 10000000000000;
            yT += 1LL * 10000000000000;
            
            if (solveLinearSystem(xA, xB, xT, yA, yB, yT) != -1) {
                ans += solveLinearSystem(xA, xB, xT, yA, yB, yT);
            }
            grid.clear();
        }
    }
    
    cout << ans << '\n';
    return 0;
}
