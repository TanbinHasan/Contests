#include <bits/stdc++.h>

#define int long long

using namespace std;

// #define MultipleCase       
void Solve(int tc) {
  int a, b, c;
  cin >> a >> b >> c;
  int o1 = a + b + c;
  int o2 = a * b * c;
  int o3 = (a * b) + c;
  int o4 = a + (b * c);
  int o5 = (a + b) * c;
  int o6 = a * (b + c);
  cout << max({o1, o2, o3, o4, o5, o6}) << '\n';
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