#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

void PreCalculation(void) {}

#define MultipleCase
void Solve(int tc) {
  cout << "Case " << tc << ": ";
  i64 n, p;
  cin >> n >> p;
  if (n % 4 == 3) return void(cout << "Oddius\n");
  if (n == 1) return void(cout << ((p == 1) ? ("Evenius") : ("Oddius")) << '\n');
  if (p == 2) return void(cout << ((n & 1) ? ("Evenius") : ("Oddius")) << '\n');
  cout << "Oddius\n";
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