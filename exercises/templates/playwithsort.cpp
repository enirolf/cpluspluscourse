#include "OrderedVector.hpp"
#include "Complex.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <ranges>

struct ReverseStringLess {
    bool operator()(const std::string& left, const std::string& right) const
    {
        return std::ranges::lexicographical_compare(std::views::reverse(left), std::views::reverse(right), std::less<char> {});
    }
};

struct ManhattanLess {
    bool operator()(const Complex& left, const Complex& right) const
    {
        return std::abs(left.real()) + std::abs(left.imaginary()) < std::abs(right.real()) + std::abs(right.imaginary());
    }
};

int main() {
    std::cout << "Integer\n";
    OrderedVector<int, std::greater<int>> v(10);
    for (int i = 10; i > 0; i--)
        v.add(i);
    for (int i = 0; i < 10; i++)
        std::cout << v[i] << " ";
    std::cout << "\n\n";

    std::cout << "String\n";
    OrderedVector<std::string> vs(5);
    vs.add(std::string("one"));
    vs.add(std::string("two"));
    vs.add(std::string("three"));
    vs.add(std::string("four"));
    vs.add(std::string("five"));
    for (int i = 0; i < 5; i++)
        std::cout << vs[i] << " ";
    std::cout << "\n\n";

    // TODO: Demonstrate OrderedVector with Complex as element type similar to above
    std::cout << "Complex\n";
    OrderedVector<Complex> vc(3);
    vc.add(Complex{-0.2f, 0.4f});
    vc.add(Complex{0.8f, -0.5f});
    vc.add(Complex{0.3f, 0.2f});
    for (int i = 0; i < 3; i++)
        std::cout << vc[i] << " ";
    std::cout << "\n\n";


    // TODO: Extend OrderedVector to allow to customize the ordering via an additional template paramter.
    //       Then, demonstrate the new functionality by ordering an OrderedVector<std::string>,
    //       where the strings are compared starting at their last letters.
    std::cout << "Reverse string\n";
    OrderedVector<std::string, ReverseStringLess> vsr(5);
    vsr.add(std::string("one"));
    vsr.add(std::string("two"));
    vsr.add(std::string("three"));
    vsr.add(std::string("four"));
    vsr.add(std::string("five"));
    for (int i = 0; i < 5; i++)
        std::cout << vsr[i] << " ";
    std::cout << "\n\n";


    // TODO: Order an OrderedVector of Complex based on the Manhattan distance
    std::cout << "Complex Manhattan\n";
    OrderedVector<Complex, ManhattanLess> vcm(3);
    vcm.add(Complex{-0.2f, 0.4f});
    vcm.add(Complex{0.8f, -0.5f});
    vcm.add(Complex{0.3f, 0.2f});
    for (int i = 0; i < 3; i++)
        std::cout << vcm[i] << " ";
    std::cout << "\n\n";

    std::cout << "Complex of Complex\n";
    OrderedVector<ComplexComplex> vcc(3);
    vcc.add(ComplexComplex{Complex{0.1f, 0.4f}, Complex{0.4f, 2.1f}});
    vcc.add(ComplexComplex{Complex{0.2f, 0.5f}, Complex{-0.2f, 4.4f}});
    vcc.add(ComplexComplex{Complex{7.2f, 2.5f}, Complex{1.3f, 9.5f}});
    for (int i = 0; i < 3; i++)
        std::cout << vcc[i] << " ";
    std::cout << "\n\n";

}
