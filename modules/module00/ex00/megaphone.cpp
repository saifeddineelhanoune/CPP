#include <iostream>

/*
$>./megaphone "shhhhh... I think the students are asleep..."
               SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
              DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>

*/

void    LoudIt(char *av[], int ac)
{
    for (int i = 1; i < ac; i++) {
        for (char *p = av[i]; *p; ++p) {
            *p = (std::toupper(*p));
            std::cout << *p;
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}

int main(int ac, char *av[])
{
    (ac == 1) ? :
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}

/*
    Damnit " ! " "Sorry students, I thought this thing was off."
    DAMNIT  !  SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
*/