#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n;
  std::cin >> n;
  std::vector<std::pair<ll,ll>> v(n);
  for(int i = 0; i < n; i++)
  {
    int duration, finishing;
    std::cin >> duration >> finishing;
    v[i].first = duration; v[i].second = finishing;
  }
  std::sort(v.begin(), v.end());
  ll reward = 0, curr_time = 0;
  for(int i = 0;  i< n; i++)
  {
    curr_time += v[i].first;
    reward += (v[i].second - curr_time);
  }
  std::cout << reward;
}
