#include <bits/stdc++.h>

#define int long long

using namespace std;

#define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  cout << "Case " << tc << ": ";
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  if (k == 1) {
    cout << accumulate(a.begin(), a.end(), 0LL) << '\n';
    return;
  }
  int mx = *max_element(a.begin(), a.end());
  cout << accumulate(a.begin(), a.end(), 0LL) + mx * (k - 1) << '\n';
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