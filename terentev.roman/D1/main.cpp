#include <iostream>

int main() {
  size_t n = 0;
  char ch;
  char* a = nullptr;
  size_t size = 0;
  size_t cap = 0;
  while (std::cin >> n >> ch) {
      if (size + n > cap) {
        size_t newCap = 0;
        if (cap == 0) {
          newCap = 1;
        } else {
          newCap = cap;
        }
        while (newCap < size + n) {
          newCap *= 2;
        }
        char* b = new char[newCap];
        for (size_t i = 0; i < size; ++i) {
          b[i] = a[i];
        }
        delete[] a;
        a = b;
        cap = newCap;
      }
      for (size_t i = 0; i < n; ++i) {
        a[size++] = ch;
      }
  }
  for (size_t i = 0; i < size; ++i) {
    std::cout << a[i];
  }
  std::cout << '\n';
  delete[] a;
}
