#include <bits/stdc++.h>
using ll = long long;
const ll MOD= 1e9+7;
 
ll inverse(ll i){
  if(i==1) return 1;
  return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
 
int main()
{
  ll n;
  std::cin >> n;
  std::vector<std::pair<ll,ll>> v(n);
  std::vector<ll> factorials(1e6+1);
  factorials[0] = factorials[1] = 1;
  for(int i = 2; i <=1e6; i++)
    factorials[i] = (factorials[i-1]*i)%MOD;
  for(int i = 0; i < n; i++)
  {
    ll a,b;
    std::cin >> a >> b;
    ll high = (factorials[a]*inverse(factorials[b]))%MOD;
    high *= inverse(factorials[a-b]);
    high %= MOD;
    std::cout << high << '\n';
  }
}
