// #include "Bureaucrat.hpp"

// int main() {
    
//     {
//         //values between 1 and 150
//         try {
//             Bureaucrat molotov("Vyacheslav Molotov", 2);
//             molotov.increment();
//             std::cout << molotov;
//             molotov.decrement();
//             std::cout << molotov;
//         } catch(const std::exception &e) {
//             std::cout << e.what();
//         }

//         try {
//             Bureaucrat mikoyan("Anastas Mikoyan", 42);
//             mikoyan.increment();
//             std::cout << mikoyan;
//             mikoyan.decrement();
//             std::cout << mikoyan;
//         } catch(const std::exception &e) {
//             std::cout << e.what();
//         }
//     }
//     {
//         // Low value
//         try {
//             Bureaucrat yezhov("Nikolai Yezhov", 0);
//             yezhov.increment();
//             std::cout << yezhov;
//         } catch(const std::exception& e) {
//             std::cout << e.what();
//         }
//         // High value;
//         try {
//             Bureaucrat marshall("George Marshall", 160);
//             marshall.decrement();
//             std::cout << marshall;
//         } catch(const std::exception& e) {
//             std::cout << e.what();
//         }
//     }
//     return 0;
// }
// #include "Bureaucrat.hpp"

// int main(void)
// {
//     {
//         try
//         {
//             {
//                 Bureaucrat b("test 1", 42);
//                 std::cout << b << std::endl;
//                 b.increment();
//                 std::cout << b << std::endl;
//                 b.decrement();
//                 std::cout << b << std::endl;
//             }
//             {
//                 Bureaucrat b("test 2", 37);
//                 std::cout << b << std::endl;
//                 b.decrement();
//                 std::cout << b << std::endl;
//                 b.increment();
//                 std::cout << b << std::endl;
//             }
//             {
//                 Bureaucrat b("test 3", 0);
//                 std::cout << b << std::endl;
//             }
//         }
//         catch(const std::exception& e)
//         {
//             std::cerr << e.what() << std::endl;
//         }

//         try
//         {
//             Bureaucrat b("test 4", 150);
//             std::cout << b << std::endl;
//             b.decrement();
//             std::cout << b << std::endl;
//         }
//         catch(const Bureaucrat::GradeTooLowException & e)
//         {
//             std::cerr << e.what() << std::endl;
//         }

//         try
//         {
//             Bureaucrat b("test 5", 1);
//             std::cout << b << std::endl;
//             b.increment();
//             std::cout << b << std::endl;
//         }
//         catch(const Bureaucrat::GradeTooHighException & e)
//         {
//             std::cerr << e.what() << std::endl;
//         }
//     }
//     return 0;
// }
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;
        
        b1.incrementGrade();
        std::cout << b1 << std::endl;  // Grade should now be 1

        // This will throw an exception because the grade is too high (below 1)
        b1.incrementGrade();
    } 
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;

        b2.decrementGrade();
        std::cout << b2 << std::endl;  // Grade should now be 150

        // This will throw an exception because the grade is too low (above 150)
        b2.decrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
