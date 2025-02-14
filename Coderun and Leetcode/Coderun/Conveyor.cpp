#include <iostream>
#include <vector>
#include <stack>

bool canSortContainers(const std::vector<double>& containers) {
    std::stack<double> storage;
    double expected = 0.0;

    for (double urgency : containers) {
        while (!storage.empty() && storage.top() < urgency) {
            if (storage.top() < expected) {
                return false;
            }
            expected = storage.top();
            storage.pop();
        }
        storage.push(urgency);
    }

    
    while (!storage.empty()) {
        if (storage.top() < expected) {
            return false;
        }
        expected = storage.top();
        storage.pop();
    }

    return true;
}

int main() {
    int n;
    std::cin >> n;
    
    while (n--) {
        int k;
        std::cin >> k;
        std::vector<double> containers(k);
        
        for (int i = 0; i < k; ++i) {
            std::cin >> containers[i];
        }
        
        std::cout << (canSortContainers(containers) ? 1 : 0) << '\n';
    }

    return 0;
}