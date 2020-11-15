/*
** EPITECH PROJECT, 2019
** 201yams
** File description:
** main.cpp
*/

#include "yams.hpp"

int main(int ac, char **av)
{
  std::ifstream filedata("help");
  std::string buff = "";
  std::string help;

  if (ac == 7) {
    Calcul yams(av[6]);
    for (int i = 1; i < 6; i += 1) {
      if (yams.add_dice(av[i]) == 1) {
        return (84);
      }
    }
    yams.display(yams.algorithm());

    return (0);
  } else if (ac == 2 && !strcmp("-h", av[1])) {
    if (filedata.is_open()) {
      while (std::getline(filedata, buff)) {
        help = help + buff;
        help = help + '\n';
      }
      std::cout << help;
    }
    return (0);
  }

  return (84);
}
