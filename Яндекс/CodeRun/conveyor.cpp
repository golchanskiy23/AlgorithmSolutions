#include <bits/stdc++.h>

int main() 
{
	int n; std::cin >> n;
    for(int i = 0; i < n; ++i){
        int k; std::cin >> k;
        double d;
        std::stack<double> stack;
        std::vector<double> v1, v2;
        for(int j = 0; j < k; ++j){
            std::cin >> d;
            v1.push_back(d);
            v2.push_back(d);
        }
        std::sort(v1.begin(), v1.end(), std::greater<double>());
        for(int i = 0; i < v2.size(); ++i){
            if(v2[i] == v1.back()){
                v1.pop_back();
                continue;
            }
            while(!stack.empty() && stack.top() == v1.back()){
                v1.pop_back();
                stack.pop();
                continue;
            }
            stack.push(v2[i]);
        }
        while(!stack.empty() && stack.top() == v1.back()){
                v1.pop_back();
                stack.pop();
        }
        if(stack.empty()) std::cout << 1 << '\n';
        else std::cout << 0 << '\n'; 
    }

	return 0;
}
