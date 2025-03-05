#include <iostream>

#include "Queue.h"
#include "Stack.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    try {
        Stack<int> stack;
        Queue<int> queue;
        stack.push(12);
        queue.push(13);
        std::cout << queue.front() << '\n';
        stack.pop();
        queue.pop();
    }
    catch (...) {
        std::cerr << "Some exception!!!";
    }
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.