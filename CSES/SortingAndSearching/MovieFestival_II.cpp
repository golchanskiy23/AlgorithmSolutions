#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n,k;
  std::cin >> n >> k;
  std::vector<std::pair<ll,ll>> movies;
  for(int i = 0;  i< n; i++)
  {
    ll first, second;
    std::cin >> first >> second;
    movies.push_back({first, second});
  }
  std::sort(movies.begin(), movies.end(), [](const std::pair<ll,ll>& p1, const std::pair<ll,ll>& p2){
    if(p1.second==p2.second)
    {
      return p1.first < p2.first;
    }
    return p1.second < p2.second;
  });
 
  std::multiset<ll> set;
  for(int i = 0; i < k; i++)
    set.insert(0);
 
  ll answer = 0;
  for(int i = 0; i < n; i++)
  {
    auto it = set.upper_bound(movies[i].first);
    if(it == set.begin()) continue;
    set.erase(std::prev(it));
    set.insert(movies[i].second);
    answer++;
  }
  std::cout << answer;
}