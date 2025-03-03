#include <iostream>
#include <string>
#include <vector>

bool is_palindrome(int l, int r, const std::vector<int>& v){
	bool flag = true;
	while(l <= r){
		if(v[l] != v[r]){
			flag = false;
			break;
		}
		l++;
		r--;
	}
	return flag;
}

int main() 
{
	int n; std::cin >> n;
	std::vector<int> v(n);
	for(int i =0; i < n; ++i){
		std::cin >> v[i];
	}
	int l = n-1, r = n-1, max_l = n-1;
	while(l >= 0){
		if(is_palindrome(l,r,v)){
			max_l = l;
		}
		--l;
	}
	if(max_l == 0) std::cout << 0;
	else{
		std::cout << max_l << '\n';
		for(int i = max_l-1; i >= 0; --i) std::cout << v[i] << " ";
	}

	return 0;
}