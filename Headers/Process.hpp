/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Process
*/

#pragma once

#include "Kitchen.hpp"

namespace plazza {
    class Process {
        public:
            Process();
            ~Process();
            void createProcessKitchen(int, int);

            std::shared_ptr<plazza::Kitchen> getKitchen() { return this->_kitchen; };
            pid_t getPid() { return this->_pid;};

        protected:
            pid_t _pid;
            std::shared_ptr<plazza::Kitchen> _kitchen;
            bool _success;
        private:
    };
}
