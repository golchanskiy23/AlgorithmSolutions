#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

int main() 
{
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);
	int n; std::cin >> n;
	std::vector<int> v(26,0);
	for(int i = 0; i < n; ++i){
	    std::string a,b; std::cin >> a >> b;
	    std::map<char, int> m1,m2;
	    for(auto& c:a) m1[c-'a']++;
	    for(auto& c:b) m2[c-'a']++;
	    for(int i = 0; i < 26; ++i){
	        v[i] += std::max(m1[i], m2[i]);
	    }
	}
	for(int i = 0; i < 26; ++i){
	    std::cout << v[i] << '\n';
	}
}