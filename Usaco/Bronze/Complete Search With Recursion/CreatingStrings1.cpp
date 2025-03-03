#include <bits/stdc++.h>
//typedef long long ll;

std::vector<std::string> v;

void create_permutations(std::string curr, std::vector<int>& app, const std::string& str){
    if(str.size() == curr.size()) {
        v.push_back(curr);
        return;
    }
    for(int i = 0; i < 26; ++i){
        if(app[i] > 0){
            app[i]--;
            curr.push_back(i+'a');
            create_permutations(curr,app,str);
            curr.pop_back();
            app[i]++;
        }
    }
}

int main()
{
    std::string str; std::cin >> str;
    std::vector<int> appearances(26,0);
    for(int i = 0; i < str.size(); ++i){
        appearances[str[i]-'a']++;
    }
    create_permutations("",appearances, str);
    std::cout << v.size() << '\n';
    for(auto& a : v) std::cout << a << '\n';
}