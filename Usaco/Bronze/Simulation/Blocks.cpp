#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <set>
#include <string>


int main()
{
    freopen("blocks.in","r",stdin);
    freopen("blocks.out","w",stdout);
    int n; std::cin >> n;
    std::vector<int> alphabet(26,0);
    for(int i = 0; i < n; ++i) {
        std::string s1, s2; std::cin >> s1 >> s2;
        std::set<char> s;
        for(auto& a : s1) s.insert(a);
        for(auto& a : s2) s.insert(a);
        for(auto& a : s)  alphabet[a-'a'] += 1;
    }
    for(auto& a : alphabet){
        std::cout << a << '\n';
    }

    return 0;
}