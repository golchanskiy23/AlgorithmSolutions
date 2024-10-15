#include <bits/stdc++.h>


int main() 
{
   std::vector<int> v1, v2;
    int num;
	while (std::cin.peek() != '\n') {
        std::cin >> num;
        v1.push_back(num);
    }
    std::cin.ignore(); 
    
    while (std::cin.peek() != '\n') {
        std::cin >> num;
        v2.push_back(num);
    }
    std::cin.ignore(); 
    int f=0,s =0;
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    while(f < v1.size() && s < v2.size()){
        if(v1[f] > v2[s]) ++s;
        else if(v1[f] < v2[s]) ++f;
        else{
            std::cout << v1[f] << " ";
            ++s;
        }
    }
    
	return 0;
}
