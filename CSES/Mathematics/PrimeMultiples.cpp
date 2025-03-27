#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n,k;
  std::cin >> n >> k;
  std::vector<ll> v(k);
  for(auto& a : v)
    std::cin >> a;
  ll answer = 0;
  for(int i = 0; i <(1<<k); i++)
  {
    std::vector<ll> subset;
    for(int j = 0; j < k; j++)
    {
      if((i&(1<<j))!= 0)
        subset.push_back(v[j]);
    }
    ll multiplication = 1;
    for(int j = 0; j < subset.size(); j++)
    {
      if(multiplication>n/subset[j])
      {
        multiplication = n+1;
        break;
      }
      multiplication *= subset[j];
    }
    if(subset.size()%2==0) answer -= n/multiplication;
    else answer += n/multiplication;
  }
  std::cout << answer+n;
}
