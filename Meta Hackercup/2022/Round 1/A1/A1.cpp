#include <bits/stdc++.h>

#define int long long

using namespace std;

#define MultipleCase       
void Solve(int tc) {
  cout << "Case #" << tc << ": ";
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<int> b(n);
  for (auto &i : b) {
    cin >> i;
  }
  if (k == 0) {
    cout << ((a == b) ? ("YES") : ("NO")) << '\n';
    return;
  }
  if (k == 1) {
    cout << ((a == b) ? ("NO") : ("YES")) << '\n';
    return;
  }
  if (n == 2) {
    if (a == b && k % 2 == 0) {
      cout << "YES\n";
    } else if (a != b && k % 2 == 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    return;
  }
  int x = b.front();
  int ind = find(a.begin(), a.end(), x) - (a).begin();
  int l = ind;
  vector<int> c;
  while ((int)c.size() != n) {
    c.push_back(a[ind++ % n]);
  }
  if (b != c) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
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