/** @file main.cpp Demonstrates purely functional, tail-recursive,
  * arbitrary-precision factorial and Fibonacci functions using
  * Boost.Multiprecision.
  * 
  * @note This implementation uses a concise style, passing and returning
  * objects by value.
  */

#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using BigInt = boost::multiprecision::cpp_int;

BigInt factorial(int n, BigInt r =1) {
    return n ? factorial(n - 1, r * n) : r;
}

BigInt fibonacci(int n, BigInt a =1, BigInt b =1) {
    return n ? fibonacci(n - 1, b, a + b) : a;
}

int main() {
    for (int i = 0; i < 100; ++i)
        std::cout << i << ' ' << factorial(i) << ' ' << fibonacci(i) << '\n';
}
