#include "sparse_table.h"
#include "testing_utils.h"
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

void runTests() {
  std::vector<int> array = testing_utils::generate_random_array(
      -100000, 100000, 1000);
  sparse_table_minimum::SparseTable<int> sparse_table(array);
  std::vector<std::pair<int, int> > requests =
      testing_utils::generate_random_requests(1000, 1000);
  for (std::pair<int, int> request : requests) {
    if (sparse_table.query(request.first, request.second)  !=
        *std::min_element(array.begin() + request.first,
            array.begin() + request.second + 1)) {
      std::cout << "Tests failed!" << std::endl << array.size() << std::endl;
      for (int index = 0; index < array.size(); ++index) {
        std::cout << array[index] << ' ';
      }
      std::cout << std::endl << "Request is" << std::endl;
      std::cout << request.first << ' ' << request.second << std::endl <<
        "Your answer is " << sparse_table.query(request.first, request.second)
        << std::endl << "Right answer is " <<
        *std::min_element(array.begin() + request.first,
            array.begin() + request.second + 1) << std::endl;
      return;
    }
  }
  std::cout << "Tests passed successfully!";
}

int main() {
  runTests();
}