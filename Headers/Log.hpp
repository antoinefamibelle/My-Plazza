/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Log
*/

#pragma once

#include "fstream"
#include "plazza.hpp"
#include "string"

namespace plazza {
    class Log {
        public:
            Log();
            ~Log();

            void writeLog(std::string, std::string);

        protected:
            
            std::string _filepath = "./logs/log.txt";
            std::ofstream _log;
        private:
    };
}
