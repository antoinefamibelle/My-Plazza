/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** IMutex
*/

#pragma once
#include "thread"

class IMutex {
    public:
        virtual ~IMutex() {};

        virtual void lockMutex() = 0;
        virtual void unlockMutex() = 0;
        virtual pthread_mutex_t &getMutex() = 0;
    protected:
    private:
};
