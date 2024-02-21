#include <iostream>

class Date {

    public:
        int day, month, year;
        Date(int d, int m, int y) : day(d), month(m), year(y) {

        }
        friend std::ostream& operator<<(std::ostream& os, const Date& dt);
};

std::ostream& operator<<(std::ostream& os, const Date& dt) {
    os << dt.day << '/' << dt.month << '/' << dt.year;
    return os;
}

int main() {
    Date date(26, 11, 2023);
    std::cout << date << std::endl;
    return 0;
}
