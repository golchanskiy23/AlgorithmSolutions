#include <bits/stdc++.h>

int main(){
    long long curr_next, next, curr_prev, prev;
    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    long long number;
    std::vector<long long> arr;

    while (ss >> number) {
        arr.push_back(number);
    }

    long long max1 = std::numeric_limits<long long>::min(), max2 = std::numeric_limits<long long>::min();
    long long min1 = std::numeric_limits<long long>::max(), min2 = std::numeric_limits<long long>::max();

    for (auto num : arr) {
        if (num > max1) {
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max2 = num;
        }

        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }
    }

    std::vector<long long> v;
    if(max1*max2 > min1*min2){
    	v.push_back(max1); v.push_back(max2);
    }
    else{
    	v.push_back(min1); v.push_back(min2);
    }
    std::sort(v.begin(), v.end());

    std::cout << v[0] << " " << v[1] << std::endl;
}
