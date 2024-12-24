// #include <cfloat>
// #include <cmath>
// #include <iostream>
 
// int main()
// {
// //     std::cout << std::boolalpha
// //               << "isnan(NaN) = " << std::isnan(NAN) << '\n'
// //               << "isnan(Inf) = " << std::isnan(INFINITY) << '\n'
// //               << "isnan(0.0) = " << std::isnan(0.0) << '\n'
// //               << "isnan(DBL_MIN/2.0) = " << std::isnan(DBL_MIN / 2.0) << '\n'
// //               << "isnan(0.0 / 0.0)   = " << std::isnan(0.0 / 0.0) << '\n'
// //               << "isnan(Inf - Inf)   = " << std::isnan(INFINITY - INFINITY) << '\n';

// }

#include <iostream>
#include <limits>
 
int main()
{
    double inf = std::numeric_limits<double>::infinity();
    double inf1 = std::numeric_limits<double>::infinity() + 1;
 
    if (inf1 > inf)
        std::cout << inf1 << " is greater than " << inf << '\n';
    else std::cout << "error" << std::endl;
}