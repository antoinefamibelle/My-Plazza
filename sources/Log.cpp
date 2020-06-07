/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Log
*/

#include "Log.hpp"

plazza::Log::Log()
{
}

plazza::Log::~Log()
{
}

void plazza::Log::writeLog(std::string str, std::string time)
{
    this->_log.open(this->_filepath.c_str(),std::ios_base::app);
    this->_log << str << " [Event Time] : " << time << std::endl;
    this->_log.close();
}