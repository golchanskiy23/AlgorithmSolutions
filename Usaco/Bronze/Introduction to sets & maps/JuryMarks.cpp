#include <bits/stdc++.h>
typedef long long ll;

int main() {
    int k, n;
    std::cin >> k >> n;
    std::vector<int> a(k), b(n), prefix(k);
    for (int i = 0; i < k; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];
    prefix[0] = a[0];
    for (int i = 1; i < k; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    std::unordered_set<ll> possible_starts;
    for (int j = 0; j < k; ++j) {
        possible_starts.insert(b[0] - prefix[j]);
    }

    ll answer = 0;
    for (ll start_value : possible_starts) {
        std::unordered_set<ll> generated_results;
        for (int i = 0; i < k; ++i) {
            generated_results.insert(start_value + prefix[i]);
        }

        bool valid = true;
        for (int b_value : b) {
            if (!generated_results.count(b_value)) {
                valid = false;
                break;
            }
        }   
        if (valid) ++answer;
    }
    std::cout << answer << '\n';
}
