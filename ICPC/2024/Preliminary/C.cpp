#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

void PreCalculation(void) {}

#define MultipleCase
void Solve(int tc) {
  cout << "Case " << tc << ": ";
  int n, k;
  cin >> n >> k;
  i64 ans = 0;
  while (n--) {
    int x, y;
    cin >> x >> y;
    ans += (k / x);
  }
  cout << ans << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  PreCalculation();
  int tt = 1;
#ifdef MultipleCase
  cin >> tt;
#endif
  for (int tc = 1; tc <= tt; ++tc) {
    Solve(tc);
  }
  return 0;
}