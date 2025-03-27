#include <iostream>
#define li long int
 
int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int tc;
  li x, y;
  std::cin >> tc;
  while (tc--)
  {
    std::cin >> x >> y;
    if (x < y)
    {
      if (y % 2 == 1)
      {
        li r = y * y;
        std::cout << r - x + 1 << '\n';
      }
      else
      {
        li r = (y - 1) * (y - 1) + 1;
        std::cout << r + x - 1 << '\n';
      }
    }
    else
    {
      if (x % 2 == 0)
      {
        li r = x * x;
        std::cout << r - y + 1 << '\n';
      }
      else
      {
        li r = (x - 1) * (x - 1) + 1;
        std::cout << r + y - 1 << '\n';
      }
    }
  }
  return 0;
}