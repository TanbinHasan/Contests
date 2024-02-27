#include <bits/stdc++.h>

#define int long long
#define ll __int128_t

using namespace std;

template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1);
  template <typename... Args>
  Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

class SparseTable {
 public:
  vector<vector<int>> mat;
  SparseTable(vector<int> &ar) {
    int n = (int)ar.size();
    int pw = __lg(n);
    mat = vector<vector<int>>(n, vector<int>(pw + 1));
    for (int i = 0; i < n; ++i) mat[i][0] = ar[i];
    for (int p = 1; p <= pw; ++p) {
      int x = (1LL << (p - 1));
      for (int i = 0; i + x < n; ++i) {
        mat[i][p] = __gcd(mat[i][p - 1], mat[i + x][p - 1]);
      }
    }
  }
  int query(int l, int r) {
    int g = 0;
    int pw = __lg(r - l + 1);
    for (int i = pw; i >= 0; --i) {
      if ((1LL << i) <= r - l + 1) {
        g = __gcd(g, mat[l][i]);
        l += (1LL << i);
      }
    }
    return g;
  }
};

const int lim = 1050;
bitset<lim> check(3); // sqrt(n) + 1, Safe: 1e7
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

auto prime = GenPrime(lim - 1);

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

vector<vector<int>> pf(1000005);

void PreCalc(void) {}

#define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  cout << "Case " << tc << ": ";
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }
  SparseTable st(a);
  set<int> si;
  map<int, int> mp;
  int left = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (pf[a[i]].empty()) pf[a[i]] = PrimeFact(a[i]);
    for (auto& p : pf[a[i]]) {
      ++mp[p];
      si.insert(p);
    }
    while ((int)si.size() > k) {
      for (auto& p : pf[a[left]]) {
        --mp[p];
        if (mp[p] == 0) si.erase(p);
      }
      ++left;
    }
    if (st.query(left, i) > 1 || (int)si.size() != k) continue;
    ans = max(ans, i - left + 1);
  }
  cout << ans << '\n';
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  PreCalc();
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) Solve(++tc);
  return 0;
}