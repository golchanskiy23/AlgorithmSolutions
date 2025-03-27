#include <bits/stdc++.h>
using ll = long long;
const ll MOD = 1e9+7;
 
long long inverse(long long i){
  if(i==1) return 1;
  return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
 
int main()
{
  ll n;
  std::cin>>n;
  if(n%2==1)
  {
    std::cout<<0;
    return 0;
  }
  n/=2;
  ll fact[2*n+1];
  fact[0]=1;
  for(ll i=1;i<=2*n;i++)
  {
    fact[i]=(fact[i-1]*i)%MOD;
  }
  ll ans=(fact[2*n]*inverse(fact[n]))%MOD;
  ans*=(inverse(fact[n])*inverse(n+1))%MOD;
  ans%=MOD;
  std::cout<<ans;
}
