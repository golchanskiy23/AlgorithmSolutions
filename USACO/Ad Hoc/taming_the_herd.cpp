#include <bits/stdc++.h>

int main() {
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);
	int n;	std::cin >> n;
	std::vector<int> status(n, 0);
	std::vector<int> log(n);
	for (int i = 0; i < n; i++) { std::cin >> log[i]; }
	bool valid = true;
	if (log[0] == 1) {
		valid = false;
	} else {
		status[0] = 2;
	}

	for (int i = 1; i < n; i++) {
		if (!valid) { break; }
		if (log[i] == -1) {
			continue;
		} else if (log[i] == 0) {
			status[i] = 2;
		} else {
			status[i] = 1;
			int curr_index = i - 1;
			log[i]--;
			while (log[i] > 0 && curr_index > -1) {
				if (status[curr_index] == 0 || status[curr_index] == 1) {
					status[curr_index] = 1;
				} else {
					valid = false;
					break;
				}
				log[i]--;
				curr_index--;
			}
			if (curr_index > -1 &&
			    (status[curr_index] == 0 || status[curr_index] == 2)) {
				status[curr_index] = 2;
			} else {
				valid = false;
			}
		}
	}

	int min_ans = 0;
	int max_ans = 0;
	if (valid) {
		for (int i : status) {
			if (i == 2) {
				min_ans++;
				max_ans++;
			} else if (i == 0) {
				max_ans++;
			}
		}
		std::cout << min_ans << " " << max_ans << "\n";
	} else {
		std::cout << -1 << "\n";
	}
}
