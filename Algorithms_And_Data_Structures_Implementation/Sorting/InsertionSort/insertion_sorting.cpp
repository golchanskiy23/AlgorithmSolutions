#include <iostream>
#include <vector>

template <typename T>
std::vector<T>& insertion(std::vector<T>& vec){
	size_t n = vec.size();
	if(n <= 1) return vec;
	for(size_t i = 0; i < n; ++i){
		size_t j = i;
		while(j > 0 && vec[j] < vec[j-1]){
			std::swap(vec[j], vec[j-1]);
			--j;
		}
	}
	return vec;
}

int main(){
	std::vector<std::string> v{"aaaaa","wq","r"};
	v = insertion(v);
	for(auto& a : v) std::cout << a << " ";
}
