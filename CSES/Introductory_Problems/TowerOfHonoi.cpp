#include <bits/stdc++.h>
using ll = long long;
 
void honoi(ll n, ll source, ll dest, ll tmp)
{
  if(n==0)
    return;
  honoi(n-1, source, tmp, dest);
  std::cout << source << " " << tmp << '\n';
  honoi(n-1, dest, source, tmp);
}
 
int main()
{
  ll n;
  std::cin >> n;
  std::cout << (1<<n)-1 << '\n';
  honoi(n, 1, 2, 3);
}
