#include <bits/stdc++.h>

void reverse(std::vector<int>& v, int start, int end){
	while(start < end){
	    int temp = 0;
	    temp = v[start];
	    v[start] = v[end];
	    v[end] = temp;
	    
	    start++;
	    end--;
	}
}

int main(){
	std::ifstream in("swap.in");
	std::ofstream out("swap.out");

	int n,k,a,b,c,d; in >> n >> k >> a >> b >> c >> d;
	std::vector<int> v(n);
	for(int i = 1; i <= n; ++i) v[i-1] = i;
	
	std::set<std::vector<int>> reversed{v};
	while(true){
		reverse(v, a-1, b-1);
		reverse(v, c-1, d-1);
		if(reversed.count(v) != 0) break;
		reversed.insert(v);
	}
	
	int mod = k%(int)reversed.size();
	for(int i = 0; i < mod; ++i){
		reverse(v, a-1, b-1);
		reverse(v, c-1, d-1);
	}

	for(auto& a : v){
	    out << a << '\n';
	}	
}