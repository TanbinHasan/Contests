#include <bits/stdc++.h>

#define int long long

using namespace std;

// #define MultipleCase       
void Solve(int tc) {
  int l, w;
  while (1) {
    cin >> l >> w;
    if (l == 0 && w == 0) break;
    cout << fixed << setprecision(4);
    cout << 0.75l * (long double) l + (long double) w << '\n';
  }
}

signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1, tc = 0;
  #ifdef MultipleCase
  cin >> tt;      
  #endif
  while (tt--) Solve(++tc);
  return 0;
}