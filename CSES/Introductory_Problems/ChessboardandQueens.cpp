#include <bits/stdc++.h>
 
std::vector<std::string> string(8);
int answer = 0;
bool diag1[16], diag2[16], column[8];
 
void backtracking(int row)
{
  if(row == 8) {
    answer++;
    return;
  }
  for(int column_ = 0; column_ < 8; column_++)
  {
    if(string[row][column_] == '.' && !column[column_] &&
    !diag1[column_+row] && !diag2[column_-row+7])
    {
      column[column_] = diag1[column_+row] = diag2[column_+(8-1-row)] = true;
      backtracking(row+1);
      column[column_] = diag1[column_+row] = diag2[column_+(8-1-row)] = false;
    }
  }
}
 
int main()
{
  for(int i = 0; i < 8; i++)
    std::cin >> string[i];
  backtracking(0);
  std::cout << answer;
}
