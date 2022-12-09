#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <span>
// requires C++20

void helper(int* in, int len, int* out) {
    std::stack<int> st;
    int score = 0, i = 0;
    while(i < len) {
        while(!st.empty() && in[st.top()] < in[i])
            st.pop();
        if(!st.empty()) {
            out[i] = i - st.top();
        } else {
            out[i] = i;
        }
        st.push(i); i++;
    }
}

void helper2(std::span<int> in, std::span<int> buf, std::span<int> score) {
    int n = in.size();
    std::reverse(in.begin(), in.end());
    helper(in.data(), in.size(), score.data());
    std::reverse(score.begin(), score.end());
    std::reverse(in.begin(), in.end());
    helper(in.data(), in.size(), buf.data());
    std::transform(score.begin(), score.end(), buf.begin(), score.begin(), std::multiplies{});
}

int main() {
    std::string line;
    std::vector<int> data;
    int ncol, ans = 0, nrow;
    while(std::cin >> line) {
        for(const char c : line)
            data.push_back(c-'0');
        ncol = line.size();
    }
    nrow = data.size() / ncol;
    std::vector<int> score(nrow*ncol, 1), buf1(std::max(nrow,ncol)), buf2(nrow), buf3(nrow);
    std::span ds{data.data(), data.size()}, ss{score.data(), score.size()};
    for(int i = 0; i < nrow; i++)
        helper2(ds.subspan(i*ncol, ncol), buf1, ss.subspan(i*ncol, ncol));
    for(int j = 0; j < ncol; j++) {
        for(int i = 0; i < nrow; i++)
            buf2[i] = data[i*ncol+j];
        helper2(buf2, buf3, buf1);
        for(int i = 0; i < nrow; i++)
            score[i*ncol+j] *= buf1[i];
    }
    std::cout << *std::max_element(score.begin(), score.end()) << "\n";
    return 0;
}