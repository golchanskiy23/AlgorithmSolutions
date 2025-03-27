#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n, k;
  std::cin >> n >> k;
  std::vector<ll> v(n);
  std::map<ll,ll> map;
  for(auto& a : v)
    std::cin >> a;
  ll right = 0, count = 0;
  for(ll left = 0; left < n; left++)
  {
    while(right < n && (map.size() < k || map.count(v[right])>0))
        map[v[right++]]++;
    count += right - left;
    map[v[left]]--;
    if(map[v[left]]==0)
      map.erase(v[left]);
  }
  std::cout << count;
}