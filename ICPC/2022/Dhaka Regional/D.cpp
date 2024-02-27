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
  double x;
  cin >> x;
  double y = sqrtl(4.0l - x * x);
  cout << fixed << setprecision(4) << sqrtl(x * x - 1) / y << '\n';
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