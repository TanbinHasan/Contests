#include <bits/stdc++.h>

#define int long long

using namespace std;

#define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  double a, b;
  cin >> a >> b;
  cout << fixed << setprecision(9) << 0.5l * a * b << '\n';
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