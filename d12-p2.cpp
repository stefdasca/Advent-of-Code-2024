#include <bits/stdc++.h>
using namespace std;

static map<pair<int,int>, char> graph;
static set<pair<int,int>> visited;
int n, m;

inline pair<int,int> rotate90(const pair<int,int>& d) {
    return { -d.second, d.first };
}

char getChar(const pair<int,int> &node) {
    auto it = graph.find(node);
    return (it == graph.end()) ? '#' : it->second;
}

tuple<int,int,int> dfs(set<pair<int,int>> &visited, pair<int,int> node, char color, pair<int,int> dir) {
    char c = getChar(node);
    if (c != color) {
        pair<int,int> node_plus_rot = { node.first + (-dir.second), node.second + dir.first };
        pair<int,int> node_minus_dir = { node.first - dir.first, node.second - dir.second };
        pair<int,int> node_complex = { node_minus_dir.first + (-dir.second), node_minus_dir.second + dir.first };

        char c1 = getChar(node_plus_rot);
        char c2 = getChar(node_complex);

        if (c1 == color || c2 != color) return {0, 1, 1};
        return {0, 1, 0};
    }

    if (visited.count(node)) return {0,0,0};
    visited.insert(node);

    int area = 1, perimeter = 0, sides = 0;
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    for (auto &d : directions) {
        auto res = dfs(visited, {node.first + d.first, node.second + d.second}, color, d);
        area += get<0>(res);
        perimeter += get<1>(res);
        sides += get<2>(res);
    }
    return {area, perimeter, sides};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.in");
    vector<string> lines;
    {
        string line;
        while (getline(file, line)) {
            while(!line.empty() && isspace((unsigned char)line.back())) line.pop_back();
            lines.push_back(line);
        }
    }

    n = (int)lines.size();
    m = (int)lines[0].size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            graph[{i,j}] = lines[i][j];

    for (int i = -1; i <= n; i++) {
        graph[{i,-1}] = '#';
        graph[{i,m}] = '#';
    }
    for (int j = -1; j <= m; j++) {
        graph[{-1,j}] = '#';
        graph[{n,j}] = '#';
    }

    long long ans1 = 0, ans2 = 0;
    for (auto &kv : graph) {
        if (!visited.count(kv.first) && kv.second != '#') {
            auto res = dfs(visited, kv.first, kv.second, {1,0});
            ans1 += (long long)get<0>(res) * get<1>(res);
            ans2 += (long long)get<0>(res) * get<2>(res);
        }
    }
    
    ofstream cout("output.out");
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}
