#include <bits/stdc++.h>

int main() {
    std::string a;
    std::cin >> a;
    std::string b = a.std::string::substr(0, a.size() / 2);
    int curr = std::count(b.begin(), b.end(), 'B');
    int ans = curr;
    for (int i = 0; i < a.size() - 1; i++) {
        curr -= a[i] == 'B' ? 1 : 0;
        curr += a[(i + a.size() / 2) % a.size()] == 'B' ? 1 : 0;
        ans = std::max(curr, ans);
    }
    std::cout << ans << std::endl;
    return 0;
}
