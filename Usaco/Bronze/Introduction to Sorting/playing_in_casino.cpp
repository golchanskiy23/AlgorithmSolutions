#include <bits/stdc++.h>

typedef long long ll;

int main(){
  ll t; std::cin >> t;
  for(int i = 0; i < t; ++i){
    ll n,m; std::cin >> n >> m;
    std::vector<std::vector<ll>> grid(m,std::vector<ll>(n,0)), prefix(m,std::vector<ll>(n,0));
    for(int j = 0; j < n; ++j){
      for(int k = 0; k < m; ++k){
        std::cin >> grid[k][j];
      }
    }
    for(int j = 0; j < m; ++j){
      std::sort(grid[j].begin(), grid[j].end());
    }

    for(int j = 0; j < m; ++j){
      prefix[j][0] = grid[j][0];
      for(int k = 1; k < n; ++k){
        prefix[j][k] = prefix[j][k-1];
        prefix[j][k] += grid[j][k];
      }
    }

    ll ans = 0;
    for(int j = 0; j < m; ++j){
      for(int k = 0; k < n; ++k){
        ans += (grid[j][k]*(k+1)-prefix[j][k]);
      }
    }

    std::cout << ans << '\n';
  }
}