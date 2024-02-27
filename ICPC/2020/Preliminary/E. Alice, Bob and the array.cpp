#include <bits/stdc++.h>

#define int long long

using namespace std;

#define MultipleCase       
void Solve(int tc) {
  cout << "Case " << tc << ": ";
  int n;
  cin >> n;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  int mx = *max_element(ar.begin(), ar.end());
  if (mx <= 0) {
    cout << mx << " " << 0 << '\n';
    return;
  }
  int val = 0;
  for (auto &i : ar) {
    if (i > 0) val += i;
  }
  deque<int> dq;
  for (auto &i : ar) {
    if (i == 0) continue;
    int cur = ((i < 0) ? (0) : (1));
    if (dq.empty()) {
      if (cur == 1) dq.push_back(i);
      continue;
    }
    if (dq.back() == cur) continue;
    else dq.push_back(cur);
  }
  while (dq.front() == 0) dq.pop_front();
  while (dq.back() == 0) dq.pop_back();
  cout << val << " " << ((int)dq.size() - 1) / 2 << '\n';
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