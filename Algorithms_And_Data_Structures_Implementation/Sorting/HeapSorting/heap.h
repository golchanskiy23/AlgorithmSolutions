#ifndef HEAP_H
#define HEAP_H
#include <cassert>
#include <exception>

namespace data_structures {
  template<class T>
  class Heap{
  public:
    Heap();
    ~Heap();
    Heap(const T&) = delete;
    Heap(const Heap&) = default;
    Heap& operator=(const Heap&) = default;
    Heap& operator=(Heap&&) = default;
    Heap(T&&) = delete;

    void insert(const T&);
    T get_min() const;
    void remove_min();
    void heap_sort(T* arr, int n);
  private:
    T* heap;
    int h_size;
    int h_used;
  };
}

template<class T>
data_structures::Heap<T>::Heap() : heap(new T[100]), h_size(100), h_used(0) {}

template<class T>
data_structures::Heap<T>::~Heap() {
  delete [] heap;
}

template<class T>
void data_structures::Heap<T>::insert(const T& x) {
  if (h_used == h_size) {
    T* new_heap = new T[h_size * 2];
    std::copy(heap, heap + h_size, new_heap);
    delete[] heap;
    heap = new_heap;
    h_size *= 2;
  }
  heap[h_used++] = x;
  int i = h_used - 1;
  while (i > 0 && heap[i] > heap[(i-1)/2]) {
    std::swap(heap[i], heap[(i-1)/2]);
    i = (i-1)/2;
  }
}

template<class T>
T data_structures::Heap<T>::get_min() const {
  return heap[0];
}

template<class T>
void data_structures::Heap<T>::remove_min() {
  if (h_used == 0) throw std::runtime_error("Try to get element from empty heap\n");
  std::swap(heap[0], heap[h_used-1]);
  h_used--;

  int i = 0;
  while (h_used > 2*i+1) {
    int j = 2*i + 1;
    if (2*i + 2 < h_used && heap[j] > heap[2*i + 2]) {
      j = 2*i + 2;
    }
    if (heap[i] <= heap[j]) break;
    std::swap(heap[i], heap[j]);
    i = j;
  }
}

template<class T>
void data_structures::Heap<T>::heap_sort(T* arr, int n) {
  assert(arr != nullptr && n <= 100);
  for (int i = 0; i < n; i++) {
    insert(arr[i]);
  }
  for (int i = 0; i < n; i++) {
    std::cout << get_min() << " ";
    remove_min();
  }
}

#endif