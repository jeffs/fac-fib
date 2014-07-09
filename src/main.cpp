/** @file main.cpp Demonstrates purely functional, tail-recursive,
  * arbitrary-precision factorial and Fibonacci functions using
  * Boost.Multiprecision.
  *
  * @note That this implementation passes parameters by constant reference, but
  * returns by value.  This approach strikes a balance between high- and
  * low-level concerns.
  *
  * @see pretty.cpp for less noisy (but potentially less efficient) code.
  *
  * @see control.cpp for tighter control over memory.
  */

#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using big_int = boost::multiprecision::cpp_int;

big_int factorial(int n, big_int const& r =1)
{
    return n ? factorial(n - 1, r * n) : r;
}

big_int fibonacci(int n, big_int const& a =1, big_int const& b =1)
{
    return n ? fibonacci(n - 1, b, a + b) : a;
}

int main()
{
    for (int i = 0; i < 100; ++i) {
        std::cout << i << ' ' << factorial(i) << ' ' << fibonacci(i) << '\n';
    }
}
