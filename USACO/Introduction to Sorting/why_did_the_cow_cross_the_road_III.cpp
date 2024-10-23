#include <bits/stdc++.h>

class  Cow{
public:
        int arrival;
        int time;
        Cow(int a, int t) : arrival(a) , time(t){}
};

bool cmp(const Cow& c1, const Cow& c2){
                if(c1.arrival == c2.arrival){ 
                        return c1.time < c2.time;
                }
                return c1.arrival < c2.arrival;
}

int main(){ 
        freopen("cowqueue.in", "r", stdin);
        freopen("cowqueue.out",  "w", stdout);
        int n; std::cin >> n;
        std::vector<Cow> v;
        for(int i = 0; i < n; ++i){ 
                int a,t; std::cin >> a >> t;
                v.push_back(Cow(a,t));
        }
        std::sort(v.begin(), v.end(), cmp); 
        int ans = 0;
        for(int i = 0; i < n; ++i){ 
                if(v[i].arrival > ans) ans = v[i].arrival;
                ans += v[i].time;
        }
        std::cout << ans; 
}
