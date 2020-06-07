/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Graphical
*/

#include "Graphical.hpp"

Graphical::Graphical()
{
    target = 0;
    actualIndex = 0;
    actualLine = 0;
    defPizza = -1;
    defSize = -1;
    defNumber = -1;
    _isOrderEnd = false;
    // this->Init_launcher();
}

Graphical::~Graphical()
{
    endwin();
}

void Graphical::Init_launcher()
{
    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
    START_COLOR()
}

void Graphical::SQUARE(int x1, int x2, int y1, int y2)
{
    HORIZONTAL(x1, y1, y2 - y1);
    HORIZONTAL(x2, y1, y2 - y1);
    VERTICAL(x1, y1, x2 - x1);
    VERTICAL(x1, y2, x2 - x1);
    CORNER_BG(x2, y2);
    CORNER_HG(x1, y2);
    CORNER_BD(x2, y1);
    CORNER_HD(x1, y1);
}

void Graphical::displaySquareWithWord(std::string name, int x1, int x2, int y1, int y2)
{
    if ((defPizza != -1 && name == _pizzaName[defPizza]) || (defSize != -1 && name == _pizzaSize[defSize]) || (defNumber != -1 && name.substr(0, 6) == "Number"))
        USE_COLOR(BLUE);
    if ((name == _pizzaName[actualIndex] && actualLine == 0) || (name == _pizzaSize[actualIndex] && actualLine == 1) || (actualLine == 2 && name.substr(0, 6) == "Number") || (actualLine == 3 && name == _endButton[actualIndex]))
        USE_COLOR(YELLOW);
    this->SQUARE(x1, x2, y1, y2);
    PRINT((x1 + x2) / 2, ((y1 + y2) / 2) - (name.size() / 2) + target, name.c_str())
    END_COLOR()
}

void Graphical::displayFullPizza()
{
    target = 1;
    this->displaySquareWithWord("Regina", 10, 14, 5, 18);
    this->displaySquareWithWord("Fantasia", 10, 14, 20, 33);
    this->displaySquareWithWord("Marguerita", 10, 14, 35, 48);
    this->displaySquareWithWord("Americana", 10, 14, 50, 63);
}

void Graphical::displayFullSize()
{
    target = 0;
    this->displaySquareWithWord("S", 16, 18, 5, 15);
    this->displaySquareWithWord("M", 16, 18, 17, 27);
    this->displaySquareWithWord("L", 16, 18, 29, 39);
    this->displaySquareWithWord("XL", 16, 18, 41, 51);
    this->displaySquareWithWord("XXL", 16, 18, 53, 63);
}

void Graphical::displayNumberOfPizza()
{
    std::string text = "Number of Pizza: ";
    std::string number = defNumber == -1 ? std::to_string(actualIndex) : std::to_string(defNumber);
    if (actualLine < 2)
        number = "1";
    this->displaySquareWithWord(text + number, 20, 22, 17, 51);
}

void Graphical::displayConfirmButton()
{
    this->displaySquareWithWord("Continue", 24, 26, 5, 33);    
    this->displaySquareWithWord("End", 24, 26, 34, 63);    
}

void Graphical::displayChoices()
{
    SQUARE(9, 27, 3, 65);
    displayFullPizza();
    displayFullSize();
    displayNumberOfPizza();
    displayConfirmButton();
    displaySelectedPizza();
}

void Graphical::addToOrder()
{
    _order.addOrder(_pizzaName[defPizza], _pizzaSize[defSize], std::to_string(defNumber));
}

void Graphical::displayOrder(std::map<int, plazza::Order> order)
{
    int x = 0;

    this->SQUARE(9, 49, 125, 175);
    if (order.empty() == true)
        this->displaySquareWithWord("No order", 27, 29, 127, 173);
    for (auto &i: order) {
        this->displaySquareWithWord("Command numero: " + std::to_string(i.first), 10 + x, 12 + x, 127, 173);
        x+= 3;
    }
}

void Graphical::displaySelectedPizza()
{
    std::vector<std::string> vec = _order.getOrder();
    int x = 0;

    this->SQUARE(9, 49, 70, 120);
    if (vec.empty() == true)
        this->displaySquareWithWord("No pizza", 27, 29, 72, 118);
    for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); ++it, x+= 3) {
        std::string tmp = *it;
        this->displaySquareWithWord(tmp, 10 + x, 12 + x, 72, 118);
    }
}

void Graphical::doKeyLeft()
{
    if (actualLine == 2) {
        if (actualIndex != 1)
            actualIndex--;
    } else if (actualLine == 3 && actualIndex == 1)
        actualIndex--;
    else if (actualIndex != 0)
        actualIndex--;
}

void Graphical::doKeyRight()
{
    if (actualIndex != 3 && actualLine == 0)
        actualIndex++;
    else if (actualIndex != 4 && actualLine == 1)
        actualIndex++;
    else if (actualLine == 2 && actualIndex != 13 && (actualIndex + _order.getOrder().size()) < 13)
        actualIndex++;
    else if (actualLine == 3 && actualIndex == 0)
        actualIndex++;
}

void Graphical::doKeyEnter()
{
    if (actualLine == 0)
        defPizza = actualIndex;
    else if (actualLine == 1)
        defSize = actualIndex;
    else if (actualLine == 2)
        defNumber = actualIndex;
    else if (actualLine == 3) {
        if (actualIndex == 0)
            addToOrder();
        if (actualIndex == 1 || this->_order.getOrder().size() == 12)
            this->_isOrderEnd = true;
        defPizza = -1;
        defSize = -1;
        defNumber = -1;
        actualIndex = 0;
        actualLine = -1;
    }
    if (actualLine == 1)
        actualIndex = 1;
    else
        actualIndex = 0;
    actualLine++;
}

void Graphical::manageKey()
{
    int c = getch();
    if (c == KEY_LEFT)
        doKeyLeft();
    if (c == KEY_RIGHT)
        doKeyRight();
    if (c == KEY_DOWN || c == ENTER_KEY)
        doKeyEnter();
}

void Graphical::setIsOrderEnd(bool tmp)
{
    this->_isOrderEnd = tmp;
    _order = plazza::Order();
}

bool Graphical::getIsOrderEnd() const
{
    return this->_isOrderEnd;
}

plazza::Order Graphical::getOrder() const
{
    return this->_order;
}