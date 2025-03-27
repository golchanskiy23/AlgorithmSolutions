#include <bits/stdc++.h>
using ll = long long;
const ll MOD = 1e9+7;
 
long long inverse(long long i){
  if(i==1) return 1;
  return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
 
int main()
{
  std::string str;
  std::cin >> str;
  std::vector<ll> factorial(1e6+1), alphabet(26,0);
  factorial[0] = factorial[1] = 1;
  for(int i = 2; i<=1e6+1; i++)
    factorial[i] = (i*factorial[i-1])%MOD;
  for(auto& a : str)
    alphabet[a-'a']++;
  ll answer = 1;
  answer = answer*factorial[str.size()];
  for(int i = 0; i < 26; i++)
  answer = (answer*inverse(factorial[alphabet[i]]))%MOD;
  std::cout << answer;
}
