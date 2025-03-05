#ifndef STACK_H
#define STACK_H

#include "List.h"

template <class T>
class Stack {
public:
    void push(const T& value) { list.addFront(value); }

    void pop() { list.removeFront(); }

    T top() const { return list.front(); }

    bool empty() const { return list.empty(); }

    size_t size() const { return list.size(); }

    void print() const { list.print(); }

private:
    List<T> list;
};

#endif //STACK_H
