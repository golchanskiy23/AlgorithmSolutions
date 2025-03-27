#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  std::string str;
  std::cin >> str;
  ll left = 0, right = 1, ans = 0;
  if(str.size()>1) {
    while (right < str.size()) {
      if (str[left] != str[right])
        ++left;
      else
        ++right;
      ans = std::max(right - left, ans);
    }
  }
  if(str.size()==1)
  {
    std::cout << 1;
    return 0;
  }
  std::cout << ans;
}