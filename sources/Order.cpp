/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Order
*/

#include "Order.hpp"

plazza::Order::Order()
{
}

plazza::Order::~Order()
{
}

const std::vector<std::string> plazza::Order::getOrder() const
{
    return this->_order;
}

void plazza::Order::addOrder(std::string type, std::string size, std::string number)
{
    for (int i = 0; i < std::stoi(number); i++)
        this->_order.push_back(type + " " + size);
}

void plazza::Order::delOrder(std::string order)
{
    this->_order.erase(std::find(this->_order.begin(), this->_order.end(), order));
}