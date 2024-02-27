#include <bits/stdc++.h>

#define int long long

using namespace std;

#define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  cout << "Case " << tc << ": ";
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  if ((a + b + c) % 3 != 0) {
    cout << "Fight\n";
    return;
  }
  int cnt = (a == 0) + (b == 0) + (c == 0);
  if (cnt == 2) {
    cout << "Fight\n";
    return;
  }
  int avg = (a + b + c) / 3LL;
  if ((avg - a) % k == 0 && (avg - b) % k == 0 && (avg - c) % k == 0) {
    cout << "Peaceful\n";
  } else {
    cout << "Fight\n";
  }
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) Solve(++tc);
  return 0;
}