#include <bits/stdc++.h>

typedef long long ll;
struct Cow {
    std::string from, when, yearName, to;
};

std::vector<std::string> zodiacs = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", 
                                    "Monkey", "Rooster", "Dog", "Pig", "Rat"};

std::map<std::string, int> birthYear;

int getZodiacIndex(const std::string& zodiac) {
    return std::find(zodiacs.begin(), zodiacs.end(), zodiac) - zodiacs.begin();
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Cow> cows;
    
    for (int i = 0; i < n; ++i) {
        std::string from, when, yearName, to, unused;
        std::cin >> from >> unused >> unused >> when >> yearName >> unused >> unused >> to;
        cows.push_back({from, when, yearName, to});
    }

    birthYear["Bessie"] = 2400;

    for (const auto& cow : cows) {
        int zodiacIdx = getZodiacIndex(cow.yearName);
        int changeIncr = (cow.when == "previous") ? -1 : 1;
        int refYear = birthYear[cow.to]+changeIncr;
        
        while ((refYear % 12 + 12) % 12 != zodiacIdx) {
                refYear += changeIncr;
        }
        birthYear[cow.from] = refYear;
    }

    std::cout << std::abs(birthYear["Elsie"] - birthYear["Bessie"]) << std::endl;

    return 0;
}