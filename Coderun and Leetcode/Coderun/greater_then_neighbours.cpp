#include <iostream>
#include <vector>
using namespace std;

int moreYourNeighbors(const vector<int>& array) {
    int moreCount = 0;
    int n = array.size();
    
    for (int i = 1; i < n - 1; i++) {
        if (array[i] > array[i - 1] && array[i] > array[i + 1]) {
            moreCount++;
        }
    }
    return moreCount;
}

int main() {
    vector<int> array;
    int num;
    
    while (cin >> num) {
        array.push_back(num);
    }
    
    cout << moreYourNeighbors(array) << endl;
    return 0;
}
