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
#include <vector>
#include <string>
#include <cstdio>

void LoudIt(std::vector<std::string>& args)
{
  for (const auto& arg : args) {
      for (char c : arg) {
          putchar(std::toupper(c));
      }
      putchar(' ');
  }
  putchar('\n');
}
// void    LoudIt(char *av[], int ac)
// {
//     for (int i = 1; i < ac; i++) {
//         for (char *p = av[i]; *p; ++p) {
//             *p = (std::toupper(*p));
//             std::cout << *p;
//         }
//         std::cout << " ";
//     }
//     std::cout << std::endl;
// }

int main(int ac, char *av[])
{
    std::vector<std::string> args(av + 1, av + ac);
    if (ac == 1)
        (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl);
    else
        (LoudIt(args));
    return 0;
}

/*
    Damnit " ! " "Sorry students, I thought this thing was off."
    DAMNIT  !  SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
*/