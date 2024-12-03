#include <fstream>
#include <vector>
#include <string>
 
using namespace std;
 
int main() {
    
    ifstream cin("input.in");
    ofstream cout("output.out");
    
    string s;
    getline(cin, s);
    
    int ans = 0;
    int N = s.size();
    bool ok = 1;
    for (int i = 0; i < N; i++) {
        if (i + 2 < N && s[i] == 'm' && s[i+1] == 'u' && s[i+2] == 'l') {
            int poz = i+3;
            if (poz < N && s[poz] != '(') {
                continue;
            }
            poz++;
            if (poz < N && s[poz] >= '0' && s[poz] <= '9') {
                int sol = 0;
                while (poz < N && s[poz] >= '0' && s[poz] <= '9') {
                    sol = sol * 10 + (s[poz] - '0');
                    poz++;
                }
                if (poz < N && s[poz] == ',') {
                    poz++;
                    int sol2 = 0;
                    while (poz < N && s[poz] >= '0' && s[poz] <= '9') {
                        sol2 = sol2 * 10 + (s[poz] - '0');
                        poz++;
                    }
                    if (poz < N && s[poz] == ')') {
                        if (ok) {   
                            ans += sol * sol2;
                        }
                    }
                }
            }
        }
        if (i + 3 < N && s[i] == 'd' && s[i+1] == 'o' && s[i+2] == '(' && s[i+3] == ')') {
            ok = 1;
        }
        if (i + 6 < N && s[i] == 'd' && s[i+1] == 'o' && s[i+2] == 'n' && s[i+3] == 39 && s[i+4] == 't' && s[i+5] == '(' && s[i+6] == ')') {
            ok = 0;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
