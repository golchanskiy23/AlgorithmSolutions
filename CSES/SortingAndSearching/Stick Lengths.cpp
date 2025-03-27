#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n;
  std::cin >> n;
  std::vector<ll> vector;
  for(int i = 0; i < n; i++)
  {
    ll val;
    std::cin >> val;
    vector.push_back(val);
  }
  std::sort(vector.begin(), vector.end());
  ll target = vector[n/2], answer = 0;
  for(int i = 0; i < n; i++)
    answer += std::abs(vector[i]-target);
  std::cout << answer;
}
