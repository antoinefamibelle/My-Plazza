/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

plazza::Kitchen::Kitchen()
{
}

plazza::Kitchen::Kitchen(int numberOfCook, int speed, int kitchenNumber)
{
    this->_inactive = false;
    this->_speedStock = speed;
    this->_numberOfCook = numberOfCook;
    this->_kitchenNumber = kitchenNumber;
    this->_communication = new plazza::Communication();
    this->_ingredient = new plazza::StoredIngredient(kitchenNumber);
    this->_isStarted = false;
    this->_chrono = new plazza::Chrono();
    this->_stockChrono = new plazza::Chrono();
    this->generateCook();
}

void plazza::Kitchen::writeInLog(std::string str)
{
    this->_log.writeLog(str,this->_chrono->getTime());
}

void plazza::Kitchen::generateCook()
{
    int numberGenerated = 0;

    while (numberGenerated != this->getNumberOfCook()) {
        plazza::Cook *object = new plazza::Cook();
        std::thread *thread;
        this->_cooks.push_back(std::make_pair(object,thread));
        numberGenerated += 1;
    }
}

bool plazza::Kitchen::areBusy()
{
    for (auto &i : this->_cooks) {
        if (i.first->isBusy() == false) {
            return false;
        }
    }
    return true;
}

bool plazza::Kitchen::areWaiting()
{
    for (auto &i : this->_cooks) {
        if (i.first->isWaiting() == false) {
            return false;
        }
    }
    return true;
}

int plazza::Kitchen::getNumberOfPizza()
{
    int number = 0;
    for (auto &i : this->_cooks) {
        if (i.first->isBusy() == true)
            number += 1;
        if (i.first->isWaiting() == true)
            number += 1;
    }
    return number;
}

bool plazza::Kitchen::canBeSend()
{
    plazza::Pizza *tmp;

    for (auto &i : this->_pizza) {
        if (i.second == false)
            tmp = i.first;
    }
    if (!tmp)
        return false;
    std::vector<plazza::PizzaIngredients> list = tmp->getRecette();

    if (this->_ingredient->isRecettePossible(list) == true) {
        std::cout << "possible" << std::endl;
        this->_ingredient->makeRecette(list);
        return true;
    }
    return false;
}

void plazza::Kitchen::giveOrder()
{
    bool isTmp = false;
    plazza::Pizza *tmp;

    for (auto &i : this->_pizza) {
        if (i.second == false) {
            tmp = i.first;
            i.second = true;
            isTmp = true;
        }
    }
    if (isTmp == false)
        return;
    for (auto &i : this->_cooks) {
        if (i.first->isBusy() == false) {
            i.first->setBusy(true);
            i.first->setActualPizza(tmp);
            std::cout << "Cook accepted and actually cooking pizza" << std::endl;
            this->_chrono->resetChrono();
            i.second = new std::thread(&plazza::Cook::cooking, i.first);
            i.second->join();
            return;
        }
    }
    for (auto &i : this->_cooks) {
        if (i.first->isWaiting() == false) {
            i.first->setWaiting(true);
            i.first->setActualPizza(tmp);
            std::cout << "Cook accepted (in waiting) pizza" << std::endl;
            this->_chrono->resetChrono();
            i.second = new std::thread(&plazza::Cook::cooking, i.first);
            i.second->join();
            return;
        }
    }
}

void plazza::Kitchen::manageResponse()
{
    std::string msg = this->_communication->receiveCommunication(getpid());

    if (strcmp(msg.c_str(), "isNotBusy") == 0) {
        if (this->areBusy() == false)
            this->_communication->sendCommunication("True", 1);
        else
            this->_communication->sendCommunication("False", 1);
        return;
    }
    else if (strcmp(msg.c_str(), "isNotAwaiting") == 0) {
        if (this->areWaiting() == false)
            this->_communication->sendCommunication("True", 1);
        else
            this->_communication->sendCommunication("False", 1);
        return;
    }
    else if (strcmp(msg.c_str(), "isInactive") == 0) {
        if (this->_inactive == false)
            this->_communication->sendCommunication("False", 1);
        else
            this->_communication->sendCommunication("True", 1);
        return;
    }
    else if (strcmp(msg.c_str(), "exit") == 0) {
        this->_communication->sendCommunication("Exited", 1);
        exit(0);
    }
    else if (strcmp(msg.c_str(), "isPizzaEnd") == 0) {
        for (auto &i : this->_cooks) {
            if (i.first->isCooked() == true) {
                this->_communication->sendCommunication(this->_parser.unpack(i.first->getActualPizza()).c_str(), 1);
                i.first->setUnCooked();
                return ;
            }
        }
        this->_communication->sendCommunication("False", 1);
    }
    else if (this->_parser.IsPossibleToPack(msg) == true) {
        std::cout << "Kitchen (" << getpid() << ") received: " << msg << std::endl;
        plazza::Pizza *object = this->_parser.pack(msg);
        this->_pizza.push_back(std::make_pair(object,false));

        std::string tmp = "La kitchen avec le pid [" + std::to_string(getpid()) + "] a recu une pizza !";
        this->_log.writeLog(tmp,this->_chrono->getTime());
        return ;
    }
        this->_communication->sendCommunication("False", 1);
}

void plazza::Kitchen::manageKitchen()
{
    std::cout << "Open new kitchen at: " << getpid() << std::endl;
    this->_stockChrono->startChrono();
    this->_chrono->startChrono();
    while (1) {
        this->manageResponse();
        this->giveOrder();
        if (this->_chrono->getElapsedTime() < 5.0) {
            if (this->areWaiting() == true || this->areWaiting() == true) {
                this->_chrono->resetChrono();
            }
            if (this->_stockChrono->getElapsedTime() >= this->_speedStock) {
                this->_ingredient->addIngredients();
                this->_stockChrono->resetChrono();
            }
        }
        else {
            this->_inactive = true;
        }
    }
}

    /*
 
        for (auto &i : this->_cooks) {
            i.second->join();
        }
    }
    */


