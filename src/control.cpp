/** @file main.cpp Demonstrates arbitrary-precision factorial and Fibonacci
  * functions using Boost.Multiprecision.
  *
  * @note This implementation uses output parameters to allow reuse of
  * previously allocated memory.  The technique also supports the potential
  * future use of custom allocators, since the caller of each function
  * allocates and configures the result object.  Moreover, the use of in-place
  * operators for assignments avoids the creation of unnecessary temporary
  * objects.
  *
  * @todo Memoize functions.  They currently require O(n) time per call.
  */

#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using big_int = boost::multiprecision::cpp_int;

using std::swap;

void factorial(big_int* r, int n)
{
    for (*r = 1; n > 1; --n) {
        *r *= n;
    }
}

void fibonacci(big_int* r, int n)
{
    *r = 1;
    for (big_int s = 1; n > 0; --n) {
        swap(*r, s);
        s += *r;
    }
}

int main()
{
    big_int r;
    for (int i = 0; i < 100; ++i) {
        factorial(&r, i);
        std::cout << i << ' ' << r << ' ';
        fibonacci(&r, i);
        std::cout << r << '\n';
    }
}
