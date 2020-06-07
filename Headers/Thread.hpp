/*
** EPITECH PROJECT, 2020
** 
** File description:
** Thread
*/

#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <chrono>
#include <ctime>
#include <mutex>
#include "Cook.hpp"

namespace plazza {
    enum USAGE {
            UNDEFINED,
            KITCHEN
    };
    class Thread{
        
        public:
            Thread();
            Thread(plazza::USAGE);
            ~Thread();
            std::thread *getThread();
            void join();
            //void assign(void* (*func)(void *), plazza::Cook *);

        public:
            pthread_t _tool;
            std::thread *_thread;
            plazza::USAGE _usage;
        private:
    };
}