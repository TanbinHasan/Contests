#include <bits/stdc++.h>

#define int long long

using namespace std;

void ClockWise(vector<pair<int, int>> &v) {
  const int pi = acosl(-1.0L);
  vector<pair<int, int>> vp;
  vector<tuple<double, int, int>> vt;
  for (auto &[x, y] : v) {
    double angle = (atan2(y, x) * 180 / pi);
    angle += (angle < 0) * 360;
    vt.push_back({angle, x, y});
  }
  sort(vt.begin(), vt.end());
  for (auto &[a, x, y] : vt) {
    vp.push_back({x, y});
  }
  v = vp;
}

#define MultipleCase
void Solve(__attribute__((unused)) int tc) {
  cout << "Case " << tc << ": ";
  int n;
  cin >> n;
  vector<pair<int, int>> vp(n);
  for (auto &[x, y] : vp) {
    cin >> x >> y;
  }
  ClockWise(vp);
  for (auto &[x, y] : vp) {
    cout << x << " " << y << '\n';
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