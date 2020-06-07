/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Mutex
*/

#include "Mutex.hpp"

Mutex::Mutex()
{
    pthread_mutex_init(&this->_mutex, nullptr);
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&this->_mutex);
}

void Mutex::lockMutex()
{
    pthread_mutex_lock(&this->_mutex);
}

void Mutex::unlockMutex()
{
  pthread_mutex_unlock(&this->_mutex);
}

pthread_mutex_t &Mutex::getMutex()
{
    return this->_mutex;
}

