#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    
    ifstream cin("input.in");
    ofstream cout("output.out");
    
    int n;
    cin >> n;
    
    int adj[100][100];
    for (int i = 0; i <= 99; i++) {
        for (int j = 0; j <= 99; j++) {
            adj[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        
        int val = (s[0] - '0') * 10 + (s[1] - '0');
        int val2 = (s[3] - '0') * 10 + (s[4] - '0');
        adj[val][val2] = 1;
    }
    
    int q;
    cin >> q;
    
    int ans = 0;
    for (; q; q--) {
        string s;
        cin >> s;
        
        vector<int> v;
        for (int i = 0; i < (int) s.size(); i += 3) {
            v.push_back((s[i] - '0') * 10 + (s[i+1] - '0'));
        }
        
        bool ok = 1;
        for (int i = 0; i < (int) v.size(); i++) {
            for (int j = i+1; j < (int) v.size(); j++) {
                if (adj[v[i]][v[j]] != 1) {
                    ok = 0;
                }
            }
        }
        
        if (ok == 0) {
            vector<pair<int, int>> v2;
            for (int i = 0; i < v.size(); i++) {
                v2.push_back({v[i], 0});
            }
            for (int i = 0; i < (int) v.size(); i++) {
                for (int j = i+1; j < (int) v.size(); j++) {
                    if (adj[v[i]][v[j]] == 1) {
                        v2[i].second++;
                    }
                    else {
                        v2[j].second++;
                    }
                }
            }
            for (int i = 0; i < (int) v.size(); i++) {
                for (int j = i+1; j < (int) v.size(); j++) {
                    if (v2[i].second > v2[j].second) {
                        swap(v2[i], v2[j]);
                    }
                }
            }
            
            ans += v2[v2.size()/2].first;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
