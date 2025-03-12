#include <bits/stdc++.h>
typedef long long ll;

int main(){
    std::ifstream in("whereami.in");
    std::ofstream out("whereami.out");
    ll n; in >> n;
    std::string str; in >> str;
    for(int i = 1; i <= n; ++i){
        std::map<std::string, int> map;
        bool flag = false;
        for(int j = 0; j <= n-i;++j){
            std::string curr = str.substr(j,i);
            //std::cout << curr << " ";
            map[curr]++;
            if(map[curr] > 1) flag = true;
        }
        //std::cout << '\n';
        if(!flag){
            out << i;
            return 0;
        }
    }
}