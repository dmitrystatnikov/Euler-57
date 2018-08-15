#include <boost/multiprecision/cpp_int.hpp>
#include <cstdlib>
#include <iostream>
#include <tuple>

using namespace boost;
using namespace boost::multiprecision;
using namespace std;

bool equal_decimal_length(cpp_int const & num, cpp_int const & den)
{
    static cpp_int measure = 1;
    if (num / measure > 9)
        measure *= 10;
    return den / measure > 0;
}

tuple<cpp_int, cpp_int> next_approximation(cpp_int && num, cpp_int && den)
{
    return make_tuple(num + 2 * den, num + den);
}

int main(int argc, char** argv)
{
    cpp_int num = 1;
    cpp_int den = 1;
    size_t count = 0;
    for (size_t i = 1; i < 1001; ++i)
    {
        tie(num, den) = next_approximation(std::move(num), std::move(den));
        if (!equal_decimal_length(num, den))
            ++count;
    }
    cout << count << endl;
    return 0;
}