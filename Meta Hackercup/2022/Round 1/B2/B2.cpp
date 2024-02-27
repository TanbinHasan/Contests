#include <bits/stdc++.h>

#define int long long

using namespace std;

#define MultipleCase       
void Solve(int tc) {
  cout << "Case #" << tc << ": ";
  int n;
  cin >> n;
  vector<pair<int,int>> vp(n);
  int ssq = 0, sa = 0, sb = 0;
  const int md = 1000000007;
  for (auto &[x, y] : vp) {
    cin >> x >> y;
    ssq = (ssq + ((x * x) % md)) % md;
    ssq = (ssq + ((y * y) % md)) % md;
    sa = (sa + x) % md;
    sb = (sb + y) % md;
  }
  int q;
  cin >> q;
  int ans = 0;
  while (q--) {
    int x, y;
    cin >> x >> y;
    int p1 = (n * ((x * x + y * y) % md)) % md;
    int p2 = ssq;
    int p3 = (2LL * ((x * sa) % md)) % md;
    int p4 = (2LL * ((y * sb) % md)) % md;
    int sum = 0;
    sum = (sum + p1) % md;
    sum = (sum + p2) % md;
    sum = (sum - p3) % md;
    sum = (sum - p4) % md;
    ans = (ans + sum + md) % md;
  }
  cout << (ans + md) % md << '\n';
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