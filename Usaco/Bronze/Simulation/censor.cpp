#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

int main() 
{
	freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);
	std::string a,b; std::cin >> a >> b;
	while(a.find(b) != std::string::npos){
	    int idx = a.find(b);
	    a.erase(idx, b.size());
	}
	std::cout << a;
}