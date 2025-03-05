#include <iostream>
#include <vector>
#include <concepts>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
typedef long long ll;

template <typename T>
concept Comparable = requires(T a, T b) {
    { a == b } -> std::same_as<bool>;
    { a != b } -> std::same_as<bool>;
    { a < b } -> std::same_as<bool>;
    { a > b } -> std::same_as<bool>;
    { a <= b } -> std::same_as<bool>;
    { a >= b } -> std::same_as<bool>;
};


// return idx of vector or -1 if doesn't exist
// return min idx of target in vector
template<class T>
requires Comparable<T>
ll binary_search(std::vector<T> vector, ll l, ll r, T target) {
    if (l == r) {
        if (vector[l] != target) return -1;
        return l;
    }
    ll mid = l + (r-l)/2;
    T curr = vector[mid];
    std::cout << l << " " << r << '\n';
    if (target <= vector[mid]) return binary_search(vector, l,mid,target);
    return binary_search(vector,mid+1, r, target);
}

int main() {
    std::vector<std::string> v{"a","b","bdc","bfg","bvf","c","derf"};
    std::cout << binary_search<std::string>(v, 0,v.size()-1,"ca");
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.