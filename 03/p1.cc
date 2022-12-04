#include <iostream>
#include <fstream>
#include <string>

int score(char c) {
    return (c <= 'z' && c >= 'a') ? c - 'a' + 1: c - 'A' + 27;
}

int main(int argc, char *argv[]) {
    std::ifstream in(argv[1]);
    std::string line;
    int ans = 0;
    while (getline(in, line)) {
        int n = line.size();
        uint64_t a = 0, b = 0;
        for(int i = 0; i < n / 2; i++) {
            a |= 1ULL << score(line[i]);
            b |= 1ULL << score(line[i + n / 2]);
        }
        ans += __builtin_ctzll(a & b);
    }
    std::cout << ans << "\n";
    return 0;
}