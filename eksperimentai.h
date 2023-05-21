#include "Vector.h"

template <typename T, typename Allocator = std::allocator<T>> class Vektorius {
private:
  std::vector<T> duomenys;
  Allocator imas;
public:
  // Konstruktoriai

  Vektorius() {}
  Vektorius(std::initializer_list<T> init) : duomenys(init) {}
  ~Vektorius() {}

  // Dydis
  size_t size() const { return duomenys.size(); }
  size_t max_size() const { return duomenys.max_size(); }
  size_t capacity() const { return duomenys.capacity(); }
  void resize(size_t n) {duomenys.resize(n); }
  void resize(size_t n, const T& value) {duomenys.resize(n, value); }
  bool empty() const { return duomenys.empty(); }
  void shrink_to_fit() { duomenys.shrink_to_fit(); }
  void reserve(size_t n) { duomenys.reserve(n); }
  // Element access
  Vektorius(size_t n) : duomenys(n) {
  for (size_t i = 0; i < n; i++) {
    duomenys[i] = static_cast<T>(i + 1);
  }
}
  T& operator[](size_t g) { return duomenys[g]; }
  const T& operator[](size_t g) const { return duomenys[g]; }
  T& at(size_t g) { return duomenys.at(g); }
  const T& at(size_t g) const { return duomenys.at(g); }
  T& front() { return duomenys.front(); }
  const T& front() const { return duomenys.front(); }
  T& back() { return duomenys.back(); }
  const T& back() const { return duomenys.back(); }

  typename std::vector<T>::iterator begin() { return duomenys.begin(); }
  typename std::vector<T>::const_iterator begin() const { return duomenys.begin(); }
  typename std::vector<T>::iterator end() { return duomenys.end(); }
  typename std::vector<T>::const_iterator end() const { return duomenys.end(); }
  typename std::vector<T>::const_iterator cbegin() const { return duomenys.cbegin(); }
  typename std::vector<T>::const_iterator cend() const { return duomenys.cend(); }
  typename std::vector<T>::reverse_iterator rbegin() { return duomenys.rbegin(); }
  typename std::vector<T>::const_reverse_iterator rbegin() const { return duomenys.rbegin(); }
  typename std::vector<T>::reverse_iterator rend() { return duomenys.rend(); }
  typename std::vector<T>::const_reverse_iterator rend() const { return duomenys.rend(); }
  typename std::vector<T>::const_reverse_iterator crbegin() const { return duomenys.crbegin(); }
  typename std::vector<T>::const_reverse_iterator crend() const { return duomenys.crend(); }
    
    using allocator_type = Allocator;
    const Allocator& get_allocator() const {
        return priskyrimas;
    }
  // Modifiers
  template <typename InputIt>
void assign(InputIt first, InputIt last) {
  clear();
  for (auto it = first; it != last; ++it) {
    duomenys.push_back(*it);
  }
}
void assign(size_t count, const T& value) {
  clear();
  duomenys.assign(count, value);
}
void assign(const std::initializer_list<T>& init) {
    clear();
    for (const auto& element : init) {
      duomenys.push_back(element);
    }
  }
  void assign_range(const std::initializer_list<T>& init) { duomenys.assign(init); }
  void push_back(const T& value) { duomenys.push_back(value); }
  void pop_back() { duomenys.pop_back(); }
  void swap(Vektorius& other) { duomenys.swap(other.duomenys); }
  void clear() { duomenys.clear(); }

  typename std::vector<T>::iterator insert(typename std::vector<T>::const_iterator pos, const T& value) {
    return duomenys.insert(pos, value);
  }
typename std::vector<T>::iterator insert(typename std::vector<T>::iterator pos, typename std::vector<T>::const_iterator first,
typename std::vector<T>::const_iterator last) {
    return duomenys.insert(pos, first, last);
}
  typename std::vector<T>::iterator erase(typename std::vector<T>::const_iterator pos) {
    return duomenys.erase(pos);
  }

  typename std::vector<T>::iterator erase(typename std::vector<T>::const_iterator first,
                                          typename std::vector<T>::const_iterator last) {
    return duomenys.erase(first, last);
  }

  template <typename... Args>
  typename std::vector<T>::iterator emplace(typename std::vector<T>::const_iterator pos, Args&&... args) {
    return duomenys.emplace(pos, std::forward<Args>(args)...);
  }

  template <typename... Args>
  void emplace_back(Args&&... args) { duomenys.emplace_back(std::forward<Args>(args)...); }

  void print() const {
      if (empty()) {
    std::cout << "Empty Vector" << std::endl;
    return;
        }

    for (const auto& element : duomenys) {
      std::cout << element << " ";
        }
    std::cout << std::endl;
  }

   // papildomi
  template <typename InputIt>
void assert_range(InputIt first, InputIt last) {
  if (first < duomenys.begin() || last > duomenys.end()) {
    throw std::out_of_range("Out of range!");
  }
}

  template <typename InputIt>
void assign_range(InputIt first, InputIt last) {
  if (first > last) {
    throw std::invalid_argument("Invalid range!");
  }
  clear();
  while (first != last) {
    duomenys.insert(duomenys.end(), *first);
    ++first;
  }
}
};