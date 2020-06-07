/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Chrono
*/

#include "Chrono.hpp"

plazza::Chrono::Chrono()
{
}

plazza::Chrono::~Chrono()
{
}

std::string plazza::Chrono::getTime()
{
    auto end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    return std::ctime(&end_time);
}

void plazza::Chrono::resetChrono()
{
    this->startChrono();
}

void plazza::Chrono::startChrono()
{
    this->_begin = std::chrono::system_clock::now();
}

double plazza::Chrono::getElapsedTime()
{
    this->_end = std::chrono::system_clock::now();
    std::chrono::duration<double> result = this->_end - this->_begin;
    return result.count();
}