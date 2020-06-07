/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

#include "Process.hpp"

#include "Order.hpp"
#include "Pizza.hpp"
#include "StoredIngredient.hpp"

#include "Graphical.hpp"
#include "Parser.hpp"
#include "iostream"
#include <string>
#include <vector>
#include <memory>

#include <cstring>
#include <stdio.h>
#include "unistd.h"
#include <stdlib.h>

#include <sys/ipc.h> 
#include <sys/msg.h>
#include <assert.h>

namespace plazza {
    class Reception {
        public:
            Reception(int, int, int, char *);
            ~Reception() {};
            void head();
            bool everyKitchenAreBusy();
            int getLaziestKitchen();

            pid_t OpenNewKitchen();
            void clearInactive();
            pid_t getFreeKitchen();
            void manageInput(int ret);
            void pizzaDistribution();
            void pizzaDone(std::string msg);
            void checkEndOrder();
            void isPizzaDone();

        protected:
        private:
            plazza::Process *_process;
            std::vector<pid_t> _storedKitchens;
            int _multiplier;
            int _nbOfCook;
            int _stockTime;
            plazza::Communication *_communication;
            std::map<int, plazza::Order> _order;
            int orderIndex;
            plazza::Parser *_parser;
            bool _isGraphic;
    };
}

#endif /* !RECEPTION_HPP_ */