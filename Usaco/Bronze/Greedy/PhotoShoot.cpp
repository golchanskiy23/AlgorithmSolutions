#include <bits/stdc++.h>

int main(){
	int n, flip = 0; std::cin >> n;
	std::string s; std::cin >> s;
	for(int i = n-2; i >= 0; i -= 2){
		auto substr = s.substr(i,2);
		if((substr == "GH" && flip%2 == 0) || (substr == "HG" && flip%2 == 1)){
			flip++;
		}
	}

	std::cout << flip;
}