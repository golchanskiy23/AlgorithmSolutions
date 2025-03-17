#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, num;
    char op;
    cin >> n;

    deque<int> left, right;

    for(int i=0; i < n;++i) {
        cin >> op;
        if (op == '+') {
            cin >> num;
            right.push_back(num);
        } 
        else if (op == '*') {
            cin >> num;
            right.push_front(num);
        } 
        else {
            cout << left.front() << '\n';
            left.pop_front();
        }

        if (left.size() < right.size()) {
            left.push_back(right.front());
            right.pop_front();
        }
    }
}