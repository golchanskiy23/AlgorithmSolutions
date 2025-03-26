#include <bits/stdc++.h>

constexpr int COLORS = 4;

int main() {
	std::ifstream in("revegetate.in");
	std::ofstream out("revegetate.out");
	int pasture_num, cow_num, p1, p2;
	in >> pasture_num >> cow_num;
	std::vector<std::pair<int, int>> cows(cow_num);
	for (int i = 0; i < cow_num; ++i) {
		in >> p1 >> p2;
		p1--;
		p2--;
		if (p1 > p2) std::swap(p1, p2);
		cows[i] = std::make_pair(p1,p2);
	}

	std::vector<int> pastures(pasture_num);
	for (int p = 0; p < pasture_num; p++) {
		int color = 1;
		for (; color <= COLORS; color++) {
			bool conflicts = false;
			for (auto& a : cows) {
			    int f = a.first, s = a.second;
				if (pastures[f] == color && s == p) {
					conflicts = true;
					break;
				}
			}
			if (!conflicts) { break; }
		}
		pastures[p] = color;
	}


	for (auto& a : pastures){
	    out << a;
	}
}