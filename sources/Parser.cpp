/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Parser
*/

#include <iostream>
#include <bits/stdc++.h> 
#include <string>
#include <iterator>
#include <sstream>
#include <map>
#include "APizza.hpp"
#include "Pizza.hpp"
#include "Parser.hpp"
#include "Order.hpp"
#include "string"

bool InsensitiveCompare(unsigned char a, unsigned char b)
{
    return (std::tolower(a) == std::tolower(b));
}

bool IsAlphaNumeric(const std::string &s)
{
    std::string::const_iterator it;

    for (it = s.begin(); it != s.end() && std::isdigit(*it); ++it);
    return (!s.empty() && it == s.end());
}

void plazza::Parser::getEndOfOrder()
{
    if (_actualWord->back() == ';') {
        *_actualWord = _actualWord->substr(0, _actualWord->size() - 1);
        _endOfCommand = true;
    } else if (_orderInput.size() == 1) {
        _endOfCommand = true;
    } else if (std::next(_actualWord) == _orderInput.end()) {
        _endOfCommand = true;
    } else {
        _endOfCommand = false;
    }
}

void plazza::Parser::addOrderNamesOfPizzas()
{
    if (_actualWord->length() == _pizzasInfo[0].length() || _actualWord->length() == _pizzasInfo[1].length() || _actualWord->length() == _pizzasInfo[2].length() || _actualWord->length() == _pizzasInfo[3].length()) {
        if (std::equal(_pizzasInfo[0].begin(), _pizzasInfo[0].end(), _actualWord->begin(), InsensitiveCompare)) {
            if (this->_Errors[0] == true) {
                this->_Ret = 1;
            }
            _pizzasNames.push_back(*_actualWord);
            this->_Errors[0] = true;
        } else if (std::equal(_pizzasInfo[1].begin(), _pizzasInfo[1].end(), _actualWord->begin(), InsensitiveCompare)) {
            if (this->_Errors[0] == true) {
                this->_Ret = 1;
            }
            _pizzasNames.push_back(*_actualWord);
            this->_Errors[0] = true;
        } else if (std::equal(_pizzasInfo[2].begin(), _pizzasInfo[2].end(), _actualWord->begin(), InsensitiveCompare)) {
            if (this->_Errors[0] == true) {
                this->_Ret = 1;
            }
            _pizzasNames.push_back(*_actualWord);
            this->_Errors[0] = true;
        } else if (std::equal(_pizzasInfo[3].begin(), _pizzasInfo[3].end(), _actualWord->begin(), InsensitiveCompare)) {
            if (this->_Errors[0] == true) {
                this->_Ret = 1;
            }
            _pizzasNames.push_back(*_actualWord);
            this->_Errors[0] = true;
        }
    }
}

void plazza::Parser::addOrderSizeOfPizzas()
{
    if (_actualWord->length() == _pizzasInfo[4].length() || _actualWord->length() == _pizzasInfo[5].length() || _actualWord->length() == _pizzasInfo[6].length() || _actualWord->length() == _pizzasInfo[7].length() || _actualWord->length() == _pizzasInfo[8].length()) {
        if (std::equal(_pizzasInfo[4].begin(), _pizzasInfo[4].end(), _actualWord->begin(), InsensitiveCompare)) {
            if (this->_Errors[1] == true) {
                this->_Ret = 1;
            }
            _pizzasSize.push_back(*_actualWord);
            this->_Errors[1] = true;
        } else if (std::equal(_pizzasInfo[5].begin(), _pizzasInfo[5].end(), _actualWord->begin(), InsensitiveCompare)) {
            if (this->_Errors[1] == true) {
                this->_Ret = 1;
            }
            _pizzasSize.push_back(*_actualWord);
            this->_Errors[1] = true;
        } else if (std::equal(_pizzasInfo[6].begin(), _pizzasInfo[6].end(), _actualWord->begin(), InsensitiveCompare)) {
            if (this->_Errors[1] == true) {
                this->_Ret = 1;
            }
            _pizzasSize.push_back(*_actualWord);
            this->_Errors[1] = true;
        } else if (std::equal(_pizzasInfo[7].begin(), _pizzasInfo[7].end(), _actualWord->begin(), InsensitiveCompare)) {
            if (this->_Errors[1] == true) {
                this->_Ret = 1;
            }
            _pizzasSize.push_back(*_actualWord);
            this->_Errors[1] = true;
        } else if (std::equal(_pizzasInfo[8].begin(), _pizzasInfo[8].end(), _actualWord->begin(), InsensitiveCompare)) {
            if (this->_Errors[1] == true) {
                this->_Ret = 1;
            }
            _pizzasSize.push_back(*_actualWord);
            this->_Errors[1] = true;
        }
    }
}

void plazza::Parser::addOrderNumberOfPizzas()
{
    if (_actualWord->length() >= 1 && _actualWord->length() <= 3 && _actualWord->at(0) == 'x') {
        _actualWord->erase(0, 1);
        if (IsAlphaNumeric(*_actualWord) == true) {
            if (std::stoi(*_actualWord) >= 1 && std::stoi(*_actualWord) <= 99) {
                if (this->_Errors[2] == true) {
                    exit(84);
                }
                _pizzasNumber.push_back(*_actualWord);
                this->_Errors[2] = true;
            }
        }
    }
}

void plazza::Parser::checkEndOfOrderError()
{
    if (_endOfCommand == true) {
        for (int i = 0; i < 3; i++) {
            if (this->_Errors[i] == false) {
                this->_Ret = 1;
                return ;
            }
            this->_Errors[i] = false;
        }
        if (_pizzasNames.size() >= 1 && _pizzasSize.size() >= 1 && _pizzasNumber.size() >= 1) {
            _Send = Order();
            _Send.addOrder(_pizzasNames.back(), _pizzasSize.back(), _pizzasNumber.back());
            this->_Ret = 2;
        }
    }
}

void plazza::Parser::getUserCommand()
{
    std::string tempVar;
    std::string buffOrder;

    std::getline(std::cin, buffOrder);
    std::istringstream delimitedInput(buffOrder);
    _orderInput.clear();
    while (delimitedInput) {
        delimitedInput >> tempVar;
        _orderInput.push_back(tempVar);
        if (tempVar != "")
        tempVar = "";
    }
}

int plazza::Parser::parserLoop()
{
    std::string command = "status";

    this->_Ret = -1;
    this->getUserCommand();
    for (_actualWord = _orderInput.begin(); _actualWord != _orderInput.end() && this->_Ret == -1; ++_actualWord) {
        if (_actualWord->length() == command.length()) {
            if (std::equal(command.begin(), command.end(), _actualWord->begin(), InsensitiveCompare)) {
                return (3);
            }
        }
        this->getEndOfOrder();
        this->addOrderNamesOfPizzas();
        this->addOrderSizeOfPizzas();
        this->addOrderNumberOfPizzas();
        this->checkEndOfOrderError();
    }
    if (this->_Ret != 0 && this->_Ret != 1) {
        this->_Ret = 2;
    }
    return (this->_Ret);
}

plazza::PizzaType plazza::Parser::getPackName(std::string Name)
{
    if (Name.length() == _pizzasInfo[0].length() || Name.length() == _pizzasInfo[1].length() || Name.length() == _pizzasInfo[2].length() || Name.length() == _pizzasInfo[3].length()) {
        if (std::equal(_pizzasInfo[0].begin(), _pizzasInfo[0].end(), Name.begin(), InsensitiveCompare)) {
            return (Regina);
        } else if (std::equal(_pizzasInfo[1].begin(), _pizzasInfo[1].end(), Name.begin(), InsensitiveCompare)) {
            return (Fantasia);
        } else if (std::equal(_pizzasInfo[2].begin(), _pizzasInfo[2].end(), Name.begin(), InsensitiveCompare)) {
            return (Margarita);
        } else if (std::equal(_pizzasInfo[3].begin(), _pizzasInfo[3].end(), Name.begin(), InsensitiveCompare)) {
            return (Americana);
        }
    }
    return plazza::UNDEFINEDTYPE;
}

plazza::PizzaSize plazza::Parser::getPackSize(std::string Size)
{
    if (Size.length() == _pizzasInfo[4].length() || Size.length() == _pizzasInfo[5].length() || Size.length() == _pizzasInfo[6].length() || Size.length() == _pizzasInfo[7].length() || Size.length() == _pizzasInfo[8].length()) {
        if (std::equal(_pizzasInfo[4].begin(), _pizzasInfo[4].end(), Size.begin(), InsensitiveCompare)) {
            return (S);
        } else if (std::equal(_pizzasInfo[5].begin(), _pizzasInfo[5].end(), Size.begin(), InsensitiveCompare)) {
            return (M);
        } else if (std::equal(_pizzasInfo[6].begin(), _pizzasInfo[6].end(), Size.begin(), InsensitiveCompare)) {
            return (L);
        } else if (std::equal(_pizzasInfo[7].begin(), _pizzasInfo[7].end(), Size.begin(), InsensitiveCompare)) {
            return (XL);
        } else if (std::equal(_pizzasInfo[8].begin(), _pizzasInfo[8].end(), Size.begin(), InsensitiveCompare)) {
            return (XXL);
        }
    }
    return plazza::UNDEFINEDSIZE;
}

bool plazza::Parser::IsPossibleToPack(std::string strToPack)
{
    bool is_possible = false;
    std::istringstream delimitedInput(strToPack);
    std::vector<std::string> delimited;
    std::string tempVar;
    bool isId[2] = {false, false};

    while (delimitedInput) {
        delimitedInput >> tempVar;
        delimited.push_back(tempVar);
        if (tempVar != "")
        tempVar = "";
    }
    for (std::vector<std::string>::iterator it = delimited.begin(); it != delimited.end(); ++it) {
        if (isId[0] == true && isId[1] == true && IsAlphaNumeric(*it) == true) {
            is_possible = true;
            break;
        }
        if (it->length() == _pizzasInfo[0].length() || it->length() == _pizzasInfo[1].length() || it->length() == _pizzasInfo[2].length() || it->length() == _pizzasInfo[3].length()) {
            if (std::equal(_pizzasInfo[0].begin(), _pizzasInfo[0].end(), it->begin(), InsensitiveCompare)) {
                isId[0] = true;
            } else if (std::equal(_pizzasInfo[1].begin(), _pizzasInfo[1].end(), it->begin(), InsensitiveCompare)) {
                isId[0] = true;
            } else if (std::equal(_pizzasInfo[2].begin(), _pizzasInfo[2].end(), it->begin(), InsensitiveCompare)) {
                isId[0] = true;
            } else if (std::equal(_pizzasInfo[3].begin(), _pizzasInfo[3].end(), it->begin(), InsensitiveCompare)) {
                isId[0] = true;
            }
        }
        if (it->length() == _pizzasInfo[4].length() || it->length() == _pizzasInfo[5].length() || it->length() == _pizzasInfo[6].length() || it->length() == _pizzasInfo[7].length() || it->length() == _pizzasInfo[8].length()) {
            if (std::equal(_pizzasInfo[4].begin(), _pizzasInfo[4].end(), it->begin(), InsensitiveCompare)) {
                isId[1] = true;
            } else if (std::equal(_pizzasInfo[5].begin(), _pizzasInfo[5].end(), it->begin(), InsensitiveCompare)) {
                isId[1] = true;
            } else if (std::equal(_pizzasInfo[6].begin(), _pizzasInfo[6].end(), it->begin(), InsensitiveCompare)) {
                isId[1] = true;
            } else if (std::equal(_pizzasInfo[7].begin(), _pizzasInfo[7].end(), it->begin(), InsensitiveCompare)) {
                isId[1] = true;
            } else if (std::equal(_pizzasInfo[8].begin(), _pizzasInfo[8].end(), it->begin(), InsensitiveCompare)) {
                isId[1] = true;
            }
        }
    }
    return (is_possible);
}

plazza::Pizza *plazza::Parser::pack(std::string strToPack)
{
    std::istringstream delimitedInput(strToPack);
    std::vector<std::string> delimited;
    std::string tempVar;
    plazza::PizzaType pizzaNm;
    plazza::PizzaSize pizzaSz;
    int pizzaId;
    bool isId[2] = {false, false};

    while (delimitedInput) {
        delimitedInput >> tempVar;
        delimited.push_back(tempVar);
        if (tempVar != "")
        tempVar = "";
    }
    for (std::vector<std::string>::iterator it = delimited.begin(); it != delimited.end(); ++it) {
        if (isId[0] == true && isId[1] == true && IsAlphaNumeric(*it) == true) {
            pizzaId = std::stoi(*it);
        }
        if (it->length() == _pizzasInfo[0].length() || it->length() == _pizzasInfo[1].length() || it->length() == _pizzasInfo[2].length() || it->length() == _pizzasInfo[3].length()) {
            if (std::equal(_pizzasInfo[0].begin(), _pizzasInfo[0].end(), it->begin(), InsensitiveCompare)) {
                pizzaNm = Regina;
                isId[0] = true;
            } else if (std::equal(_pizzasInfo[1].begin(), _pizzasInfo[1].end(), it->begin(), InsensitiveCompare)) {
                pizzaNm = Fantasia;
                isId[0] = true;
            } else if (std::equal(_pizzasInfo[2].begin(), _pizzasInfo[2].end(), it->begin(), InsensitiveCompare)) {
                pizzaNm = Margarita;
                isId[0] = true;
            } else if (std::equal(_pizzasInfo[3].begin(), _pizzasInfo[3].end(), it->begin(), InsensitiveCompare)) {
                pizzaNm = Americana;
                isId[0] = true;
            }
        }
        if (it->length() == _pizzasInfo[4].length() || it->length() == _pizzasInfo[5].length() || it->length() == _pizzasInfo[6].length() || it->length() == _pizzasInfo[7].length() || it->length() == _pizzasInfo[8].length()) {
            if (std::equal(_pizzasInfo[4].begin(), _pizzasInfo[4].end(), it->begin(), InsensitiveCompare)) {
                pizzaSz = S;
                isId[1] = true;
            } else if (std::equal(_pizzasInfo[5].begin(), _pizzasInfo[5].end(), it->begin(), InsensitiveCompare)) {
                pizzaSz = M;
                isId[1] = true;
            } else if (std::equal(_pizzasInfo[6].begin(), _pizzasInfo[6].end(), it->begin(), InsensitiveCompare)) {
                pizzaSz = L;
                isId[1] = true;
            } else if (std::equal(_pizzasInfo[7].begin(), _pizzasInfo[7].end(), it->begin(), InsensitiveCompare)) {
                pizzaSz = XL;
                isId[1] = true;
            } else if (std::equal(_pizzasInfo[8].begin(), _pizzasInfo[8].end(), it->begin(), InsensitiveCompare)) {
                pizzaSz = XXL;
                isId[1] = true;
            }
        }
    }
    return (new plazza::Pizza(pizzaNm, pizzaSz, pizzaId));
}

std::string plazza::Parser::unpack(plazza::Pizza *PizzaClass)
{
    std::string PizzaName;
    std::string PizzaSize;
    int id = PizzaClass->getPizzaId();

    if (PizzaClass->getPizzaType() == Regina) {
        PizzaName = "Regina";
    } else if (PizzaClass->getPizzaType() == Fantasia) {
        PizzaName = "Fantasia";        
    } else if (PizzaClass->getPizzaType() == Margarita) {
        PizzaName = "Margarita";
    } else if (PizzaClass->getPizzaType() == Americana) {
        PizzaName = "Americana";
    }
    if (PizzaClass->getPizzaSize() == S) {
        PizzaSize = "S";
    } else if (PizzaClass->getPizzaSize() == M) {
        PizzaSize = "M";
    } else if (PizzaClass->getPizzaSize() == L) {
        PizzaSize = "L";
    } else if (PizzaClass->getPizzaSize() == XL) {
        PizzaSize = "XL";
    } else if (PizzaClass->getPizzaSize() == XXL) {
        PizzaSize = "XXL";
    }
    return (PizzaName + " " + PizzaSize + " " + std::to_string(id));
}
