#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, sum = 0, p = 0;
    long k;
    cin >> n >> k;

    long s = pow(2, n);
    if (k <= s / 2)
      cout << 2 * (s - 1) * k << "\n";
    else
      cout << s * (s - 1) << "\n";
  }
  return 0;
}
