#include <bits/stdc++.h>

int ans(int a, int b, int c, int d){
	int total = (d-c)+(b-a);
	int intersection  = std::max(std::min(b,d)-std::max(a,c),0);
	return total-intersection;	
}

int main(){
	std::ifstream in("paint.in");
	std::ofstream out("paint.out");
	int a,b,c,d; in >> a >> b >> c >> d;
	out << ans(a,b,c,d);
}