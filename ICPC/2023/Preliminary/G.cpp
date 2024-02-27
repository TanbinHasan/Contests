#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc = 1, tc1 = 1;
  cin >> tc;
up:
  while (tc--) {
    string s;
    cin >> s;
    ll n = s.size(), w = 0, r = 0;
    for (ll i = 0; i < n; i++) {
      if (s[i] == 'W') {
        w++;
      } else {
        ll x = s[i] - '0';
        r += x;
      }
    }
    cout << n / 6 << "." << n % 6 << " Over";
    if (n / 6 > 1) {
      cout << "s ";
    } else if (n / 6 == 1 && n % 6 != 0) {
      cout << "s ";
    } else {
      cout << " ";
    }
    cout << r << " Run";
    if (r > 1) {
      cout << "s ";
    } else {
      cout << " ";
    }
    cout << w << ' ' << "Wicket";
    if (w > 1) {
      cout << "s.";
    } else {
      cout << ".";
    }
    cout << '\n';
  }
}