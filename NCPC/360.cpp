#include <bits/stdc++.h>
using namespace std;

// Function to find the length of LCS of A and B
int lcs(vector<int>& A, vector<int>& B, int m, int n) {
  // Create a 2D array to store the lengths of LCS for subproblems
  vector<vector<int>> L(m + 1, vector<int>(n + 1));

  // Fill the array using bottom-up approach
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      // If either A or B is empty, LCS is 0
      if (i == 0 || j == 0) {
        L[i][j] = 0;
      }
      // If the last elements of A and B are equal, LCS is 1 + LCS of remaining elements
      else if (A[i - 1] == B[j - 1]) {
        L[i][j] = 1 + L[i - 1][j - 1];
      }
      // If the last elements of A and B are different, LCS is the maximum of LCS of A without last element and LCS of B without last element
      else {
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);
      }
    }
  }

  // Return the length of LCS of A and B
  return L[m][n];
}

// Function to find the minimum length of the subarray to be deleted from B
int minDelete(vector<int>& A, vector<int>& B, int m, int n) {
  // Find the length of LCS of A and B
  int l = lcs(A, B, m, n);

  // Return the difference between the length of B and the length of LCS
  return n - l;
}

// Driver code
int main() {
  
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    vector<int> b(n);
    for (auto& i : b) {
      cin >> i;
    }
    cout << minDelete(a, b, n, n) << '\n';
  }
  return 0;
}
