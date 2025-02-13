#include <iostream>
#include <cstdlib>

int split(int* arr, int l, int r) {
    //int pivot = arr[(l+r)/2];
    int pivot = arr[l+rand()%(r-l+1)];
    std::cout << "Pivot is: " << pivot << '\n';
    int i = l, j = r;
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i >= j) break;
        std::swap(arr[i++], arr[j--]);
    }
    return j;
}

void quick_sort(int* arr, int l, int r) {
    std::cout << l << " " << r << '\n';
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
    if (l < r) {
        int m = split(arr,l,r);
        quick_sort(arr,l,m);
        quick_sort(arr,m+1,r);
    }
}

int find_kth(int* arr, int l, int r, int k) {
    if (r == l) return l;
    int m = split(arr, l,r);
    if (k < m) return find_kth(arr, l,m,k);
    else if ( k > m) return find_kth(arr,m+1, r, k);
    return arr[m];
}

int main() {
    int* arr = new int[10]{2,3,4,5,1,2,3,7,8,3};
    quick_sort(arr, 0, 9);
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n' << find_kth(arr, 0,9,9);
    delete [] arr;
}