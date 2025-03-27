#include <bits/stdc++.h>
using ll = long long;
const ll MOD = 1e9+7;
 
int main()
{
  std::vector<ll> derangement(1e6+1);
  derangement[0] = 1; derangement[1] = 0;
  ll n;
  std::cin >> n;
  for(int i = 2; i <= 1e6; i++)
    derangement[i] = ((i-1)*((derangement[i-1]+derangement[i-2])%MOD))%MOD;
  std::cout << derangement[n];
}