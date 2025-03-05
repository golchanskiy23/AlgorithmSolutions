#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

template <class T>
class Queue {
public:
    void push(const T& value) { list.add(value); }

    void pop() { list.removeFront(); }

    T front() const { return list.front(); }

    bool empty() const { return list.empty(); }

    size_t size() const { return list.size(); }

    void print() const { list.print(); }

private:
    List<T> list;
};

#endif //QUEUE_H
