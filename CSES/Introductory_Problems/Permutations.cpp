#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n;
  std::cin >> n;
  if(n == 1)
  {
    std::cout << 1;
    return 0;
  }
  if( n == 2 || n == 3)
  {
    std::cout << "NO SOLUTION";
    return 0;
  }
  else
  {
    if(n%2==0)
    {
      for(int i = 0; i < n/2; i++)
        std::cout << 2*i+2 << " ";
      for(int i = 0; i < n/2; i++)
        std::cout << 2*i+1 << " ";
    }
    else
    {
      for(int i = 0; i < n/2; i++)
        std::cout << 2*i+2 << " ";
      for(int i = 0; i < n/2+1; i++)
        std::cout << 2*i+1 << " ";
    }
  }
}
