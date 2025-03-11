#include <iostream>
#include <string>
#include <vector>
#include <set>

void output(const std::set<int>& s){
	std::cout << s.size() << '\n';
	for(auto& a : s) std::cout << a << " ";
	std::cout << '\n';
}

int main() 
{
	int n,m,c; std::cin >> n >> m;
	std::set<int> AnyaSet, BoryaSet, ResultSet;
	for(int i = 0; i < n; ++i){
		std::cin >> c;
		AnyaSet.insert(c);
	}
	for(int i = 0; i < m; ++i){
		std::cin >> c;
		BoryaSet.insert(c);
	}

	for (auto it = AnyaSet.begin(); it != AnyaSet.end(); ) {
        if (BoryaSet.count(*it) != 0) {
            ResultSet.insert(*it);
            BoryaSet.erase(*it);
            it = AnyaSet.erase(it); // Correct way to erase while iterating
        } else {
            ++it;
        }
    }

	output(ResultSet);
	output(AnyaSet);
	output(BoryaSet);

	return 0;
}