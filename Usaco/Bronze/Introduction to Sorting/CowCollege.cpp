#include <bits/stdc++.h>
typedef long long ll;

int main(){
  ll n; std::cin >> n;
  std::vector<ll> v(n);
  for(int i = 0; i < n; ++i) std::cin >> v[i];
  std::sort(v.begin(), v.end(), std::greater<ll>());
  // lower_bound + 1
  ll max_ = 0, curr = 0;
  for(int i = 0; i < n; ++i){
    if (v[i]*(i+1) >= max_) {
      max_ = v[i]*(i+1);
      curr = v[i];
    }
  }
  std::cout << max_ << " " << curr;
}
