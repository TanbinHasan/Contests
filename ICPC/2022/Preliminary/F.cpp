#include <bits/stdc++.h>

#define int long long

using namespace std;

// #define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  map<string, pair<int, string>> mp;
  int n;
  cin >> n;
  vector<tuple<int, int, int, int, int, int, string, string, string>> vt(n);
  for (auto &[dd, mm, yy, h, m, s, a, b, c] : vt) {
    char c1, c2, c3, c4, c5;
    cin >> dd >> c1 >> mm >> c2 >> yy >> c3 >> h >> c4 >> m >> c5 >> s >> a >> b >> c;
  }
  sort(vt.begin(), vt.end());
  for (auto &[dd, mm, yy, h, m, s, a, b, c] : vt) {
    string year;
    year.push_back(b.back());
    b.pop_back();
    year.push_back(b.back());
    b.pop_back();
    year.push_back(b.back());
    b.pop_back();
    year.push_back(b.back());
    b.pop_back();
    reverse(year.begin(), year.end());
    mp[a] = {stoll(year), c};
  }
  map<int, int> m1;
  map<string, int> m2;
  set<string> ss = {"A+", "A-", "AB+", "AB-", "B+", "B-", "O+", "O-"};
  for (auto &[x, y] : mp) {
    ++m1[y.first];
    ++m2[y.second];
    ss.erase(y.second);
  }
  for (auto &i : ss) {
    m2.insert({i, 0});
  }
  for (auto &[x, y] : m2) {
    cout << x << " " << y << '\n';
  }
  for (auto &[x, y] : m1) {
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