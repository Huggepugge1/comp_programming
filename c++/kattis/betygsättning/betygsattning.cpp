#include <bits/stdc++.h>

int main() {
    int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;
    char ans = 'E';
    if (c == f) {
        if (e == b) {
            ans = 'C';
        } else if (b / 2.0 <= e) {
            ans = 'D';
        }
    }
    if (ans == 'C') {
        if (a == d) {
            ans = 'A';
        } else if (a / 2.0 <= d) {
            ans = 'B';
        }
    }

    std::cout << ans << std::endl;
}
