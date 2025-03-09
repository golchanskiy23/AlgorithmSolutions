#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

using std::cout;
using std::endl;


bool isValid(const std::string& str) {
    if (str[0] != '<' || str[str.size() - 1] != '>') {
        return false;
    }

    std::stack<std::string> stack;
    size_t i = 0;

    while (i < str.size()) {
        if (str[i] != '<') {
            return false;
        }
        i++;

        bool closing = false;
        if (str[i] == '/') {
            closing = true;
            i++;
        }

        if (!(str[i] >= 'a' && str[i] <= 'z')) {
            return false;
        }

        std::string tag = "";
        while (i < str.size() && str[i] >= 'a' && str[i] <= 'z') {
            tag += str[i];
            i++;
        }

        if (str[i] != '>') {
            return false;
        }
        i++;

        if (closing == false) {
            stack.push(tag);
        } else {
            if (stack.empty()) {
                return false;
            }
            if (stack.top() != tag) {
                return false;
            }
            stack.pop();
        }
    }

    return stack.empty();
}

int main() {
    std::string s;
    std::cin >> s;

    std::vector<char> chars = {'<', '/', '>', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    int open_quotes = 0, close_quotes = 0, slashes = 0;
    std::unordered_map<char, int> letters;

    for (char c : s) {
        if (c == '<') open_quotes++;
        else if (c == '>') close_quotes++;
        else if (c == '/') slashes++;
        else letters[c]++;
    }
    
    for (char j : chars) {
        if (j == '<' && open_quotes % 2 == 1) {
            for (size_t i = 0; i < s.size(); i++) {
                char prev = s[i];
                s[i] = j;
                if (isValid(s)) {
                    cout << s << endl;
                    return 0;
                }
                s[i] = prev;
            }
        }
        if (j == '>' && close_quotes % 2 == 1) {
            for (size_t i = 0; i < s.size(); i++) {
                char prev = s[i];
                s[i] = j;
                if (isValid(s)) {
                    cout << s << endl;
                    return 0;
                }
                s[i] = prev;
            }
        }
        if (j == '/' && close_quotes / 2 != slashes) {
            for (size_t i = 0; i < s.size(); i++) {
                char prev = s[i];
                s[i] = j;
                if (isValid(s)) {
                    cout << s << endl;
                    return 0;
                }
                s[i] = prev;
            }
        }
        if (letters[j] % 2 == 1) {
            for (size_t i = 0; i < s.size(); i++) {
                char prev = s[i];
                s[i] = j;
                if (isValid(s)) {
                    cout << s << endl;
                    return 0;
                }
                s[i] = prev;
            }
        }
    }
    return 0;
}