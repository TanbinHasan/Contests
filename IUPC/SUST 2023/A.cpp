#include <bits/stdc++.h>

#define int long long

using namespace std;

// #define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  deque<int> dq;
  int lim = 4e6;
  uint64_t sum = 0;
  int sz = 0;
  string s;
  bool ok = true;
  while (cin >> s) {
    if (s == "PUSH") {
      int x;
      cin >> x;
      sum += x;
      ++sz;
      if (ok) dq.push_back(x);
      else dq.push_front(x);
    } else if (s == "POP") {
      if (dq.empty()) continue;
      int x = ((ok) ? (dq.back()) : (dq.front()));
      if (ok) dq.pop_back();
      else dq.pop_front();
      --sz;
      sum -= x;
    } else if (s == "PRINT") {
      if (ok) cout << dq.back() << '\n';
      else cout << dq.front() << '\n';
    } else if (s == "SIZE") {
      cout << sz << '\n';
    } else if (s == "SUM") {
      cout << sum << '\n';
    } else if (s == "REVERSE") {
      ok ^= true;
    } else if (s == "REPEAT") {
      int x;
      cin >> x;
      sum += x * sum;
      if (sz <= lim) {
        if (dq.empty()) continue;
        int c = min(x, (lim + sz - 1) / sz);
        sz += x * sz;
        if (c == 0) continue;
        auto v = dq;
        while (c--) {
          for (auto &i : v) dq.push_back(i);
        }
      } else {
        sz += x * sz;
        continue;
      }
    }
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