#include <bits/stdc++.h>

const int INF = int(1e9);

int main(){
	int W,H,x1, y1, x2, y2, w,h;
	int t; std::cin >> t;
	for(int i = 0; i < t; ++i){
		std::cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
		int ans = INF, tmp;
		if (x2 - x1 + w <= W) {
			tmp = std::min(std::max(0, x2 - (W - w)) , std::max(0, w - x1));
			ans = std::min(ans, tmp);
		}
		if (y2 - y1 + h <= H) {
			tmp = std::min(std::max(0, y2 - (H - h)) , std::max(0, h - y1));
			ans = std::min(ans, tmp);
		}
		if (ans == INF)
			std::cout << -1 << '\n';
		else
			std::cout << ans << '\n';
	}
}