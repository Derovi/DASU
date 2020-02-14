#ifndef testing_utils_h
#define testing_utils_h

#include <vector>

namespace testing_utils {
  std::vector<int> generate_random_array(int min_element,
                                       int max_element,
                                       int size);

  std::vector<std::pair<int, int> > generate_random_requests(
      int array_size,
      int request_count);
}


#endif  // testing_utils_h
