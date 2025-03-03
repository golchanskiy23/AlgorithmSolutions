#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ifstream in("lifeguards.in");
    std::ofstream out("lifeguards.out");
    int n;
    in >> n;
    vector<pair<int, int>> shifts(n);

    for (int i = 0; i < n; i++) {
        in >> shifts[i].first >> shifts[i].second;
    }

    sort(shifts.begin(), shifts.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    });

    vector<int> covered(1001, 0);
    int totalCovered = 0;

    for (auto [start, end] : shifts) {
        for (int t = start; t < end; t++) {
            if (covered[t] == 0) {
                totalCovered++;
            }
            covered[t]++;
        }
    }

    int maxCovered = 0;

    for (auto [start, end] : shifts) {
        vector<int> tempCovered = covered;
        int tempTotal = totalCovered;

        for (int t = start; t < end; t++) {
            if (tempCovered[t] == 1) {
                tempCovered[t] = 0;
                tempTotal--;
            }
        }

        maxCovered = max(maxCovered, tempTotal);
        //cout << maxCovered << endl;
    }

    out << maxCovered << endl;
    return 0;
}