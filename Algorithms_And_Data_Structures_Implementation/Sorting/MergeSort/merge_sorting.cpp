#include <iostream>
#include <vector>

namespace sorting {
    template<typename T>
    std::vector<T> merge(const std::vector<T>& first, const std::vector<T>& second) {
        size_t idx1 = 0, idx2 = 0;
        size_t first_size = first.size(), second_size = second.size();
        std::vector<T> ans;

        while (idx1 < first_size && idx2 < second_size) {
            if (first[idx1] < second[idx2])
                ans.push_back(first[idx1++]);
            else
                ans.push_back(second[idx2++]);
        }

        while (idx1 < first_size) {
            ans.push_back(first[idx1++]);
        }

        while (idx2 < second_size) {
            ans.push_back(second[idx2++]);
        }

        return ans;
    }

    template<typename T>
    std::vector<T>& sort(std::vector<T>& vec) {
        size_t n = vec.size();
        if (n <= 1) return vec;

        size_t mid = n / 2;
        std::vector<T> left(vec.begin(), vec.begin() + mid);
        std::vector<T> right(vec.begin() + mid, vec.end());

        sort(left);
        sort(right);

        vec = merge(left, right);

        return vec;
    }
}

int main() {
    std::vector<long long> v{3, 5, 4, 6, 7, 8, 7, 3, 2, 33, 24, 556, 786, 2112121, 25463653, 6685, -22323, -35245345, -42354234543524524, 452315454242};
    sorting::sort(v);
    for (const auto& a : v) std::cout << a << " ";
    return 0;
}
