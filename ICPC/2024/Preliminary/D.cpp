#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

template <int MOD>
class Mint {
 public:
  static const int mod = MOD;
  int v;
  explicit operator int() const { return v; }
  Mint() : v(0) {}
  Mint(i64 _v) : v(int(_v % MOD)) { v += (v < 0) * MOD; }
  Mint& operator+=(Mint o) {
    if ((v += o.v) >= MOD) v -= MOD;
    return *this;
  }
  Mint& operator-=(Mint o) {
    if ((v -= o.v) < 0) v += MOD;
    return *this;
  }
  Mint& operator*=(Mint o) {
    v = int(1LL * v * o.v % MOD);
    return *this;
  }
  friend Mint power(Mint b, i64 p) {
    Mint res = 1;
    while (p > 0) {
      if (p & 1) res *= b;
      b *= b;
      p >>= 1;
    }
    return res;
  }
  friend Mint inv(Mint b) {
    assert(b.v != 0);
    return power(b, MOD - 2);
  }
  friend Mint operator+(Mint a, Mint b) { return a += b; }
  friend Mint operator-(Mint a, Mint b) { return a -= b; }
  friend Mint operator*(Mint a, Mint b) { return a *= b; }
};

const int MX = (int)3e5 + 10;
const int MOD = 998244353;
using mi = Mint<MOD>;
vector<mi> F(MX), IF(MX), I(MX); // factorial, inverse factorial, inverse value
bool ISCALC;

class Combinatorics {
  bool CalcFacts(void) {
    F[0] = F[1] = IF[0] = IF[1] = I[1] = 1;
    for (int i = 2; i < MX; ++i) {
      I[i] = I[MOD % i] * -(MOD / i);
      F[i] = F[i - 1] * i;
      IF[i] = IF[i - 1] * I[i];
    }
    return true;
  }
 public:
  Combinatorics() { if (!ISCALC) ISCALC = CalcFacts(); }
  mi nPr(int n, int r) { return F[n] * IF[n - r]; }
  mi nCr(int n, int r) { return nPr(n, r) * IF[r]; }
};

void PreCalculation(void) {}

// #define MultipleCase
void Solve(int tc) {
  Combinatorics comb;
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  i64 sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    sum += b[i];
  }
  for (int k = 1; k <= n; ++k) {
    mi x = comb.nCr(n - 1, k - 1) * sum;
    mi y = (mi)2 * comb.nCr(n, k);
    cout << (int)(x * inv(y)) << " \n"[k == n];
  }
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