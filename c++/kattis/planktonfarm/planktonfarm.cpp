#include <bits/stdc++.h>

using namespace std;

int main () {
  long a, b, c[1000000];
  cin >> a >> b;
  for (int i = 0; i < b; i++) {
    long curr;
    cin >> curr;
    c[i] = curr;
  }
  sort(c, c + b);
  long p1=0, p2=b-1, ans=0;
  while (p1 < p2) {
    if (c[p1] * c[p2] < a) {
      p1++;
    } else {
      p1++;
      p2--;
      ans++;
    }
  }
  cout << ans << endl;
}
