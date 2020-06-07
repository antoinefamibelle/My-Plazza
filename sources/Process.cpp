/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Process
*/

#include "Process.hpp"


plazza::Process::Process()
{ 
}

plazza::Process::~Process()
{
}



void plazza::Process::createProcessKitchen(int nbOfCook, int Stock)
{
    std::shared_ptr<plazza::Kitchen> object (new Kitchen(nbOfCook, Stock, this->_pid));
    this->_pid = fork();

    if (this->_pid == 0) {
        this->_kitchen = object;
    }
}