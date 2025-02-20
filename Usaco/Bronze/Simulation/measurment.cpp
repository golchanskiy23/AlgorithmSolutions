#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

class Cow {
    public:
    int day, add;
    std::string name;
    Cow() = delete;
    
    Cow(int d, std::string n, int a) {
        day = d;
        name = n;
        add = a;
    }
};

bool comp(const Cow& c1, const Cow& c2) {
    return c1.day < c2.day;
}

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n; 
    std::cin >> n;
    
    std::map<std::string, int> m = {{"Bessie", 0}, {"Elsie", 1}, {"Mildred", 2}};
    std::vector<int> r(3, 7);
    std::vector<Cow> v;
    
    for (int i = 0; i < n; ++i) {
        int day, change;
        std::string name;
        std::cin >> day >> name >> change;
        v.push_back(Cow(day, name, change));
    }
    
    std::sort(v.begin(), v.end(), comp);
    
    int leader_val = 7;
    int ans = 0;
    std::set<std::string> current_leaders = {"Bessie", "Elsie", "Mildred"};
    
    for (int i = 0; i < n; ++i) {
        r[m[v[i].name]] += v[i].add;
        int new_leader_val = *std::max_element(r.begin(), r.end());
        std::set<std::string> new_leaders;
        for (const auto& cow : m) {
            if (r[cow.second] == new_leader_val) {
                new_leaders.insert(cow.first);
            }
        }
        if (new_leaders != current_leaders) {
            ans++;
            current_leaders = new_leaders;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
