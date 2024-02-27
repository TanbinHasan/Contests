#include <bits/stdc++.h>

#define int long long

using namespace std;

#define MultipleCase       
void Solve(int tc) {
  cout << "Case " << tc << ": ";
  int n;
  cin >> n;
  vector<int> val(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
  }
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> dis(n + 1);
  vector<bool> vis(n + 1);
  queue<int> q;
  q.push(1);
  vis[1] = true;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (auto &child : adj[node]) {
      if (vis[child]) continue;
      vis[child] = true;
      dis[child] = (dis[node] + 1) % 2;
      q.push(child);
    }
  }
  int k1 = 0, k2 = 0;
  for (int i = 1; i <= n; ++i) {
    if (dis[i] == 0) ++k1, k2 += val[i];
    else --k1, k2 -= val[i];
  }
  int ans = 1, mx = numeric_limits<int>::min();
  for (int i = 1; i <= n; ++i) {
    if (dis[i] == 1) {
      int cur = k2 - val[i] * k1;
      if (cur > mx) {
        mx = cur;
        ans = i;
      }
    } else {
      int cur = val[i] * k1 - k2;
      if (cur > mx) {
        mx = cur;
        ans = i;
      }
    }
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