#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;
template <class T, class C = less<T>>
using iset = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class C = less_equal<T>>
using imultiset = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;
vector<int> val = {0, 1, 2, 2, 4};

int r(int n, int k) {
  // cout << n << " " << k << '\n';
  int p = n + 2;
  int a = (1LL << p);
  if (a < k) return -1;
  if (p == 2) return val[k];
  a >>= 1;
  if (a < k) return 2LL * r(n - 1, k - a);
  else return r(n - 1, k);
}

#define MultipleCase    
void Solve(int tc) {
  cout << "Case " << tc << ": ";
  int k, n;
  cin >> k >> n;
  cout << r(n, k) << '\n';
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