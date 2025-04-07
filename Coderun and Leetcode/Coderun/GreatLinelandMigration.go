#include <bits/stdc++.h>

int main() 
{
	int n; std::cin >> n;
	std::vector<int> idxs(n), v(n);
	for(int i =0; i < n; ++i) std::cin >> v[i];
	std::iota(idxs.begin(), idxs.end(), 0);
	std::stack<int> stack;
	for(int i = 0; i < n; ++i){
		while (!stack.empty() && v[i] < v[stack.top()]) {
				idxs[stack.top()] = i;
				stack.pop();
		}
		stack.push(i);
	}

	while (!stack.empty()){
		idxs[stack.top()] = -1;
		stack.pop();
	}

	for(auto& a : idxs) std::cout << a << " ";

	return 0;
}