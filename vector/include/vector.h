#ifndef VECTOR_H_
#define VECTOR_H_

#include <cstddef>
#include <cstring>
#include <exception>
#include <climits>


namespace dsa {

template<typename T>
class VectorImpl {
public:
  explicit VectorImpl(std::size_t size = 0);

  ~VectorImpl() noexcept;

  void Swap(VectorImpl &other) noexcept;

  VectorImpl(const VectorImpl &) = delete;

  VectorImpl &operator=(const VectorImpl &) = delete;

private:
  T *data_;
  std::size_t size_;
  std::size_t capacity_;
  const std::size_t kN = 2u;
};


template<typename T>
VectorImpl<T>::VectorImpl(std::size_t size) :
        data_(size == 0 ? nullptr : operator new(sizeof(T) * size)),
        size_{size},
        capacity_{size_} {

}


template<typename T>
VectorImpl<T>::~VectorImpl() noexcept {

}


template<typename T>
void VectorImpl<T>::Swap(VectorImpl &other) noexcept {

}


template<typename T>
class vector {
public:
  vector();

  vector(std::size_t size);

  vector(std::size_t size, const T &val);

  ~vector();

  vector(const vector<T> &other);

  vector<T> &operator=(const vector<T> &other);

  std::size_t capacity() const;

  std::size_t size() const;

  T &at(const std::size_t &i);

  const T &at(const std::size_t &i) const;

  void push_back(const T &val);

  void pop_back();

  const T *data() const noexcept;

  void clear() noexcept;

  std::size_t max_size() const;

  void reserve(std::size_t new_cap);

  bool empty() const;

private:
  void init(const vector<T> &other);

private:
  std::size_t capacity_;
  std::size_t size_;
  T *data_;
  const std::size_t kN = 2u;
};


template<typename T>
vector<T>::vector() : capacity_{}, size_{}, data_{nullptr} {

}


template<typename T>
vector<T>::vector(std::size_t size) {
    // todo
}


template<typename T>
vector<T>::vector(std::size_t size, const T &val) {
    // todo
}


template<typename T>
vector<T>::~vector() {
    capacity_ = 0;
    size_ = 0;
    delete[] data_;
    data_ = nullptr;
}


template<typename T>
vector<T>::vector(const vector<T> &other) {
    init(other);
}


template<typename T>
vector<T> &vector<T>::operator=(const vector<T> &other) {
    if (this != &other) {
        delete[] data_;
        init(other);
    }
    return *this;
}


template<typename T>
std::size_t vector<T>::capacity() const {
    return capacity_;
}


template<typename T>
std::size_t vector<T>::size() const {
    return size_;
}


template<typename T>
T &vector<T>::at(const std::size_t &i) {
    if (size_ == 0u || i > size_ - 1u) throw std::out_of_range("out of range");
    return data_[i];
}


template<typename T>
const T &vector<T>::at(const std::size_t &i) const {
    if (size_ == 0u || i > size_ - 1u) throw std::out_of_range("out of range");
    return data_[i];
}


template<typename T>
void vector<T>::push_back(const T &val) {
    if (capacity_ == 0) {
        data_ = new T[1];
        capacity_ = 1;
    } else {
        std::size_t unused_capacity = capacity_ - size_;
        if (unused_capacity == 0) {
            T *tmp = new T[capacity_];
            memcpy(tmp, data_, capacity_ * sizeof(T));
            delete[] data_;
            std::size_t new_capacity = capacity_ * kN;
            data_ = new T[new_capacity];
            memcpy(data_, tmp, capacity_ * sizeof(T));
            capacity_ = new_capacity;
            delete[] tmp;
        }
    }
    data_[size_++] = val;
}


template<typename T>
void vector<T>::pop_back() {
    if (size_ == 0) return; // todo throw exception
    --size_;
}


template<typename T>
const T *vector<T>::data() const noexcept {
    return data_;
}


template<typename T>
void vector<T>::clear() noexcept {
    size_ = 0;
}


template<typename T>
void vector<T>::init(const vector<T> &other) {
    capacity_ = other.capacity_;
    data_ = new T[capacity_];
    size_ = other.size_;
    memcpy(data_, other.data_, size_ * sizeof(T));
}


template<typename T>
std::size_t vector<T>::max_size() const {
    return (std::numeric_limits<size_t>::max() / sizeof(T)) - 1;
}


template<typename T>
void vector<T>::reserve(std::size_t new_cap) {
    if (new_cap > max_size()) throw std::length_error("new_cap  > max_size()");
    if (new_cap > capacity_) {
        if (capacity_ > 0) {
            T *tmp = new T[capacity_];
            memcpy(tmp, data_, size_ * sizeof(T));
            delete[] data_;
            data_ = new T[new_cap];
            memcpy(data_, tmp, size_ * sizeof(T));
            capacity_ = new_cap;
            delete[] tmp;
        }
        capacity_ = new_cap;
        data_ = new T[capacity_];
    }
}


template<typename T>
bool vector<T>::empty() const {
    return size_ == 0;
}


} // namespace dsa

#endif // VECTOR_H_
