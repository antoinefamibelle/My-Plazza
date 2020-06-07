/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Mutex
*/

#pragma once
#include "IMutex.hpp"

class Mutex : public IMutex{
    public:
        Mutex();
        ~Mutex();

        void lockMutex();
        void unlockMutex();
        pthread_mutex_t &getMutex();
    protected:
        pthread_mutex_t _mutex;
        
};
