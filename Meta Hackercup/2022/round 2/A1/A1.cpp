#include <bits/stdc++.h>

#define int long long

using namespace std;

#define MultipleCase       
void Solve(int tc) {
  cout << "Case #" << tc << ": ";
  string s;
  cin >> s;
  int n = (int)s.size();
  s = "." + s;
  vector<vector<int>> pref(27, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    int cur = s[i] - 'a';
    for (int j = 0; j <= 26; ++j) {
      pref[j][i] = pref[j][i - 1] + (cur == j);
    }
  }
  int q;
  cin >> q;
  int ans = 0;
  while (q--) {
    int l, r;
    cin >> l >> r;
    int len = r - l + 1;
    // if (len == 1) continue;
    if (len & 1) {
      int m = len / 2;
      m += l;
      int opt1 = 0, opt2 = 0;
      for (int i = 0; i < 26; ++i) {
        int x = pref[i][m] - pref[i][l - 1];
        int y = pref[i][r] - pref[i][m];
        opt1 += llabs(x - y);
      }
      for (int i = 0; i < 26; ++i) {
        int x = pref[i][m - 1] - pref[i][l - 1];
        int y = pref[i][r] - pref[i][m - 1];
        opt2 += llabs(x - y);
      }
      if (opt1 <= 1 || opt2 <= 1) ++ans;
    }
  }
  cout << ans << '\n';
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