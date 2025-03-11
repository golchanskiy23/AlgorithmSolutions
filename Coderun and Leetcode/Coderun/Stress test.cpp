#include <bits/stdc++.h>

int main() 
{
    std::string curr;
    // word / correct_word
    std::map<std::string,std::vector<std::string>> m;
    int n; std::cin >> n;
    for(int i = 0; i < n; ++i){
        std::cin >> curr;
        std::string e = curr;
        std::transform(e.begin(), e.end(), e.begin(), [](unsigned char c) { return std::tolower(c); });
        //std::sort(e.begin(), e.end());
        m[e].push_back(curr);
    }
    std::cin.ignore();  // Игнорируем перевод строки после числа N
    std::getline(std::cin, curr);
    std::stringstream ss(curr);
    int errors = 0;
    while(std::getline(ss,curr,' ')){
        std::string t = curr;
        std::transform(t.begin(), t.end(), t.begin(), [](unsigned char c) { return std::tolower(c); });
        //std::sort(t.begin(),t.end());
        if(m.count(t) == 0){
            int uppers = 0;
            for(auto& a : curr){
                if(std::isupper(a)) uppers++; 
            }
            if(uppers != 1) errors++;
        }
        else{
            bool flag = false;
            for(auto& a : m[t]){
                if(a == curr) flag = true;
            }
            if(!flag) errors++;

        }
    } 

    std::cout << errors;

	return 0;
}