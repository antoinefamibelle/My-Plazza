/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** main
*/

#include <iostream>
#include "Reception.hpp"
#include "plazza.hpp"

static bool IsAlphaNumeric(const std::string &s)
{
    std::string::const_iterator it;

    for (it = s.begin(); it != s.end() && std::isdigit(*it); ++it);
    if (!s.empty() && it == s.end()) {
        return (true);
    }
    return (false);
}

int main(int ac, char **av)
{
    try {
        if (!((ac == 5 && strcmp(av[4], "-g") == 0) || (ac == 5 && strcmp(av[4], "-graphics") == 0) || ac == 4)) {
            throw "Missing an argument";
        } else if (IsAlphaNumeric(av[1]) == false || IsAlphaNumeric(av[2]) == false || IsAlphaNumeric(av[3]) == false) {
            throw "Positive Number awaited";
        } else if (std::stoi(av[1]) == 0 ||  std::stoi(av[2]) == 0 || std::stoi(av[3]) == 0) {
            throw "Non null number awaited";
        }
        plazza::Reception _rec(atoi(av[1]), atoi(av[2]), atoi(av[3]), ac == 5 ? av[4] : NULL);
        _rec.head();
    } catch (const char *message) {
        std::cerr << message << std::endl;
    }
    return 0;
}