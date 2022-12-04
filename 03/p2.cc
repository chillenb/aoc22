#include <iostream>
#include <fstream>
#include <string>

int score(char c) {
    return (c <= 'z' && c >= 'a') ? c - 'a' + 1: c - 'A' + 27;
}

int main(int argc, char *argv[]) {
    std::ifstream in(argv[1]);
    std::string line1, line2, line3;
    int ans = 0;
    while (getline(in, line1)) {
        getline(in, line2);
        getline(in, line3);
        uint64_t a = 0, b = 0, c = 0;
        for(const char x : line1) a |= 1ULL << score(x);
        for(const char x : line2) b |= 1ULL << score(x);
        for(const char x : line3) c |= 1ULL << score(x);
        ans += __builtin_ctzll(a & b & c);
    }
    std::cout << ans << "\n";
    return 0;
}