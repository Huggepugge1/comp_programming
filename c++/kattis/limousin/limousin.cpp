#include <bits/stdc++.h>

int main() {
    long a, b;
    std::cin >> a >> b;
    long c[a];
    for (int i = 0; i < a; i++) {
        long curr1, curr2;
        std::cin >> curr1 >> curr2;
        c[i] = (abs(curr1) + abs(curr2)) * 2;
    }
    std::sort(c, c+sizeof(c) / sizeof(c[0]));
    long ans = 0;
    for (long x : c) {
        if (b - x >= 0) {
            ans++;
        }
        b -= x;
    }
    std::cout << ans << std::endl;
}
