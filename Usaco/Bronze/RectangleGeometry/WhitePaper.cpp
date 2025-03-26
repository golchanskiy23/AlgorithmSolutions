#include <bits/stdc++.h>
typedef long long ll;

struct Rectangle {
    ll lowX, lowY, upX, upY;
    Rectangle(ll lx, ll ly, ll ux, ll uy) {
        lowX = lx;
        lowY = ly;
        upX = ux;
        upY = uy;
    }
};

ll square(const Rectangle& r1) {
    return (r1.upX - r1.lowX) * (r1.upY - r1.lowY);
}

ll intersection(const Rectangle& r1, const Rectangle& r2) {
    ll diffX = std::max(std::min(r1.upX, r2.upX) - std::max(r1.lowX, r2.lowX), 0LL);
    ll diffY = std::max(std::min(r1.upY, r2.upY) - std::max(r1.lowY, r2.lowY), 0LL);
    return diffX * diffY;
}

Rectangle intersect_rect(const Rectangle& r1, const Rectangle& r2) {
    ll lx = std::max(r1.lowX, r2.lowX);
    ll ly = std::max(r1.lowY, r2.lowY);
    ll ux = std::min(r1.upX, r2.upX);
    ll uy = std::min(r1.upY, r2.upY);

    if (lx >= ux || ly >= uy) return Rectangle(0, 0, 0, 0);
    return Rectangle(lx, ly, ux, uy);
}

int main() {
    ll x1, y1, x2, y2;
    std::vector<Rectangle> v;

    for (int i = 0; i < 3; ++i) {
        std::cin >> x1 >> y1 >> x2 >> y2;
        v.emplace_back(x1, y1, x2, y2);
    }

    ll white_area = square(v[0]);
    ll covered_by_black1 = intersection(v[0], v[1]);
    ll covered_by_black2 = intersection(v[0], v[2]);
    ll overlap_black = intersection(intersect_rect(v[0], v[1]), v[2]);

    ll total_covered = covered_by_black1 + covered_by_black2 - overlap_black;

    if (white_area > total_covered) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
