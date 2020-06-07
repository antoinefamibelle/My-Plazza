/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Thread
*/

#include "Thread.hpp"
#include "functional"


plazza::Thread::Thread()
{

}

plazza::Thread::~Thread()
{
}

plazza::Thread::Thread(plazza::USAGE usage)
{
    this->_usage = usage;
}

std::thread *plazza::Thread::getThread()
{
    return this->_thread;
}

void plazza::Thread::join()
{
    if (this->_thread->joinable() == true)
        this->_thread->join();
    throw "There is an error into the join of the thread";
}
/*
void plazza::Thread::assign(void (*func)(plazza::Cook args))
{
    if (this->_usage == plazza::USAGE::KITCHEN)
        if (pthread_create(&this->_tool, NULL, func, arg) != 0) {
            std::cout << "T'es qu'une grosse merde" << std::endl;
        }
       // this->_thread = std::thread (&plazza::Cook::cooking);
}*/