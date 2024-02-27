#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll LIS(vector<ll> &ar) {
  vector<ll> v;
  for (auto &i : ar) {
    auto it = lower_bound(v.begin(), v.end(), i);
    if (it == (v).end())
      v.push_back(i);
    else
      *it = i;
  }
  return (ll)v.size();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc = 1, tc1 = 1;
  cin >> tc;
up:
  while (tc--) {
    ll n;
    cin >> n;
    ll b[n];
    for (ll i = 0; i < n; i++) {
      cin >> b[i];
    }
    cout << "Case " << tc1++ << ": ";
    vector<ll> a;
    for (ll i = 0; i < n - 1; i++) {
      if (b[i] != b[i + 1]) {
        a.push_back(b[i]);
      }
    }
    if (b[n - 1] != a.back()) {
      a.push_back(b[n - 1]);
    }
    ll mx = 0, mx1 = -1;
    n = a.size();
    for (ll i = 1; i < n - 1; i++) {
      if (a[i - 1] < a[i] && a[i + 1] < a[i]) {
        if (mx < a[i]) {
          mx = a[i];
          mx1 = i;
        }
      }
    }
    if (mx1 == -1) {
      cout << "-1\n";
      goto up;
    }
    vector<ll> v;
    for (ll i = 0; i <= mx1; i++) {
      v.push_back(a[i]);
    }
    ll l1 = LIS(v);
    v.clear();
    for (ll i = n - 1; i >= mx1; i--) {
      v.push_back(a[i]);
    }
    ll l2 = LIS(v);
    cout << l1 + l2 - 1 << '\n';
  }
}