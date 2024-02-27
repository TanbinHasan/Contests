#include <bits/stdc++.h>

#define int long long

using namespace std;

#define MultipleCase       
void Solve(int tc) {
  cout << "Case #" << tc << ": ";
  int n, k;
  cin >> n >> k;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  map<int, int> mp;
  set<int> part1, part2;
  for (auto &i : ar) {
    ++mp[i];
    if (mp[i] == 1) {
      if ((int)part1.size() < k) part1.insert(i);
      else if ((int)part2.size() < k) part2.insert(i);
      else {
        cout << "NO\n";
        return;
      }
    } else if (mp[i] == 2) {
      if ((int)part2.size() < k) part2.insert(i);
      else if ((int)part1.size() < k) part1.insert(i);
      else {
        cout << "NO\n";
        return;
      }
    } else {
      cout << "NO\n";
      return;
    }
  }
  cout << (((int)part1.size() + (int)part2.size() == n) ? ("YES") : ("NO")) << '\n';
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