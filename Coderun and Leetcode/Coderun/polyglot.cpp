#include <iostream>
#include <string>
#include <vector>
#include <set>

int main() 
{
    int n; 
    std::cin >> n;
    std::vector<std::set<std::string>> v(n);
    std::set<std::string> all_languages; 

    for(int i = 0; i < n; ++i) {
        int m; 
        std::cin >> m;
        for(int j = 0; j < m; ++j) {
            std::string str; 
            std::cin >> str;
            v[i].insert(str);
            all_languages.insert(str);
        }
    }

    std::set<std::string> intersection_set = v[0]; 

    for(int i = 1; i < n; ++i) {
        std::set<std::string> temp;
        for (const auto& lang : v[i]) {
            if (intersection_set.count(lang)) {
                temp.insert(lang);
            }
        }
        intersection_set = std::move(temp);
    }

    std::cout << intersection_set.size() << '\n';
    for (const auto& lang : intersection_set) {
        std::cout << lang << '\n';
    }

    std::cout << all_languages.size() << '\n';
    for (const auto& lang : all_languages) {
        std::cout << lang << '\n';
    }

    return 0;
}
