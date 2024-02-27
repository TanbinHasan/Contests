#include <bits/stdc++.h>

#define int long long

using namespace std;

const int lim = (int)1e7 + 1;
bitset<lim> check(3);  // sqrt(n) + 1, Safe: 1e7
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

auto prime = GenPrime(lim);  // sqrt(n) + 1, Safe: 1e7

vector<int> PrimeFact(int n) {
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

vector<vector<int>> pf(lim);

#define MultipleCase
void Solve(__attribute__((unused)) int tc) {
  cout << "Case " << tc << ": ";
  int n;
  cin >> n;
  set<int> aprime;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
    if (pf[i].empty()) pf[i] = PrimeFact(i);
    for (auto &j : pf[i]) {
      aprime.insert(j);
    }
  }
  set<int> bprime;
  vector<int> b(n);
  for (auto &i : b) {
    cin >> i;
    if (pf[i].empty()) pf[i] = PrimeFact(i);
    for (auto &j : pf[i]) {
      bprime.insert(j);
    }
  }
  for (auto &i : bprime) {
    if (!aprime.count(i)) {
      cout << "No No\n";
      return;
    }
  }
  cout << "Yes ";
  int g = 0;
  for (auto &i : a) {
    g = __gcd(g, i);
  }
  if (pf[g].empty()) pf[g] = PrimeFact(g);
  int x = a[0];
  int y = b[0];
  if (x >= y) {
    int t = x / y;
    for (int i = 0; i < n; ++i) {
      if (b[i] * t != a[i]) {
        cout << "No\n";
        return;
      }
    }
    if (pf[t].empty()) pf[t] = PrimeFact(t);
    set<int> sgcd(pf[g].begin(), pf[g].end());
    for (auto &i : pf[t]) {
      if (!sgcd.count(i)) {
        cout << "No\n";
        return;
      }
    }
    cout << "Yes\n";
    return;
  } else {
    int t = y / x;
    for (int i = 0; i < n; ++i) {
      if (a[i] * t != b[i]) {
        cout << "No\n";
        return;
      }
    }
    if (pf[t].empty()) pf[t] = PrimeFact(t);
    set<int> sgcd(pf[g].begin(), pf[g].end());
    for (auto &i : pf[t]) {
      if (!sgcd.count(i)) {
        cout << "No\n";
        return;
      }
    }
    cout << "Yes\n";
    return;
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