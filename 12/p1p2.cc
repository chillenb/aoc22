#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <array>
using namespace std;

int main() {
    string line;
    int ncol, nrow = 0, startr, startc, endr, endc;
    vector<int> terrain;
    while(cin >> line) {
        ncol = line.size();
        for(int i = 0; i < ncol; i++) {
            char c = line[i];
            if(c == 'S') {
                startr = nrow; startc = i; c = 'a';
            } else if(line[i] == 'E') {
                endr = nrow; endc = i; c = 'z';
            }
            terrain.push_back(c - 'a');
        }
        nrow++;
    }
    
    vector<int> dist_map(terrain.size(), -1);
    dist_map[endr*ncol+endc] = 0;
    queue<int> q; q.push(endr*ncol+endc);
    while(!q.empty()) {
        int to = q.front(); q.pop();
        for(const int from : std::array<int, 4>{to-ncol, to+ncol, to+1, to-1}) {
            if(from >= 0 && from <= nrow*ncol && dist_map[from] == -1 && terrain[from] + 1 >= terrain[to]) {
                dist_map[from] = dist_map[to] + 1;
                q.push(from);
            }
        }
    }
    int ans = dist_map[startr*ncol+startc];
    cout << ans << "\n";
    for(int i = 0; i < nrow*ncol; i++) {
        if(terrain[i] == 0 && dist_map[i] != -1)
            ans = std::min(ans, dist_map[i]);
    }
    cout << ans << "\n";
    return 0;
}