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

void PreCalc(void) {}

int days_in_month(int month, int year) {
  vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
    return days[month - 1] + 1;
  }
  return days[month - 1];
}

void print_calendar(int month, int year, int start_day) {
  vector<string> days = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
  cout << "|---------------------------|" << '\n';
  for (int i = 0; i < 7; i++) {
    cout << "|" << days[i];
  }
  cout << "|" << '\n';
  cout << "|---------------------------|" << '\n';
  vector<vector<int>> mat(5, vector<int>(7));
  int curr_day = 1;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 7; j++) {
      if (curr_day <= days_in_month(month, year) && j == start_day) {
        mat[i][j] = curr_day;
        curr_day++;
        start_day++;
        if (start_day > 6) start_day = 0;
      }
    }
  }
  int ind = 0;
  while (curr_day <= days_in_month(month, year)) mat[0][ind++] = curr_day++;
  for (auto& i : mat) {
    for (auto& j : i) {
      cout << "|";
      if (j) cout << setfill(' ') << setw(3) << j;
      else cout << " - ";
    }
    cout << "|" << '\n';
    cout << "|---------------------------|" << '\n';
  }
}

#define MultipleCase
void Solve(__attribute__((unused)) int tc) {
  int date, month, year, start_day;
  char ch;
  string day;
  cin >> date >> ch >> month >> ch >> year >> day;
  if (day == "Sun") {
    start_day = 0;
  } else if (day == "Mon") {
    start_day = 1;
  } else if (day == "Tue") {
    start_day = 2;
  } else if (day == "Wed") {
    start_day = 3;
  } else if (day == "Thu") {
    start_day = 4;
  } else if (day == "Fri") {
    start_day = 5;
  } else if (day == "Sat") {
    start_day = 6;
  }
  start_day = (start_day - date + 1 + 35) % 7;
  print_calendar(month, year, start_day);
  cout << '\n';
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