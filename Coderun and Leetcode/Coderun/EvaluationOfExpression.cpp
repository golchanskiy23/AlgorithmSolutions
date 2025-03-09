#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <stdexcept>

typedef long long ll;

int calc(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    throw std::logic_error("WRONG");
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*') return 2;
    return 0;
}

void parsing(const std::string& str) {
    std::stack<int> values;
    std::stack<char> operators;
    int n = str.size();
    bool expectNumber = true;

    for (int i = 0; i < n; ++i) {
        char c = str[i];

        if (c == ' ') continue;

        if (std::isdigit(c)) {
            int num = 0;
            while (i < n && std::isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
                ++i;
            }
            --i;
            values.push(num);
            expectNumber = false;
        } 
        else if (c == '(') {
            if (!expectNumber) throw std::logic_error("WRONG");
            operators.push(c);
            expectNumber = true;  // После '(' должно быть число
        } 
        else if (c == ')') {
            if (expectNumber) throw std::logic_error("WRONG");
            
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                if (values.size() < 2) throw std::logic_error("WRONG");
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();

                values.push(calc(a, b, op));
            }
            if (operators.empty() || operators.top() != '(') throw std::logic_error("WRONG");
            operators.pop();
            expectNumber = false;
        } 
        else {
            if (expectNumber) throw std::logic_error("WRONG");
            
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                char op = operators.top();
                operators.pop();

                if (values.size() < 2) throw std::logic_error("WRONG");
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();

                values.push(calc(a, b, op));
            }
            operators.push(c);
            expectNumber = true;
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();

        if (values.size() < 2) throw std::logic_error("WRONG");
        int b = values.top(); values.pop();
        int a = values.top(); values.pop();

        values.push(calc(a, b, op));
    }

    if (values.size() == 1 && operators.empty()) {
        std::cout << values.top();
    } else {
        throw std::logic_error("WRONG");
    }
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    try {
        parsing(input);
    } catch (...) {
        std::cout << "WRONG";
    }

    return 0;
}