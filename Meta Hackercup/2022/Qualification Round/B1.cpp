#include <bits/stdc++.h>

#define int long long

using namespace std;

#define MultipleCase       
void Solve(int tc) {
  cout << "Case #" << tc << ": ";
  int n, m;
  cin >> n >> m;
  if (n == 1 || m == 1) {
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        char ch;
        cin >> ch;
        if (ch == '^') ok = false;
      }
    }
    cout << ((ok) ? ("Possible") : ("Impossible")) << '\n';
    if (ok) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          cout << ".";
        }
        cout << '\n';
      }
    }
    return;
  }
  cout << "Possible\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char ch;
      cin >> ch;
      cout << "^";
    }
    cout << '\n';
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