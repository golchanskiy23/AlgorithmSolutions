#include <bits/stdc++.h>
using ll = long long;
 
std::vector<std::string> create(ll n)
{
  std::vector<std::string> gray;
  gray.push_back("0"); gray.push_back("1");
  for(int i = 2; i < (1<<n); i *= 2)
  {
    for(int j = i-1; j >= 0; j--)
      gray.push_back(gray[j]);
 
    for(int j = 0; j < i; j++)
      gray[j] = "0" + gray[j];
 
    for(int j = i; j < 2*i; j++)
      gray[j] = "1" + gray[j];
  }
  return gray;
}
 
int main()
{
  ll n;
  std::cin >> n;
  auto v = create(n);
  for(auto& a : v)
    std::cout << a << '\n';
}
