#include <iostream>
#include <string>
#include <vector>
#include <set>

int main() 
{
	int n; std::cin >> n;
	std::set<int> set;
	for(int i = 0; i < n; ++i){
		int a,b; std::cin >> a >> b;
		set.insert(a);
	}
	std::cout << set.size();

	return 0;
}