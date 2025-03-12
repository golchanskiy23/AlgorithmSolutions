#include <bits/stdc++.h>


int main() {
    std::ifstream in("citystate.in");
    std::ofstream out("citystate.out");
    
    int n, ans = 0; in >> n;
    std::map<std::string, int> map;
    std::vector<std::pair<std::string, std::string>> pairs;
    for(int i = 0; i < n; ++i){
        std::string a,b; in >> a >> b;
        pairs.push_back(std::make_pair(a.substr(0,2), b));
    }
    
    for(auto& a : pairs){
        if(a.first != a.second) ans += map[a.second+a.first];
        map[a.first+a.second]++;
    }
    out << ans;
}