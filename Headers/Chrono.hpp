/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Chrono
*/

#pragma once

#include "IChrono.hpp"
#include "ctime"

namespace plazza {
    class Chrono : public IChrono {
        public:
            Chrono();
            ~Chrono();

            void resetChrono();
            void startChrono();
            double getElapsedTime();
            std::string getTime();
        protected:
            std::chrono::time_point<std::chrono::system_clock> _begin;
            std::chrono::time_point<std::chrono::system_clock> _end;
        private:
    };
}
