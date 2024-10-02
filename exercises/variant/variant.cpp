/*

In the code below, replace inheritance with the use of a `std::variant<Electron, Proton, Neutron>`.
There is no more need for a base class, and no more need pointers.
Two solutions are provided :
1. with `std::get_if`,
2. with `std::visit`.

*/

#include <iostream>
#include <memory>
#include <variant>
#include <vector>

struct Electron {
  void print() const { std::cout << "E\n"; }
};

struct Proton {
  void print() const { std::cout << "P\n"; }
};

struct Neutron {
  void print() const { std::cout << "N\n"; }
};

int main() {
  std::vector<std::variant<Electron, Proton, Neutron>> ps;
  ps.push_back(Electron{});
  ps.push_back(Proton{});
  ps.push_back(Neutron{});

  for (auto const &p : ps) {
    std::visit([](auto &p){ p.print(); }, p);
  }
}
