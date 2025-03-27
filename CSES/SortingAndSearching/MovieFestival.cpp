#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n;
  std::cin >> n;
  std::vector<std::pair<ll,ll>> start_end;
  for(int i = 0; i < n; i++)
  {
    ll start, end;
    std::cin >> start >> end;
    start_end.push_back({start, end});
  }
  std::sort(start_end.begin(), start_end.end(), [](const std::pair<ll,ll>& p1, const std::pair<ll,ll>& p2){
    return p1.second < p2.second;
  });
  ll movies = 0, bound = -1;
  for(int i = 0; i < start_end.size(); i++)
  {
    if(start_end[i].first >= bound)
    {
      bound = start_end[i].second;
      ++movies;
    }
  }
  std::cout << movies << '\n';
  return 0;
}