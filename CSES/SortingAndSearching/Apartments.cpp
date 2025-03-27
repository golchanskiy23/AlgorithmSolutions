#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n,m, k;
  std::cin >> n >> m >> k;
  std::vector<ll> applicants(n), apartments(m);
 
  for(auto& a : applicants)
    std::cin >> a;
  for(auto& a : apartments)
    std::cin >> a;
 
  std::sort(applicants.begin(), applicants.end());
  std::sort(apartments.begin(), apartments.end());
 
  ll i = 0, j = 0, count = 0;
  while(i < n && j < m)
  {
    if(applicants[i] > apartments[j] + k) j++;
    else if(apartments[j] > applicants[i] + k) i++;
    else
    {
      i++; j++;
      count++;
    }
  }
  std::cout << count;
 
}
