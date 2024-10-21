#include <bits/stdc++.h>

bool is_palindrome(const std::vector<int>& v, int left, int right) {
    while (left < right) {
        if (v[left] != v[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}


int main(){
	int n; std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	
	int add_count = n;
    for (int i = 0; i < n; ++i) {
        if (is_palindrome(v, i, n - 1)) {
            add_count = i;
            break;
        }
    }

    std::cout << add_count << std::endl;
    for (int i = add_count - 1; i >= 0; --i) {
        std::cout << v[i] << " ";
    }
}
