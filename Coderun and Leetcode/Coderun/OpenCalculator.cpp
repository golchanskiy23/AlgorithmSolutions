#include <iostream>
#include <string>
#include <vector>
#include <set>

int main() 
{
	int a,b,c; std::cin >> a >> b >> c;
    std::set<int> s, neccessary;
    s.insert(a); s.insert(b); s.insert(c);
    int d; std::cin >> d;
    while(d > 0){
        int curr = d%10;
        if(!s.count(curr) && !neccessary.count(curr)){
            neccessary.insert(curr);
        }
        d /= 10;
    }
    std::cout << neccessary.size();

	return 0;
}