#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

int main()
{
    //std::ifstream in("diamond.in");
    //std::ofstream out("diamond.out");
    int n; std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0;  i < n; ++i) std::cin >> v[i];
    
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        double sum = 0.0;
        for(int j = i; j < n; ++j){
            sum += v[j];
            for(int k = i; k <= j; ++k){
                if(sum/(j-i+1) == v[k]){
                    cnt++;
                    break;
                }
            }
        }
    }
    std::cout << cnt;
}