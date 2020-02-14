#ifndef sparse_table_h
#define sparse_table_h

#include <vector>
#include <cstdint>

namespace sparse_table_minimum {

template <class T>
class SparseTable {
 public:
  explicit SparseTable(const std::vector<T>& elements);

  T query(int l, int r) const;

 private:
  uint32_t depth_ = 0;
  uint32_t size_;
  std::vector<std::vector<T> > sparse_;
  std::vector<int> logs_;
};

template <class T>
SparseTable<T>::SparseTable(const std::vector<T> &elements) {
  size_ = elements.size();
  logs_.resize(size_ + 1);
  for (uint32_t index = 0, current_log = 0; index <= size_; ++index) {
    if ((1U << (current_log + 1U)) <= index) {
      ++current_log;
    }
    logs_[index] = current_log;
  }
  depth_ = logs_.back() + 2;
  sparse_.assign(depth_, std::vector<T>(elements.size()));
  for (int index = 0; index < size_; ++index) {
    sparse_[0][index] = elements[index];
  }
  for (uint32_t current_depth = 1; current_depth < depth_; ++current_depth) {
    for (uint32_t index = 0; index < size_; ++index) {
      sparse_[current_depth][index] = std::min(sparse_[current_depth - 1][index],
                                               sparse_[current_depth - 1][index + (1U << (current_depth - 1U))]);
    }
  }
}

template <class T>
T SparseTable<T>::query(const int l, const int r) const {
  uint32_t k = logs_[r - l + 1];
  return std::min(sparse_[k][l], sparse_[k][r - (1U << k) + 1]);
}

}  // namespace sparse_table_range_minimum

#endif
