/*
$>./megaphone "shhhhh... I think the students are asleep..."
               SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
              DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
*/
#include <iostream>
#include <string>

int main(int ac, char *av[])
{
    std::string out;
    int i = 0;
    while(++i < ac) {
        std::string arguments(av[i]);
        for (int j = 0; arguments[j]; j++) {
            arguments[j] = toupper(arguments[j]);
            std::cout << arguments[j];
        }
        if (i < (ac - 1))
            std::cout << " ";
        out += arguments;
    }
    if (out.empty())
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}

/*
    Damnit " ! " "Sorry students, I thought this thing was off."
    DAMNIT  !  SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
*/