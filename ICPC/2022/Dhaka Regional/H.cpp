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

#define MultipleCase    
void Solve(int tc) {
  cout << "Case " << tc << ": ";
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int ans = 1;
  for (int i = 1; i <= n; ++i) ans *= i;
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