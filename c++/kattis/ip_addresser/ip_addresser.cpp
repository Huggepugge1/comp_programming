#include <bits/stdc++.h>

int main() {
    std::string a;
    std::cin >> a;
    int ans = 0;
    for (int i = 1; i < a.size() - 2; i++) {
        int b = std::stoi(a.std::string::substr(0, i));
        if (b > 255 || std::to_string(b) != a.std::string::substr(0, i)) {
            continue;
        }
        for (int j = i + 1; j < a.size() - 1; j++) {
            int c = std::stoi(a.std::string::substr(i, j - i));
            if (c > 255 || std::to_string(c) != a.std::string::substr(i, j - i)) {
                continue;
            }
            for (int k = j + 1; k < a.size(); k++) {
                int d = std::stoi(a.std::string::substr(j, k - j));
                if (d > 255 || std::to_string(d) != a.std::string::substr(j, k - j)) {
                    continue;
                }
                int e = std::stoi(a.std::string::substr(k, a.size() - k));
                if (e > 255 || std::to_string(e) != a.std::string::substr(k)) {
                    continue;
                } else {
                    ans++;
                }
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
