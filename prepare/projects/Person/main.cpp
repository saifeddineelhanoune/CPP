#include "Student.hpp"

int main(void) {
    Person p1("Saifeddine Elhanoune", 24);
    p1.introduce();
    p1.writeAge();

    Student s1("Saifeddine Elhanoune", 24, "Software Engineer");
    s1.introduce();
    int average = Person::getAverageAge(p1, s1);
    std::cout << "Average age: " << average << std::endl;
    return 0;
}