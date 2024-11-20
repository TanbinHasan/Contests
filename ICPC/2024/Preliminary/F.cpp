#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

void PreCalculation(void) {}

#define MultipleCase
void Solve(int tc) {
  int a, b, c;
  cin >> a >> b >> c;
  i64 x = 1LL * (b + c - a) * (a + c - b) * (a + b - c);
  i64 y = (a + b + c) * 4LL;
  i64 g = __gcd(x, y);
  x /= g, y /= g;
  cout << x << "/" << y << '\n';
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