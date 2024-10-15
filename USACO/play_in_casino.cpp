#include <bits/stdc++.h>

int main()
{
    long long t;
    std::cin >> t;
    for(int i = 0; i < t; ++i) {
        long long n, m;
        std::cin >> n >> m;

        std::vector<std::vector<long long>> vec(m, std::vector<long long>(n, 0));

        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < m; ++k) {
                long long q;
                std::cin >> q;
                vec[k][j] = q;
            }
        }

        for(int j = 0; j < m; ++j) {
            std::sort(vec[j].begin(), vec[j].end());
        }

        long long ans = 0;

        for(int k = 0; k < m; ++k) {
            std::vector<long long> prefix(n + 1, 0);
            for(int j = 1; j <= n; ++j) {
                prefix[j] = prefix[j-1] + vec[k][j-1];
                ans += (vec[k][j-1] * (j-1) - prefix[j-1]);
            }
        }

        std::cout << ans << '\n';
    }
}
