/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Cook
*/

#include <iostream>
#include "Cook.hpp"

plazza::Cook::Cook()
{
    this->_isBusy = false;
    this->_isWaiting = false;
    this->_isCooking = false;
    this->_isCooked = false;
}

void plazza::Cook::info()
{
    if (this->_isBusy == true)
        std::cout << "Pizza en cours !" <<std::endl;
    else
        std::cout << "Je me branle" << std::endl;
}

bool plazza::Cook::isCooking() const
{
    return this->_isCooking;
}

bool plazza::Cook::isBusy() const
{
    return this->_isBusy;
}

bool plazza::Cook::isWaiting() const
{
    return this->_isWaiting;
}

void plazza::Cook::setBusy(bool busy)
{
    this->_isBusy = busy;
}

void plazza::Cook::setActualPizza(plazza::Pizza *pizza)
{
    this->_actualPizza = pizza;
}

void plazza::Cook::setWaitingPizza(plazza::Pizza *pizza)
{
    this->_awaitingPizza = pizza;
}

void plazza::Cook::describePizza()
{
    std::cout << this->_actualPizza->getPizzaType() << this->_actualPizza->getPizzaSize() << std::endl;
}

void plazza::Cook::simulate()
{
    /*
    this->_isCooking = true;
    this->_cookingChrono = new plazza::Chrono();
    this->_cookingChrono->startChrono();
    while (this->_cookingChrono->getElapsedTime() < this->_actualPizza->getCookingTime())
    {
        //Il wait la cuisson
    }
    std::cout << "Je viens de finir une pizza" << std::endl;
    if (this->isWaiting() == true) {
        this->_actualPizza = this->_awaitingPizza;
        this->_isWaiting = false;
        this->_isBusy = true;
    }
    else {
        this->_isCooking = false;
        this->_isBusy = false;
        this->_isWaiting = false;
    }*/
}

void plazza::Cook::setUnCooked()
{
    this->_isCooked = false;
    if (this->isWaiting() == true) {
        this->_actualPizza = this->_awaitingPizza;
        this->_isWaiting = false;
    }
}

bool plazza::Cook::isCooked() const
{
    return this->_isCooked;
}

plazza::Pizza *plazza::Cook::getActualPizza() const
{
    return this->_actualPizza;
}