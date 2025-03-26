#include <cstdio>
#include <bits/stdc++.h>

int main() {
	std::ifstream in("billboard.in");
	std::ofstream out("billboard.out");

	std::vector<int> x(5), y(5);
	for (int i = 1; i <= 4; i++) { in >> x[i] >> y[i]; }

	if (x[4] >= x[2] && x[3] <= x[1] && y[4] >= y[2] && y[3] <= y[1]) {
		out << 0;
	}
	else if (x[3] <= x[1] && y[3] <= y[1] && y[4] > y[1] && x[4] >= x[2]) {
		out << (x[2] - x[1]) * (y[2] - y[4]);
	}
	else if (y[3] < y[2] && x[3] <= x[1] && y[4] >= y[2] && x[4] >= x[2]) {
		out << (x[2] - x[1]) * (y[3] - y[1]);
	}
	else if (x[4] > x[1] && x[3] <= x[1] && y[4] >= y[2] && y[3] <= y[1]) {
		out << (x[2] - x[4]) * (y[2] - y[1]);
	}
	else if (x[3] < x[2] && x[4] >= x[2] && y[4] >= y[2] && y[3] <= x[1]) {
		out << (x[3] - x[1]) * (y[2] - y[1]);
	}
	else {
		out << (x[2] - x[1]) * (y[2] - y[1]);
	}
}