#include <bits/stdc++.h>

struct cow{
    int s_,t_,c_;
};

struct conditioner{
    int a_,b_,p_,m_;
};

std::vector<cow> cows;
std::vector<conditioner> conditioners;
std::vector<bool> using_conditioners;
int min_coin = std::numeric_limits<int>().max();


void init(int n, int m){
    //cows.resize(n);
    //conditioners.resize(m);
    using_conditioners.resize(m);
    for(int i = 0; i < m;++i) using_conditioners[i] = false;
}

void update(int n,int m){
    bool flag = true;
    for(int i = 1; i <= 100; ++i){
        
        int temperature = 0;
        for(int j = 0; j < m;++j){
            if (!using_conditioners[j]) { continue; }
            auto curr_conditioner = conditioners[j];
            if(curr_conditioner.a_ <= i && i <= curr_conditioner.b_) temperature += curr_conditioner.p_;
        }
        
        int y = 0;
        for(int j = 0; j < n; ++j){
            auto curr_cow = cows[j];
            if(curr_cow.s_ <= i && i <= curr_cow.t_) {
                y = curr_cow.c_;
                break;
            }
        }
        
        if(y > temperature){
            flag = false;
            break;
        }
    }
    if(flag){
        int cost = 0;
        for(int j = 0; j < m; ++j){
            if(using_conditioners[j]) cost += conditioners[j].m_;
        }
        min_coin = std::min(min_coin, cost);
    }
}

void search(int i, int n, int m){
    if(i == m){
        update(n,m);
        return;
    }
    using_conditioners[i] = false;
    search(i+1,n,m);
    using_conditioners[i] = true;
    search(i+1,n,m);
}

int main()
{
    int n,m; std::cin >> n >> m;
    init(n,m);
    for(int i = 0; i < n; ++i){
        int s ,t ,c ; std::cin >> s >> t >> c;
        cows.push_back({s,t,c});
    }
    
    for(int i = 0; i < m; ++i){
        int a,b,p,mo; std::cin >> a >> b >> p >> mo;
        conditioners.push_back({a,b,p,mo});
    }
    search(0,n,m);
    std::cout << min_coin;
}