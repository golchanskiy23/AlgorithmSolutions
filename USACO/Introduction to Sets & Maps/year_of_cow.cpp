#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

const vector<string> ZODIAC{"Ox",   "Tiger",  "Rabbit",  "Dragon", "Snake", "Horse",
                            "Goat", "Monkey", "Rooster", "Dog",    "Pig",   "Rat"};

struct Relation {
	string name;
	bool prev;  // is this a "previous" or "next" relation?
	int year;
	string relative;
};

int mod(int n, int m) { return ((n % m) + m) % m; }

int main() {
	int n;
	std::cin >> n;

	vector<Relation> relations(n);
	for (Relation &r : relations) {
		string unused;
		string prev_str;
		string animal;
		std::cin >> r.name >> unused >> unused >> prev_str >> animal >> unused >>
		    unused >> r.relative;

		r.prev = prev_str == "previous";
		r.year = std::find(ZODIAC.begin(), ZODIAC.end(), animal) - ZODIAC.begin();
	}

	std::map<string, int> birthYears{{"Bessie", 0}};
	for (Relation r : relations) {
		int change = r.prev ? -1 : 1;
		// +change because it has to be at least 1 year off
		int year = birthYears[r.relative] + change;
		while (mod(year, ZODIAC.size()) != r.year) { year += change; }
		birthYears[r.name] = year;
	}

	int dist = abs(birthYears["Bessie"] - birthYears["Elsie"]);
	cout << dist << endl;
}
