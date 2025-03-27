#include <bits/stdc++.h>
using ll = long long;
const ll MOD = 1e9+7;
 
long long inverse(long long i){
  if(i==1) return 1;
  return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
 
int main()
{
  int n;
  std::cin >> n;
  if(n%2==1)
  {
    std::cout << 0;
    return 0;
  }
  n/=2;
  std::string str;
  std::cin >> str;
  std::vector<ll> factorial(1e6+1,0);
  factorial[0] = factorial[1] = 1;
  for(int i = 2; i <= 1e6; i++)
    factorial[i] = (i*factorial[i-1])%MOD;
  ll k = 0, o = 0;
  for(int i=0;i<str.size();i++)
  {
    if(str[i]=='(')
    {
      k++;
      o++;
    }
    else k--;
    if(k<0)
    {
      std::cout<<0;
      return 0;
    }
  }
  n-=o;
  if(k<0 || n<0 || 2*n+k<n)
  {
    std::cout<<0;
    return 0;
  }
  ll ans=(factorial[2*n+k]*inverse(factorial[n]))%MOD;
  ans*=inverse(factorial[n+k]);
  ans%=MOD;
  ans*=((k+1)*inverse(n+k+1))%MOD;
  ans%=MOD;
  std::cout<<ans;
}
