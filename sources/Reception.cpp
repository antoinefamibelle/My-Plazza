/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Reception
*/


#include "Reception.hpp"

/// a supprimer apres

plazza::Reception:: Reception(int multiplier, int nbOfCook, int stockTime, char *flag) : _multiplier(multiplier), _nbOfCook(nbOfCook), _stockTime(stockTime)
{
    // std::shared_ptr<plazza::Communication> object(new plazza::Communication());
    // this->_communication = object;
    this->_communication = new plazza::Communication();
    this->_parser = new plazza::Parser();
    this->orderIndex = 1;
    this->_isGraphic = flag == NULL ? false : true;
}

void plazza::Reception::manageInput(int ret)
{
    if (ret == 1)
        return ;
    if (ret == 2)
        this->_order.insert(std::pair<int, Order>(this->_order.size() + 1, this->_parser->getOrderClass()));
    if (ret == 3)
        //do command
        return ;
}

void plazza::Reception::pizzaDistribution()
{
    std::map<int, Order>::iterator it = this->_order.find(this->orderIndex);
    if (it == this->_order.end()) {
        return;
    }
    std::vector<std::string> order = it->second.getOrder();
    for (auto &i : order) {
        std::string tmp = std::string(i + " " + std::to_string(this->orderIndex));
        this->_communication->sendCommunication((char *)tmp.c_str(), this->getFreeKitchen());
    }
    this->orderIndex++;
}

void plazza::Reception::pizzaDone(std::string msg)
{
    std::string id;
    std::string pizza;

    for (std::string::size_type i = 0; msg[i]; i++) {
        if (isdigit(msg[i])) {
            id.append(msg.substr(i, msg.size()));
            pizza.append(msg.substr(0, i));
            break;
        }
    }
    std::cout << "Pizza cooked and send to reception: " << msg << std::endl;
   // this->_order.at(std::stoi(id)).delOrder(pizza);
}

void plazza::Reception::isPizzaDone()
{
    for (auto &i : this->_storedKitchens) {
        this->_communication->sendCommunication("isPizzaEnd", i);
        std::string received = this->_communication->receiveCommunication(1);
       if (strcmp(received.c_str(), "False") != 0)
           this->pizzaDone(received);
    }
}

void plazza::Reception::checkEndOrder()
{
    for (std::map<int, Order>::iterator it = this->_order.begin(); it != this->_order.end(); ++it) {
        std::vector<std::string> vec = it->second.getOrder();
        if (vec.empty() == true) {
            std::cout << "Order " << it->first << " is done" << std::endl;
            this->_order.erase(it);
        }
    }
}

void plazza::Reception::head()
{
    int ret = 0;
    Graphical _graphical;

    if (this->_isGraphic == true)
        _graphical.Init_launcher();
    while (1) {
        if (this->_isGraphic == true) {
            clear();
            _graphical.displayChoices();
            _graphical.displayOrder(_order);
            refresh();
            _graphical.manageKey();
            if (_graphical.getIsOrderEnd() == true) {
                this->_order.insert(std::pair<int,plazza::Order>(this->_order.size() + 1, _graphical.getOrder()));
                _graphical.setIsOrderEnd(false);
            }
        } else {
            std::cout << "Enter your command: ";
            if ((ret = this->_parser->parserLoop()) == 2) {
                this->_order.insert(std::pair<int,plazza::Order>(this->_order.size() + 1, this->_parser->getOrderClass()));
                this->pizzaDistribution();
            } else if (ret == 1)
                std::cout << "Command Invalid!" << std::endl;
        }
        this->clearInactive();
        this->isPizzaDone();
        this->checkEndOrder();
    }
}

pid_t plazza::Reception::OpenNewKitchen()
{
    this->_process = new plazza::Process();
    this->_process->createProcessKitchen(_nbOfCook, _stockTime);
   
    if (this->_process->getPid() == -1)
        throw "Fork has just failed";
    
    if (this->_process->getPid() == 0) {
        this->_process->getKitchen()->manageKitchen();
        exit(0);
    } 
    else {
        _storedKitchens.push_back(this->_process->getPid());
    }
    return this->_process->getPid();
}

void plazza::Reception::clearInactive()
{
    if (this->_storedKitchens.empty() == true) {
        std::cout << "Exiting" << std::endl;
        return ;
    }
    for (std::vector<pid_t>::iterator it = _storedKitchens.begin(); it != _storedKitchens.end(); ++it) {
        this->_communication->sendCommunication("isInactive", *it);
        if (strcmp(this->_communication->receiveCommunication(1).c_str(), "True") == 0) {
            this->_communication->sendCommunication("exit", *it);
            if (strcmp(this->_communication->receiveCommunication(1).c_str(), "Exited") == 0)
                this->_storedKitchens.erase(it);
        }
    }
}

pid_t plazza::Reception::getFreeKitchen()
{
    pid_t pid = -1;
 
    for (auto &i : this->_storedKitchens) {
        this->_communication->sendCommunication("isNotBusy", i);
        if (strcmp(this->_communication->receiveCommunication(1).c_str(), "True") == 0)
            return i;
        this->_communication->sendCommunication("isNotAwaiting", i);
        if (strcmp(this->_communication->receiveCommunication(1).c_str(), "True") == 0 && pid == -1)
            pid = i;
    }
    if (pid != -1)
        return pid;
    return this->OpenNewKitchen();
}