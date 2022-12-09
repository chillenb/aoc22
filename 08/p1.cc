#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main() {
    std::string line;
    std::vector<int> data;
    int ncol;
    while(std::cin >> line) {
        for(const char c : line)
            data.push_back(c-'0');
        ncol = line.size();
    }
    int nrow = data.size() / ncol;
    std::vector<bool> visible(nrow*ncol);
    std::vector<int> buf(std::max(nrow,ncol));
    for(int i = 0; i < nrow; i++) {
        int rmax = -1;
        for(int j = 0; j < ncol; j++) {
            visible[i*ncol+j] = visible[i*ncol+j] || (data[i*ncol+j]>rmax);
            rmax = std::max(rmax, data[i*ncol+j]);
        }
        rmax = -1;
        for(int j = ncol - 1; j >= 0; j--) {
            visible[i*ncol+j] = visible[i*ncol+j] || (data[i*ncol+j]>rmax);
            rmax = std::max(rmax, data[i*ncol+j]);
        }
    }
    for(int j = 0; j < ncol; j++) {
        int rmax = -1;
        for(int i = 0; i < nrow; i++) {
            visible[i*ncol+j] = visible[i*ncol+j] || (data[i*ncol+j]>rmax);
            rmax = std::max(rmax, data[i*ncol+j]);
        }
        rmax = -1;
        for(int i = nrow - 1; i >= 0; i--) {
            visible[i*ncol+j] = visible[i*ncol+j] || (data[i*ncol+j]>rmax);
            rmax = std::max(rmax, data[i*ncol+j]);
        }
    }
    std::cout << std::transform_reduce(visible.begin(), visible.end(), 0, std::plus{}, [](bool b){return b ? 1 : 0;}) << "\n";
    return 0;
}