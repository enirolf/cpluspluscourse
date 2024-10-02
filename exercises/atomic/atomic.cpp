#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

constexpr unsigned int nThread = 2;

int main() {
  int nError = 0;

  for (int j = 0; j < 100000; j++) {
    std::atomic<int> a = 0;

    // Increment the variable a 100 times:
    auto inc100 = [&a](){
      for (int i = 0; i < 100; ++i) {
        a++;
      }
    };

    // Start up all threads:
    std::vector<std::thread> threads;
    for (unsigned int i = 0; i < nThread; ++i) threads.emplace_back(inc100);
    for (auto & thread : threads) thread.join();

    // Check
    if (a != nThread * 100) {
      std::cerr << "Race detected! Result: " << a << '\n';
      nError++;
    }
  }

  return nError;
}
