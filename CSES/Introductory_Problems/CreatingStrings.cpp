#include <bits/stdc++.h>
std::vector<char> alphabet(26);
using namespace std;
 
string s;
vector<string> perms;
int char_count[26];
 
void search(string curr) {
// we've finished creating a permutation
if (curr.size() == s.size()) {
perms.push_back(curr);
return;
}
for (int i = 0; i < 26; i++) {
// for all available characters
if (char_count[i] > 0) {
// add it to the current string and search
char_count[i]--;
search(curr + (char)('a' + i));
char_count[i]++;
}
}
}
 
int main() {
  cin >> s;
  for (char c : s) { char_count[c - 'a']++; }
  search("");
  cout << perms.size() << "\n";
  for (string perm : perms) { cout << perm << "\n"; }
}
