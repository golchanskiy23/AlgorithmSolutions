#include <bits/stdc++.h>


int main() {
    std::ifstream in("notlast.in");
    std::ofstream out("notlast.out");
    std::map<std::string, int> map = {{"Bessie",0}, {"Elsie",0}, {"Daisy",0}, {"Gertie",0}, 
        {"Annabelle",0}, {"Maggie",0}, {"Henrietta",0}};
    
    std::vector<std::vector<std::string>> v(10001);
    int n; in >> n;
    for(int i = 0; i < n; ++i){
        std::string string; in >> string;
        int curr; in >> curr;
        map[string] += curr;
    }
    
    for(auto& a : map)  v[a.second].push_back(a.first);
    
    int smallestIdx = -1;
    for(int i = 0; i < v.size(); ++i){
        if(!v[i].empty() && smallestIdx == -1) smallestIdx = i;
        else if(!v[i].empty() && smallestIdx != -1){
            if(v[i].size() > 1) out << "Tie" << '\n';
            else {
                out << v[i][0] << '\n';
            }
            return 0;
        }
    }
    out << "Tie" << '\n';
}
