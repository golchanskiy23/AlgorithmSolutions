#include <bits/stdc++.h>

using namespace std;

const int RESTRICT_LEN = 6;
const vector<string> COWS = {"Beatrice", "Belinda", "Bella",     "Bessie",
                             "Betsy",    "Blue",    "Buttercup", "Sue"};

vector<vector<string>> orderings;
void build(vector<string> ordering) {
	if ((int)(ordering.size()) == 8) {
		orderings.push_back(ordering);
		return;
	}

	for (const string &COW : COWS) {
		if (find(ordering.begin(), ordering.end(), COW) == ordering.end()) {
			ordering.push_back(COW);
			build(ordering);
			ordering.pop_back();
		}
	}
}

int loc(const vector<string> &order, const string &cow) {
	return find(order.begin(), order.end(), cow) - order.begin();
}

int main() {
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	int n;
	cin >> n;

	vector<pair<string, string>> restrictions;
	for (int i = 0; i < n; i++) {
		string cow1 = "";
		string cow2 = "";
		for (int j = 0; j < RESTRICT_LEN; j++) {
			string word;
			cin >> word;
			cow1 = cow1.empty() ? word : cow1;
			cow2 = word;
		}
		restrictions.emplace_back(cow1, cow2);
	}

	build({});
	for (vector<string> &order : orderings) {
		bool ok = true;
		for (const pair<string, string> &rule : restrictions) {
			if (abs(loc(order, rule.first) - loc(order, rule.second)) > 1) {
				ok = 0;
				break;
			}
		}

		if (ok) {
			for (const string &i : order) { cout << i << '\n'; }
			break;
		}
	}
}