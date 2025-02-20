#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

int main()
{
    std::ifstream in("pails.in");
    std::ofstream out("pails.out");
    int x,y,m, max = 0;
    in >> x >> y >> m;
    for(int i = 0; i < 1000; ++i){
        int current = x*i;
        if(current > m){
                break;
           }
            max = std::max(max, current);
        for(int j = 0; j < 1000; ++j){
            current += y;
            if(current > m){
                break;
            }
            max = std::max(max, current);
        }
    }
    out << max;
}