#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#define P2 1

int main(int argc, char *argv[]) {
    std::ifstream in(argv[1]);
    std::string line;
    std::getline(in, line); in.seekg(0);
    int n = (line.size() + 1) / 4;
    std::vector<std::deque<char>> st(n);
    while(true) {
        std::getline(in, line);
        if(line[1] == '1') break;
        for(int j = 0; j < n; j++)
            if(line[4*j+1] != ' ')
                st[j].push_front(line[4*j+1]);
    }
    std::getline(in, line);
    int num, src, dest;
    std::stack<char> buf;
    while(getline(in, line)) {
        sscanf(line.c_str(), "move %d from %d to %d", &num, &src, &dest);
        for(int i = 0; i < num; i++) {
        #ifndef P2
            st[dest-1].push_back(st[src-1].back());
            st[src-1].pop_back();
        #else
            buf.push(st[src-1].back());
            st[src-1].pop_back();
        #endif
        }
        #ifdef P2
        while(!buf.empty()) {
            st[dest-1].push_back(buf.top());
            buf.pop();
        }
        #endif
    }
    for(auto& s : st)
        std::cout << s.back();
    std::cout << "\n";
    return 0;
}