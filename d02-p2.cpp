#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
 
bool okay (vector<int> numbers) {
    bool ok = 1;
    for (int i = 1; i < numbers.size(); i++) {
        if (abs(numbers[i] - numbers[i-1]) == 0 || abs(numbers[i] - numbers[i-1]) > 3) {
            ok = 0;
        }
    }
    
    bool increasing = 1, decreasing = 1;
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] >= numbers[i-1]) {
            decreasing = 0;
        }
        if (numbers[i] <= numbers[i-1]) {
            increasing = 0;
        }
    }
    
    if (ok && (increasing || decreasing)) {
        return 1;
    }
    return 0;
}

int main() {
    
    ifstream cin("input.in");
    ofstream cout("output.out");
    
    string s;
    int cnt = 0;
    while (getline(cin, s)) {
        vector<int> numbers;
        
        int xx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                xx = xx * 10 + s[i] - '0';
            }
            else {
                if (xx != 0) {
                    numbers.push_back(xx);
                    xx = 0;
                }
            }
        }
        if (xx != 0) {
            numbers.push_back(xx);
            xx = 0;
        }
        
        bool ok = okay(numbers);
        for (int i = 0; i < numbers.size(); i++) {
            vector<int> cpy;
            for (int j = 0; j < numbers.size(); j++) {
                if (j != i) {
                    cpy.push_back(numbers[j]);
                }
            }
            ok |= okay(cpy);
        }
        
        if (ok) {
            cnt++;
        }
    }
    
    cout << cnt << '\n';
    return 0;
}
