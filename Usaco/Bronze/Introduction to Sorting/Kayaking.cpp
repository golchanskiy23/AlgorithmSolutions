#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> w(2 * n);

  for (int i = 0; i < 2 * n; i++) {
    cin >> w[i];
  }

  sort(w.begin(), w.end());
  int min_unstability = INT_MAX;

  for (int i = 0; i < 2 * n; i++) {
    for (int j = i + 1; j < 2 * n; j++) {
      vector<int> remaining;

      for (int k = 0; k < 2 * n; k++) {
        if (k != i && k != j) {
          remaining.push_back(w[k]);
        }
      }

      int instability = 0;
      for (int k = 0; k < remaining.size(); k += 2) {
        instability += remaining[k + 1] - remaining[k];
      }

      min_unstability = min(min_unstability, instability);
    }
  }

  cout << min_unstability << endl;
  return 0;
}
