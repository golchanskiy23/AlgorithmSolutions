#include <bits/stdc++.h>
using ll = long long;
using pll = std::pair<ll,ll>;
const ll MOD = 1e9+7, MAX = LLONG_MAX;

int main()
{
    ll n,m,a,b,c; std::cin >> n >> m;
    std::vector<std::vector<std::pair<ll,ll>>> edges(n+1);
    std::vector<bool> visited(n+1, false);
    for(int i = 0; i < m; i++){
        std::cin >> a >> b >> c;
        edges[a].push_back({c,b});
    }
    
    std::vector<ll> minPrice(n+1, MAX), numFlights(n+1, 0), minFlights(n+1, MAX), maxFlights(n+1, 0);
    
    minPrice[1] = 0;
    numFlights[1] = 1;
    minFlights[1] = 0;
    std::priority_queue<pll , std::vector<pll>, std::greater<pll>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto head = pq.top();
        pq.pop();
        if(visited[head.second]) continue;
        visited[head.second] = true;
        for(auto& d : edges[head.second]){
            ll dist = minPrice[head.second]+d.first;
            if(dist == minPrice[d.second]){
                numFlights[d.second] = (numFlights[d.second]+numFlights[head.second])%MOD;
                minFlights[d.second] = std::min(minFlights[d.second], minFlights[head.second]+1);
                maxFlights[d.second] = std::max(maxFlights[d.second], maxFlights[head.second]+1);
            } else if(dist < minPrice[d.second]){
                numFlights[d.second] = numFlights[head.second];
                minPrice[d.second] = minPrice[head.second]+d.first;
                minFlights[d.second] = minFlights[head.second]+1;
                maxFlights[d.second] = maxFlights[head.second]+1;
                pq.push({minPrice[d.second], d.second});
            }
        }
    }
    
    std::cout << minPrice[n] << " " << numFlights[n] << " " << minFlights[n] << " " << maxFlights[n]; 
    return 0;
}