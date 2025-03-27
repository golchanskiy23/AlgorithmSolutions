#include <bits/stdc++.h>
using ll = long long;
 
int main() {
 ll n;
 std::cin >> n;
 std::stack<std::pair<ll, ll>> stack;
 stack.push({0, 0});
 
	for(int i = 1; i <= n; ++i) {
		ll a; std::cin >> a;
		while(!stack.empty() && stack.top().first >= a) stack.pop();
		std::cout << stack.top().second << " ";
		stack.push({a, i});
	}
}