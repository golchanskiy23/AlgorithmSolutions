#include <bits/stdc++.h>

int main(){
    std::ifstream in("herding.in");
    std::ofstream out("herding.out");
	int a,b,c; in >> a >> b >> c;
	std::vector<int> v{a,b,c};
	std::sort(v.begin(), v.end());
	int diff1 = v[1]-v[0], diff2 = v[2]-v[1];
	if(diff2 == 1 && diff1 == 1) {
	    out << 0 << '\n';
	}
	else if(diff1 == 2 || diff2 == 2){
	    out << 1 << '\n';
	}
	else{
	    out << 2 << '\n';
	}
	int ans = std::max(v[2]-v[1] , v[1]-v[0]) - 1;
	out << ans << '\n';
}