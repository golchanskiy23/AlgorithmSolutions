#include <bits/stdc++.h>
using ll = long long;
const ll MOD = 1e9+7;
 
long long inverse(long long i){
  if(i==1) return 1;
  return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
 
ll solution(ll a, ll power)
{
  if(power==0) return 1;
  if(power==1) return a%MOD;
  if(power%2==0)
    return (((solution(a,power/2))*(solution(a,power/2))))%MOD;
  else
    return (((solution(a,power/2))*(solution(a,power/2))%MOD)*a)%MOD;
}
 
ll gcd(ll a, ll b)
{
  return (b==0) ? a : gcd(b, a%b);
}
 
int main()
{
  ll n,m;
  std::cin >> n >> m;
  ll ans = 0;
  for(int i = 0; i < n; i++)
  {
    ll temp = solution(m, gcd(i,n));
    temp *= inverse(n);
    temp %= MOD;
    ans += temp;
    ans %= MOD;
  }
  std::cout << ans;
}
