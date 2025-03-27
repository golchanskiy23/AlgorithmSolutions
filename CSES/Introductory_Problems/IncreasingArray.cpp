#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n, count = 0;
  std::cin >> n;
  std::vector<ll> vector(n);
  for(auto& a : vector)
    std::cin >> a;
  if(n > 1)
  {
    for(int i = 1; i < n; i++)
    {
      if(vector[i-1]>=vector[i])
        count += std::abs(vector[i] - vector[i-1]);
      if(vector[i]<vector[i-1])
      {vector[i] += std::abs(vector[i] - vector[i-1]);}
    }
  }
  if(n==1)
  {
    std::cout << 0;
    return 0;
  }
  std::cout << count;
}