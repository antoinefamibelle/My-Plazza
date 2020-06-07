/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Graphical
*/

#ifndef GRAPHICAL_HPP_
#define GRAPHICAL_HPP_

#include <curses.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>

#include "../Headers/Order.hpp"

#define PRINT(x, y, text) mvprintw(x, y, text);
#define HORIZONTAL(x, y, size) mvhline(x, y, 0, size);
#define VERTICAL(x, y, size) mvvline(x, y, 0, size);
#define CORNER_BG(x, y) mvaddch(x, y, ACS_LRCORNER);
#define CORNER_BD(x, y) mvaddch(x, y, ACS_LLCORNER);
#define CORNER_HD(x, y) mvaddch(x, y, ACS_ULCORNER);
#define CORNER_HG(x, y) mvaddch(x, y, ACS_URCORNER);

#define START_COLOR() start_color(); init_pair(1, COLOR_WHITE, COLOR_BLACK); init_pair(2, COLOR_YELLOW, COLOR_BLACK); init_pair(3, COLOR_CYAN, COLOR_BLACK);
#define END_COLOR() attron(COLOR_PAIR(1));
#define USE_COLOR(COLOR) attron(COLOR_PAIR(COLOR));
#define NORMAL 1
#define YELLOW 2
#define BLUE 3
#define ENTER_KEY 10


class Graphical {
    public:
        Graphical();
        ~Graphical();
        void displayChoices();
        void manageKey();
        void Init_launcher();
        void setIsOrderEnd(bool tmp);
        bool getIsOrderEnd() const;
        plazza::Order getOrder() const;
        void displayOrder(std::map<int, plazza::Order> order);
        void doKeyEnter();

    protected:
    private:
        void SQUARE(int x1, int x2, int y1, int y2);
        void displaySquareWithWord(std::string name, int x1, int x2, int y1, int y2);
        void displayFullPizza();
        void displayFullSize();
        void displayConfirmButton();
        void displayNumberOfPizza();
        void displaySelectedPizza();
        void addToOrder();
        void doKeyLeft();
        void doKeyRight();
        
        std::vector<std::string> _pizzaName = {"Regina", "Fantasia", "Marguerita", "Americana"};
        std::vector<std::string> _pizzaSize = {"S", "M", "L", "XL", "XXL"};
        std::vector<std::string> _endButton = {"Continue", "End"};

        int actualLine;
        int actualIndex;
        int target;
        int defPizza;
        int defSize;
        int defNumber;
        bool _isOrderEnd;
        
        plazza::Order _order;
};

#endif /* !GRAPHICAL_HPP_ */
