#include <bits/stdc++.h>
using ll = long long;
const ll MOD = 1e9+7;
 
long long inverse(long long i){
  if(i==1) return 1;
  return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
 
int main()
{
  ll n,m;
  std::cin >> n >> m;
  std::vector<ll> factorial(2e6);
  factorial[0] = factorial[1] = 1;
  for(int i = 2; i <= 2e6; i++)
    factorial[i] = (i*factorial[i-1])%MOD;
  ll ans = factorial[n+m-1];
  ans *= inverse(factorial[m]);
  ans%=MOD;
  ans *= inverse(factorial[n-1]);
  ans %= MOD;
  std::cout << ans;
}