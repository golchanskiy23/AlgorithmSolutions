#include <iostream>
#include <stack>

struct Node {
    int x;
    int Height;
    Node(int x, int Height) : x(x), Height(Height) {}
};

int main() {
    int n;
    std::cin >> n;

    std::stack<Node> s;
    s.push(Node(0, -1));
    long long res = 0;

    for (int i = 1; i <= n + 1; i++) {
        int h;
        if (i <= n) std::cin >> h;
        else h = 0;

        int x = i;
        while (h <= s.top().Height) {
            int prev_x = s.top().x;
            int prev_h = s.top().Height;
            s.pop();
            long long area = 1LL * prev_h * (i - prev_x);
            res = std::max(res, area);
            x = prev_x;
        }
        s.push(Node(x, h));
    }

    std::cout << res << std::endl;
    return 0;
}