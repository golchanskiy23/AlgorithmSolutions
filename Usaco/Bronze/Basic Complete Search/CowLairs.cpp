#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

int main()
{
    //std::ifstream in("diamond.in");
    //std::ofstream out("diamond.out");
    int n; std::cin >> n;
    std::vector<std::pair<int, std::string>> v;
    for(int i = 0;  i < n; ++i) {
        std::string w; int e;
        std::cin >> w >> e;
        v.push_back(std::make_pair(e,w));
    }
    std::sort(v.begin(), v.end());
    std::vector<int> greater_lairs(n,0) , less_lairs(n,0);
    for(int i = 1; i < n; ++i){
        less_lairs[i] = less_lairs[i-1];
        if(v[i-1].second == "L"){
            less_lairs[i] += 1;
        }
    }
    
    for(int i = n-2; i >= 0; --i){
        greater_lairs[i] = greater_lairs[i+1];
        if(v[i+1].second == "G"){
            greater_lairs[i] += 1;
        }
    }
    int cnt = INT_MAX;
    for(int i = 0; i < n; ++i){
        cnt = std::min(cnt, greater_lairs[i]+less_lairs[i]);
    }
    
    std::cout << cnt;
}