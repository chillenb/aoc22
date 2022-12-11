#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(int n) {
    return (n == 20 || n == 60 || n == 100 || n == 140 || n == 180 || n == 220);
}

int main() {
    string s;
    char buf[100];
    vector<char> screen(240, ' ');
    int arg, cyc = 1, ans = 0, crtpos, X = 1;
    while(getline(cin, s)) {
        if(check(cyc))
            ans += X * cyc;
        crtpos = (cyc-1) % 40;
        if(X==crtpos || X+1==crtpos || X-1==crtpos)
            screen[std::min(cyc-1, 239)] = '#';
        if(s[0] == 'a') {
            if(check(cyc+1))
                ans += X * (cyc+1);
            crtpos = cyc % 40;
            if(X==crtpos || X+1==crtpos || X-1==crtpos)
                screen[std::min(cyc, 239)] = '#';
            sscanf(s.c_str(), "%s %d\n", buf, &arg);
            X += arg;
            cyc += 2;
        } else
            cyc += 1;
    }
    cout << ans << "\n";
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 40; j++)
            cout << screen[i*40+j];
        cout << "\n";
    }
    return 0;
}