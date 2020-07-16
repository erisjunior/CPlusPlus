#ifndef VECTORSUPERMARKET_HPP
#define VECTORSUPERMARKET_HPP

template <class T> class vector_supermarket {
public:
  int size;
  int capacity;
  T *elements;

  vector_supermarket() {
    size = 0;
    capacity = 10;
    elements = new T[capacity];
  }

  ~vector_supermarket() { delete[] elements; }

  void push(T &element) {
    if (capacity <= size) {
      capacity *= 2;

      T *new_elements = new T[capacity];

      for (size_t i = 0; i < size; i++) {
        new_elements[i] = elements[i];
      }

      delete[] elements;
      elements = new_elements;
    }

    elements[size] = element;
    size += 1;
  }
};

#endif
