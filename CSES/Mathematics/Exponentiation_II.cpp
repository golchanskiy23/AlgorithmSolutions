#include <bits/stdc++.h>
using ll = long long;
 
ll MOD = 1e9+7;
 
ll solution(ll a, ll power, ll mod)
{
  if(power == 0) return 1;
  if(power == 1) return a%mod;
  ll temp = solution(a,power/2, mod);
  if(power%2==0)
    return (temp*temp)%mod;
  else return ((temp*temp)%mod*a)%mod;
}
 
int main()
{
  ll n;
  std::cin >> n;
  while(n--)
  {
    ll a, b, c;
    std::cin >> a >> b >> c;
    ll ferma = solution(b,c,MOD-1);
    std::cout << solution(a,ferma,MOD) << '\n';
  }
}