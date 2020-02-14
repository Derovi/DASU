#include "testing_utils.h"
#include <chrono>
#include <random>

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<int> testing_utils::generate_random_array(
    int min_element,
    int max_element,
    int size) {
  std::vector<int> random_array(size);
  for (int index = 0; index < size; ++index) {
    random_array[index] = rnd() % (max_element - min_element + 1) + min_element;
  }
  return random_array;
}

std::vector<std::pair<int, int> > testing_utils::generate_random_requests(
    int array_size, int request_count) {
  std::vector<std::pair<int, int> > random_requests(request_count);
  for (int index = 0; index < request_count; ++index) {
    random_requests[index].first = rnd() % array_size;
    random_requests[index].second =
        random_requests[index].first +
        rnd() % (array_size - random_requests[index].first);
  }
  return random_requests;
}