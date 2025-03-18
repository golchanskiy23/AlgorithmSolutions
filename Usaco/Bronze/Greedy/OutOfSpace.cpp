#include <bits/stdc++.h>

int main(){
    std::ifstream in("outofplace.in");
    std::ofstream out("outofplace.out");
	int n; in >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i) in >> v[i];
	std::vector<int> tmp(v);
	std::sort(tmp.begin(), tmp.end());
	int k =  0;
	for(int i = 0; i < n; ++i){
	    if(tmp[i] != v[i]) k++;
	}
	out << k-1;
}