#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n,a,b;
  std::cin >> n >> a >> b;
  std::vector<ll> v(n), prefix(n+1,0);
  for(auto& c : v)
    std::cin >> c;
  for(int i = 1; i <= n; i++)
    prefix[i] += prefix[i-1] + v[i-1];
  ll ans = -1e18;
  std::multiset<ll> set;
 
  for(ll i = a; i <= n; i++)
  {
    if(i > b)
    {
      set.erase(set.find(prefix[i-b-1]));
    }
    set.insert(prefix[i-a]);
    ans = std::max(ans, prefix[i]-*set.begin());
  }
 
  // too slow
  /*for(ll right = a; right <= b; right++)
  {
    for(ll left = 0; left+right < n+1; left++)
    {
      ll curr = prefix[left+right] - prefix[left];
      ans = std::max(ans, curr);
    }
  }*/
  std::cout << ans;
}