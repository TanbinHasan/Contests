#include <bits/stdc++.h>

#define int long long

using namespace std;

bitset<2000001> check(3);
vector<int> GenPrime(int n) {
  vector<int> prime;
  if (n > 1) prime.push_back(2);
  for (int i = 3; i <= n; i += 2) {
    if (check[i]) continue;
    prime.push_back(i);
    for (int j = i * i; j <= n; j += 2 * i) check[j] = 1;
  }
  return prime;
}

auto prime = GenPrime(2000001);

vector<int> PrimeFact(int n) {
  if (n < 2) return {};
  vector<int> factors;
  for (auto &i : prime) {
    if (1LL * i * i > n) break;
    if (n % i) continue;
    while (!(n % i)) n /= i;
    factors.push_back(i);
  }
  if (n != 1) factors.push_back(n);
  return factors;
}

#define MultipleCase       
void Solve(int tc) {
  cout << "Case " << tc << ": ";
  int a, b, m;
  cin >> a >> b >> m;
  if (a > b) swap(a, b);
  b -= a;
  int ans = m + 1;
  int l = a, r = a + m;
  if (b == 0) {
    if (l == 1 || r == 1) cout << 1 << '\n';
    else cout << 0 << '\n';
    return;
  }
  auto fact = PrimeFact(b);
  int n = (int)fact.size();
  // inclusion-exclusion
  for (int mask = 0; mask < (1LL << n); ++mask) {
    int cnt = 0, prod = 1;
    for (int i = 0; i < n; ++i) {
      if (mask & (1LL << i)) {
        ++cnt;
        prod *= fact[i];
      }
    }
    if (cnt == 0) continue;
    int sign = ((cnt & 1) ? (-1) : (1));
    int cur = r / prod - ((l - 1) / prod);
    ans += (sign * cur);
  }
  cout << ans << '\n';
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