#include <iostream>

// TERRIBLE implementation
void counting_sort_1(int* arr, int n, int m) {
    int* cnt = new int[m]{0};
    for (int i = 0; i < n; ++i) {
        cnt[arr[i]]++;
    }
    int* a = new int[n];
    int t = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < cnt[i];++j) {
            a[t++] = i;
        }
    }
    for (int i = 0; i < n;++i) arr[i]=a[i];
    delete[] a;
    delete[] cnt;
}

void counting_sort_2(int* arr, int n, int m) {
    int* cnt = new int[m]{0};
    int* p = new int[m]{0};
    for (int i = 0; i < n; ++i) {
        cnt[arr[i]]++;
    }
    for (int i = 1; i < m;++i) {
        p[i] = p[i-1]+cnt[i-1];
    }
    int* a = new int[n]{0};
    for (int i = 0; i < n; ++i) {
        a[p[arr[i]]++] = arr[i];
    }
    delete[] cnt;
    delete[] p;
    delete[] a;
}

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    int* arr = new int[10]{2,1,3,2,2,3,1,3,3,2};
    counting_sort_2(arr,10,3);
    counting_sort_1(arr,10,3);
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.