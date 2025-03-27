#include <bits/stdc++.h>
using ll = long long;
 
const ll MOD = 1e9+7;
 
ll solution(ll a, ll power)
{
  if(power==0) return 1;
  if(power==1) return a%MOD;
  if(power%2==0)
    return (((solution(a,power/2))*(solution(a,power/2))))%MOD;
  else
    return (((solution(a,power/2))*(solution(a,power/2))%MOD)*a)%MOD;
}
 
int main()
{
  ll q;
  std::cin >> q;
  while(q--)
  {
    ll a,b;
    std::cin >> a >> b;
    std::cout << solution(a,b) << '\n';
  }
}