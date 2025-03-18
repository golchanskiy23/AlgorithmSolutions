#include <bits/stdc++.h>

int main()
{
    std::ifstream in("breedflip.in");
    std::ofstream out("breedflip.out");
    int n, ans = 0; in >> n;
    std::string s1,s2; in >> s1 >> s2;
    // GHHHGHH
    // HHGGGHH
    bool flag = false;
    for(int i = 0; i < s1.size(); ++i){
        if(s1[i] != s2[i]){
            flag = true;
        }
        else if(s1[i] == s2[i]){
            if(flag){
                ans++;
            }
            flag = false;
        }
    }
    if(flag) ++ans;
    out << ans;
    return 0;
}