#include <iostream>
#include "heap.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    try {
        data_structures::Heap<int> heap;
        int* a = new int[5];
        a[0] = 5;
        a[1] = 2;
        a[2] = 3;
        a[3] = 4;
        a[4] = 5;
        heap.heap_sort(a, 5);
        delete[] a;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.