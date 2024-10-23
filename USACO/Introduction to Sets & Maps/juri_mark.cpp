    #include <bits/stdc++.h>
     
    int main() {
      int k, n;
      std::cin >> k >> n;
      std::vector<int> changes(k + 1);
      std::vector<int> scores(n);
      for (int i = 1; i <= k; ++i) {
        std::cin >> changes[i];
        changes[i] += changes[i - 1];
      }
      for (int& p : scores)
        std::cin >> p;
      std::set<int> poss_starts;
      for (int m = 1; m <= k; ++m)
        poss_starts.insert(scores.front() - changes[m]);
      int ans = 0;
      for (int s : poss_starts) {
        std::set<int> points;
        for (int i = 1; i <= k; ++i)
          points.insert(s + changes[i]);
        bool valid = true;
        for (int p : scores)
          valid &= points.count(p);
        ans += valid;
      }
      std::cout << ans << "\n";
    }
