#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

int main()
{
    std::ifstream in("diamond.in");
    std::ofstream out("diamond.out");
    int n,k, max = 0; in >> n >> k;
    std::vector<int> v, diamonds(n);
    for(int i = 0; i < n; ++i) in >> diamonds[i];
    std::sort(diamonds.begin(), diamonds.end());
    int curr =0;
    for(int i  =0; i < n; ++i){
        curr = 0;
        for(int j = i; j < n; ++j){
            if(std::abs(diamonds[i]-diamonds[j]) <= k){
                curr = j-i+1;
            }
            else break;
        }
        max = std::max(max, curr);
    }
    out << max;
}