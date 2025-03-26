#include <bits/stdc++.h>

int main(){
	std::ifstream in("factory.in");
	std::ofstream out("factory.out");
	int n, x,y; in >> n;
	
	std::vector<std::vector<int>> neighbors(n);
	for(int i = 0; i < n-1; ++i){
		in >> x >> y;
		neighbors[--y].push_back(--x);
	}

	int root = -1;
	for(int i = 0; i < n; ++i){
		std::vector<bool> visited(n, false);

		visited[i] = true;
		std::vector<int> nodeVisited{i};
		while(!nodeVisited.empty()){
			int curr = nodeVisited.back();
			nodeVisited.pop_back();
			for (int n : neighbors[curr]) {
					if (!visited[n]) {
						visited[n] = true;
						nodeVisited.push_back(n);
					}
			}
		}
		
		bool isValid = true;
		
		for(int j = 0; j < n; ++j){
		    if(!visited[j]){
		        isValid = false;
		        break;
		    }
		}
		
		if(isValid){
		    root = i+1;
		    break;
		}
			
	}
	
	out << root;
	return 0;
}