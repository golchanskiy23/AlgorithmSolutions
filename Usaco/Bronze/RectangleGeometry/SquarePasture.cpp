#include <bits/stdc++.h>

struct Rectangle{
	int lowX, lowY, upX, upY;
	Rectangle(int lx, int ly, int ux, int uy){
		lowX = lx;
		lowY = ly;
		upX = ux;
		upY = uy;
	}

	int square(const Rectangle& r1){
    		int l = (r1.upX-r1.lowX);
    		int r = (r1.upY-r1.lowY);
    		return l*r;
	}

	int intersection(const Rectangle& r1, const Rectangle& r2){
		int diffX = std::max(std::min(r1.upX, r2.upX)-std::max(r1.lowX, r2.lowX),0);
		int diffY = std::max(std::min(r1.upY, r2.upY)-std::max(r1.lowY, r2.lowY),0);
		return diffX*diffY;
	}
};


int main(){
	std::ifstream in("square.in");
	std::ofstream out("square.out");
	int x1, y1, x2,y2;
	std::vector<Rectangle> v;
	for(int i = 0; i < 2; ++i){
		in >> x1 >> y1 >> x2 >> y2;
		v.push_back(Rectangle(x1, y1, x2,y2));
	}
	int ans = std::max(std::max(v[0].upY, v[1].upY)-std::min(v[0].lowY, v[1].lowY), std::max(v[0].upX, v[1].upX)-std::min(v[0].lowX, v[1].lowX));
	out  << ans*ans;
}